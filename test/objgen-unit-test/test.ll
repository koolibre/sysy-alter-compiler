; ModuleID = 'test.ll'
source_filename = "test.ll"

@0 = private unnamed_addr constant [8 x i8] c"\22hello\22\00", align 1
@1 = private unnamed_addr constant [11 x i8] c"\22hello \\n\22\00", align 1
@2 = private unnamed_addr constant [15 x i8] c"\22a=%d, b=%d\\n\22\00", align 1

define void @func() {
func:
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([8 x i8], [8 x i8]* @0, i32 0, i32 0))
  ret void
}

declare i32 @printf(i8*, ...)

define void @main() {
main:
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @1, i32 0, i32 0))
  %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @2, i32 0, i32 0), i32 3, i32 4)
  call void @func()
  ret void
}

declare i32 @printf.1(i8*, ...)

declare i32 @printf.2(i8*, ...)
