// MESSAGE SENSOR_HEAD_DATA PACKING

#define MAVLINK_MSG_ID_SENSOR_HEAD_DATA 150

typedef struct __mavlink_sensor_head_data_t
{
 int32_t time_gps_ms; ///< Timestamp (milliseconds)
 int32_t lat_gps; ///< GPS latitude (deg), multiplied by 1e7
 int32_t lon_gps; ///< GPS longitude (deg), multiplied by 1e7
 int32_t alt_gps; ///< GPS altitude above MSL (millimeters)
 float att_est[3]; ///< Estimated attitude angles (roll, pitch, yaw in radians)
 int32_t altitude; ///< Altitude above sea level (cm)
 int16_t hdg_gps; ///< GPS heading (milliradians)
 uint16_t speed_gps; ///< GPS groundspeed (cm/s)
 int16_t pos_fix_gps; ///< GPS Position Fix Status
 int16_t nosv_gps; ///< GPS Number of Satellites Used
 int16_t hdop_gps; ///< GPS Horizontal Dilution of Precision
 int16_t acc[3]; ///< Accelerometer readings (raw)
 int16_t gyro[3]; ///< Gyrometer readings (raw)
 int16_t gyro_temp; ///< Gyrometer temperature (raw)
 int16_t mag[3]; ///< Magnetometer readings (raw)
 int16_t dyn_press; ///< Dynamic pressure (raw)
 int16_t stat_press; ///< Static pressure (raw)
 uint16_t airspeed; ///< Airspeed (cm/s)
} mavlink_sensor_head_data_t;

#define MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN 68
#define MAVLINK_MSG_ID_150_LEN 68

#define MAVLINK_MSG_ID_SENSOR_HEAD_DATA_CRC 180
#define MAVLINK_MSG_ID_150_CRC 180

#define MAVLINK_MSG_SENSOR_HEAD_DATA_FIELD_ATT_EST_LEN 3
#define MAVLINK_MSG_SENSOR_HEAD_DATA_FIELD_ACC_LEN 3
#define MAVLINK_MSG_SENSOR_HEAD_DATA_FIELD_GYRO_LEN 3
#define MAVLINK_MSG_SENSOR_HEAD_DATA_FIELD_MAG_LEN 3

#define MAVLINK_MESSAGE_INFO_SENSOR_HEAD_DATA { \
	"SENSOR_HEAD_DATA", \
	18, \
	{  { "time_gps_ms", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_sensor_head_data_t, time_gps_ms) }, \
         { "lat_gps", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_sensor_head_data_t, lat_gps) }, \
         { "lon_gps", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_sensor_head_data_t, lon_gps) }, \
         { "alt_gps", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_sensor_head_data_t, alt_gps) }, \
         { "att_est", NULL, MAVLINK_TYPE_FLOAT, 3, 16, offsetof(mavlink_sensor_head_data_t, att_est) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_sensor_head_data_t, altitude) }, \
         { "hdg_gps", NULL, MAVLINK_TYPE_INT16_T, 0, 32, offsetof(mavlink_sensor_head_data_t, hdg_gps) }, \
         { "speed_gps", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_sensor_head_data_t, speed_gps) }, \
         { "pos_fix_gps", NULL, MAVLINK_TYPE_INT16_T, 0, 36, offsetof(mavlink_sensor_head_data_t, pos_fix_gps) }, \
         { "nosv_gps", NULL, MAVLINK_TYPE_INT16_T, 0, 38, offsetof(mavlink_sensor_head_data_t, nosv_gps) }, \
         { "hdop_gps", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_sensor_head_data_t, hdop_gps) }, \
         { "acc", NULL, MAVLINK_TYPE_INT16_T, 3, 42, offsetof(mavlink_sensor_head_data_t, acc) }, \
         { "gyro", NULL, MAVLINK_TYPE_INT16_T, 3, 48, offsetof(mavlink_sensor_head_data_t, gyro) }, \
         { "gyro_temp", NULL, MAVLINK_TYPE_INT16_T, 0, 54, offsetof(mavlink_sensor_head_data_t, gyro_temp) }, \
         { "mag", NULL, MAVLINK_TYPE_INT16_T, 3, 56, offsetof(mavlink_sensor_head_data_t, mag) }, \
         { "dyn_press", NULL, MAVLINK_TYPE_INT16_T, 0, 62, offsetof(mavlink_sensor_head_data_t, dyn_press) }, \
         { "stat_press", NULL, MAVLINK_TYPE_INT16_T, 0, 64, offsetof(mavlink_sensor_head_data_t, stat_press) }, \
         { "airspeed", NULL, MAVLINK_TYPE_UINT16_T, 0, 66, offsetof(mavlink_sensor_head_data_t, airspeed) }, \
         } \
}


