################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ugfx/src/gdisp/mcufont/mf_bwfont.c \
../ugfx/src/gdisp/mcufont/mf_encoding.c \
../ugfx/src/gdisp/mcufont/mf_font.c \
../ugfx/src/gdisp/mcufont/mf_justify.c \
../ugfx/src/gdisp/mcufont/mf_kerning.c \
../ugfx/src/gdisp/mcufont/mf_rlefont.c \
../ugfx/src/gdisp/mcufont/mf_scaledfont.c \
../ugfx/src/gdisp/mcufont/mf_wordwrap.c 

OBJS += \
./ugfx/src/gdisp/mcufont/mf_bwfont.o \
./ugfx/src/gdisp/mcufont/mf_encoding.o \
./ugfx/src/gdisp/mcufont/mf_font.o \
./ugfx/src/gdisp/mcufont/mf_justify.o \
./ugfx/src/gdisp/mcufont/mf_kerning.o \
./ugfx/src/gdisp/mcufont/mf_rlefont.o \
./ugfx/src/gdisp/mcufont/mf_scaledfont.o \
./ugfx/src/gdisp/mcufont/mf_wordwrap.o 

C_DEPS += \
./ugfx/src/gdisp/mcufont/mf_bwfont.d \
./ugfx/src/gdisp/mcufont/mf_encoding.d \
./ugfx/src/gdisp/mcufont/mf_font.d \
./ugfx/src/gdisp/mcufont/mf_justify.d \
./ugfx/src/gdisp/mcufont/mf_kerning.d \
./ugfx/src/gdisp/mcufont/mf_rlefont.d \
./ugfx/src/gdisp/mcufont/mf_scaledfont.d \
./ugfx/src/gdisp/mcufont/mf_wordwrap.d 


# Each subdirectory must supply rules for building sources it contributes
ugfx/src/gdisp/mcufont/%.o: ../ugfx/src/gdisp/mcufont/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F417xx -DUSE_UGFX -DBOARD_ARMEBS4 -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Inc" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/CMSIS/Include" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/xf" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/xf/critical" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/cxfwrapper" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/ugfx" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/ugfx/include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


