################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/adc.c \
../Src/fsmc.c \
../Src/gpio.c \
../Src/i2c.c \
../Src/main.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_hal_timebase_TIM.c \
../Src/stm32f4xx_it.c \
../Src/system_stm32f4xx.c \
../Src/tim.c 

OBJS += \
./Src/adc.o \
./Src/fsmc.o \
./Src/gpio.o \
./Src/i2c.o \
./Src/main.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_hal_timebase_TIM.o \
./Src/stm32f4xx_it.o \
./Src/system_stm32f4xx.o \
./Src/tim.o 

C_DEPS += \
./Src/adc.d \
./Src/fsmc.d \
./Src/gpio.d \
./Src/i2c.d \
./Src/main.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_hal_timebase_TIM.d \
./Src/stm32f4xx_it.d \
./Src/system_stm32f4xx.d \
./Src/tim.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F417xx -DUSE_UGFX -DBOARD_ARMEBS4 -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Inc" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/CMSIS/Include" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/xf" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/xf/critical" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/cxfwrapper" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/ugfx" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/ugfx/include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


