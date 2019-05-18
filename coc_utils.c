#include "coc_utils.h"
#include <stddef.h>

void send_byte(uint8_t is_byte)
{
	if (is_byte == 1) {
		/* Do magic */

	}
	delay(BYTE_TIME);
}



int encode_data(uint8_t* packet, size_t packet_length, coffee_t coffee)
{
	if (packet_length <= MIN_PACKET_SIZE) {
		return 1;
	}
	packet[0] = coffee.length;
	packet[1] = coffee.temp;
	packet[1] = coffee.random_shit_i_just_wanted_to_send_over_coffee;
	return 0;
}


void send_packet(uint8_t* packet, size_t packet_length)
{
	size_t i;
	size_t j;
	uint8_t temp;
	for (i = 0; i < packet_length; i++) {
		for (j = 0; j <= 8; j++) {
			temp = packet[i] >> j;
			temp = temp & 0x1;
			send_byte(temp);
		}
	}
}

int create_packet(coffee_t coffee)
{
	uint8_t packet[MIN_PACKET_SIZE] = {0};
	size_t packet_length = MIN_PACKET_SIZE;

	/* Encode the data to a packet */
	if (encode_data(packet, packet_length, coffee) != 0)
		return 1;
	/* Encrypt the data */

	/* Send data */
	send_packet(packet, packet_length);

}
