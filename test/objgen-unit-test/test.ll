; ModuleID = 'test.ll'
source_filename = "test.ll"

@0 = private unnamed_addr constant [6 x i8] c"hello\00", align 1
@1 = private unnamed_addr constant [9 x i8] c"hello \\n\00", align 1
@2 = private unnamed_addr constant [13 x i8] c"a=%d, b=%d\\n\00", align 1

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
  %2 = load i32, i32* %0, align 4
  %3 = alloca i32, align 4
  store i32 2, i32* %3, align 4
  %4 = load i32, i32* %3, align 4
  %5 = add i32 %2, %4
  %6 = sub i32 %2, %4
  store i32 %6, i32* %0, align 4
  %7 = load i32, i32* %0, align 4
  %8 = alloca i32, align 4
  store i32 2, i32* %8, align 4
  %9 = load i32, i32* %8, align 4
  %10 = sub i32 %7, %9
  store i32 %10, i32* %0, align 4
  %11 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([9 x i8], [9 x i8]* @1, i32 0, i32 0))
  %12 = load i32, i32* %0, align 4
  %13 = load i32, i32* %1, align 4
  %14 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @2, i32 0, i32 0), i32 %12, i32 %13)
  call void @func()
  ret void
}

declare i32 @printf.1(i8*, ...)

declare i32 @printf.2(i8*, ...)
