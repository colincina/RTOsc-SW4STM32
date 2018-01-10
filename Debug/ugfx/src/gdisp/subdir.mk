################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ugfx/src/gdisp/fonts.c \
../ugfx/src/gdisp/gdisp.c \
../ugfx/src/gdisp/gdisp_lld_SSD2119.c \
../ugfx/src/gdisp/image.c \
../ugfx/src/gdisp/image_bmp.c \
../ugfx/src/gdisp/image_gif.c \
../ugfx/src/gdisp/image_jpg.c \
../ugfx/src/gdisp/image_native.c \
../ugfx/src/gdisp/image_png.c 

OBJS += \
./ugfx/src/gdisp/fonts.o \
./ugfx/src/gdisp/gdisp.o \
./ugfx/src/gdisp/gdisp_lld_SSD2119.o \
./ugfx/src/gdisp/image.o \
./ugfx/src/gdisp/image_bmp.o \
./ugfx/src/gdisp/image_gif.o \
./ugfx/src/gdisp/image_jpg.o \
./ugfx/src/gdisp/image_native.o \
./ugfx/src/gdisp/image_png.o 

C_DEPS += \
./ugfx/src/gdisp/fonts.d \
./ugfx/src/gdisp/gdisp.d \
./ugfx/src/gdisp/gdisp_lld_SSD2119.d \
./ugfx/src/gdisp/image.d \
./ugfx/src/gdisp/image_bmp.d \
./ugfx/src/gdisp/image_gif.d \
./ugfx/src/gdisp/image_jpg.d \
./ugfx/src/gdisp/image_native.d \
./ugfx/src/gdisp/image_png.d 


# Each subdirectory must supply rules for building sources it contributes
ugfx/src/gdisp/%.o: ../ugfx/src/gdisp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F417xx -DUSE_UGFX -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Inc" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/Drivers/CMSIS/Include" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/ugfx" -I"C:/Users/Colin Cina/Desktop/RTOsc_Proj/RTOsc-SW4STM32/ugfx/include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


