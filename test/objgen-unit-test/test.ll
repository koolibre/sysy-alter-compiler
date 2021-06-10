; ModuleID = 'test.ll'
source_filename = "test.ll"

@0 = private unnamed_addr constant [11 x i8] c"\22hello \\n\22\00", align 1
@1 = private unnamed_addr constant [15 x i8] c"\22a=%d, b=%f\\n\22\00", align 1

define void @func() {
func:
  ret void
}

define void @main() {
main:
  %0 = alloca i32, align 4
  store i32 1, i32* %0, align 4
  %1 = load i32, i32* %0, align 4
  %2 = alloca float, align 4
  store float 0x3FF99999A0000000, float* %2, align 4
  %3 = load float, float* %2, align 4
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @0, i32 0, i32 0))
  %5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @1, i32 0, i32 0), i8* getelementptr inbounds ([15 x i8], [15 x i8]* @1, i32 0, i32 0), float 2.500000e+00)
  call void @func()
  ret void
}

declare i32 @printf(i8*, ...)

declare i32 @printf.1(i8*, ...)
