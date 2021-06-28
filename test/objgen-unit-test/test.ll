; ModuleID = 'test.ll'
source_filename = "test.ll"

@global_var = common global [10000 x i32] 0, align 2
@global_var.1 = common global i32 0, align 2
@0 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@1 = private unnamed_addr constant [5 x i8] c"<%d>\00", align 1
@2 = private unnamed_addr constant [7 x i8] c"  ->  \00", align 1
@3 = private unnamed_addr constant [5 x i8] c"<%d>\00", align 1
@4 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@5 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@6 = private unnamed_addr constant [5 x i8] c"<%d>\00", align 1
@7 = private unnamed_addr constant [5 x i8] c"<%d>\00", align 1

define void @printNL() {
printNL:
  %0 = alloca i8, align 1
  %1 = alloca i32, align 4
  store i32 10, i32* %1, align 4
  %2 = load i32, i32* %1, align 4
  store i32 %2, i8* %0, align 4
  %3 = load i8, i8* %0, align 1
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @0, i32 0, i32 0), i8 %3)
  ret void
}

declare i32 @printf(i8*, ...)

define void @quickSort(i32 %0, i32 %1) {
quickSort:
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = alloca i32, align 4
  store i32 %1, i32* %3, align 4
  %4 = alloca i32, align 4
  %5 = load i32, i32* %2, align 4
  store i32 %5, i32* %4, align 4
  %6 = alloca i32, align 4
  %7 = load i32, i32* %3, align 4
  store i32 %7, i32* %6, align 4
  %8 = alloca i32, align 4
  %9 = load i32, i32* %2, align 4
  store i32 %9, i32* %8, align 4
  %10 = alloca i32, align 4
  %11 = load i32, i32* %3, align 4
  store i32 %11, i32* %10, align 4
  %12 = alloca i32, align 4
  %13 = alloca i32, align 4
  store i32 0, i32* %13, align 4
  %14 = alloca i32, align 4
  store i32 1, i32* %14, align 4
  %15 = load i32, i32* %14, align 4
  %16 = load i32, i32* %4, align 4
  %17 = mul i32 %16, %15
  %18 = load i32, i32* %13, align 4
  %19 = add i32 %17, %18
  store i32 %19, i32* %13, align 4
  %20 = load i32, i32* %13, align 4
  %arr_ele_ref = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_var, i32 0, i32 %20
  %arr_ele_ref_var = alloca i32, align 4
  %21 = load i32, i32* %arr_ele_ref, align 2
  store i32 %21, i32* %arr_ele_ref_var, align 4
  %22 = load i32, i32* %arr_ele_ref_var, align 4
  store i32 %22, i32* %12, align 4
  %23 = alloca i32, align 4
  %24 = load i32, i32* %8, align 4
  %25 = load i32, i32* %10, align 4
  %26 = icmp sge i32 %24, %25
  br i1 %26, label %true, label %cont

true:                                             ; preds = %quickSort
  ret void
  br label %cont

cont:                                             ; preds = %true, %quickSort
  %27 = alloca i32, align 4
  %28 = alloca i32, align 4
  store i32 0, i32* %28, align 4
  %29 = load i32, i32* %28, align 4
  store i32 %29, i32* %27, align 4
  br label %cond

cond:                                             ; preds = %body, %cont
  %30 = load i32, i32* %27, align 4
  %31 = load i32, i32* @global_var.1, align 4
  %32 = icmp ult i32 %30, %31
  br i1 %32, label %body, label %cont1

body:                                             ; preds = %cond
  %33 = alloca i32, align 4
  store i32 0, i32* %33, align 4
  %34 = alloca i32, align 4
  store i32 1, i32* %34, align 4
  %35 = load i32, i32* %34, align 4
  %36 = load i32, i32* %27, align 4
  %37 = mul i32 %36, %35
  %38 = load i32, i32* %33, align 4
  %39 = add i32 %37, %38
  store i32 %39, i32* %33, align 4
  %40 = load i32, i32* %33, align 4
  %arr_ele_ref2 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_var, i32 0, i32 %40
  %arr_ele_ref_var3 = alloca i32, align 4
  %41 = load i32, i32* %arr_ele_ref2, align 2
  store i32 %41, i32* %arr_ele_ref_var3, align 4
  %42 = load i32, i32* %arr_ele_ref_var3, align 4
  store i32 %42, i32* %23, align 4
  %43 = load i32, i32* %23, align 4
  %44 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @1, i32 0, i32 0), i32 %43)
  %45 = load i32, i32* %27, align 4
  %46 = alloca i32, align 4
  store i32 1, i32* %46, align 4
  %47 = load i32, i32* %46, align 4
  %48 = add i32 %45, %47
  store i32 %48, i32* %27, align 4
  br label %cond