/**
 * @brief Pack a sensor_head_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_gps_ms Timestamp (milliseconds)
 * @param lat_gps GPS latitude (deg), multiplied by 1e7
 * @param lon_gps GPS longitude (deg), multiplied by 1e7
 * @param alt_gps GPS altitude above MSL (millimeters)
 * @param hdg_gps GPS heading (milliradians)
 * @param speed_gps GPS groundspeed (cm/s)
 * @param pos_fix_gps GPS Position Fix Status
 * @param nosv_gps GPS Number of Satellites Used
 * @param hdop_gps GPS Horizontal Dilution of Precision
 * @param acc Accelerometer readings (raw)
 * @param gyro Gyrometer readings (raw)
 * @param gyro_temp Gyrometer temperature (raw)
 * @param mag Magnetometer readings (raw)
 * @param dyn_press Dynamic pressure (raw)
 * @param stat_press Static pressure (raw)
 * @param att_est Estimated attitude angles (roll, pitch, yaw in radians)
 * @param airspeed Airspeed (cm/s)
 * @param altitude Altitude above sea level (cm)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_head_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int32_t time_gps_ms, int32_t lat_gps, int32_t lon_gps, int32_t alt_gps, int16_t hdg_gps, uint16_t speed_gps, int16_t pos_fix_gps, int16_t nosv_gps, int16_t hdop_gps, const int16_t *acc, const int16_t *gyro, int16_t gyro_temp, const int16_t *mag, int16_t dyn_press, int16_t stat_press, const float *att_est, uint16_t airspeed, int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN];
	_mav_put_int32_t(buf, 0, time_gps_ms);
	_mav_put_int32_t(buf, 4, lat_gps);
	_mav_put_int32_t(buf, 8, lon_gps);
	_mav_put_int32_t(buf, 12, alt_gps);
	_mav_put_int32_t(buf, 28, altitude);
	_mav_put_int16_t(buf, 32, hdg_gps);
	_mav_put_uint16_t(buf, 34, speed_gps);
	_mav_put_int16_t(buf, 36, pos_fix_gps);
	_mav_put_int16_t(buf, 38, nosv_gps);
	_mav_put_int16_t(buf, 40, hdop_gps);
	_mav_put_int16_t(buf, 54, gyro_temp);
	_mav_put_int16_t(buf, 62, dyn_press);
	_mav_put_int16_t(buf, 64, stat_press);
	_mav_put_uint16_t(buf, 66, airspeed);
	_mav_put_float_array(buf, 16, att_est, 3);
	_mav_put_int16_t_array(buf, 42, acc, 3);
	_mav_put_int16_t_array(buf, 48, gyro, 3);
	_mav_put_int16_t_array(buf, 56, mag, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN);
#else
	mavlink_sensor_head_data_t packet;
	packet.time_gps_ms = time_gps_ms;
	packet.lat_gps = lat_gps;
	packet.lon_gps = lon_gps;
	packet.alt_gps = alt_gps;
	packet.altitude = altitude;
	packet.hdg_gps = hdg_gps;
	packet.speed_gps = speed_gps;
	packet.pos_fix_gps = pos_fix_gps;
	packet.nosv_gps = nosv_gps;
	packet.hdop_gps = hdop_gps;
	packet.gyro_temp = gyro_temp;
	packet.dyn_press = dyn_press;
	packet.stat_press = stat_press;
	packet.airspeed = airspeed;
	mav_array_memcpy(packet.att_est, att_est, sizeof(float)*3);
	mav_array_memcpy(packet.acc, acc, sizeof(int16_t)*3);
	mav_array_memcpy(packet.gyro, gyro, sizeof(int16_t)*3);
	mav_array_memcpy(packet.mag, mag, sizeof(int16_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SENSOR_HEAD_DATA;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN);
#endif
}

/**
 * @brief Pack a sensor_head_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_gps_ms Timestamp (milliseconds)
 * @param lat_gps GPS latitude (deg), multiplied by 1e7
 * @param lon_gps GPS longitude (deg), multiplied by 1e7
 * @param alt_gps GPS altitude above MSL (millimeters)
 * @param hdg_gps GPS heading (milliradians)
 * @param speed_gps GPS groundspeed (cm/s)
 * @param pos_fix_gps GPS Position Fix Status
 * @param nosv_gps GPS Number of Satellites Used
 * @param hdop_gps GPS Horizontal Dilution of Precision
 * @param acc Accelerometer readings (raw)
 * @param gyro Gyrometer readings (raw)
 * @param gyro_temp Gyrometer temperature (raw)
 * @param mag Magnetometer readings (raw)
 * @param dyn_press Dynamic pressure (raw)
 * @param stat_press Static pressure (raw)
 * @param att_est Estimated attitude angles (roll, pitch, yaw in radians)
 * @param airspeed Airspeed (cm/s)
 * @param altitude Altitude above sea level (cm)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_head_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int32_t time_gps_ms,int32_t lat_gps,int32_t lon_gps,int32_t alt_gps,int16_t hdg_gps,uint16_t speed_gps,int16_t pos_fix_gps,int16_t nosv_gps,int16_t hdop_gps,const int16_t *acc,const int16_t *gyro,int16_t gyro_temp,const int16_t *mag,int16_t dyn_press,int16_t stat_press,const float *att_est,uint16_t airspeed,int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN];
	_mav_put_int32_t(buf, 0, time_gps_ms);
	_mav_put_int32_t(buf, 4, lat_gps);
	_mav_put_int32_t(buf, 8, lon_gps);
	_mav_put_int32_t(buf, 12, alt_gps);
	_mav_put_int32_t(buf, 28, altitude);
	_mav_put_int16_t(buf, 32, hdg_gps);
	_mav_put_uint16_t(buf, 34, speed_gps);
	_mav_put_int16_t(buf, 36, pos_fix_gps);
	_mav_put_int16_t(buf, 38, nosv_gps);
	_mav_put_int16_t(buf, 40, hdop_gps);
	_mav_put_int16_t(buf, 54, gyro_temp);
	_mav_put_int16_t(buf, 62, dyn_press);
	_mav_put_int16_t(buf, 64, stat_press);
	_mav_put_uint16_t(buf, 66, airspeed);
	_mav_put_float_array(buf, 16, att_est, 3);
	_mav_put_int16_t_array(buf, 42, acc, 3);
	_mav_put_int16_t_array(buf, 48, gyro, 3);
	_mav_put_int16_t_array(buf, 56, mag, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN);
#else
	mavlink_sensor_head_data_t packet;
	packet.time_gps_ms = time_gps_ms;
	packet.lat_gps = lat_gps;
	packet.lon_gps = lon_gps;
	packet.alt_gps = alt_gps;
	packet.altitude = altitude;
	packet.hdg_gps = hdg_gps;
	packet.speed_gps = speed_gps;
	packet.pos_fix_gps = pos_fix_gps;
	packet.nosv_gps = nosv_gps;
	packet.hdop_gps = hdop_gps;
	packet.gyro_temp = gyro_temp;
	packet.dyn_press = dyn_press;
	packet.stat_press = stat_press;
	packet.airspeed = airspeed;
	mav_array_memcpy(packet.att_est, att_est, sizeof(float)*3);
	mav_array_memcpy(packet.acc, acc, sizeof(int16_t)*3);
	mav_array_memcpy(packet.gyro, gyro, sizeof(int16_t)*3);
	mav_array_memcpy(packet.mag, mag, sizeof(int16_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SENSOR_HEAD_DATA;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN);
#endif
}

/**
 * @brief Encode a sensor_head_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sensor_head_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_head_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sensor_head_data_t* sensor_head_data)
{
	return mavlink_msg_sensor_head_data_pack(system_id, component_id, msg, sensor_head_data->time_gps_ms, sensor_head_data->lat_gps, sensor_head_data->lon_gps, sensor_head_data->alt_gps, sensor_head_data->hdg_gps, sensor_head_data->speed_gps, sensor_head_data->pos_fix_gps, sensor_head_data->nosv_gps, sensor_head_data->hdop_gps, sensor_head_data->acc, sensor_head_data->gyro, sensor_head_data->gyro_temp, sensor_head_data->mag, sensor_head_data->dyn_press, sensor_head_data->stat_press, sensor_head_data->att_est, sensor_head_data->airspeed, sensor_head_data->altitude);
}

/**
 * @brief Encode a sensor_head_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sensor_head_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_head_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sensor_head_data_t* sensor_head_data)
{
	return mavlink_msg_sensor_head_data_pack_chan(system_id, component_id, chan, msg, sensor_head_data->time_gps_ms, sensor_head_data->lat_gps, sensor_head_data->lon_gps, sensor_head_data->alt_gps, sensor_head_data->hdg_gps, sensor_head_data->speed_gps, sensor_head_data->pos_fix_gps, sensor_head_data->nosv_gps, sensor_head_data->hdop_gps, sensor_head_data->acc, sensor_head_data->gyro, sensor_head_data->gyro_temp, sensor_head_data->mag, sensor_head_data->dyn_press, sensor_head_data->stat_press, sensor_head_data->att_est, sensor_head_data->airspeed, sensor_head_data->altitude);
}

/**
 * @brief Send a sensor_head_data message
 * @param chan MAVLink channel to send the message
 *
 * @param time_gps_ms Timestamp (milliseconds)
 * @param lat_gps GPS latitude (deg), multiplied by 1e7
 * @param lon_gps GPS longitude (deg), multiplied by 1e7
 * @param alt_gps GPS altitude above MSL (millimeters)
 * @param hdg_gps GPS heading (milliradians)
 * @param speed_gps GPS groundspeed (cm/s)
 * @param pos_fix_gps GPS Position Fix Status
 * @param nosv_gps GPS Number of Satellites Used
 * @param hdop_gps GPS Horizontal Dilution of Precision
 * @param acc Accelerometer readings (raw)
 * @param gyro Gyrometer readings (raw)
 * @param gyro_temp Gyrometer temperature (raw)
 * @param mag Magnetometer readings (raw)
 * @param dyn_press Dynamic pressure (raw)
 * @param stat_press Static pressure (raw)
 * @param att_est Estimated attitude angles (roll, pitch, yaw in radians)
 * @param airspeed Airspeed (cm/s)
 * @param altitude Altitude above sea level (cm)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sensor_head_data_send(mavlink_channel_t chan, int32_t time_gps_ms, int32_t lat_gps, int32_t lon_gps, int32_t alt_gps, int16_t hdg_gps, uint16_t speed_gps, int16_t pos_fix_gps, int16_t nosv_gps, int16_t hdop_gps, const int16_t *acc, const int16_t *gyro, int16_t gyro_temp, const int16_t *mag, int16_t dyn_press, int16_t stat_press, const float *att_est, uint16_t airspeed, int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN];
	_mav_put_int32_t(buf, 0, time_gps_ms);
	_mav_put_int32_t(buf, 4, lat_gps);
	_mav_put_int32_t(buf, 8, lon_gps);
	_mav_put_int32_t(buf, 12, alt_gps);
	_mav_put_int32_t(buf, 28, altitude);
	_mav_put_int16_t(buf, 32, hdg_gps);
	_mav_put_uint16_t(buf, 34, speed_gps);
	_mav_put_int16_t(buf, 36, pos_fix_gps);
	_mav_put_int16_t(buf, 38, nosv_gps);
	_mav_put_int16_t(buf, 40, hdop_gps);
	_mav_put_int16_t(buf, 54, gyro_temp);
	_mav_put_int16_t(buf, 62, dyn_press);
	_mav_put_int16_t(buf, 64, stat_press);
	_mav_put_uint16_t(buf, 66, airspeed);
	_mav_put_float_array(buf, 16, att_est, 3);
	_mav_put_int16_t_array(buf, 42, acc, 3);
	_mav_put_int16_t_array(buf, 48, gyro, 3);
	_mav_put_int16_t_array(buf, 56, mag, 3);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_HEAD_DATA, buf, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_HEAD_DATA, buf, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN);
#endif
#else
	mavlink_sensor_head_data_t packet;
	packet.time_gps_ms = time_gps_ms;
	packet.lat_gps = lat_gps;
	packet.lon_gps = lon_gps;
	packet.alt_gps = alt_gps;
	packet.altitude = altitude;
	packet.hdg_gps = hdg_gps;
	packet.speed_gps = speed_gps;
	packet.pos_fix_gps = pos_fix_gps;
	packet.nosv_gps = nosv_gps;
	packet.hdop_gps = hdop_gps;
	packet.gyro_temp = gyro_temp;
	packet.dyn_press = dyn_press;
	packet.stat_press = stat_press;
	packet.airspeed = airspeed;
	mav_array_memcpy(packet.att_est, att_est, sizeof(float)*3);
	mav_array_memcpy(packet.acc, acc, sizeof(int16_t)*3);
	mav_array_memcpy(packet.gyro, gyro, sizeof(int16_t)*3);
	mav_array_memcpy(packet.mag, mag, sizeof(int16_t)*3);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_HEAD_DATA, (const char *)&packet, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_HEAD_DATA, (const char *)&packet, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sensor_head_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t time_gps_ms, int32_t lat_gps, int32_t lon_gps, int32_t alt_gps, int16_t hdg_gps, uint16_t speed_gps, int16_t pos_fix_gps, int16_t nosv_gps, int16_t hdop_gps, const int16_t *acc, const int16_t *gyro, int16_t gyro_temp, const int16_t *mag, int16_t dyn_press, int16_t stat_press, const float *att_est, uint16_t airspeed, int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int32_t(buf, 0, time_gps_ms);
	_mav_put_int32_t(buf, 4, lat_gps);
	_mav_put_int32_t(buf, 8, lon_gps);
	_mav_put_int32_t(buf, 12, alt_gps);
	_mav_put_int32_t(buf, 28, altitude);
	_mav_put_int16_t(buf, 32, hdg_gps);
	_mav_put_uint16_t(buf, 34, speed_gps);
	_mav_put_int16_t(buf, 36, pos_fix_gps);
	_mav_put_int16_t(buf, 38, nosv_gps);
	_mav_put_int16_t(buf, 40, hdop_gps);
	_mav_put_int16_t(buf, 54, gyro_temp);
	_mav_put_int16_t(buf, 62, dyn_press);
	_mav_put_int16_t(buf, 64, stat_press);
	_mav_put_uint16_t(buf, 66, airspeed);
	_mav_put_float_array(buf, 16, att_est, 3);
	_mav_put_int16_t_array(buf, 42, acc, 3);
	_mav_put_int16_t_array(buf, 48, gyro, 3);
	_mav_put_int16_t_array(buf, 56, mag, 3);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_HEAD_DATA, buf, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_HEAD_DATA, buf, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN);
#endif
#else
	mavlink_sensor_head_data_t *packet = (mavlink_sensor_head_data_t *)msgbuf;
	packet->time_gps_ms = time_gps_ms;
	packet->lat_gps = lat_gps;
	packet->lon_gps = lon_gps;
	packet->alt_gps = alt_gps;
	packet->altitude = altitude;
	packet->hdg_gps = hdg_gps;
	packet->speed_gps = speed_gps;
	packet->pos_fix_gps = pos_fix_gps;
	packet->nosv_gps = nosv_gps;
	packet->hdop_gps = hdop_gps;
	packet->gyro_temp = gyro_temp;
	packet->dyn_press = dyn_press;
	packet->stat_press = stat_press;
	packet->airspeed = airspeed;
	mav_array_memcpy(packet->att_est, att_est, sizeof(float)*3);
	mav_array_memcpy(packet->acc, acc, sizeof(int16_t)*3);
	mav_array_memcpy(packet->gyro, gyro, sizeof(int16_t)*3);
	mav_array_memcpy(packet->mag, mag, sizeof(int16_t)*3);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_HEAD_DATA, (const char *)packet, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_HEAD_DATA, (const char *)packet, MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE SENSOR_HEAD_DATA UNPACKING


/**
 * @brief Get field time_gps_ms from sensor_head_data message
 *
 * @return Timestamp (milliseconds)
 */
