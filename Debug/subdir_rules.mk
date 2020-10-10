################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"F:/ccs/ccs/tools/compiler/ti-cgt-arm_20.2.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Shake/Downloads/2020-1-pec1-master/lib_PAC1/inc" --include_path="C:/Users/Shake/Downloads/2020-1-pec1-master/lib_PAC1/msp432" --include_path="C:/Users/Shake/Downloads/2020-1-pec1-master/PAC1" --include_path="F:/ccs/ccs/tools/compiler/ti-cgt-arm_20.2.1.LTS/include" --include_path="F:/ccs/ccs/ccs_base/arm/include" --include_path="F:/ccs/ccs/ccs_base/arm/include/CMSIS" --advice:power="all" --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


