#ifndef __INPUT_H__
#define __INPUT_H__

#include <unistd.h>
#include <termios.h>

int getch(void) {
	char buf = 0;
	struct termios terminal_setting = {0};
	tcgetattr(0, &terminal_setting);
	terminal_setting.c_lflag &= ~ICANON;
	terminal_setting.c_lflag &= ~ECHO;
	terminal_setting.c_cc[VMIN] = 0;
	terminal_setting.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &terminal_setting);
	read(0, &buf, 1);
	return buf;
}
#endif