static inline int32_t mavlink_msg_sensor_head_data_get_time_gps_ms(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field lat_gps from sensor_head_data message
 *
 * @return GPS latitude (deg), multiplied by 1e7
 */
static inline int32_t mavlink_msg_sensor_head_data_get_lat_gps(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field lon_gps from sensor_head_data message
 *
 * @return GPS longitude (deg), multiplied by 1e7
 */
static inline int32_t mavlink_msg_sensor_head_data_get_lon_gps(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field alt_gps from sensor_head_data message
 *
 * @return GPS altitude above MSL (millimeters)
 */
static inline int32_t mavlink_msg_sensor_head_data_get_alt_gps(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field hdg_gps from sensor_head_data message
 *
 * @return GPS heading (milliradians)
 */
static inline int16_t mavlink_msg_sensor_head_data_get_hdg_gps(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  32);
}

/**
 * @brief Get field speed_gps from sensor_head_data message
 *
 * @return GPS groundspeed (cm/s)
 */
static inline uint16_t mavlink_msg_sensor_head_data_get_speed_gps(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  34);
}

/**
 * @brief Get field pos_fix_gps from sensor_head_data message
 *
 * @return GPS Position Fix Status
 */
static inline int16_t mavlink_msg_sensor_head_data_get_pos_fix_gps(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  36);
}

/**
 * @brief Get field nosv_gps from sensor_head_data message
 *
 * @return GPS Number of Satellites Used
 */
static inline int16_t mavlink_msg_sensor_head_data_get_nosv_gps(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  38);
}

