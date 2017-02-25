#ifndef _GETCH_
#define _GETCH_

#include<unistd.h>
#include<termios.h>
#include<stdio.h>

int getch()
{
	int c;
	struct termios a, b;
	tcgetattr(STDIN_FILENO, &a);
	tcgetattr(STDIN_FILENO, &b);
	a.c_lflag &= ~(ECHO | ICANON | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
	tcsetattr(STDIN_FILENO, TCSANOW, &a);
	c = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &b);

	return c;
}

#endif