cont1:                                            ; preds = %cond
  %49 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @2, i32 0, i32 0))
  br label %cond4

cond4:                                            ; preds = %cont27, %cont1
  %50 = load i32, i32* %4, align 4
  %51 = load i32, i32* %6, align 4
  %52 = icmp ult i32 %50, %51
  br i1 %52, label %body5, label %cont6

body5:                                            ; preds = %cond4
  %53 = alloca i32, align 4
  store i32 0, i32* %53, align 4
  %54 = alloca i32, align 4
  store i32 1, i32* %54, align 4
  %55 = load i32, i32* %54, align 4
  %56 = load i32, i32* %6, align 4
  %57 = mul i32 %56, %55
  %58 = load i32, i32* %53, align 4
  %59 = add i32 %57, %58
  store i32 %59, i32* %53, align 4
  %60 = load i32, i32* %53, align 4
  %arr_ele_ref7 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_var, i32 0, i32 %60
  %arr_ele_ref_var8 = alloca i32, align 4
  %61 = load i32, i32* %arr_ele_ref7, align 2
  store i32 %61, i32* %arr_ele_ref_var8, align 4
  %62 = load i32, i32* %arr_ele_ref_var8, align 4
  store i32 %62, i32* %23, align 4
  %63 = alloca i32, align 4
  %64 = alloca i32, align 4
  store i32 1, i32* %64, align 4
  %65 = load i32, i32* %64, align 4
  store i32 %65, i32* %63, align 4
  br label %cond9

cont6:                                            ; preds = %cond4
  %66 = alloca i32, align 4
  store i32 0, i32* %66, align 4
  %67 = alloca i32, align 4
  store i32 1, i32* %67, align 4
  %68 = load i32, i32* %67, align 4
  %69 = load i32, i32* %4, align 4
  %70 = mul i32 %69, %68
  %71 = load i32, i32* %66, align 4
  %72 = add i32 %70, %71
  store i32 %72, i32* %66, align 4
  %73 = load i32, i32* %66, align 4
  %arr_ele_ref40 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_var, i32 0, i32 %73
  %arr_ele_ref_var41 = alloca i32, align 4
  %74 = load i32, i32* %arr_ele_ref40, align 2
  store i32 %74, i32* %arr_ele_ref_var41, align 4
  %75 = alloca i32, align 4
  %76 = load i32, i32* %arr_ele_ref40, align 2
  store i32 %76, i32* %75, align 4
  %77 = load i32, i32* %12, align 4
  store i32 %77, i32* %arr_ele_ref40, align 2
  %78 = alloca i32, align 4
  store i32 0, i32* %78, align 4
  %79 = load i32, i32* %78, align 4
  store i32 %79, i32* %27, align 4
  br label %cond42

cond9:                                            ; preds = %cont13, %body5
  %80 = load i32, i32* %63, align 4
  %81 = alloca i32, align 4
  store i32 0, i32* %81, align 4
  %82 = load i32, i32* %81, align 4
  %83 = icmp ne i32 %80, %82
  br i1 %83, label %body10, label %cont11

body10:                                           ; preds = %cond9
  %84 = load i32, i32* %4, align 4
  %85 = load i32, i32* %6, align 4
  %86 = icmp ult i32 %84, %85
  br i1 %86, label %true12, label %false18

