################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../unittesting/Geometry/main.cpp 

OBJS += \
./unittesting/Geometry/main.o 

CPP_DEPS += \
./unittesting/Geometry/main.d 


# Each subdirectory must supply rules for building sources it contributes
unittesting/Geometry/%.o: ../unittesting/Geometry/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


