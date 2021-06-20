; ModuleID = 'test.ll'
source_filename = "test.ll"

@global_arr_arr = common global [10000 x i32] 0, align 2
@global_var_len = common global i32 0, align 2
@global_var_one = common global i32 0, align 2
@global_var_zero = common global i32 0, align 2
@global_var_control = common global i32 0, align 2
@str_literal = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@str_literal.1 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@str_literal.2 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@str_literal.4 = private unnamed_addr constant [3 x i8] c"%d\00", align 1

define void @printNL() {
printNL:
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @str_literal, i32 0, i32 0), i32 10)
  ret void
}

declare i32 @printf(i8*, ...)

define void @quickSort(i32 %0, i32 %1) {
quickSort:
  %2 = add i32 %0, %0
  %3 = sdiv i32 %2, 2
  %4 = mul i32 %3, 1
  %5 = add i32 %4, 0
  %arr_ele_ref = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_arr_arr, i32 0, i32 %5
  %__arr_ele_ref_value = load i32, i32* %arr_ele_ref, align 2
  store i32 1, i32* @global_var_control
  %6 = icmp sge i32 %0, %1
  br i1 %6, label %true, label %cont

true:                                             ; preds = %quickSort
  ret void
  br label %cont

cont:                                             ; preds = %true, %quickSort
  br label %cond

cond:                                             ; preds = %cont22, %cont
  %decl_var_first.0 = phi i32 [ %3, %cont ], [ %decl_var_first.1, %cont22 ]
  %decl_var_last.0 = phi i32 [ %1, %cont ], [ %decl_var_last.1, %cont22 ]
  %7 = icmp ult i32 %decl_var_first.0, %decl_var_last.0
  br i1 %7, label %body, label %cont2

body:                                             ; preds = %cond
  %8 = load i32, i32* @global_var_one
  store i32 %8, i32* @global_var_control
  %9 = mul i32 %decl_var_last.0, 1
  %10 = add i32 %9, 0
  %arr_ele_ref3 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_arr_arr, i32 0, i32 %10
  %__arr_ele_ref_value4 = load i32, i32* %arr_ele_ref3, align 2
  br label %cond5

cont2:                                            ; preds = %cond
  %11 = mul i32 %decl_var_first.0, 1
  %12 = add i32 %11, 0
  %arr_ele_ref33 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_arr_arr, i32 0, i32 %12
  %__arr_ele_ref_value34 = load i32, i32* %arr_ele_ref33, align 2
  %13 = load i32, i32* %arr_ele_ref33, align 2
  store i32 %__arr_ele_ref_value, i32* %arr_ele_ref33, align 2
  %14 = load i32, i32* @global_var_one
  %15 = sub i32 %decl_var_first.0, %14
  call void @quickSort(i32 %0, i32 %15)
  %16 = load i32, i32* @global_var_one
  %17 = add i32 %decl_var_first.0, %16
  call void @quickSort(i32 %17, i32 %1)
  ret void

cond5:                                            ; preds = %cont9, %body
  %decl_var_last.1 = phi i32 [ %decl_var_last.0, %body ], [ %decl_var_last.2, %cont9 ]
  %decl_var_temp.0 = phi i32 [ %__arr_ele_ref_value4, %body ], [ %decl_var_temp.1, %cont9 ]
  %18 = load i32, i32* @global_var_control
  %19 = load i32, i32* @global_var_zero
  %20 = icmp ne i32 %18, %19
  br i1 %20, label %body6, label %cont7

body6:                                            ; preds = %cond5
  %21 = load i32, i32* @global_var_zero
  store i32 %21, i32* @global_var_control
  %22 = icmp ult i32 %decl_var_first.0, %decl_var_last.1
  br i1 %22, label %true8, label %cont9

cont7:                                            ; preds = %cond5
  %23 = load i32, i32* @global_var_one
  store i32 %23, i32* @global_var_control
  %24 = mul i32 %decl_var_last.1, 1
  %25 = add i32 %24, 0
  %arr_ele_ref14 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_arr_arr, i32 0, i32 %25
  %__arr_ele_ref_value15 = load i32, i32* %arr_ele_ref14, align 2
  %26 = mul i32 %decl_var_first.0, 1
  %27 = add i32 %26, 0
  %arr_ele_ref16 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_arr_arr, i32 0, i32 %27
  %__arr_ele_ref_value17 = load i32, i32* %arr_ele_ref16, align 2
  %28 = load i32, i32* %arr_ele_ref16, align 2
  store i32 %__arr_ele_ref_value15, i32* %arr_ele_ref16, align 2
  %29 = mul i32 %decl_var_first.0, 1
  %30 = add i32 %29, 0
  %arr_ele_ref18 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_arr_arr, i32 0, i32 %30
  %__arr_ele_ref_value19 = load i32, i32* %arr_ele_ref18, align 2
  br label %cond20

true8:                                            ; preds = %body6
  %31 = icmp sge i32 %decl_var_temp.0, %__arr_ele_ref_value
  br i1 %31, label %true10, label %cont11

cont9:                                            ; preds = %cont11, %body6
  %decl_var_last.2 = phi i32 [ %decl_var_last.3, %cont11 ], [ %decl_var_last.1, %body6 ]
  %decl_var_temp.1 = phi i32 [ %decl_var_temp.2, %cont11 ], [ %decl_var_temp.0, %body6 ]
  br label %cond5

true10:                                           ; preds = %true8
  %32 = load i32, i32* @global_var_one
  %33 = sub i32 %decl_var_last.1, %32
  %34 = mul i32 %33, 1
  %35 = add i32 %34, 0
  %arr_ele_ref12 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_arr_arr, i32 0, i32 %35
  %__arr_ele_ref_value13 = load i32, i32* %arr_ele_ref12, align 2
  %36 = load i32, i32* @global_var_one
  store i32 %36, i32* @global_var_control
  br label %cont11

cont11:                                           ; preds = %true10, %true8
  %decl_var_last.3 = phi i32 [ %33, %true10 ], [ %decl_var_last.1, %true8 ]
  %decl_var_temp.2 = phi i32 [ %__arr_ele_ref_value13, %true10 ], [ %decl_var_temp.0, %true8 ]
  br label %cont9

cond20:                                           ; preds = %cont24, %cont7
  %decl_var_first.1 = phi i32 [ %decl_var_first.0, %cont7 ], [ %decl_var_first.2, %cont24 ]
  %decl_var_temp.3 = phi i32 [ %__arr_ele_ref_value19, %cont7 ], [ %decl_var_temp.4, %cont24 ]
  %37 = load i32, i32* @global_var_control
  %38 = load i32, i32* @global_var_zero
  %39 = icmp ne i32 %37, %38
  br i1 %39, label %body21, label %cont22

body21:                                           ; preds = %cond20
  %40 = load i32, i32* @global_var_zero
  store i32 %40, i32* @global_var_control
  %41 = icmp ult i32 %decl_var_first.1, %decl_var_last.1
  br i1 %41, label %true23, label %cont24

cont22:                                           ; preds = %cond20
  %42 = mul i32 %decl_var_first.1, 1
  %43 = add i32 %42, 0
  %arr_ele_ref29 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_arr_arr, i32 0, i32 %43
  %__arr_ele_ref_value30 = load i32, i32* %arr_ele_ref29, align 2
  %44 = mul i32 %decl_var_last.1, 1
  %45 = add i32 %44, 0
  %arr_ele_ref31 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_arr_arr, i32 0, i32 %45
  %__arr_ele_ref_value32 = load i32, i32* %arr_ele_ref31, align 2
  %46 = load i32, i32* %arr_ele_ref31, align 2
  store i32 %__arr_ele_ref_value30, i32* %arr_ele_ref31, align 2
  br label %cond

true23:                                           ; preds = %body21
  %47 = icmp sle i32 %decl_var_temp.3, %__arr_ele_ref_value
  br i1 %47, label %true25, label %cont26

cont24:                                           ; preds = %cont26, %body21
  %decl_var_first.2 = phi i32 [ %decl_var_first.3, %cont26 ], [ %decl_var_first.1, %body21 ]
  %decl_var_temp.4 = phi i32 [ %decl_var_temp.5, %cont26 ], [ %decl_var_temp.3, %body21 ]
  br label %cond20

true25:                                           ; preds = %true23
  %48 = load i32, i32* @global_var_one
  %49 = add i32 %decl_var_first.1, %48
  %50 = mul i32 %49, 1
  %51 = add i32 %50, 0
  %arr_ele_ref27 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_arr_arr, i32 0, i32 %51
  %__arr_ele_ref_value28 = load i32, i32* %arr_ele_ref27, align 2
  %52 = load i32, i32* @global_var_one
  store i32 %52, i32* @global_var_control
  br label %cont26

cont26:                                           ; preds = %true25, %true23
  %decl_var_first.3 = phi i32 [ %49, %true25 ], [ %decl_var_first.1, %true23 ]
  %decl_var_temp.5 = phi i32 [ %__arr_ele_ref_value28, %true25 ], [ %decl_var_temp.3, %true23 ]
  br label %cont24
}

