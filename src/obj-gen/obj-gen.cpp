
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>
#include <llvm/ADT/Optional.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/IR/LegacyPassManager.h>
#include <string>

#include "ir-gen/ir-gen.hpp"
#include "obj-gen/obj-gen.hpp"

using namespace llvm;
using namespace llvm::sys;
using namespace std;


void ObjGen(IrGenVisitor & irgenvisitor, const std::string& filename){
    Module* module_ = irgenvisitor.GetModule();
    // Initialize the target registry etc.
    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    auto targetTriple = sys::getDefaultTargetTriple();
    module_->setTargetTriple(targetTriple);

    std::string error;
    auto Target = TargetRegistry::lookupTarget(targetTriple, error);

    if( !Target ){
        errs() << error;
        return;
    }

    auto CPU = "generic";
    auto features = "";

    TargetOptions opt;
    auto RM = Optional<Reloc::Model>();
    auto theTargetMachine = Target->createTargetMachine(targetTriple, CPU, features, opt, RM);

    module_->setDataLayout(theTargetMachine->createDataLayout());
    module_->setTargetTriple(targetTriple);


    std::error_code EC;
    raw_fd_ostream dest(filename.c_str(), EC, sys::fs::F_None);
//    raw_fd_ostream dest(filename.c_str(), EC, sys::fs::F_None);
//    formatted_raw_ostream formattedRawOstream(dest);

    legacy::PassManager pass;
    auto fileType = CGFT_ObjectFile;

    if( theTargetMachine->addPassesToEmitFile(pass, dest, nullptr, fileType) ){
        errs() << "theTargetMachine can't emit a file of this type";
        return;
    }

    pass.run(*module_);
    dest.flush();

    outs() << "Object code wrote to " << filename.c_str() << "\n";

    // print IR
    //verifyModule(*module_);
    std::error_code errorcode;
    auto stream = new llvm::raw_fd_ostream("test.ll", errorcode);
    module_->print(*stream, nullptr);
    return;
}