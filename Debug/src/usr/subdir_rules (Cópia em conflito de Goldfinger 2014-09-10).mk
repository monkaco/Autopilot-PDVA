################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/usr/Application_Control_Variables.obj: ../src/usr/Application_Control_Variables.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/Application_Control_Variables.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/Application_IO_Functions.obj: ../src/usr/Application_IO_Functions.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/Application_IO_Functions.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/EKF_Predict.obj: ../src/usr/EKF_Predict.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/EKF_Predict.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/EKF_Update.obj: ../src/usr/EKF_Update.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/EKF_Update.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/GPS.obj: ../src/usr/GPS.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/GPS.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/Gumstix.obj: ../src/usr/Gumstix.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/Gumstix.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/ISR.obj: ../src/usr/ISR.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/ISR.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/Tradutor_NMEA.obj: ../src/usr/Tradutor_NMEA.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/Tradutor_NMEA.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_comm.obj: ../src/usr/dsp_comm.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_comm.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_i2c.obj: ../src/usr/dsp_i2c.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_i2c.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_i2c_adxl345.obj: ../src/usr/dsp_i2c_adxl345.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_i2c_adxl345.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_i2c_bmp085.obj: ../src/usr/dsp_i2c_bmp085.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_i2c_bmp085.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_i2c_hmc5883.obj: ../src/usr/dsp_i2c_hmc5883.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_i2c_hmc5883.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_i2c_hsc.obj: ../src/usr/dsp_i2c_hsc.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_i2c_hsc.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_i2c_itg3200.obj: ../src/usr/dsp_i2c_itg3200.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_i2c_itg3200.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_matrix.obj: ../src/usr/dsp_matrix.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_matrix.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_quat.obj: ../src/usr/dsp_quat.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_quat.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/dsp_system.obj: ../src/usr/dsp_system.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/dsp_system.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/ekf.obj: ../src/usr/ekf.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/ekf.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/main.obj: ../src/usr/main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/main.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/usr/mavlink.obj: ../src/usr/mavlink.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/sys" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/common" --include_path="D:/Dropbox/Project UAV/Firmware/Firmware_VANT_MAVLink_Flash[Netrino]/inc/usr/mavlink/v1.0/pdvapilot" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="src/usr/mavlink.pp" --obj_directory="src/usr" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


