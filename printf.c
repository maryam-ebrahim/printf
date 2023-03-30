#include "main.h"
#include <string.h>

ssize_t write(int fd, const void *buf, size_t count);

/**
 * _printf - a function that produces output according to a format
 * @format: a character string
 *
 * Return:  the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg_list;
	int i = 0;
	int j = 0;
	char buffer[100] = {0};
	char *format_arg;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(arg_list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				buffer[j] = (char)va_arg(arg_list, int);
				j++;
			}
			elif(format[i] == 's')
			{
				format_arg = va_arg(arg_list, char*);
				strcpy(&buffer[j], format_arg);
				j += strlen(format_arg);
			}
		}
		i++;
	}
	fwrite(buffer, j, 1, stdout);
	va_end(arg_list);
	return (j);
}
