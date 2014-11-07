#include "dsp_types.h"
#include "dsp_sensorhead_types.h"
#include "dsp_gps.h"

uint8_t line[80];
uint8_t gps_in_index;
uint8_t gps_in[200];// = {"$GPGGA,184450.000,1954.3925,S,440437.10,W,2,5,1.03,902,M,55.2,M,,*76"};        // messenge received from GPS
uint8_t line[80];
uint8_t gps_in_flag;
gps_data_buffer_t gps_data;
float gps_speed;
float gps_heading;

    // Abrir arquivo contendo mensagens do GPS
    // Separar mensagem que começa com $ e termina com * + 2 caracteres(check)
    // Esperar por caracteres <CR><LF que de fato terminam a mensagem

    // Conferir sequencia GP no 2 e 3 digitos
    // Descobrir tipo da mensagem no 4, 5, 6 digitos (ex: GGA)

    // For each kind of messanges use property translate rules


    // DATA NEEDED BY VANT
    // GGA:
    // -> Time
    // -> Latitude
    // -> Latitude sector
    // -> Longitude
    // -> Longitude sector
    // -> altitude above sea level

    // GLL
    // VTG
    // -> Speed over ground
    // -> course over ground
    // -> Speed over ground



uint8_t Process_GPS (gps_data_buffer_t* gps_dat)
{
	static uint8_t returnval = 0U;
    static uint8_t num_lines = 0U;

    // Colocar aqui a função dinâmica dentro de um FOR para ir construindo as 
    // linhas das mensagens GPS. Se houver apenas uma linha, o FOR é executado
    // apenas uma vez...
    for (num_lines = 0; num_lines < 2; num_lines++)
    {
    	returnval &= get_line(line, gps_in);
        translate_msg(line, gps_dat);
    }
    print_serial_gps (gps_dat);

    // Indicates a if there is (1) or not (0) a new GPS message.
    gps_dat->gps_new_message = 1;

//    gps_speed = gps_dat->Speed;
//    gps_heading = gps_dat->course;

    return returnval;
}


void Init_GPS()
{

}

/*
uint8_t Read_Byte_RS232()
{
    uint8_t *byte = 0;

    sciBatchRead( byte, 1 );
    return *byte;
}

void Transmit_Byte_RS232(uint8_t *byte)
{

    sciBatchWrite( byte, 1 );
}


void Wait_for_uint8_t_RS232(uint8_t c)
{
    uint8_t *byte = 0;
    
    while (*byte != c){
        sciBatchRead( byte, 1 );
    }
}


// Read one messange until a new line is fouded.
int RS232_gets(uint8_t* line, int max)
{
    int i = -1;
        
    if (max == 0) return NULL;
    do{
        i++;
        line[i] = Read_Byte_RS232();        
    } while (i != max || line[i]=='\0' || line[i]=='\n');
    
    return i; 
}*/


// Receive the GPS line and check the header
// Separar mensagem que começa com $ e termina com * + 2 caracteres(checksum)
// Esperar por caracteres <CR><LF que de fato terminam a mensagem
// Check if the sequence started witch "GP" on 2 and 3 uint8_tacter
uint8_t get_line (uint8_t* line, uint8_t* msg_in)
{
	static uint8_t returnval;
	static uint8_t j;
	static uint8_t exitLoop;
    uint8_t check;
    static uint16_t h = 0;
    static uint16_t num_lines = 0;
    static uint8_t state = 's';
//    uint8_t msg_check[2];

    exitLoop = 1;
    check = 0;
    
    if ((h >= 160) || (num_lines >= 2))
    {   
        h = 0;
    }

    while ((exitLoop) && (h < 160))
    {
        switch (state){
            // start state - looking for '$'
            case 's':    
                    {
                        j = 0;
                        if (msg_in[h++] == '$')    state = 'p';
                        break;
                    }
            // in progress state of reading
            case 'p':    
                    {
                        if (msg_in[h] == '*')
                        {
                            state = 'e';
                            j++;
                            line[j] = '\n';
                            num_lines++;
                            // GPS message checksum
                            //msg_check[0] = msg_in[h+1];
                            //msg_check[1] = msg_in[h+2];
                        }
                        else
                        {
                            line[j] = msg_in[h];
                            check = check ^ line[j];
                            j++;
                            h++;
                        }
                        
                        break;
                    }
            // exit FOR loop
            case 'e':
                    {
                        state = 's';
                        exitLoop = 0;

                        if(num_lines >= 2)    num_lines = 0;
                        //gps_new_message = 1;
                    break;
                    }
        } // end-switch
    } //end-while

}
    

/*    Wait_for_uint8_t_RS232('$');
    if (RS232_gets(line, 80) != NULL){
        if(line[0] == '$' && line[1] == 'G' && line[2] == 'P'){
            p = strchr (line, '*');        // lookfor *
            if (p == NULL) return 0;
            *p = '\0';                    // finish the string at *  
            return 1;                    // line is ok
        }
    }
    return 0;
}
*/


