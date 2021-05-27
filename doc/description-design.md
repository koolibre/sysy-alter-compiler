## Description & Design

#### 说明

- [...]表示可重复0或1次的可选项
- {...}表示可重复0次或多次的项
- // 表示从SysY文法修改的部分
- 增加了对float, char的支持

#### 文法

​	编译单元 CompUnit → [ CompUnit ] ( Decl | FuncDef ) 
​	声明 Decl → ConstDecl | VarDecl
​	常量声明 ConstDecl → '**const**' BType ConstDef { '**,**' ConstDef } '**;**' 
​	// 基本类型 BType → '**int**' | '**float**' | '**char**'
​	常数定义 ConstDef → **Ident** { '**[**' ConstExp '**]**' } '**=**' ConstInitVal
​	常量初值 ConstInitVal → ConstExp | '**{**' [ ConstInitVal { '**,**' ConstInitVal } ] '**}**'
​	变量声明 VarDecl → BType VarDef { '**,**' VarDef } '**;**'
​	变量定义 VarDef → **Ident** { '**[**' ConstExp '**]**' } | **Ident** { '**[**' ConstExp '**]**' } '**=**' InitVal
​	变量初值 InitVal → Exp | '**{**' [ InitVal { '**,**' InitVal } ] '**}**'
​	函数定义 FuncDef → FuncType **Ident** '**(**' [FuncFParams] '**)**' Block
 // 函数类型 FuncType → '**void**' | '**int**' | '**float**' | '**char**'
​	函数形参表 FuncFParams → FuncFParam { '**,**' FuncFParam } 
​	函数形参 FuncFParam → BType **Ident** ['**[**' '**]**' { '**[**' Exp '**]**' }] 
​	语句块 Block → '**{**' { BlockItem } '**}**'
​	语句块项 BlockItem → Decl | Stmt 
​	语句 Stmt → LVal '**=**' Exp '**;**' | [Exp] '**;**' | Block | '**if**' '**(**' Cond '**)**' Stmt [ '**else**' Stmt ] 	| '**while**' '**(**' Cond '**)**' Stmt | '**break**' '**;**' | '**continue**' '**;**' | '**return**' [Exp] '**;**'
​	表达式 Exp → AddExp
​	条件表达式 Cond → LOrExp
​	左值表达式 LVal → **Ident** {'**[**' Exp '**]**'}
​	基本表达式 PrimaryExp → '**(**' Exp '**)**' | LVal | IntNumber | FloatNumber | 		  Character | String
​	// 整数数值 IntNumber → **IntConst** 
​	// 浮点数数值 FloatNumber → **FloatConst**
​	// 字符 Character → **CharConst**
​	// 字符串 String → **StringConst**
​	一元表达式 UnaryExp → PrimaryExp | **Ident** '**(**' [FuncRParams] '**)**' | UnaryOp 	UnaryExp
​	单目运算符 UnaryOp → '**+**' | '**−**' | '**!**' 注：'!'仅出现在条件表达式中
​	函数实参表 FuncRParams → Exp { '**,**' Exp } 
​	乘除模表达式 MulExp → UnaryExp | MulExp ('*****' | '**/**' | '**%**') UnaryExp
​	加减表达式 AddExp → MulExp | AddExp ('**+**' | '**−**') MulExp
​	关系表达式 RelExp → AddExp | RelExp ('**<**' | '**>**' | '**<=**' | '**>=**') AddExp
​	相等性表达式 EqExp → RelExp | EqExp ('**==**' | '**!=**') RelExp
​	逻辑与表达式 LAndExp → EqExp | LAndExp '**&&**' EqExp
​	逻辑或表达式 LOrExp → LAndExp | LOrExp '**||**' LAndExp
​	常量表达式 ConstExp → AddExp

#### 终结符

- keyword: const, int, float, char, void, if, else, while, break, continue, return
- identifier: Ident
- literal: IntConst, FloatConst, CharConst, StringConst
- symbols: , ; [ ] { } + - ! * / % < > <= >= == != && || =
- error: Error

```lex
character [a-zA-Z]
digit [0-9]
Ident {character}({character}|"_"|{digit})*
IntConst [+-]?{digit}+
floatConst [+-]?({digit}+\.{digit}* | {digit}*\.{digit}+)
CharConst '{character}'
StringConst \"[^\"]*\"
comment_typeone "//"
comment_typetwo "/*"([^\*]|(\*)*[^\*/])*(\*)*"*/"
symbol1 [","";""[""]""{""}""+""-""!""*""/""%""<"">""="]
keyword "const" | "int" | "float" | "char" | "void" | "if" | "else" | "while" | "break" | "continue" | "return"
```

#### naive AST design

##### class relation

```txt
virtual design:
Node
   |-DeclNode
	 |-FucDefNode
	 |-BlockNode
	 |-(StmtNode)
	 | |-AssignStmtNode
	 | |-IfStmtNode
	 | |-WhileStmtNode
	 | |-BreakStmtNode
	 | |-ContinueStmtNode
	 | |-ReturnStmtNode
	 |-InitValNode
	 |-IdentNode
	 |-(ExpNode)
	 |-FuncCallExpNode
	 |-BinaryExpNode
	 |-UnaryExpNode
   |-(PrimaryExpNode)
	 |-LvalPrimaryExpNode (represent all LVal)
   |-IntPrimaryExpNode
	 |-FloatPrimaryExpNode
	 |-CharPrimaryExpNode
	 |-StringPrimaryExpNode
implementation design:
	all inherit from class Node, "( )" means that class will not be implemented.
```