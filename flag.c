#include "main.h"

/**
 * get_flag - Calculates active flags
 * @format: Formatted string in which to print the argument
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flag(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, current_index;
	int flags = 0;
	const char FLAG_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_index = *i + 1; format[current_index] != '\0'; current_index++)
	{
		for (j = 0; FLAG_CHAR[j] != '\0'; j++)
			if (format[current_index] == FLAG_CHAR[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		if (FLAG_CHAR[j] == 0)
			break;
	}
	*i = current_index - 1;
	return (flags);
}
