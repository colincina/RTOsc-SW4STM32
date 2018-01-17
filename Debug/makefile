################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include xf/critical/subdir.mk
-include xf/subdir.mk
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
-include trace/examples/subdir.mk
-include trace/subdir.mk
-include startup/subdir.mk
-include osc/subdir.mk
-include mcu/subdir.mk
-include fsm/subdir.mk
-include cxfwrapper/cxf/subdir.mk
-include board/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: RTOsc-SW4STM32.elf

# Tool invocations
RTOsc-SW4STM32.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU G++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -specs=nosys.specs -specs=nano.specs -T"../STM32F417IGHx_FLASH.ld" -Wl,-Map=output.map -Wl,--gc-sections -fno-exceptions -fno-rtti -o "RTOsc-SW4STM32.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
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