cont11:                                           ; preds = %cond9
  %87 = alloca i32, align 4
  store i32 0, i32* %87, align 4
  %88 = alloca i32, align 4
  store i32 1, i32* %88, align 4
  %89 = load i32, i32* %88, align 4
  %90 = load i32, i32* %6, align 4
  %91 = mul i32 %90, %89
  %92 = load i32, i32* %87, align 4
  %93 = add i32 %91, %92
  store i32 %93, i32* %87, align 4
  %94 = load i32, i32* %87, align 4
  %arr_ele_ref19 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_var, i32 0, i32 %94
  %arr_ele_ref_var20 = alloca i32, align 4
  %95 = load i32, i32* %arr_ele_ref19, align 2
  store i32 %95, i32* %arr_ele_ref_var20, align 4
  %96 = load i32, i32* %arr_ele_ref_var20, align 4
  store i32 %96, i32* %23, align 4
  %97 = alloca i32, align 4
  store i32 0, i32* %97, align 4
  %98 = alloca i32, align 4
  store i32 1, i32* %98, align 4
  %99 = load i32, i32* %98, align 4
  %100 = load i32, i32* %4, align 4
  %101 = mul i32 %100, %99
  %102 = load i32, i32* %97, align 4
  %103 = add i32 %101, %102
  store i32 %103, i32* %97, align 4
  %104 = load i32, i32* %97, align 4
  %arr_ele_ref21 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_var, i32 0, i32 %104
  %arr_ele_ref_var22 = alloca i32, align 4
  %105 = load i32, i32* %arr_ele_ref21, align 2
  store i32 %105, i32* %arr_ele_ref_var22, align 4
  %106 = alloca i32, align 4
  %107 = load i32, i32* %arr_ele_ref21, align 2
  store i32 %107, i32* %106, align 4
  %108 = load i32, i32* %23, align 4
  store i32 %108, i32* %arr_ele_ref21, align 2
  %109 = alloca i32, align 4
  store i32 0, i32* %109, align 4
  %110 = alloca i32, align 4
  store i32 1, i32* %110, align 4
  %111 = load i32, i32* %110, align 4
  %112 = load i32, i32* %4, align 4
  %113 = mul i32 %112, %111
  %114 = load i32, i32* %109, align 4
  %115 = add i32 %113, %114
  store i32 %115, i32* %109, align 4
  %116 = load i32, i32* %109, align 4
  %arr_ele_ref23 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_var, i32 0, i32 %116
  %arr_ele_ref_var24 = alloca i32, align 4
  %117 = load i32, i32* %arr_ele_ref23, align 2
  store i32 %117, i32* %arr_ele_ref_var24, align 4
  %118 = load i32, i32* %arr_ele_ref_var24, align 4
  store i32 %118, i32* %23, align 4
  %119 = alloca i32, align 4
  store i32 1, i32* %119, align 4
  %120 = load i32, i32* %119, align 4
  store i32 %120, i32* %63, align 4
  br label %cond25

true12:                                           ; preds = %body10
  %121 = load i32, i32* %23, align 4
  %122 = load i32, i32* %12, align 4
  %123 = icmp sge i32 %121, %122
  br i1 %123, label %true14, label %false

cont13:                                           ; preds = %false18, %cont15
  br label %cond9

true14:                                           ; preds = %true12
  %124 = load i32, i32* %6, align 4
  %125 = alloca i32, align 4
  store i32 1, i32* %125, align 4
  %126 = load i32, i32* %125, align 4
  %127 = sub i32 %124, %126
  store i32 %127, i32* %6, align 4
  %128 = alloca i32, align 4
  store i32 0, i32* %128, align 4
  %129 = alloca i32, align 4
  store i32 1, i32* %129, align 4
  %130 = load i32, i32* %129, align 4
  %131 = load i32, i32* %6, align 4
  %132 = mul i32 %131, %130
  %133 = load i32, i32* %128, align 4
  %134 = add i32 %132, %133
  store i32 %134, i32* %128, align 4
  %135 = load i32, i32* %128, align 4
  %arr_ele_ref16 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_var, i32 0, i32 %135
  %arr_ele_ref_var17 = alloca i32, align 4
  %136 = load i32, i32* %arr_ele_ref16, align 2
  store i32 %136, i32* %arr_ele_ref_var17, align 4
  %137 = load i32, i32* %arr_ele_ref_var17, align 4
  store i32 %137, i32* %23, align 4
  br label %cont15

cont15:                                           ; preds = %false, %true14
  br label %cont13

false:                                            ; preds = %true12
  %138 = alloca i32, align 4
  store i32 0, i32* %138, align 4
  %139 = load i32, i32* %138, align 4
  store i32 %139, i32* %63, align 4
  br label %cont15

false18:                                          ; preds = %body10
  %140 = alloca i32, align 4
  store i32 0, i32* %140, align 4
  %141 = load i32, i32* %140, align 4
  store i32 %141, i32* %63, align 4
  br label %cont13

cond25:                                           ; preds = %cont29, %cont11
  %142 = load i32, i32* %63, align 4
  %143 = alloca i32, align 4
  store i32 0, i32* %143, align 4
  %144 = load i32, i32* %143, align 4
  %145 = icmp ne i32 %142, %144
  br i1 %145, label %body26, label %cont27

