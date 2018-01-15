################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ugfx/src/gwin/button.c \
../ugfx/src/gwin/checkbox.c \
../ugfx/src/gwin/console.c \
../ugfx/src/gwin/gimage.c \
../ugfx/src/gwin/graph.c \
../ugfx/src/gwin/gwidget.c \
../ugfx/src/gwin/gwin.c \
../ugfx/src/gwin/gwm.c \
../ugfx/src/gwin/label.c \
../ugfx/src/gwin/list.c \
../ugfx/src/gwin/radio.c \
../ugfx/src/gwin/slider.c 

OBJS += \
./ugfx/src/gwin/button.o \
./ugfx/src/gwin/checkbox.o \
./ugfx/src/gwin/console.o \
./ugfx/src/gwin/gimage.o \
./ugfx/src/gwin/graph.o \
./ugfx/src/gwin/gwidget.o \
./ugfx/src/gwin/gwin.o \
./ugfx/src/gwin/gwm.o \
./ugfx/src/gwin/label.o \
./ugfx/src/gwin/list.o \
./ugfx/src/gwin/radio.o \
./ugfx/src/gwin/slider.o 

C_DEPS += \
./ugfx/src/gwin/button.d \
./ugfx/src/gwin/checkbox.d \
./ugfx/src/gwin/console.d \
./ugfx/src/gwin/gimage.d \
./ugfx/src/gwin/graph.d \
./ugfx/src/gwin/gwidget.d \
./ugfx/src/gwin/gwin.d \
./ugfx/src/gwin/gwm.d \
./ugfx/src/gwin/label.d \
./ugfx/src/gwin/list.d \
./ugfx/src/gwin/radio.d \
./ugfx/src/gwin/slider.d 


# Each subdirectory must supply rules for building sources it contributes
ugfx/src/gwin/%.o: ../ugfx/src/gwin/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F417xx -DUSE_UGFX -DBOARD_ARMEBS4 -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Inc" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/CMSIS/Include" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/xf" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/xf/critical" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/cxfwrapper" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/ugfx" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/ugfx/include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