define i32 @main() {
main:
  %decl_var_x = alloca i32
  store i32 0, i32* %decl_var_x
  store i32 0, i32* @global_var_zero
  store i32 1, i32* @global_var_one
  %0 = load i32, i32* @global_var_len
  %1 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @str_literal.1, i32 0, i32 0), i32* @global_var_len)
  %2 = load i32, i32* @global_var_len
  %3 = icmp eq i32 %2, 0
  br i1 %3, label %true, label %cont

true:                                             ; preds = %main
  %int_literal5 = alloca i32
  store i32 0, i32* %int_literal5
  %4 = load i32, i32* %int_literal5
  ret i32 %4
  br label %cont

cont:                                             ; preds = %true, %main
  br label %cond

cond:                                             ; preds = %body, %cont
  %decl_var_i.0 = phi i32 [ 0, %cont ], [ %14, %body ]
  %5 = load i32, i32* @global_var_len
  %6 = icmp ult i32 %decl_var_i.0, %5
  br i1 %6, label %body, label %cont6

body:                                             ; preds = %cond
  %7 = load i32, i32* %decl_var_x
  %8 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @str_literal.2, i32 0, i32 0), i32* %decl_var_x)
  %9 = mul i32 %decl_var_i.0, 1
  %10 = add i32 %9, 0
  %arr_ele_ref = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_arr_arr, i32 0, i32 %10
  %__arr_ele_ref_value = load i32, i32* %arr_ele_ref, align 2
  %11 = load i32, i32* %arr_ele_ref, align 2
  %12 = load i32, i32* %decl_var_x
  store i32 %12, i32* %arr_ele_ref, align 2
  %13 = load i32, i32* @global_var_one
  %14 = add i32 %decl_var_i.0, %13
  br label %cond

