#include "ir-gen/type-system.hpp"

#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

using namespace llvm;

TypeSystem::TypeSystem(LLVMContext &llvm_context) :
    llvm_context_(llvm_context) {
  AddBinaryResult(TypeCheckBasicType::INT, 
                  TypeCheckBasicType::FLOAT, 
                  TypeCheckBasicType::FLOAT);
  AddBinaryResult(TypeCheckBasicType::FLOAT, 
                  TypeCheckBasicType::INT, 
                  TypeCheckBasicType::FLOAT);
  
  AddAssignResult(TypeCheckBasicType::FLOAT, 
                  TypeCheckBasicType::INT, 
                  TypeCheckBasicType::INT);
  AddAssignResult(TypeCheckBasicType::INT, 
                  TypeCheckBasicType::FLOAT, 
                  TypeCheckBasicType::FLOAT);

  AddCastOp(Type::getInt32Ty(llvm_context_),
            Type::getFloatTy(llvm_context_),
            llvm::CastInst::SIToFP);
  AddCastOp(Type::getFloatTy(llvm_context_),
            Type::getInt32Ty(llvm_context_),
            llvm::CastInst::SIToFP);
}

void TypeSystem::AddBinaryResult(TypeCheckBasicType type1,
                                 TypeCheckBasicType type2,
                                 TypeCheckBasicType result_type) {
  binary_expression_type_result_.insert(
    std::make_pair(std::make_pair(int(type1), int(type2)), result_type));
}

void TypeSystem::AddAssignResult(TypeCheckBasicType left_type,
                                 TypeCheckBasicType right_type,
                                 TypeCheckBasicType result_type) {
  assignment_type_result_.insert(
    std::make_pair(std::make_pair(int(left_type), int(right_type)), result_type));
}

void TypeSystem::AddCastOp(llvm::Type* type1,
                           llvm::Type* type2,
                           llvm::CastInst::CastOps op) {
  assert(type1 != nullptr);
  assert(type2 != nullptr);
  type_cast_op_.insert(
    std::make_pair(std::make_pair(type1, type2), op)
  );
}

llvm::Value* TypeSystem::Cast(llvm::Value *from, llvm::Type *to_type, llvm::BasicBlock *insert_block) {
  assert(from != nullptr);
  assert(to_type != nullptr);
  assert(insert_block != nullptr);
  llvm::Type *from_type = from->getType();
  
  // same type
  if (from_type == to_type)
    return from;
  // no op for type cast
  auto itr = type_cast_op_.find(std::make_pair(from_type, to_type));
  if ( itr != type_cast_op_.end()) {
#ifdef DEBUG
#ifdef DEBUG_IR_GEN
    std::cout << "no such type cast" << std::endl;
#endif
#endif
    return CastInst::Create(itr->second, from, to_type, "type_cast", insert_block);
  } else {
    return from;
  }
}

TypeCheckBasicType TypeSystem::GetBinaryExpTypeResult(TypeCheckBasicType type1, TypeCheckBasicType type2) {
  // same type, return same type
  if (type1 == type2)
    return type1;
    
  // differnt type, check table
  auto itr = binary_expression_type_result_.find(std::make_pair(int(type1), int(type2)));
  if (itr != binary_expression_type_result_.end())
    return itr->second;
  else
    return TypeCheckBasicType::ERROR;
}

TypeCheckBasicType TypeSystem::GetAssignTypeResult(TypeCheckBasicType left_type, TypeCheckBasicType right_type) {
  // same type, return same type
  if (left_type == right_type)
    return left_type;
    
  // differnt type, check table
  auto itr = assignment_type_result_.find(std::make_pair(int(left_type), int(right_type)));
  if (itr != assignment_type_result_.end())
    return itr->second;
  else
    return TypeCheckBasicType::ERROR;
}
