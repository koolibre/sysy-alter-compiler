```c++
RootNode *root = new RootNode;
```

1. 编译单元 CompUnit → CompUnit Decl

   ```c++
   $1->AddNode($2)
   $$ = $1;
   ```

2. 编译单元 CompUnit → CompUnit FuncDef

   ```c++
   $1->AddNode($2);
   $$ = $1;
   ```

3. 编译单元 CompUnit → Decl

   ```c++
   root->AddNode($1);
   $$ = root;
   ```

4. 编译单元 CompUnit → FuncDef

   ```c++
   root->AddNode($1);
   $$ = root;
   ```

5. 声明 Decl → ConstDecl

   ```c++
   $$ = $1;
   ```

6. 声明 Decl → VarDecl

   ```c++
   $$ = $1;
   ```

7. 常量声明 ConstDecl → '**const**' BType ConstDefList'**;**'

   ```c++
   $3->SetBasicType();
   $$ = $3;
   ```

8. 基本类型 BType → '**int**'

   ```c++
   DeclNode::basic_type_ = INT;
   FuncDefNode::tmp_fparam_basic_type_ = INT;
   $$ = nullptr;
   ```

9. 基本类型 BType → '**float**'

   ```c++
   DeclNode::basic_type_ = FLOAT;
   FuncDefNode::tmp_fparam_basic_type_ = FLOAT;
   $$ = nullptr;
   ```

10. 基本类型 BType → '**char**'

    ```c++
    DeclNode::basic_type_ = CHAR;
    FuncDefNode::tmp_fparam_basic_type_ = CHAR;
    $$ = nullptr;
    ```

11. 常数定义列表 ConstDefList → ConstDef

    ```c++
    DeclNode* new_decl_node = new DeclNode(CONST_DECL_NODE);
    new_decl_node->AddDecl();
    $$ = new_decl_node;
    ```
    
12. 常数定义列表 ConstDefList → ConstDefList '**,**' ConstDef

    ```c++
    $1->AddDecl();
    $$ = $1;
    ```

13. 常数定义 ConstDef → **Ident** ConstDefDimensionList '**=**' ConstInitVal

    ```c++
    DeclNode::tmp_ident_ = $1->GetIdent();
    DeclNode::tmp_init_val_ = $4;
    $$ = nullptr;
    ```

14. 常数定义维度列表 ConstDefDimensionList → /*  empty */

    ```c++
    DeclNode::tmp_array_dimension_array_.resize(0);
    $$ = nullptr;
    ```

15. 常数定义维度列表 ConstDefDimensionList → ConstDefDimensionList '**[**' ConstExp '**]**'

    ```c++
    DeclNode::tmp_array_dimension_array_.push_back($3);
    $$ = $1;
    ```

16. 常数定义初值 ConstInitVal → ConstExp

    ```c++
    $$ = $1;
    ```

17. 常数定义初值 ConstInitVal → '**{**' ConstInitValList '**}**'

    ```c++
    $$ = $2;
    ```

18. 常数定义初值 ConstInitVal → '**{**' '**}**'

    ```c++
    $$ = new InitValNode;
    ```

19. 常数定义初值列表 ConstInitValList → ConstInitValList '**,**' ConstInitVal

    ```c++
    $1->AddInitVal($3);
    $$ = $1;
    ```

20. 常数定义初值列表 ConstInitValList → ConstInitVal

    ```c++
    InitValNode *new_init_val_node = new InitValNode;
    new_init_val_node->AddInitVal($1);
    $$ = new_init_val_node;
    ```

21. 变量声明 VarDecl → BType VarDefList'**;**'

    ```c++
    $3->SetBasicType();
    $$ = $3;
    ```

22. 变量定义列表 VarDefList → VarDef

    ```c++
    DeclNode* new_decl_node = new DeclNode(VAR_DECL_NODE);
    new_decl_node->AddDecl();
    $$ = new_decl_node;
    ```

