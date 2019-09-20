################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/trabajoPractico2.c \
../src/utn_incomeStruct.c \
../src/utn_inputs.c \
../src/utn_operacionesStruct.c 

OBJS += \
./src/trabajoPractico2.o \
./src/utn_incomeStruct.o \
./src/utn_inputs.o \
./src/utn_operacionesStruct.o 

C_DEPS += \
./src/trabajoPractico2.d \
./src/utn_incomeStruct.d \
./src/utn_inputs.d \
./src/utn_operacionesStruct.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


