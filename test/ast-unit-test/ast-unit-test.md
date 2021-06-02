## ast unit test

### 测试目的

测试构建ast。

### 输入格式

一段代码。如: input.txt内代码。

### 输出格式

```
[Node]
 -ContentMember: content
  [SubNode]
  ......
```

用`[]`表示节点的类型，`-`表示节点的组分。组分可能是子节点。依照此格式递归输出ast。

### 测试结果

为了保证结果正确，需要修改文法中的`LVal -> '(' Exp ')'`为`LVal -> '(' LOrExp ')'`。