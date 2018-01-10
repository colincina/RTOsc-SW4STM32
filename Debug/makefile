################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include ugfx/src/tdisp/subdir.mk
-include ugfx/src/gwin/subdir.mk
-include ugfx/src/gtimer/subdir.mk
-include ugfx/src/gqueue/subdir.mk
-include ugfx/src/gos/subdir.mk
-include ugfx/src/gmisc/subdir.mk
-include ugfx/src/ginput/subdir.mk
-include ugfx/src/gevent/subdir.mk
-include ugfx/src/gdisp/mcufont/subdir.mk
-include ugfx/src/gdisp/subdir.mk
-include ugfx/src/gaudout/subdir.mk
-include ugfx/src/gaudin/subdir.mk
-include ugfx/src/gadc/subdir.mk
-include ugfx/src/subdir.mk
-include startup/subdir.mk
-include osc/subdir.mk
-include mcu/subdir.mk
-include board/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: RTOsc-SW4STM32.elf

# Tool invocations
RTOsc-SW4STM32.elf: $(OBJS) $(USER_OBJS) ../STM32F417IGHx_FLASH.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -specs=nosys.specs -specs=nano.specs -T"../STM32F417IGHx_FLASH.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "RTOsc-SW4STM32.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "RTOsc-SW4STM32.elf" "RTOsc-SW4STM32.bin"
	arm-none-eabi-size "RTOsc-SW4STM32.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
