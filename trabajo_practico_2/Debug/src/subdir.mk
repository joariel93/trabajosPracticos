################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/trabajo_practico_2.c \
../src/utn_arrayEmployees.c \
../src/utn_inputs.c 

OBJS += \
./src/trabajo_practico_2.o \
./src/utn_arrayEmployees.o \
./src/utn_inputs.o 

C_DEPS += \
./src/trabajo_practico_2.d \
./src/utn_arrayEmployees.d \
./src/utn_inputs.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


