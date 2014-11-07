/******************************************************************************
* FILENAME:
*
* DESCRIPTION:
*       Function prototypes of ...
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

#ifndef DSP_GPS_H
#define DSP_GPS_H



#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define NULL 0

typedef struct
{
    int lat_deg;
    double lat_min;
    uint8_t lat_sector;

    int lon_deg;
    double lon_min;
    uint8_t lon_sector;

    double altitude;
    double speed;
    uint8_t speed_unit;
    double course;
    uint8_t course_type;

    uint8_t hour;
    uint8_t min;
    float sec;

    uint8_t position_fix_status;
    uint8_t nosv;
    float hdop;

    int gps_new_message;
}gps_data_buffer_t;

typedef enum {GGA, GSA, GSV, RMC, VTG, GLL, ZDA} NMEA_type_t;


// PROTOTYPES
uint8_t get_line(uint8_t* line, uint8_t* msg_in);
void translate_msg (uint8_t* line, gps_data_buffer_t* gps_data);
NMEA_type_t get_NMEA_type (uint8_t * str);
void translate_GGA ( uint8_t* line, gps_data_buffer_t* gps_data);
void translate_GLL ( uint8_t* line, gps_data_buffer_t* gps_data);
void translate_VTG ( uint8_t* line, gps_data_buffer_t* gps_data);
void translate_GSA ( uint8_t* line, gps_data_buffer_t* gps_data);
void translate_GSV ( uint8_t* line, gps_data_buffer_t* gps_data);
void translate_RMC ( uint8_t* line, gps_data_buffer_t* gps_data);
void translate_ZDA ( uint8_t* line, gps_data_buffer_t* gps_data);
void print_serial_gps (gps_data_buffer_t* gps_data);
void strcpy_len (uint8_t* destination, uint8_t* source, unsigned start, unsigned lenght);
double CvtStF (uint8_t* str);
int str_split (uint8_t* str, int start, uint8_t c, uint8_t* flag);


uint8_t Process_GPS(gps_data_buffer_t* gps_dat);
void Init_GPS();
uint8_t Read_Byte_RS232();
void Transmit_Byte_RS232(uint8_t* byte);
void Wait_for_uint8_t_RS232(uint8_t c);
// Read one messange until a new line is fouded.
int RS232_gets(uint8_t* line, int max);


#endif // GPS_H
