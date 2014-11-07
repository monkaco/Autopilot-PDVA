################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
misc/GPS_UBX.obj: ../misc/GPS_UBX.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="misc/GPS_UBX.pp" --obj_directory="misc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

misc/GPS_UBX_misc.obj: ../misc/GPS_UBX_misc.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="misc/GPS_UBX_misc.pp" --obj_directory="misc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


