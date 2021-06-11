; ModuleID = 'test.ll'
source_filename = "test.ll"

@0 = private unnamed_addr constant [6 x i8] c"hello\00", align 1
@1 = private unnamed_addr constant [5 x i8] c"good\00", align 1
@2 = private unnamed_addr constant [9 x i8] c"hello \\n\00", align 1
@3 = private unnamed_addr constant [13 x i8] c"a=%d, b=%d\\n\00", align 1

define void @func() {
func:
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @0, i32 0, i32 0))
  ret void
}

declare i32 @printf(i8*, ...)

define void @main() {
main:
  %0 = alloca i32, align 4
  store i32 5, i32* %0, align 4
  %1 = alloca i32, align 4
  store i32 4, i32* %1, align 4
  %2 = load i32, i32* %1, align 4
  %3 = alloca i32, align 4
  store i32 2, i32* %3, align 4
  %4 = load i32, i32* %3, align 4
  %5 = sdiv i32 %2, %4
  %6 = mul i32 %4, %5
  %7 = sub i32 %2, %6
  store i32 %7, i32* %1, align 4
  %8 = load i32, i32* %0, align 4
  %9 = alloca i32, align 4
  store i32 2, i32* %9, align 4
  %10 = load i32, i32* %9, align 4
  %11 = sdiv i32 %8, %10
  %12 = mul i32 %10, %11
  %13 = sub i32 %8, %12
  store i32 %13, i32* %0, align 4
  %14 = load i32, i32* %0, align 4
  %15 = alloca i32, align 4
  store i32 0, i32* %15, align 4
  %16 = load i32, i32* %15, align 4
  %17 = icmp sgt i32 %14, %16
  %18 = fpext i1 %17 to i32
  %19 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @1, i32 0, i32 0))
  %20 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([9 x i8], [9 x i8]* @2, i32 0, i32 0))
  %21 = load i32, i32* %0, align 4
  %22 = load i32, i32* %1, align 4
  %23 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @3, i32 0, i32 0), i32 %21, i32 %22)
  call void @func()
  ret void
}

declare i32 @printf.1(i8*, ...)

declare i32 @printf.2(i8*, ...)

declare i32 @printf.3(i8*, ...)
