#include <Stepper.h>
#include <SoftwareSerial.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
// SoftwareSerial softserial(3, 4);

int dirStep = 2;

#define BYTE_TIME	1000

void setup() {
	// initialize the serial port:
	Serial.begin(9600);
	myStepper.setSpeed(50);

	// softserial.begin(9600);
}


int flip = 1;
void send_bit() {
	flip = -flip;

	myStepper.step(57 * flip);
	// delay(1000);
}


void send_byte(int data) {
	int i = 0;
	int tmp = 0;
	for(i = 0; i <= 8; i++){
		tmp = data >> i;
		tmp &= 1;
		if (tmp) {
			send_bit();
		}
		delay(BYTE_TIME);
	}
}

void loop() {
	// int data = 0x55;
	// if (softserial.available()) {
		// data = SoftwareSerial.read();
		// send_byte(data);
	// }
	send_bit();
	delay(BYTE_TIME);

}
