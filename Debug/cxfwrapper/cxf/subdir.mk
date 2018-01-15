################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cxfwrapper/cxf/wrapper.cpp 

OBJS += \
./cxfwrapper/cxf/wrapper.o 

CPP_DEPS += \
./cxfwrapper/cxf/wrapper.d 


# Each subdirectory must supply rules for building sources it contributes
cxfwrapper/cxf/%.o: ../cxfwrapper/cxf/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F417xx -DUSE_UGFX -DBOARD_ARMEBS4 -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Inc" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/CMSIS/Include" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/ugfx" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/ugfx/include"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