23. 变量定义列表 VarDefList → VarDefList '**,**' VarDef

    ```c++
    $1->AddDecl();
    $$ = $1;
    ```

24. 变量定义 VarDef → **Ident** VarDefDimensionList '**=**' VarInitVal

    ```c++
    DeclNode::tmp_ident_ = $1->GetIdent();
    DeclNode::tmp_init_val_ = $4;
    $$ = nullptr;
    ```

25. 变量定义维度列表 VarDefDimensionList → /*  empty */

    ```c++
    DeclNode::tmp_array_dimension_array_.resize(0);
    $$ = nullptr;
    ```

26. 变量定义维度列表 VarDefDimensionList → VarDefDimensionList '**[**' VarExp '**]**'

    ```c++
    DeclNode::tmp_array_dimension_array_.push_back($3);
    $$ = $1;
    ```

27. 变量定义初值 VarInitVal → VarExp

    ```c++
    $$ = $1;
    ```

28. 变量定义初值 VarInitVal → '**{**' VarInitValList '**}**'

    ```c++
    $$ = $2;
    ```

29. 变量定义初值 VarInitVal → '**{**' '**}**'

    ```c++
    $$ = new InitValNode;
    ```

30. 变量定义初值列表 VarInitValList → VarInitValList '**,**' VarInitVal

    ```c++
    $1->AddInitVal($3);
    $$ = $1;
    ```

31. 变量定义初值列表 VarInitValList → VarInitVal

    ```c++
    InitValNode *new_init_val_node = new InitValNode;
    new_init_val_node->AddInitVal($1);
    $$ = new_init_val_node;
    ```

32. 变量定义VarDef → **Ident** VarDefDimensionList

    ```c++
    DeclNode::tmp_ident_ = $1->GetIdent();
    DeclNode::tmp_init_val_ = nullptr;
    $$ = nullptr;
    ```

33. 语句块 Block → '**{**' BlockItemList '**}**'

    ```c++
    $$ = $2;
    ```

34. 语句块项目列表 BlockItemList → /* empty */

    ```c++
    $$ = new BlockNode();
    ```

35. 语句块项目列表 BlockItemList → BlockItemList BlockItem 

    ```c++
    $1->AddNode($2);
    $$ = $1;
    ```

36. 语句块项目 BlockItem → Decl

    ```c++
    $$ = $1;
    ```

37. 语句块项目 BlockItem → Stmt

    ```c++
    $$ = $1;
    ```

38. 返回语句 Stmt → '**return**' ExpChoice '**;**'

    ```c++
    $$ = new ReturnStmtNode($2);
    ```

39. 表达式选择 ExpChoice → Exp

    ```c++
    $$ = $1;
    ```

40. 表达式选择 ExpChoice → /* empty */

    ```c++
    $$ = nullptr;
    ```

41. continue语句 Stmt → '**continue**' '**;**'

    ```c++
    $$ = new ContinueStmtNode();
    ```

42. break语句 Stmt → '**break**' '**;**' 

    ```c++
    $$ = new BreakStmtNode();
    ```

43. while语句 Stmt → '**while**' '**(**' Cond '**)**' Stmt

    ```c++
    $$ = new WhileStmtNode($3, $5);
    ```

44. 条件Cond → LOrExp

    ```c++
    $$ = $1;
    ```

45. if语句 Stmt → '**if**' '**(**' Cond '**)**' Stmt ElseChoice

    ```c++
    $$ = new IfStmtNode($3, $5, $6);
    ```

46. 其他选择语句 ElseChoice → /* empty */

    ```c++
    $$ = nullptr;
    ```

47. 其他选择语句 ElseChoice →  '**else**' Stmt

    ```c++
    $$ = $2;
    ```

48. 块语句 Stmt → Block

    ```c++
    $$ = $1;
    ```

49. 表达式语句 Stmt → ExpChoice '**;**'

    ```c++
    $$ = $1;
    ```

50. 赋值语句 Stmt → LVal '**=**' Exp '**;**'

    ```c++
    $$ = new AssignStmtNode($1, $3);
    ```

