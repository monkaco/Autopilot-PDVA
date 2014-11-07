################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/usr/dsp_comm.obj: ../src/usr/dsp_comm.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_comm.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_conversions.obj: ../src/usr/dsp_conversions.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_conversions.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_ekf.obj: ../src/usr/dsp_ekf.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_ekf.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_gps.obj: ../src/usr/dsp_gps.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_gps.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_i2c.obj: ../src/usr/dsp_i2c.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_i2c.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_i2c_adxl345.obj: ../src/usr/dsp_i2c_adxl345.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_i2c_adxl345.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_i2c_bmp085.obj: ../src/usr/dsp_i2c_bmp085.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_i2c_bmp085.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_i2c_hmc5883.obj: ../src/usr/dsp_i2c_hmc5883.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_i2c_hmc5883.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_i2c_hsc.obj: ../src/usr/dsp_i2c_hsc.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_i2c_hsc.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_i2c_itg3200.obj: ../src/usr/dsp_i2c_itg3200.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_i2c_itg3200.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_isr.obj: ../src/usr/dsp_isr.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_isr.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_matrix.obj: ../src/usr/dsp_matrix.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_matrix.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_quat.obj: ../src/usr/dsp_quat.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_quat.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_system.obj: ../src/usr/dsp_system.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_system.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/ekf_predict.obj: ../src/usr/ekf_predict.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/ekf_predict.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/ekf_update.obj: ../src/usr/ekf_update.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/ekf_update.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/main.obj: ../src/usr/main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="F:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/main.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


