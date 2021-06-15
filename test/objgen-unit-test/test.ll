; ModuleID = 'test.ll'
source_filename = "test.ll"

@0 = private unnamed_addr constant [4 x i8] c"%d \00", align 1
@1 = private unnamed_addr constant [4 x i8] c"%d \00", align 1
@2 = private unnamed_addr constant [5 x i8] c"%d /\00", align 1
@3 = private unnamed_addr constant [5 x i8] c"%d /\00", align 1
@4 = private unnamed_addr constant [5 x i8] c"%f /\00", align 1
@5 = private unnamed_addr constant [15 x i8] c"var1 is not 3/\00", align 1
@6 = private unnamed_addr constant [11 x i8] c"var1 is 3/\00", align 1

define void @main() {
main:
  %0 = alloca i32, align 4
  store i32 5, i32* %0, align 4
  %1 = alloca i32, align 4
  store i32 4, i32* %1, align 4
  %2 = alloca float, align 4
  store float 0x40099999A0000000, float* %2, align 4
  %3 = alloca float, align 4
  store float 0x4006666660000000, float* %3, align 4
  %4 = load i32, i32* %0, align 4
  store i32 %4, i32* %0, align 4
  %5 = load i32, i32* %0, align 4
  %6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0), i32 %5)
  %7 = load i32, i32* %0, align 4
  %8 = sub i32 0, %7
  store i32 %8, i32* %0, align 4
  %9 = load i32, i32* %0, align 4
  %10 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @1, i32 0, i32 0), i32 %9)
  %11 = load i32, i32* %0, align 4
  %12 = load i32, i32* %1, align 4
  %13 = add i32 %11, %12
  %14 = alloca i32, align 4
  store i32 1, i32* %14, align 4
  %15 = load i32, i32* %14, align 4
  %16 = add i32 %13, %15
  store i32 %16, i32* %1, align 4
  %17 = load i32, i32* %1, align 4
  %18 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @2, i32 0, i32 0), i32 %17)
  %19 = load i32, i32* %0, align 4
  %20 = load i32, i32* %1, align 4
  %21 = add i32 %19, %20
  %22 = alloca i32, align 4
  store i32 3, i32* %22, align 4
  %23 = load i32, i32* %22, align 4
  %24 = mul i32 %21, %23
  %25 = alloca i32, align 4
  store i32 7, i32* %25, align 4
  %26 = load i32, i32* %25, align 4
  %27 = sub i32 %24, %26
  %28 = alloca i32, align 4
  store i32 9, i32* %28, align 4
  %29 = load i32, i32* %28, align 4
  %30 = alloca i32, align 4
  store i32 2, i32* %30, align 4
  %31 = load i32, i32* %30, align 4
  %32 = sdiv i32 %29, %31
  %33 = mul i32 %29, %31
  %34 = sub i32 %29, %31
  %35 = add i32 %27, %34
  %36 = load i32, i32* %0, align 4
  %37 = alloca i32, align 4
  store i32 2, i32* %37, align 4
  %38 = load i32, i32* %37, align 4
  %39 = sdiv i32 %36, %38
  %40 = add i32 %35, %39
  store i32 %40, i32* %1, align 4
  %41 = load i32, i32* %1, align 4
  %42 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @3, i32 0, i32 0), i32 %41)
  %43 = load float, float* %2, align 4
  %44 = load float, float* %3, align 4
  %45 = fadd float %43, %44
  %46 = alloca float, align 4
  store float 0x400B333340000000, float* %46, align 4
  %47 = load float, float* %46, align 4
  %48 = fmul float %45, %47
  %49 = alloca float, align 4
  store float 0x401F333340000000, float* %49, align 4
  %50 = load float, float* %49, align 4
  %51 = fsub float %48, %50
  %52 = alloca i32, align 4
  store i32 6, i32* %52, align 4
  %53 = load i32, i32* %52, align 4
  %54 = alloca i32, align 4
  store i32 2, i32* %54, align 4
  %55 = load i32, i32* %54, align 4
  %56 = sdiv i32 %53, %55
  %type_cast = sitofp i32 %56 to float
  %57 = fadd float %51, %type_cast
  store float %57, float* %3, align 4
  %58 = load float, float* %3, align 4
  %59 = fpext float %58 to double
  %60 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @4, i32 0, i32 0), double %59)
  %61 = load float, float* %2, align 4
  %62 = alloca float, align 4
  store float 3.500000e+00, float* %62, align 4
  %63 = load float, float* %62, align 4
  %64 = fcmp one float %61, %63
  br i1 %64, label %true, label %cont

true:                                             ; preds = %main
  %65 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @5, i32 0, i32 0))
  br label %cont

cont:                                             ; preds = %true, %main
  %66 = load i32, i32* %0, align 4
  %67 = alloca i32, align 4
  store i32 3, i32* %67, align 4
  %68 = load i32, i32* %67, align 4
  %69 = icmp eq i32 %66, %68
  br i1 %69, label %true1, label %cont2

true1:                                            ; preds = %cont
  %70 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @6, i32 0, i32 0))
  br label %cont2

cont2:                                            ; preds = %true1, %cont
  ret void
}

declare i32 @printf(i8*, ...)

declare i32 @printf.1(i8*, ...)

declare i32 @printf.2(i8*, ...)

declare i32 @printf.3(i8*, ...)

declare i32 @printf.4(i8*, ...)

declare i32 @printf.5(i8*, ...)

declare i32 @printf.6(i8*, ...)