body26:                                           ; preds = %cond25
  %146 = load i32, i32* %4, align 4
  %147 = load i32, i32* %6, align 4
  %148 = icmp ult i32 %146, %147
  br i1 %148, label %true28, label %false35

cont27:                                           ; preds = %cond25
  %149 = alloca i32, align 4
  store i32 0, i32* %149, align 4
  %150 = alloca i32, align 4
  store i32 1, i32* %150, align 4
  %151 = load i32, i32* %150, align 4
  %152 = load i32, i32* %4, align 4
  %153 = mul i32 %152, %151
  %154 = load i32, i32* %149, align 4
  %155 = add i32 %153, %154
  store i32 %155, i32* %149, align 4
  %156 = load i32, i32* %149, align 4
  %arr_ele_ref36 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_var, i32 0, i32 %156
  %arr_ele_ref_var37 = alloca i32, align 4
  %157 = load i32, i32* %arr_ele_ref36, align 2
  store i32 %157, i32* %arr_ele_ref_var37, align 4
  %158 = load i32, i32* %arr_ele_ref_var37, align 4
  store i32 %158, i32* %23, align 4
  %159 = alloca i32, align 4
  store i32 0, i32* %159, align 4
  %160 = alloca i32, align 4
  store i32 1, i32* %160, align 4
  %161 = load i32, i32* %160, align 4
  %162 = load i32, i32* %6, align 4
  %163 = mul i32 %162, %161
  %164 = load i32, i32* %159, align 4
  %165 = add i32 %163, %164
  store i32 %165, i32* %159, align 4
  %166 = load i32, i32* %159, align 4
  %arr_ele_ref38 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_var, i32 0, i32 %166
  %arr_ele_ref_var39 = alloca i32, align 4
  %167 = load i32, i32* %arr_ele_ref38, align 2
  store i32 %167, i32* %arr_ele_ref_var39, align 4
  %168 = alloca i32, align 4
  %169 = load i32, i32* %arr_ele_ref38, align 2
  store i32 %169, i32* %168, align 4
  %170 = load i32, i32* %23, align 4
  store i32 %170, i32* %arr_ele_ref38, align 2
  br label %cond4

true28:                                           ; preds = %body26
  %171 = load i32, i32* %23, align 4
  %172 = load i32, i32* %12, align 4
  %173 = icmp sle i32 %171, %172
  br i1 %173, label %true30, label %false34

cont29:                                           ; preds = %false35, %cont31
  br label %cond25

true30:                                           ; preds = %true28
  %174 = load i32, i32* %4, align 4
  %175 = alloca i32, align 4
  store i32 1, i32* %175, align 4
  %176 = load i32, i32* %175, align 4
  %177 = add i32 %174, %176
  store i32 %177, i32* %4, align 4
  %178 = alloca i32, align 4
  store i32 0, i32* %178, align 4
  %179 = alloca i32, align 4
  store i32 1, i32* %179, align 4
  %180 = load i32, i32* %179, align 4
  %181 = load i32, i32* %4, align 4
  %182 = mul i32 %181, %180
  %183 = load i32, i32* %178, align 4
  %184 = add i32 %182, %183
  store i32 %184, i32* %178, align 4
  %185 = load i32, i32* %178, align 4
  %arr_ele_ref32 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_var, i32 0, i32 %185
  %arr_ele_ref_var33 = alloca i32, align 4
  %186 = load i32, i32* %arr_ele_ref32, align 2
  store i32 %186, i32* %arr_ele_ref_var33, align 4
  %187 = load i32, i32* %arr_ele_ref_var33, align 4
  store i32 %187, i32* %23, align 4
  br label %cont31

cont31:                                           ; preds = %false34, %true30
  br label %cont29

false34:                                          ; preds = %true28
  %188 = alloca i32, align 4
  store i32 0, i32* %188, align 4
  %189 = load i32, i32* %188, align 4
  store i32 %189, i32* %63, align 4
  br label %cont31

false35:                                          ; preds = %body26
  %190 = alloca i32, align 4
  store i32 0, i32* %190, align 4
  %191 = load i32, i32* %190, align 4
  store i32 %191, i32* %63, align 4
  br label %cont29

cond42:                                           ; preds = %body43, %cont6
  %192 = load i32, i32* %27, align 4
  %193 = load i32, i32* @global_var.1, align 4
  %194 = icmp ult i32 %192, %193
  br i1 %194, label %body43, label %cont44

