; ModuleID = 'test.ll'
source_filename = "test.ll"

@0 = private unnamed_addr constant [22 x i8] c"please input the dim:\00", align 1
@1 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@2 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@3 = private unnamed_addr constant [5 x i8] c"<%d>\00", align 1
@4 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@5 = private unnamed_addr constant [25 x i8] c"please input some words:\00", align 1
@6 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@7 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@8 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@9 = private unnamed_addr constant [3 x i8] c"%f\00", align 1
@10 = private unnamed_addr constant [3 x i8] c"%f\00", align 1
@11 = private unnamed_addr constant [3 x i8] c"%c\00", align 1

define void @main() {
main:
  %0 = alloca i8
  %1 = alloca i32
  store i32 10, i32* %1
  %2 = load i32, i32* %1
  store i32 %2, i8* %0
  %3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([22 x i8], [22 x i8]* @0, i32 0, i32 0))
  %4 = load i8, i8* %0
  %5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @1, i32 0, i32 0), i8 %4)
  %6 = alloca i32
  %7 = alloca i32
  store i32 3, i32* %7
  %8 = load i32, i32* %7
  store i32 %8, i32* %6
  %9 = load i32, i32* %6
  %10 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @2, i32 0, i32 0), i32* %6)
  %11 = alloca i32
  store i32 20, i32* %11
  %decl_arr = alloca [20 x i32], i32 20
  %12 = alloca i32
  %13 = alloca i32
  store i32 0, i32* %13
  %14 = load i32, i32* %13
  store i32 %14, i32* %12
  br label %cond

cond:                                             ; preds = %body, %main
  %15 = load i32, i32* %12
  %16 = load i32, i32* %6
  %17 = icmp ult i32 %15, %16
  br i1 %17, label %body, label %cont

body:                                             ; preds = %cond
  %18 = alloca i32
  store i32 0, i32* %18
  %19 = alloca i32
  store i32 1, i32* %19
  %20 = load i32, i32* %19
  %21 = load i32, i32* %12
  %22 = mul i32 %21, %20
  %23 = load i32, i32* %18
  %24 = add i32 %22, %23
  store i32 %24, i32* %18
  %25 = load i32, i32* %18
  %arr_ele_ref = getelementptr inbounds [20 x i32], [20 x i32]* %decl_arr, i32 0, i32 %25
  %arr_ele_ref_var = alloca i32
  %26 = load i32, i32* %arr_ele_ref, align 2
  store i32 %26, i32* %arr_ele_ref_var
  %27 = alloca i32
  %28 = load i32, i32* %arr_ele_ref, align 2
  store i32 %28, i32* %27
  %29 = load i32, i32* %12
  store i32 %29, i32* %arr_ele_ref, align 2
  %30 = load i32, i32* %12
  %31 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @3, i32 0, i32 0), i32 %30)
  %32 = load i32, i32* %12
  %33 = alloca i32
  store i32 1, i32* %33
  %34 = load i32, i32* %33
  %35 = add i32 %32, %34
  store i32 %35, i32* %12
  br label %cond

cont:                                             ; preds = %cond
  %36 = load i8, i8* %0
  %37 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @4, i32 0, i32 0), i8 %36)
  %38 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([25 x i8], [25 x i8]* @5, i32 0, i32 0))
  %39 = alloca i32
  store i32 100, i32* %39
  %decl_arr1 = alloca [100 x i8], i32 100
  %arrayPtr = getelementptr inbounds [100 x i8], [100 x i8]* %decl_arr1, i32 0, i32 0
  %40 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @6, i32 0, i32 0), i8* %arrayPtr)
  %arrayPtr2 = getelementptr inbounds [100 x i8], [100 x i8]* %decl_arr1, i32 0, i32 0
  %41 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @7, i32 0, i32 0), i8* %arrayPtr2)
  %42 = load i8, i8* %0
  %43 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @8, i32 0, i32 0), i8 %42)
  %44 = alloca float
  %45 = load float, float* %44
  %46 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @9, i32 0, i32 0), float* %44)
  %47 = load float, float* %44
  %48 = fpext float %47 to double
  %49 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @10, i32 0, i32 0), double %48)
  %50 = load i8, i8* %0
  %51 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @11, i32 0, i32 0), i8 %50)
  ret void
}

declare i32 @printf(i8*, ...)

declare i32 @printf.1(i8*, ...)

declare i32 @scanf(i8*, ...)

declare i32 @printf.2(i8*, ...)

declare i32 @printf.3(i8*, ...)

declare i32 @printf.4(i8*, ...)

declare i32 @scanf.5(i8*, ...)

declare i32 @printf.6(i8*, ...)

declare i32 @printf.7(i8*, ...)

declare i32 @scanf.8(i8*, ...)

declare i32 @printf.9(i8*, ...)

declare i32 @printf.10(i8*, ...)