/**
 * @brief Get field hdop_gps from sensor_head_data message
 *
 * @return GPS Horizontal Dilution of Precision
 */
static inline int16_t mavlink_msg_sensor_head_data_get_hdop_gps(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  40);
}

/**
 * @brief Get field acc from sensor_head_data message
 *
 * @return Accelerometer readings (raw)
 */
static inline uint16_t mavlink_msg_sensor_head_data_get_acc(const mavlink_message_t* msg, int16_t *acc)
{
	return _MAV_RETURN_int16_t_array(msg, acc, 3,  42);
}

/**
 * @brief Get field gyro from sensor_head_data message
 *
 * @return Gyrometer readings (raw)
 */
static inline uint16_t mavlink_msg_sensor_head_data_get_gyro(const mavlink_message_t* msg, int16_t *gyro)
{
	return _MAV_RETURN_int16_t_array(msg, gyro, 3,  48);
}

/**
 * @brief Get field gyro_temp from sensor_head_data message
 *
 * @return Gyrometer temperature (raw)
 */
static inline int16_t mavlink_msg_sensor_head_data_get_gyro_temp(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  54);
}

/**
 * @brief Get field mag from sensor_head_data message
 *
 * @return Magnetometer readings (raw)
 */
static inline uint16_t mavlink_msg_sensor_head_data_get_mag(const mavlink_message_t* msg, int16_t *mag)
{
	return _MAV_RETURN_int16_t_array(msg, mag, 3,  56);
}

