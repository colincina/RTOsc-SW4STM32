################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ugfx/src/ginput/dial.c \
../ugfx/src/ginput/ginput.c \
../ugfx/src/ginput/ginput_lld_mouse.c \
../ugfx/src/ginput/keyboard.c \
../ugfx/src/ginput/mouse.c \
../ugfx/src/ginput/toggle.c 

OBJS += \
./ugfx/src/ginput/dial.o \
./ugfx/src/ginput/ginput.o \
./ugfx/src/ginput/ginput_lld_mouse.o \
./ugfx/src/ginput/keyboard.o \
./ugfx/src/ginput/mouse.o \
./ugfx/src/ginput/toggle.o 

C_DEPS += \
./ugfx/src/ginput/dial.d \
./ugfx/src/ginput/ginput.d \
./ugfx/src/ginput/ginput_lld_mouse.d \
./ugfx/src/ginput/keyboard.d \
./ugfx/src/ginput/mouse.d \
./ugfx/src/ginput/toggle.d 


# Each subdirectory must supply rules for building sources it contributes
ugfx/src/ginput/%.o: ../ugfx/src/ginput/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F417xx -DUSE_UGFX -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Inc" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/CMSIS/Include" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/ugfx" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/ugfx/include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


