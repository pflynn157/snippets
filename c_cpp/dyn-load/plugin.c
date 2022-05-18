#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void start()
{
	puts("Welcome to the plugin!");
}

void print(char *str)
{
	printf("%s\n", str);
}

void func(const char *fmt,...)
{
	va_list args;
	va_start(args, fmt);
	
	if (strcmp(fmt, "print") == 0) {
		puts("Print!");
	} else if (strcmp(fmt, "print_int") == 0) {
		puts("Print integer!");
		int i = va_arg(args, int);
		printf("The INT: %d\n", i);
	} else if (strcmp(fmt, "print_float") == 0) {
		puts("Print float!");
	}
	
	va_end(args);
}
