// MESSAGE SENSOR_HEAD_COMMAND PACKING

#define MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND 151

typedef struct __mavlink_sensor_head_command_t
{
 uint16_t aileron; ///< Aileron command, 0 to 65535
 uint16_t elevator; ///< Elevator command, 0 to 65535
 uint16_t throttle; ///< Throttle command, 0 to 65535
 uint16_t rudder; ///< Rudder command, 0 to 65535
} mavlink_sensor_head_command_t;

#define MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN 8
#define MAVLINK_MSG_ID_151_LEN 8

#define MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_CRC 208
#define MAVLINK_MSG_ID_151_CRC 208



#define MAVLINK_MESSAGE_INFO_SENSOR_HEAD_COMMAND { \
	"SENSOR_HEAD_COMMAND", \
	4, \
	{  { "aileron", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_sensor_head_command_t, aileron) }, \
         { "elevator", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_sensor_head_command_t, elevator) }, \
         { "throttle", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_sensor_head_command_t, throttle) }, \
         { "rudder", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_sensor_head_command_t, rudder) }, \
         } \
}


/**
 * @brief Pack a sensor_head_command message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param aileron Aileron command, 0 to 65535
 * @param elevator Elevator command, 0 to 65535
 * @param throttle Throttle command, 0 to 65535
 * @param rudder Rudder command, 0 to 65535
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_head_command_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t aileron, uint16_t elevator, uint16_t throttle, uint16_t rudder)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN];
	_mav_put_uint16_t(buf, 0, aileron);
	_mav_put_uint16_t(buf, 2, elevator);
	_mav_put_uint16_t(buf, 4, throttle);
	_mav_put_uint16_t(buf, 6, rudder);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN);
#else
	mavlink_sensor_head_command_t packet;
	packet.aileron = aileron;
	packet.elevator = elevator;
	packet.throttle = throttle;
	packet.rudder = rudder;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN);
#endif
}

/**
 * @brief Pack a sensor_head_command message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param aileron Aileron command, 0 to 65535
 * @param elevator Elevator command, 0 to 65535
 * @param throttle Throttle command, 0 to 65535
 * @param rudder Rudder command, 0 to 65535
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_head_command_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t aileron,uint16_t elevator,uint16_t throttle,uint16_t rudder)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN];
	_mav_put_uint16_t(buf, 0, aileron);
	_mav_put_uint16_t(buf, 2, elevator);
	_mav_put_uint16_t(buf, 4, throttle);
	_mav_put_uint16_t(buf, 6, rudder);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN);
#else
	mavlink_sensor_head_command_t packet;
	packet.aileron = aileron;
	packet.elevator = elevator;
	packet.throttle = throttle;
	packet.rudder = rudder;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN);
#endif
}

/**
 * @brief Encode a sensor_head_command struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sensor_head_command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_head_command_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sensor_head_command_t* sensor_head_command)
{
	return mavlink_msg_sensor_head_command_pack(system_id, component_id, msg, sensor_head_command->aileron, sensor_head_command->elevator, sensor_head_command->throttle, sensor_head_command->rudder);
}

/**
 * @brief Encode a sensor_head_command struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sensor_head_command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_head_command_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sensor_head_command_t* sensor_head_command)
{
	return mavlink_msg_sensor_head_command_pack_chan(system_id, component_id, chan, msg, sensor_head_command->aileron, sensor_head_command->elevator, sensor_head_command->throttle, sensor_head_command->rudder);
}

/**
 * @brief Send a sensor_head_command message
 * @param chan MAVLink channel to send the message
 *
 * @param aileron Aileron command, 0 to 65535
 * @param elevator Elevator command, 0 to 65535
 * @param throttle Throttle command, 0 to 65535
 * @param rudder Rudder command, 0 to 65535
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sensor_head_command_send(mavlink_channel_t chan, uint16_t aileron, uint16_t elevator, uint16_t throttle, uint16_t rudder)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN];
	_mav_put_uint16_t(buf, 0, aileron);
	_mav_put_uint16_t(buf, 2, elevator);
	_mav_put_uint16_t(buf, 4, throttle);
	_mav_put_uint16_t(buf, 6, rudder);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND, buf, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND, buf, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN);
#endif
#else
	mavlink_sensor_head_command_t packet;
	packet.aileron = aileron;
	packet.elevator = elevator;
	packet.throttle = throttle;
	packet.rudder = rudder;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND, (const char *)&packet, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND, (const char *)&packet, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sensor_head_command_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t aileron, uint16_t elevator, uint16_t throttle, uint16_t rudder)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint16_t(buf, 0, aileron);
	_mav_put_uint16_t(buf, 2, elevator);
	_mav_put_uint16_t(buf, 4, throttle);
	_mav_put_uint16_t(buf, 6, rudder);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND, buf, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND, buf, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN);
#endif
#else
	mavlink_sensor_head_command_t *packet = (mavlink_sensor_head_command_t *)msgbuf;
	packet->aileron = aileron;
	packet->elevator = elevator;
	packet->throttle = throttle;
	packet->rudder = rudder;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND, (const char *)packet, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND, (const char *)packet, MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE SENSOR_HEAD_COMMAND UNPACKING


/**
 * @brief Get field aileron from sensor_head_command message
 *
 * @return Aileron command, 0 to 65535
 */
static inline uint16_t mavlink_msg_sensor_head_command_get_aileron(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field elevator from sensor_head_command message
 *
 * @return Elevator command, 0 to 65535
 */
static inline uint16_t mavlink_msg_sensor_head_command_get_elevator(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field throttle from sensor_head_command message
 *
 * @return Throttle command, 0 to 65535
 */
static inline uint16_t mavlink_msg_sensor_head_command_get_throttle(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field rudder from sensor_head_command message
 *
 * @return Rudder command, 0 to 65535
 */
static inline uint16_t mavlink_msg_sensor_head_command_get_rudder(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Decode a sensor_head_command message into a struct
 *
 * @param msg The message to decode
 * @param sensor_head_command C-struct to decode the message contents into
 */
static inline void mavlink_msg_sensor_head_command_decode(const mavlink_message_t* msg, mavlink_sensor_head_command_t* sensor_head_command)
{
#if MAVLINK_NEED_BYTE_SWAP
	sensor_head_command->aileron = mavlink_msg_sensor_head_command_get_aileron(msg);
	sensor_head_command->elevator = mavlink_msg_sensor_head_command_get_elevator(msg);
	sensor_head_command->throttle = mavlink_msg_sensor_head_command_get_throttle(msg);
	sensor_head_command->rudder = mavlink_msg_sensor_head_command_get_rudder(msg);
#else
	memcpy(sensor_head_command, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN);
#endif
}
