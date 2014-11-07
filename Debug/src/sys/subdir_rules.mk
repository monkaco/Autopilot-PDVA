################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/sys/DSP2833x_ADC_cal.obj: ../src/sys/DSP2833x_ADC_cal.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_ADC_cal.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_Adc.obj: ../src/sys/DSP2833x_Adc.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_Adc.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_CSMPasswords.obj: ../src/sys/DSP2833x_CSMPasswords.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_CSMPasswords.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_CodeStartBranch.obj: ../src/sys/DSP2833x_CodeStartBranch.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_CodeStartBranch.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_CpuTimers.obj: ../src/sys/DSP2833x_CpuTimers.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_CpuTimers.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_DBGIER.obj: ../src/sys/DSP2833x_DBGIER.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_DBGIER.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_DMA.obj: ../src/sys/DSP2833x_DMA.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_DMA.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_DefaultIsr.obj: ../src/sys/DSP2833x_DefaultIsr.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_DefaultIsr.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_DisInt.obj: ../src/sys/DSP2833x_DisInt.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_DisInt.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_ECan.obj: ../src/sys/DSP2833x_ECan.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_ECan.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_ECap.obj: ../src/sys/DSP2833x_ECap.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_ECap.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_EPwm.obj: ../src/sys/DSP2833x_EPwm.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_EPwm.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_EQep.obj: ../src/sys/DSP2833x_EQep.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_EQep.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_GlobalVariableDefs.obj: ../src/sys/DSP2833x_GlobalVariableDefs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_GlobalVariableDefs.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_Gpio.obj: ../src/sys/DSP2833x_Gpio.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_Gpio.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_I2C.obj: ../src/sys/DSP2833x_I2C.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_I2C.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_Mcbsp.obj: ../src/sys/DSP2833x_Mcbsp.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_Mcbsp.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_MemCopy.obj: ../src/sys/DSP2833x_MemCopy.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_MemCopy.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_PieCtrl.obj: ../src/sys/DSP2833x_PieCtrl.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_PieCtrl.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_PieVect.obj: ../src/sys/DSP2833x_PieVect.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_PieVect.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_Sci.obj: ../src/sys/DSP2833x_Sci.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_Sci.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_Spi.obj: ../src/sys/DSP2833x_Spi.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_Spi.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_SysCtrl.obj: ../src/sys/DSP2833x_SysCtrl.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_SysCtrl.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_Xintf.obj: ../src/sys/DSP2833x_Xintf.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_Xintf.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/DSP2833x_usDelay.obj: ../src/sys/DSP2833x_usDelay.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/sys/DSP2833x_usDelay.pp" --obj_directory="src/sys" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


