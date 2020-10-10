################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := F:/ccs/ccs/tools/compiler/ti-cgt-arm_20.2.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./msp432_startup_ccs.obj" \
"./system_msp432p401r.obj" \
"./lib_PAC1/msp432/adc14.obj" \
"./lib_PAC1/msp432/aes256.obj" \
"./lib_PAC1/msp432/comp_e.obj" \
"./lib_PAC1/msp432/cpu.obj" \
"./lib_PAC1/msp432/crc32.obj" \
"./lib_PAC1/msp432/cs.obj" \
"./lib_PAC1/msp432/dma.obj" \
"./lib_PAC1/msp432/flash.obj" \
"./lib_PAC1/msp432/fpu.obj" \
"./lib_PAC1/msp432/gpio.obj" \
"./lib_PAC1/msp432/i2c.obj" \
"./lib_PAC1/msp432/interrupt.obj" \
"./lib_PAC1/msp432/mpu.obj" \
"./lib_PAC1/msp432/pcm.obj" \
"./lib_PAC1/msp432/pmap.obj" \
"./lib_PAC1/msp432/pss.obj" \
"./lib_PAC1/msp432/ref_a.obj" \
"./lib_PAC1/msp432/reset.obj" \
"./lib_PAC1/msp432/rtc_c.obj" \
"./lib_PAC1/msp432/spi.obj" \
"./lib_PAC1/msp432/sysctl.obj" \
"./lib_PAC1/msp432/systick.obj" \
"./lib_PAC1/msp432/timer32.obj" \
"./lib_PAC1/msp432/timer_a.obj" \
"./lib_PAC1/msp432/uart.obj" \
"./lib_PAC1/msp432/wdt_a.obj" \
"../msp432p401r.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include lib_PAC1/msp432/subdir_vars.mk
-include subdir_rules.mk
-include lib_PAC1/msp432/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
PAC1.out \

EXE_OUTPUTS__QUOTED += \
"PAC1.out" \

BIN_OUTPUTS += \
PAC1.hex \

BIN_OUTPUTS__QUOTED += \
"PAC1.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "PAC1.out"

# Tool invocations
PAC1.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: ARM Linker'
	"F:/ccs/ccs/tools/compiler/ti-cgt-arm_20.2.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --advice:power="all" --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"PAC1.map" --heap_size=1024 --stack_size=512 -i"F:/ccs/ccs/ccs_base/arm/include" -i"F:/ccs/ccs/tools/compiler/ti-cgt-arm_20.2.1.LTS/lib" -i"F:/ccs/ccs/tools/compiler/ti-cgt-arm_20.2.1.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="PAC1_linkInfo.xml" --rom_model -o "PAC1.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

PAC1.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: ARM Hex Utility'
	"F:/ccs/ccs/tools/compiler/ti-cgt-arm_20.2.1.LTS/bin/armhex" --memwidth=8 --romwidth=8 -o "PAC1.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "msp432_startup_ccs.obj" "system_msp432p401r.obj" "lib_PAC1\msp432\adc14.obj" "lib_PAC1\msp432\aes256.obj" "lib_PAC1\msp432\comp_e.obj" "lib_PAC1\msp432\cpu.obj" "lib_PAC1\msp432\crc32.obj" "lib_PAC1\msp432\cs.obj" "lib_PAC1\msp432\dma.obj" "lib_PAC1\msp432\flash.obj" "lib_PAC1\msp432\fpu.obj" "lib_PAC1\msp432\gpio.obj" "lib_PAC1\msp432\i2c.obj" "lib_PAC1\msp432\interrupt.obj" "lib_PAC1\msp432\mpu.obj" "lib_PAC1\msp432\pcm.obj" "lib_PAC1\msp432\pmap.obj" "lib_PAC1\msp432\pss.obj" "lib_PAC1\msp432\ref_a.obj" "lib_PAC1\msp432\reset.obj" "lib_PAC1\msp432\rtc_c.obj" "lib_PAC1\msp432\spi.obj" "lib_PAC1\msp432\sysctl.obj" "lib_PAC1\msp432\systick.obj" "lib_PAC1\msp432\timer32.obj" "lib_PAC1\msp432\timer_a.obj" "lib_PAC1\msp432\uart.obj" "lib_PAC1\msp432\wdt_a.obj" 
	-$(RM) "main.d" "msp432_startup_ccs.d" "system_msp432p401r.d" "lib_PAC1\msp432\adc14.d" "lib_PAC1\msp432\aes256.d" "lib_PAC1\msp432\comp_e.d" "lib_PAC1\msp432\cpu.d" "lib_PAC1\msp432\crc32.d" "lib_PAC1\msp432\cs.d" "lib_PAC1\msp432\dma.d" "lib_PAC1\msp432\flash.d" "lib_PAC1\msp432\fpu.d" "lib_PAC1\msp432\gpio.d" "lib_PAC1\msp432\i2c.d" "lib_PAC1\msp432\interrupt.d" "lib_PAC1\msp432\mpu.d" "lib_PAC1\msp432\pcm.d" "lib_PAC1\msp432\pmap.d" "lib_PAC1\msp432\pss.d" "lib_PAC1\msp432\ref_a.d" "lib_PAC1\msp432\reset.d" "lib_PAC1\msp432\rtc_c.d" "lib_PAC1\msp432\spi.d" "lib_PAC1\msp432\sysctl.d" "lib_PAC1\msp432\systick.d" "lib_PAC1\msp432\timer32.d" "lib_PAC1\msp432\timer_a.d" "lib_PAC1\msp432\uart.d" "lib_PAC1\msp432\wdt_a.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

