################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/getData.c \
../src/hardware.c \
../src/main.c 

C_DEPS += \
./src/getData.d \
./src/hardware.d \
./src/main.d 

OBJS += \
./src/getData.o \
./src/hardware.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/getData.d ./src/getData.o ./src/hardware.d ./src/hardware.o ./src/main.d ./src/main.o

.PHONY: clean-src

