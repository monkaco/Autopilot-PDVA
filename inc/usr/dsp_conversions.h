/******************************************************************************
* FILENAME:
*
* DESCRIPTION:
*       Function prototypes of communication peripherals.
*
* FUNCTIONS:
*       void    xxx
*       void    xxx
*
* VERSION DATE        WHO                    DETAIL
* 1.0     05 Set 2011 Rogerio Lima         Start-up coding.
*                     Plínio Pereira
* -----------------------------------------------------------------------------
* 2.0     30 Aug 2014 Rogerio Lima         Improving code quality rewriting the
*                                          code and correcting errors.
******************************************************************************/
#ifndef DSP_CONVERSIONS_H
#define DSP_CONVERSIONS_H

void apply_sensors_scale_factor (sensor_data_scaled_t* scaled_data, sensor_data_raw_t* raw_data);
void compute_euler_angles (ahrs_states_t* estimated_states);

#endif