/* For each kind of messanges use property translate rules */
void translate_msg (uint8_t* line, gps_data_buffer_t* gps_data)
{
    uint8_t header[10];
    uint8_t msgtype;

    strcpy_len(header, line, 2, 3);                // get the header eliminating the $GP -> position should be 2 instead of originally 3
    msgtype = get_NMEA_type(header);

    switch (msgtype){
        case GGA:    translate_GGA (line, gps_data);
            break;

        case GSA:    translate_GSA (line, gps_data);
            break;

        case GSV:    translate_GSV (line, gps_data);
            break;

        case RMC:    translate_RMC (line, gps_data);
            break;

        case VTG:    translate_VTG (line, gps_data);
            break;

        case GLL:    translate_GLL (line, gps_data);
            break;

        case ZDA:    translate_ZDA (line, gps_data);
            break;

        default:
            break;
    }
}


NMEA_type_t get_NMEA_type(uint8_t * str)
{
    if (!strcmp(str, "GGA")) return GGA;
    if (!strcmp(str, "GSA")) return GSA;
    if (!strcmp(str, "GSV")) return GSV;
    if (!strcmp(str, "RMC")) return RMC;
    if (!strcmp(str, "VTG")) return VTG;
    if (!strcmp(str, "GLL")) return GLL;
    if (!strcmp(str, "ZDA")) return ZDA;
    return FAIL;
}

void translate_GGA( uint8_t* line, gps_data_buffer_t* gps_data)
{
    uint8_t token[20];
    uint8_t aux[20];
    float faux;
    int end;
    int start = 0;
    uint8_t flag;
    uint8_t estate = 0;

    while (estate != 10){
        end = str_split(line, start, ',', &flag);
        strcpy_len(token, line, start, end);
        if (flag) break;

        switch (estate){
            case 0:        // Ignore message's type
                        break;

            case 1:        // gets the time [hhmmss.ss]
                        if (end != 0)
                        {
                            strcpy_len(aux, token, 0, 2);    // get hour [(hh)mmss.ss]
                            gps_data->hour = atoi(aux);
                            strcpy_len(aux, token, 2, 2);    // get min [hh(mm)ss.ss]
                            gps_data->min = atoi(aux);
                            strcpy_len(aux, token, 4, 4);    // get sec [hhmm(ss.ss)]
                            faux = CvtStF (aux);
                            gps_data->sec = faux;
                            break;
                        }else    // empty field
                        {
                            gps_data->hour = 0;
                            gps_data->min = 0;
                            gps_data->sec = 0.0;
                            break;
                        }


            case 2:        // gets the latitude [ddmm.mmmm]
                        if (end != 0)
                        {
                            strcpy_len(aux, token, 0, 2);    // get degree [(dd)mm.mmmm]
                            gps_data->lat_deg = atoi(aux);
                            strcpy_len(aux, token, 2, 9);    // get minuts [dd(mm.mmmm)]
                            faux = CvtStF (aux);
                            gps_data->lat_min = faux;
                            break;
                        }else    // empty field
                        {
                            gps_data->lat_deg = 0;
                            gps_data->lat_min = 0.0;
                            break;
                        }

            case 3:        // gets the latitude's sector [uint8_t]
                        if (end != 0)
                        {
                            gps_data->lat_sector = token[0];
                            break;
                        }else
                        {
                            gps_data->lat_sector = 0;
                            break;
                        }

            case 4:        // gets the longitude [dddmm.mmmm]
                        if (end != 0)
                        {
                            strcpy_len(aux, token, 0, 3);    // get degree [(ddd)mm.mmmm]
                            gps_data->lon_deg = atoi(aux);
                            strcpy_len(aux, token, 3, 9);    // get minuts [ddd(mm.mmmm)]
                            faux = CvtStF (aux);
                            gps_data->lon_min = faux;
                            break;
                        }else
                        {
                            gps_data->lon_deg = 0;
                            gps_data->lon_min = 0.0;
                            break;
                        }

            case 5:        // gets the longitude's sector [uint8_t]
                        if (end != 0)
                        {
                            gps_data->lon_sector = token[0];
                            break;
                        }else
                        {
                            gps_data->lon_sector = 0;
                            break;
                        }

            case 6:        // gets GPS quality indicator [uint8_t]
                        if (end != 0)
                        {
                            gps_data->position_fix_status = token[0];
                            break;
                        }else
                        {
                            gps_data->position_fix_status = 0;
                            break;
                        }

            case 7:        // gets Number of SVs used in position estimation [uint8_t uint8_t]
                        if (end != 0)
                        {
                            strcpy_len(aux, token, 0, 2);    // get number of sat. used [uint8_t uint8_t]
                            gps_data->nosv = atoi(aux);
                            break;
                        }else
                        {
                            gps_data->nosv = 0;
                            break;
                        }

            case 8:        // gets hdop [uint8_t]
                        if (end != 0)
                        {
                            faux = CvtStF (token);
                            gps_data->hdop = faux;
                            break;
                        }else
                        {
                            gps_data->hdop = 0.0;
                            break;
                        }

            case 9:        // gets altitude above mean sea level
                        if (end != 0)
                        {
                            faux = CvtStF (token);
                            gps_data->altitude = faux;
                            break;
                        }else
                        {
                            gps_data->altitude = 0.0;
                            break;
                        }
        }
        start = start + end + 1;
        estate++;
    }

// ignore the rest

}


