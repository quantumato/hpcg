################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../unittesting/hpcg_dat/main.cpp 

OBJS += \
./unittesting/hpcg_dat/main.o 

CPP_DEPS += \
./unittesting/hpcg_dat/main.d 


# Each subdirectory must supply rules for building sources it contributes
unittesting/hpcg_dat/%.o: ../unittesting/hpcg_dat/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


