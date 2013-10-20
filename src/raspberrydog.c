/*
The MIT License (MIT)

Copyright (c) 2013 Terence Deng (dengtooling@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>
#include "raspberrydog.h"

void do_shutdown()
{
	printf ("Shuting down.\n");
	execl ("/sbin/shutdown", "/sbin/shutdown", "-h", "now", (char *) NULL);
}

void do_reboot()
{
	printf ("Rebooting.\n");
	execl ("/sbin/shutdown", "/sbin/shutdown", "-r", "-F", "now", (char *) NULL);
}

void init_gpio_pins()
{
	// set GPIO_PIN_CONTROL as OUTPUT mode, HIGH
	pinMode (GPIO_PIN_CONTROL, OUTPUT);
	digitalWrite (GPIO_PIN_CONTROL, HIGH);

	// set pins as INPUT mode
	pinMode (GPIO_PIN_SHUTDOWN, INPUT);
	pinMode (GPIO_PIN_REBOOT, INPUT);
	pinMode (GPIO_PIN_RESERVED, INPUT);
	pinMode (GPIO_PIN_UNUSED, INPUT);
}

int get_gpio_signal()
{
	// TODO: refactor this function
	unsigned int result = 0x00;
	for (int i = 1; i <= 4; i ++){
		unsigned int temp = digitalRead (i);
		temp = temp << (i-1);
		result |= temp;
	}
	printf("gpio_signal is %d\n", result);
	return result;
}

int main (int argc, char **argv)
{
	wiringPiSetup();

	init_gpio_pins();

	while(1){

		int signal = get_gpio_signal();

		switch (signal)  {
			case SIGNAL_NOACTION:
				break;
			case SIGNAL_SHUTDOWN:
				printf ("Shutdown signal received.\n");
				do_shutdown();
				break;
			case SIGNAL_REBOOT:
				printf ("Reboot signal received.\n");
				do_reboot();
				break;
			default:
				printf ("Unkown signal received.\n");
				break;
		}
		// TODO: sleeping for 1 second is not a good idea.
		//printf ("Sleep for 1 s.\n");
		sleep (1);
	}
	return 1;
}
