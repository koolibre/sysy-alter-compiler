#ifndef SYSY_ALTER_COMPILER_IR_GEN_TYPE_SYSTEM_HPP_
#define SYSY_ALTER_COMPILER_IR_GEN_TYPE_SYSTEM_HPP_

#include <iostream>
#include <string>
#include <list>

#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

#include "ast/ast.hpp"

// basic type for type check
enum class TypeCheckBasicType {
  CHAR, INT, VOID, FLOAT, STRING,
  CHAR_ARRAY, INT_ARRAY, FLOAT_ARRAY,
  ERROR
};

// complex type for type check
struct TypeCheckType {
 public:
  // ctor
  TypeCheckType(TypeCheckBasicType basic_type = TypeCheckBasicType::VOID) :
      basic_type_(basic_type) {}
  TypeCheckType(TypeCheckBasicType basic_type,
                std::list<int> &array_dimension_list) :
      basic_type_(basic_type),
      array_dimension_list_(array_dimension_list) {}
      
  TypeCheckType(TypeCheckType &type) {
    this->basic_type_ = type.basic_type_;
    this->array_dimension_list_ = type.array_dimension_list_;
  }
  // default dtor
  // member
  TypeCheckBasicType basic_type_;
  std::list<int> array_dimension_list_;
};

// class TypeSystem
class TypeSystem {
 public:
  // ctor
  TypeSystem(llvm::LLVMContext &llvm_context);
  // default dtor
  // other
  TypeCheckBasicType GetBinaryExpTypeResult(TypeCheckBasicType type1, TypeCheckBasicType type2);
  TypeCheckBasicType GetAssignTypeResult(TypeCheckBasicType left_type, TypeCheckBasicType right_type);

  llvm::Value* Cast(llvm::Value *from, llvm::Type *to_type, llvm::BasicBlock *insert_block);
  inline static bool BasicTypeMatch(BasicType type1, TypeCheckBasicType type2) {
    return (type1 == BasicType::CHAR && type2 == TypeCheckBasicType::CHAR) ||
           (type1 == BasicType::FLOAT && type2 == TypeCheckBasicType::FLOAT) ||
           (type1 == BasicType::INT && type2 == TypeCheckBasicType::INT) ||
           (type1 == BasicType::VOID && type2 == TypeCheckBasicType::VOID);
  }
  inline static std::string BasicTypeToString(TypeCheckBasicType type) {
    static std::string type_to_string[9] = {
      "char", "int", "void",
      "float", "string", "char array",
      "int array", "float array", "error"
    };
    return type_to_string[int(type)];
  }

 private:
  // other
  void AddBinaryResult(TypeCheckBasicType type1,
                       TypeCheckBasicType type2,
                       TypeCheckBasicType result_type);
  void AddAssignResult(TypeCheckBasicType type1,
                       TypeCheckBasicType type2,
                       TypeCheckBasicType result_type);
  void AddCastOp(llvm::Type* type1,
                 llvm::Type* type2,
                 llvm::CastInst::CastOps op);
  // member
  llvm::LLVMContext &llvm_context_;
  std::map<std::pair<int, int>, TypeCheckBasicType> binary_expression_type_result_;
  std::map<std::pair<int, int>, TypeCheckBasicType> assignment_type_result_;
  std::map<std::pair<llvm::Type*, llvm::Type*>, llvm::CastInst::CastOps> type_cast_op_;
};

#endif