/**
 * @brief Get field dyn_press from sensor_head_data message
 *
 * @return Dynamic pressure (raw)
 */
static inline int16_t mavlink_msg_sensor_head_data_get_dyn_press(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  62);
}

/**
 * @brief Get field stat_press from sensor_head_data message
 *
 * @return Static pressure (raw)
 */
static inline int16_t mavlink_msg_sensor_head_data_get_stat_press(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  64);
}

/**
 * @brief Get field att_est from sensor_head_data message
 *
 * @return Estimated attitude angles (roll, pitch, yaw in radians)
 */
static inline uint16_t mavlink_msg_sensor_head_data_get_att_est(const mavlink_message_t* msg, float *att_est)
{
	return _MAV_RETURN_float_array(msg, att_est, 3,  16);
}

/**
 * @brief Get field airspeed from sensor_head_data message
 *
 * @return Airspeed (cm/s)
 */
static inline uint16_t mavlink_msg_sensor_head_data_get_airspeed(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  66);
}

/**
 * @brief Get field altitude from sensor_head_data message
 *
 * @return Altitude above sea level (cm)
 */
static inline int32_t mavlink_msg_sensor_head_data_get_altitude(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Decode a sensor_head_data message into a struct
 *
 * @param msg The message to decode
 * @param sensor_head_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_sensor_head_data_decode(const mavlink_message_t* msg, mavlink_sensor_head_data_t* sensor_head_data)
{
#if MAVLINK_NEED_BYTE_SWAP
	sensor_head_data->time_gps_ms = mavlink_msg_sensor_head_data_get_time_gps_ms(msg);
	sensor_head_data->lat_gps = mavlink_msg_sensor_head_data_get_lat_gps(msg);
	sensor_head_data->lon_gps = mavlink_msg_sensor_head_data_get_lon_gps(msg);
	sensor_head_data->alt_gps = mavlink_msg_sensor_head_data_get_alt_gps(msg);
	mavlink_msg_sensor_head_data_get_att_est(msg, sensor_head_data->att_est);
	sensor_head_data->altitude = mavlink_msg_sensor_head_data_get_altitude(msg);
	sensor_head_data->hdg_gps = mavlink_msg_sensor_head_data_get_hdg_gps(msg);
	sensor_head_data->speed_gps = mavlink_msg_sensor_head_data_get_speed_gps(msg);
	sensor_head_data->pos_fix_gps = mavlink_msg_sensor_head_data_get_pos_fix_gps(msg);
	sensor_head_data->nosv_gps = mavlink_msg_sensor_head_data_get_nosv_gps(msg);
	sensor_head_data->hdop_gps = mavlink_msg_sensor_head_data_get_hdop_gps(msg);
	mavlink_msg_sensor_head_data_get_acc(msg, sensor_head_data->acc);
	mavlink_msg_sensor_head_data_get_gyro(msg, sensor_head_data->gyro);
	sensor_head_data->gyro_temp = mavlink_msg_sensor_head_data_get_gyro_temp(msg);
	mavlink_msg_sensor_head_data_get_mag(msg, sensor_head_data->mag);
	sensor_head_data->dyn_press = mavlink_msg_sensor_head_data_get_dyn_press(msg);
	sensor_head_data->stat_press = mavlink_msg_sensor_head_data_get_stat_press(msg);
	sensor_head_data->airspeed = mavlink_msg_sensor_head_data_get_airspeed(msg);
#else
	memcpy(sensor_head_data, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN);
#endif
}
