; ModuleID = 'test.ll'
source_filename = "test.ll"

@string = private unnamed_addr constant [13 x i8] c"hello, world\00", align 1

define void @main() {
main:
  %0 = call i32 @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @string, i32 0, i32 0))
  ret void
}

declare i32 @printf(i8*)