body43:                                           ; preds = %cond42
  %195 = alloca i32, align 4
  store i32 0, i32* %195, align 4
  %196 = alloca i32, align 4
  store i32 1, i32* %196, align 4
  %197 = load i32, i32* %196, align 4
  %198 = load i32, i32* %27, align 4
  %199 = mul i32 %198, %197
  %200 = load i32, i32* %195, align 4
  %201 = add i32 %199, %200
  store i32 %201, i32* %195, align 4
  %202 = load i32, i32* %195, align 4
  %arr_ele_ref45 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_var, i32 0, i32 %202
  %arr_ele_ref_var46 = alloca i32, align 4
  %203 = load i32, i32* %arr_ele_ref45, align 2
  store i32 %203, i32* %arr_ele_ref_var46, align 4
  %204 = load i32, i32* %arr_ele_ref_var46, align 4
  store i32 %204, i32* %23, align 4
  %205 = load i32, i32* %23, align 4
  %206 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @3, i32 0, i32 0), i32 %205)
  %207 = load i32, i32* %27, align 4
  %208 = alloca i32, align 4
  store i32 1, i32* %208, align 4
  %209 = load i32, i32* %208, align 4
  %210 = add i32 %207, %209
  store i32 %210, i32* %27, align 4
  br label %cond42

cont44:                                           ; preds = %cond42
  call void @printNL()
  %211 = load i32, i32* %4, align 4
  %212 = alloca i32, align 4
  store i32 1, i32* %212, align 4
  %213 = load i32, i32* %212, align 4
  %214 = sub i32 %211, %213
  store i32 %214, i32* %23, align 4
  %215 = load i32, i32* %8, align 4
  %216 = load i32, i32* %23, align 4
  call void @quickSort(i32 %215, i32 %216)
  %217 = load i32, i32* %4, align 4
  %218 = alloca i32, align 4
  store i32 1, i32* %218, align 4
  %219 = load i32, i32* %218, align 4
  %220 = add i32 %217, %219
  store i32 %220, i32* %23, align 4
  %221 = load i32, i32* %23, align 4
  %222 = load i32, i32* %10, align 4
  call void @quickSort(i32 %221, i32 %222)
  ret void
}

declare i32 @printf.2(i8*, ...)

declare i32 @printf.3(i8*, ...)

declare i32 @printf.4(i8*, ...)

define void @main() {
main:
  %0 = alloca i32, align 4
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = load i32, i32* %1, align 4
  store i32 %2, i32* %0, align 4
  %3 = alloca i32, align 4
  %4 = load i32, i32* @global_var.1, align 4
  %5 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @4, i32 0, i32 0), i32* @global_var.1)
  br label %cond

cond:                                             ; preds = %body, %main
  %6 = load i32, i32* %0, align 4
  %7 = load i32, i32* @global_var.1, align 4
  %8 = icmp ult i32 %6, %7
  br i1 %8, label %body, label %cont

body:                                             ; preds = %cond
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  store i32 0, i32* %10, align 4
  %11 = load i32, i32* %10, align 4
  store i32 %11, i32* %9, align 4
  %12 = load i32, i32* %9, align 4
  %13 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @5, i32 0, i32 0), i32* %9)
  %14 = alloca i32, align 4
  store i32 0, i32* %14, align 4
  %15 = alloca i32, align 4
  store i32 1, i32* %15, align 4
  %16 = load i32, i32* %15, align 4
  %17 = load i32, i32* %0, align 4
  %18 = mul i32 %17, %16
  %19 = load i32, i32* %14, align 4
  %20 = add i32 %18, %19
  store i32 %20, i32* %14, align 4
  %21 = load i32, i32* %14, align 4
  %arr_ele_ref = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_var, i32 0, i32 %21
  %arr_ele_ref_var = alloca i32, align 4
  %22 = load i32, i32* %arr_ele_ref, align 2
  store i32 %22, i32* %arr_ele_ref_var, align 4
  %23 = alloca i32, align 4
  %24 = load i32, i32* %arr_ele_ref, align 2
  store i32 %24, i32* %23, align 4
  %25 = load i32, i32* %9, align 4
  store i32 %25, i32* %arr_ele_ref, align 2
  %26 = load i32, i32* %0, align 4
  %27 = alloca i32, align 4
  store i32 1, i32* %27, align 4
  %28 = load i32, i32* %27, align 4
  %29 = add i32 %26, %28
  store i32 %29, i32* %0, align 4
  br label %cond

