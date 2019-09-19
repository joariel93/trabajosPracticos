################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/trabajoPractico2.c \
../src/utn_bibcalculations.c \
../src/utn_bibincome.c 

OBJS += \
./src/trabajoPractico2.o \
./src/utn_bibcalculations.o \
./src/utn_bibincome.o 

C_DEPS += \
./src/trabajoPractico2.d \
./src/utn_bibcalculations.d \
./src/utn_bibincome.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


