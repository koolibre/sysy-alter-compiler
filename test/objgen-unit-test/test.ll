; ModuleID = 'test.ll'
source_filename = "test.ll"

@0 = private unnamed_addr constant [7 x i8] c"hello\22\00", align 1
@1 = private unnamed_addr constant [10 x i8] c"hello \\n\22\00", align 1
@2 = private unnamed_addr constant [14 x i8] c"a=%d, b=%d\\n\22\00", align 1

define void @func() {
func:
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @0, i32 0, i32 0))
  ret void
}

declare i32 @printf(i8*, ...)

define void @main() {
main:
  %0 = alloca i32, align 4
  store i32 5, i32* %0, align 4
  %1 = load i32, i32* %0, align 4
  %2 = alloca i32, align 4
  store i32 4, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @1, i32 0, i32 0))
  %5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @2, i32 0, i32 0), i32 %1, i32 %3)
  call void @func()
  ret void
}

declare i32 @printf.1(i8*, ...)

declare i32 @printf.2(i8*, ...)