cont6:                                            ; preds = %cond
  %15 = load i32, i32* @global_var_len
  %16 = load i32, i32* @global_var_one
  %17 = sub i32 %15, %16
  %18 = load i32, i32* @global_var_zero
  call void @quickSort(i32 %18, i32 %17)
  %19 = load i32, i32* @global_var_zero
  br label %cond7

cond7:                                            ; preds = %body8, %cont6
  %decl_var_i.1 = phi i32 [ %19, %cont6 ], [ %26, %body8 ]
  %20 = load i32, i32* @global_var_len
  %21 = icmp ult i32 %decl_var_i.1, %20
  br i1 %21, label %body8, label %cont9

body8:                                            ; preds = %cond7
  %22 = mul i32 %decl_var_i.1, 1
  %23 = add i32 %22, 0
  %arr_ele_ref10 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_arr_arr, i32 0, i32 %23
  %__arr_ele_ref_value11 = load i32, i32* %arr_ele_ref10, align 2
  %24 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @str_literal.4, i32 0, i32 0), i32 %__arr_ele_ref_value11)
  call void @printNL()
  %25 = load i32, i32* @global_var_one
  %26 = add i32 %decl_var_i.1, %25
  br label %cond7

cont9:                                            ; preds = %cond7
  %int_literal12 = alloca i32
  store i32 0, i32* %int_literal12
  %27 = load i32, i32* %int_literal12
  ret i32 %27
}

declare i32 @scanf(i8*, ...)

declare i32 @scanf.3(i8*, ...)

declare i32 @printf.5(i8*, ...)
