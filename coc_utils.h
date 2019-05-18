/* This is the protocol for COC project
Coffee over coffee

every command must be over 60 bits  aka 8 bytes at lest

*/
#ifndef COC_UTILS_H
#define COC_UTILS_H

#include "stdint.h"
#include "stddef.h"

#define BYTE_TIME	100
#define MIN_PACKET_SIZE	8

typedef struct coffee_struct {
	uint8_t length;
	uint8_t temp;
	uint8_t random_shit_i_just_wanted_to_send_over_coffee;
} coffee_t;


int create_packet(coffee_t coffee);

#endif /* COC_UTILS_H */
