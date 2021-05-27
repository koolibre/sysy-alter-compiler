#ifndef SYSY_ALTER_COMPILER_IR_GEN_IR_HPP_
#define SYSY_ALTER_COMPILER_IR_GEN_IR_HPP_

#define DEBUG

#ifndef DEBUG
  #define NDEBUG
#else
  #undef NDEBUG
#endif

#include <cassert> // use assert()

#include <iostream> // use std::cout
#include <string> // use std::string
#include <vector> // use std::vector

// ir's code type
enum class CodeType {
  LABEL,    // the target of GOTO
  FUNCTION, // function definition
  GOTO,     // forced jump
  IF_GOTO,  // conditional jump
  DEC,      // variable declaration, allocate space
  RETURN,   // return in function
  ARG,      // real parameters for functions
  PARAM,    // format parameters for functions
  CALL,     // function call
  EXP,      // basic expression, result = op1 op op2
  FREE      // free variable, for temporary variable in function, block. Not include format parameters
};

// type of result and op
enum class ResultOperandType {
  INT,   // width: 4 bytes
  FLOAT, // width: 4 bytes
  CHAR,  // width: 1 bytes
  VOID,  // represent "no type" or "not useful"
  ADDR   // width: 4 bytes
};

// ir's op type
enum class OpType {
  // for condition in IF_GOTO
  // < > <= >= == !=
  LE, GE, LEEQ, GEEQ, EQ, UNEQ,
  // for expressions
  // assignment, +, -, *, /, %, left-reference, right-reference, type-conversion,
  ASSIGN, ADD, SUB, MUL, DIV, MOD, LREF, RREF, CONV,
  // NULL represent "not useful"
  MNULL
}; 

// Ir data
struct LinearIr {
 public:
  // ctor
  LinearIr() :
      normal_label_count_(0),
      function_label_count_(0),
      variable_count_(0),
      temporary_count_(0) {}
  // default dtor
  // other
  // get number of code
  inline int GetSize() const {
    return code_type_.size();
  }
  // get index'th item
  void GetItem(
      int index,
      CodeType &code_type,
      ResultOperandType &result_type, ResultOperandType &operand_type,
      std::string &label,
      std::string &result, std::string &op1, std::string &op2,
      OpType op_type) const;
  // fast code generation for different kinds of code
  void AddLabelCode();
 private: 
  // member
  // code type
  std::vector<CodeType> code_type_;

  // type of result and operand
  std::vector<ResultOperandType> result_type_;
  std::vector<ResultOperandType> operand_type_;
  
  // label, one of "li", "fi" and "main". "i" is an integer, 
  // "li" represent normal label i, "fi" represent function i
  std::vector<std::string> label_;
  // count for "i"
  int normal_label_count_;
  int function_label_count_;
  
  // result, op1 and op2
  // one of "vi", "ti", "#imm" and "null". 
  // "i" is an integer, "imm" is one of an integer, a float or a character
  // "vi" means variable i, "ti" means temporary variable, "#" means immediate data
  // "null" means "not useful"
  std::vector<std::string> result_;
  std::vector<std::string> op1_;
  std::vector<std::string> op2_;
  // count for "i"
  int variable_count_;
  int temporary_count_;
  
  // op type
  std::vector<OpType> op_type_;
};
#endif