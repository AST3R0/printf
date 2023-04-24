#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Print function
 * @fomrat: format.
 * Return: Printed char.
 */
int _printf(const char *fomrat, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (fomrat == NULL)
		return (-1);
	va_start(list, fomrat);
	for (i = 0; fomrat && fomrat[i] != '\0'; i++)
	{
		if (fomrat[i] != '%')
		{
			buffer[buff_ind++] = fomrat[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(fomrat, &i);
			width = get_width(fomrat, &i, list);
			precision = get_precision(fomrat, &i, list);
			size = get_size(fomrat, &i);
			++i;
			printed = handle_print(fomrat, &i, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist.
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, reprensent the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
