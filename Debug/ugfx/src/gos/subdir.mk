################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ugfx/src/gos/chibios.c \
../ugfx/src/gos/freertos.c \
../ugfx/src/gos/idf.c \
../ugfx/src/gos/linux.c \
../ugfx/src/gos/no_os.c \
../ugfx/src/gos/osx.c \
../ugfx/src/gos/win32.c 

OBJS += \
./ugfx/src/gos/chibios.o \
./ugfx/src/gos/freertos.o \
./ugfx/src/gos/idf.o \
./ugfx/src/gos/linux.o \
./ugfx/src/gos/no_os.o \
./ugfx/src/gos/osx.o \
./ugfx/src/gos/win32.o 

C_DEPS += \
./ugfx/src/gos/chibios.d \
./ugfx/src/gos/freertos.d \
./ugfx/src/gos/idf.d \
./ugfx/src/gos/linux.d \
./ugfx/src/gos/no_os.d \
./ugfx/src/gos/osx.d \
./ugfx/src/gos/win32.d 


# Each subdirectory must supply rules for building sources it contributes
ugfx/src/gos/%.o: ../ugfx/src/gos/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F417xx -DUSE_UGFX -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Inc" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/CMSIS/Include" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/ugfx" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/ugfx/include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