51. 表达式 Exp → AddExp

    ```c++
    $$ = $1;
    ```

52. 左值表达式 LVal → **Ident** IndexList

    ```c++
    LValPrimaryExpNode* tmp_node = new LValPrimaryExpNode($1);
    for (auto itr : LValPrimaryExpNode::tmp_index_list_)
      tmp_node->AddIndex(itr);
    $$ = tmp_node;
    ```

53. 索引列表 IndexList → /* empty */

    ```c++
    LValPrimaryExpNode::tmp_index_array_.resize(0);
    $$ = nullptr;
    ```

54. 索引列表 IndexList → IndexList '**[**' Exp '**]**'

    ```c++
    LValPrimaryExpNode::tmp_index_array_.push_back($3);
    $$ = nullptr;
    ```

55. 基本表达式 PrimaryExp →  '**(**' Exp '**)**'

    ```c++
    $$ = $2;
    ```

56. 基本表达式 PrimaryExp → LVal | IntNumber | FloatNumber | Character | String

    ```c++
    $$ = $1;
    ```

57. 整数数值 IntNumber → **IntConst**

    ```c++
    $$ = $1;
    ```

58. 浮点数数值 FloatNumber → **FloatConst**

    ```c++
    $$ = $1;
    ```

59. 字符 Character → **CharConst**

    ```c++
    $$ = $1;
    ```

60. 字符串 String → **StringConst**

    ```c++
    $$ = $1;
    ```

61. 一元表达式 UnaryExp → PrimaryExp

    ```c++
    $$ = $1;
    ```

62. 一元表达式 UnaryExp → **Ident** '**(**' FuncRParamList '**)**'

    ```c++
    $3->SetIdent($1);
    $$ = $3;
    ```

63. 一元表达式 UnaryExp → **Ident** '**(**' '**)**'

    ```c++
    FuncCallExpNode* new_node = new FuncCallExpNode;
    new_node->SetIdent($1);
    $$ = new_node;
    ```

64. 函数实参列表 FuncRParamList → Exp

    ```c++
    FuncCallExpNode *new_node = new FuncCallExpNode;
    $$ = new_node;
    ```

65. 函数实参列表 FuncRParamList → FuncRParamList '**,**' Exp

    ```c++
    $1->AddParam($3);
    ```

67. 一元表达式 UnaryExp → UnaryOp UnaryExp

    ```c++
    $1->SetExp($2);
    $$ = $1;
    ```

68. 单目运算符 UnaryOp  → '**+**' | '**-**' | '**!**'

    ```c++
    UnaryExpNode *new_node = new UnaryExpNode(
        POSITIVE_OP | NEGATIVE_OP | NOT_OP);
    $$ = new_node;
    ```

69. 乘除模表达式 MulExp → UnaryExp

    ```c++
    $$ = $1;
    ```

70. 乘除模表达式 MulExp → MulExp MulOp UnaryExp

    ```c++
    $2->SetLeftExp($1);
    $2->SetRightExp($3);
    $$ = $2;
    ```

70. 乘除模运算符 MulOp → ('*****' | '**/**' | '**%**')

    ```c++
    BinaryExpNode *new_node = new BinaryExpNode(
        MUL_OP | DIV_OP | MOD_OP)
    $$ = $new_node;
    ```

72. 加减表达式 AddExp → MulExp

    ```c++
    $$ = $1;
    ```

73. 加减表达式 AddExp → AddExp AddOp MulExp

    ```c++
    $2->SetLeftExp($1);
    $2->SetRightExp($3);
    $$ = $2;
    ```

73. 加减运算符 AddOp → ('**+**' | '**-**' )

    ```c++
    BinaryExpNode *new_node = new BinaryExpNode(
        ADD_OP | SUB_OP)
    $$ = new_node;
    ```

75. 关系表达式 RelExp → AddExp

    ```c++
    $$ = $1;
    ```

