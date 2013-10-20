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

#define GPIO_PIN_CONTROL 	0
#define GPIO_PIN_SHUTDOWN 	1
#define GPIO_PIN_REBOOT 	2
#define GPIO_PIN_RESERVED 	3
#define GPIO_PIN_UNUSED 	4

#define SIGNAL_NOACTION	0x00
#define SIGNAL_SHUTDOWN	0x01
#define SIGNAL_REBOOT	0x02
#define SIGNAL_RESERVED 0x03

void do_shutdown();
void do_reboot();
void init_gpio_pins();
int get_gpio_signal();
