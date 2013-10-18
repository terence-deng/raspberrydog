#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>

#define GPIO_SHUTDOWN_CONTROL 0
#define GPIO_SHUTDOWN_SIGNAL 1

void do_shutdown()
{
	printf ("Shuting down.\n");
	// TODO: execute shutdown -h 0
	//execl ("/sbin/shutdown", "-h", "-t 3", "now", (char *) NULL);
	execl ("/sbin/halt", "-p", (char *) NULL);
	//execl ("/sbin/init", 0,  (char *) NULL);
}

void init_gpio_pins()
{
	// set GPIO_SHUTDOWN_CONTROL as OUTPUT mode, HIGH
	pinMode (GPIO_SHUTDOWN_CONTROL, OUTPUT);
	digitalWrite (GPIO_SHUTDOWN_CONTROL, HIGH);

	// set GPIO_SHUTDOWN_SIGNAL as INPUT mode
	pinMode (GPIO_SHUTDOWN_SIGNAL, INPUT);
}

int get_shutdown_signal()
{
	if(digitalRead (GPIO_SHUTDOWN_SIGNAL) == HIGH){
		printf ("Shutdown signal received.\n");
		return 1;
	}
	return 0;
}

int main ()
{
	wiringPiSetup();

	init_gpio_pins();

	while(1){
		if ( get_shutdown_signal() ) {
			do_shutdown();
			//return 0;
		}
	//	printf ("Sleep for 1 s.\n");
		sleep (1);
	}
	return 1;
}
