#include "main.h"

/**
 *get_width - function that calculates the width for printing
 *@format: string that represents the formatted string to be printed
 *@i: a pointer to an integer representing the index
 *@list: object that contains the arguments.
 *
 *Return: width
 */

int get_width(const char *format, int *i, va_list list)
{
	int currentIndex;
	int width = 0;

	for (currentIndex = *i + 1; format[currentIndex] != '\0'; currentIndex++)
	{
		if (is_digit(format[currentIndex]))
		{
			width *= 10;
			width += format[currentIndex] - '\0';
		}
		else if (format[currentIndex] == '*')
		{
			currentIndex++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = currentIndex - 1;

	return (width);
}