cont:                                             ; preds = %cond
  %30 = alloca i32, align 4
  store i32 0, i32* %30, align 4
  %31 = load i32, i32* %30, align 4
  store i32 %31, i32* %0, align 4
  br label %cond1

cond1:                                            ; preds = %body2, %cont
  %32 = load i32, i32* %0, align 4
  %33 = load i32, i32* @global_var.1, align 4
  %34 = icmp ult i32 %32, %33
  br i1 %34, label %body2, label %cont3

body2:                                            ; preds = %cond1
  %35 = alloca i32, align 4
  store i32 0, i32* %35, align 4
  %36 = alloca i32, align 4
  store i32 1, i32* %36, align 4
  %37 = load i32, i32* %36, align 4
  %38 = load i32, i32* %0, align 4
  %39 = mul i32 %38, %37
  %40 = load i32, i32* %35, align 4
  %41 = add i32 %39, %40
  store i32 %41, i32* %35, align 4
  %42 = load i32, i32* %35, align 4
  %arr_ele_ref4 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_var, i32 0, i32 %42
  %arr_ele_ref_var5 = alloca i32, align 4
  %43 = load i32, i32* %arr_ele_ref4, align 2
  store i32 %43, i32* %arr_ele_ref_var5, align 4
  %44 = load i32, i32* %arr_ele_ref_var5, align 4
  store i32 %44, i32* %3, align 4
  %45 = load i32, i32* %3, align 4
  %46 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @6, i32 0, i32 0), i32 %45)
  %47 = load i32, i32* %0, align 4
  %48 = alloca i32, align 4
  store i32 1, i32* %48, align 4
  %49 = load i32, i32* %48, align 4
  %50 = add i32 %47, %49
  store i32 %50, i32* %0, align 4
  br label %cond1

cont3:                                            ; preds = %cond1
  call void @printNL()
  %51 = load i32, i32* @global_var.1, align 4
  %52 = alloca i32, align 4
  store i32 1, i32* %52, align 4
  %53 = load i32, i32* %52, align 4
  %54 = sub i32 %51, %53
  store i32 %54, i32* %3, align 4
  %55 = alloca i32, align 4
  store i32 0, i32* %55, align 4
  %56 = load i32, i32* %55, align 4
  %57 = load i32, i32* %3, align 4
  call void @quickSort(i32 %56, i32 %57)
  %58 = alloca i32, align 4
  store i32 0, i32* %58, align 4
  %59 = load i32, i32* %58, align 4
  store i32 %59, i32* %0, align 4
  br label %cond6

cond6:                                            ; preds = %body7, %cont3
  %60 = load i32, i32* %0, align 4
  %61 = load i32, i32* @global_var.1, align 4
  %62 = icmp ult i32 %60, %61
  br i1 %62, label %body7, label %cont8

body7:                                            ; preds = %cond6
  %63 = alloca i32, align 4
  store i32 0, i32* %63, align 4
  %64 = alloca i32, align 4
  store i32 1, i32* %64, align 4
  %65 = load i32, i32* %64, align 4
  %66 = load i32, i32* %0, align 4
  %67 = mul i32 %66, %65
  %68 = load i32, i32* %63, align 4
  %69 = add i32 %67, %68
  store i32 %69, i32* %63, align 4
  %70 = load i32, i32* %63, align 4
  %arr_ele_ref9 = getelementptr inbounds [10000 x i32], [10000 x i32]* @global_var, i32 0, i32 %70
  %arr_ele_ref_var10 = alloca i32, align 4
  %71 = load i32, i32* %arr_ele_ref9, align 2
  store i32 %71, i32* %arr_ele_ref_var10, align 4
  %72 = load i32, i32* %arr_ele_ref_var10, align 4
  store i32 %72, i32* %3, align 4
  %73 = load i32, i32* %3, align 4
  %74 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @7, i32 0, i32 0), i32 %73)
  %75 = load i32, i32* %0, align 4
  %76 = alloca i32, align 4
  store i32 1, i32* %76, align 4
  %77 = load i32, i32* %76, align 4
  %78 = add i32 %75, %77
  store i32 %78, i32* %0, align 4
  br label %cond6

cont8:                                            ; preds = %cond6
  call void @printNL()
  ret void
}

declare i32 @scanf(i8*, ...)

declare i32 @scanf.5(i8*, ...)

declare i32 @printf.6(i8*, ...)

declare i32 @printf.7(i8*, ...)