76. 关系表达式 RelExp → RelExp RelOp AddExp

    ```c++
    $2->SetLeftExp($1);
    $2->SetRightExp($3);
    $$ = $2;
    ```

76. 关系运算符 RelOp →  ('**<**' | '**>**' | '**<=**' | '**>=**')

    ```c++
    BinaryExpNode *new_node = new BinaryExpNode(
        LE_OP | GE_OP | LEEQ_OP | GEEQ_OP)
    $$ = new_node;
    ```

78. 相等性表达式 EqExp → RelExp

    ```c++
    $$ = $1;
    ```

79. 相等性表达式 EqExp → EqExp EqOp RelExp

    ```c++
    $2->SetLeftExp($1);
    $2->SetRightExp($3);
    $$ = $2;
    ```

80. 相等性运算符 EqOp → ('**==**' | '**!=**')

    ```c++
    BinaryExpNode *new_node = new BinaryExpNode(
        EQ_OP | UNEQ_OP)
    ```

81. 逻辑与表达式 LAndExp → EqExp

    ```c++
    $$ = $1;
    ```

82. 逻辑与表达式 LAndExp → LAndExp LAndOp EqExp

    ```c++
    $2->SetLeftExp($1);
    $2->SetRightExp($3);
    $$ = $2;
    ```

83. 逻辑与运算符 LAndOp → '**&&**'

    ```c++
    BinaryExpNode *new_node = new BinaryExpNode(
        AND_OP)
    ```

84. 逻辑或表达式 LOrExp → LAndExp

    ```c++
    $$ = $1;
    ```

85. 逻辑或表达式 LOrExp → LOrExp LOrOp LAndExp

    ```c++
    $2->SetLeftExp($1);
    $2->SetRightExp($3);
    $$ = $2;
    ```

86. 逻辑或运算符 LOrOp → '**||**'

    ```c++
    BinaryExpNode *new_node = new BinaryExpNode(
        OR_OP)
    ```

87. 常量表达式 ConstExp → AddExp

    ```c++
    $$ = $1;
    ```

88. 函数定义 FuncDef → FuncType **Ident** '**(**' FuncFParamList '**)**' Block

    ```c++
    $1->SetIdent($2);
    $1->SetBlock($6);
    $$ = FuncDefNode::tmp_func_def_node_;
    ```

89. 函数定义 FuncDef → FuncType **Ident** '**(**' '**)**' Block

    ```c++
    $1->SetIdent($2);
    $1->SetBlock($6);
    $$ = FuncDefNode::tmp_func_def_node_;
    ```

89. 函数形参列表 FuncFParamList → FuncFParam

    ```c++
    FuncDefNode::tmp_func_def_node_->AddParam($1);
    $$ = nullptr;
    ```

90. 函数形参列表 FuncFParamList → FuncFParamList '**,**' FuncFParam

    ```c++
    FuncDefNode::tmp_func_def_node_->AddParam($1);
    $$ = nullptr;
    ```

92. 函数形参 FuncFParam → BType **Ident**

    ```c++
    $$ = $2;
    ```

93. 函数形参 FuncFParam → BType **Ident** '**[**' '**]**' FuncFParamIndexList

    ```c++
    $$ = $2;
    ```

94. 函数形参索引列表 FuncFParamIndexList → /* empty */

    ```c++
    FuncDefNode::tmp_param_index_list_.resize(0);
    FuncDefNode::tmp_param_index_list_.push_back(nullptr);
    ```

95. 函数形参索引列表 FuncFParamIndexList → FuncFParamIndexList '**[**' Exp '**]**'

    ```c++
    FuncDefNode::tmp_param_index_list_.push_back($3);
    ```

96. 函数类型 函数类型 FuncType → '**void**' | '**int**' | '**float**' | '**char**'

    ```c++
    FuncDefNode *new_node = new FuncDefNode(
        VOID, INT, FLOAT, CHAR);
    FuncDefNode::tmp_func_def_node_ = new_node;
    $$ = new_node;
    ```

    