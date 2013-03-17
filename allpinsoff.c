///////////////////////////////////////////////////////////////////////
//
//	ALLPINSOFF.C				Written by: Adam Ickes
//
//	This program is intended for use only on a Raspberry Pi with the
//	wiringPi library installed. 
//
//
///////////////////////////////////////////////////////////////////////

#include <wiringPi.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define NUMBER_OF_PINS 8

int main() 
{
	//Start as a daemon
	if (daemon(0,0) != 0) {
	exit(1);
	}

	//Setup wiringPi
	if (wiringPiSetup() == -1) {
	exit(1);
	}
	
	//Set pins mode to out
	int i = 0;
	while (i <= NUMBER_OF_PINS){
		pinMode(i, OUTPUT);
		i = i + 1;
	}
	//Turn off pins
	i = 0;
	while (i <= NUMBER_OF_PINS){
		digitalWrite(i, 1);
		i = i + 1;
	}
		
	return 0;
}