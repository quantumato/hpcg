################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CG.cpp \
../src/CG_ref.cpp \
../src/CheckAspectRatio.cpp \
../src/ComputeDotProduct.cpp \
../src/ComputeDotProduct_ref.cpp \
../src/ComputeMG.cpp \
../src/ComputeMG_ref.cpp \
../src/ComputeOptimalShapeXYZ.cpp \
../src/ComputeProlongation_ref.cpp \
../src/ComputeResidual.cpp \
../src/ComputeRestriction_ref.cpp \
../src/ComputeSPMV.cpp \
../src/ComputeSPMV_ref.cpp \
../src/ComputeSYMGS.cpp \
../src/ComputeSYMGS_ref.cpp \
../src/ComputeWAXPBY.cpp \
../src/ComputeWAXPBY_ref.cpp \
../src/ExchangeHalo.cpp \
../src/ExchangeHaloRequest.cpp \
../src/GenerateCoarseProblem.cpp \
../src/GenerateGeometry.cpp \
../src/GenerateProblem.cpp \
../src/MixedBaseCounter.cpp \
../src/OptimizeProblem.cpp \
../src/ReadHpcgDat.cpp \
../src/ReportResults.cpp \
../src/SetupHalo.cpp \
../src/TestCG.cpp \
../src/TestNorms.cpp \
../src/TestSymmetry.cpp \
../src/WriteProblem.cpp \
../src/YAML_Doc.cpp \
../src/YAML_Element.cpp \
../src/finalize.cpp \
../src/init.cpp \
../src/main.cpp \
../src/mytimer.cpp 

OBJS += \
./src/CG.o \
./src/CG_ref.o \
./src/CheckAspectRatio.o \
./src/ComputeDotProduct.o \
./src/ComputeDotProduct_ref.o \
./src/ComputeMG.o \
./src/ComputeMG_ref.o \
./src/ComputeOptimalShapeXYZ.o \
./src/ComputeProlongation_ref.o \
./src/ComputeResidual.o \
./src/ComputeRestriction_ref.o \
./src/ComputeSPMV.o \
./src/ComputeSPMV_ref.o \
./src/ComputeSYMGS.o \
./src/ComputeSYMGS_ref.o \
./src/ComputeWAXPBY.o \
./src/ComputeWAXPBY_ref.o \
./src/ExchangeHalo.o \
./src/ExchangeHaloRequest.o \
./src/GenerateCoarseProblem.o \
./src/GenerateGeometry.o \
./src/GenerateProblem.o \
./src/MixedBaseCounter.o \
./src/OptimizeProblem.o \
./src/ReadHpcgDat.o \
./src/ReportResults.o \
./src/SetupHalo.o \
./src/TestCG.o \
./src/TestNorms.o \
./src/TestSymmetry.o \
./src/WriteProblem.o \
./src/YAML_Doc.o \
./src/YAML_Element.o \
./src/finalize.o \
./src/init.o \
./src/main.o \
./src/mytimer.o 

CPP_DEPS += \
./src/CG.d \
./src/CG_ref.d \
./src/CheckAspectRatio.d \
./src/ComputeDotProduct.d \
./src/ComputeDotProduct_ref.d \
./src/ComputeMG.d \
./src/ComputeMG_ref.d \
./src/ComputeOptimalShapeXYZ.d \
./src/ComputeProlongation_ref.d \
./src/ComputeResidual.d \
./src/ComputeRestriction_ref.d \
./src/ComputeSPMV.d \
./src/ComputeSPMV_ref.d \
./src/ComputeSYMGS.d \
./src/ComputeSYMGS_ref.d \
./src/ComputeWAXPBY.d \
./src/ComputeWAXPBY_ref.d \
./src/ExchangeHalo.d \
./src/ExchangeHaloRequest.d \
./src/GenerateCoarseProblem.d \
./src/GenerateGeometry.d \
./src/GenerateProblem.d \
./src/MixedBaseCounter.d \
./src/OptimizeProblem.d \
./src/ReadHpcgDat.d \
./src/ReportResults.d \
./src/SetupHalo.d \
./src/TestCG.d \
./src/TestNorms.d \
./src/TestSymmetry.d \
./src/WriteProblem.d \
./src/YAML_Doc.d \
./src/YAML_Element.d \
./src/finalize.d \
./src/init.d \
./src/main.d \
./src/mytimer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