void translate_VTG( uint8_t* line, gps_data_buffer_t* gps_data)
{
    uint8_t token[20];
    uint8_t aux[20];
    float faux;
    int end;
    int start = 0;
    uint8_t flag;
    uint8_t estate = 0;

    while (estate != 9){
        end = str_split(line, start, ',', &flag);
        strcpy_len(token, line, start, end);
        if (flag) break;

        switch (estate){
            case 0:        // Ignore message's type
                        break;

            case 1:        // gets course over ground (degrees)
                        if (end != 0)
                        {
                            faux = CvtStF (token);
                            gps_data->course = faux;
                            break;
                        }else
                        {
                            gps_data->course = 0.0;
                            break;
                        }

            case 2:        // gets T (true) uint8_t from true course
                        if (end != 0)
                        {
                            gps_data->course_type = token[0];
                            break;
                        }else
                        {
                            gps_data->course_type = 0;
                            break;
                        }

            case 3:        // jump empty field
                        break;

            case 4:        // jump M (magnetic) uint8_t from magnetic course
                        break;

            case 5:        // jump speed over ground (sog) in knots
                        break;

            case 6:        // jump N (knots) uint8_t from sog
                        break;

            case 7:        // get speed over ground (kph) in km/h
                        if (end != 0)
                        {
                            faux = CvtStF (token);
                            gps_data->speed = faux;
                            break;
                        }else
                        {
                            gps_data->speed = 0.0;
                            break;
                        }

            case 8:        // get K uint8_t from speed over ground in km/h
                        if (end != 0)
                        {
                            gps_data->speed_unit = token[0];
                            break;
                        }else
                        {
                            gps_data->speed_unit = 0;
                            break;
                        }

        }
        start = start + end + 1;
        estate++;
    }

// ignore the rest

}

void translate_GLL( uint8_t* line, gps_data_buffer_t* gps_data)
{
    /* TODO */
}

void translate_GSV( uint8_t* line, gps_data_buffer_t* gps_data)
{
    /* TODO */
}

void translate_RMC( uint8_t* line, gps_data_buffer_t* gps_data)
{
    /* TODO */
}

void translate_ZDA( uint8_t* line, gps_data_buffer_t* gps_data)
{
    /* TODO */
}

void translate_GSA( uint8_t* line, gps_data_buffer_t* gps_data)
{
    /* TODO */
}
void print_serial_gps (gps_data_buffer_t* gps_data)
{
//    printf ("Hora: %d: %d: %d\naltitude = %f \nVelocidade = %f m/s \nLat = %d* %f\" %c\nLong = %d*  %f\" %c\n",
//        gps_data->hour, gps_data->min, gps_data->sec, gps_data->altitude, gps_data->Speed,
//        gps_data->lat_deg, gps_data->lat_min, gps_data->lat_sector,
//        gps_data->lon_deg, gps_data->lon_min, gps_data->lon_sector);

}


void strcpy_len(uint8_t* destination, uint8_t* source, unsigned start, unsigned lenght)
{
    memcpy (destination, source + start, lenght);
    destination[lenght] = '\0';
}


double CvtStF (uint8_t* str)
{
    // converte string to float
    double inteiro = 0.0; // convert 1st
    double decimal = 0.0;
    double divisor = 10;
    int i = 0;

    // Convert uint8_tacter before point
    while (str[i] != '\0' && str[i] != '.')
    {
        inteiro = (inteiro * 10) + str[i] - '0';
        i++;
    }
    if (str[i] == '.') i++;
    while (str[i] != '\0'){
        decimal += (str[i] - '0') / divisor;
        divisor *= 10;
        i++;
    }
    return inteiro + decimal;
}


// It's similar to strtok
// return the diference between start and the first uint8_t c found
// if flag = 1 end of string was found
int str_split(uint8_t* str, int start, uint8_t c, uint8_t *flag)
{
    int i = start;

    *flag = 0;
    while (str[i] != NULL){
        if (str[i] == c) return i - start;
        i++;
    }
    *flag = 1;
    return i - start;
}
