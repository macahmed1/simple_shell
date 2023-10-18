#include "shell.h"
/**
 * _strdup - a ptr to a new allocated space in memory, contain a cp of the str.
 * @str: user string inputted.
 * Return: return a pointer to string
 */

char *_strdup(const char *str)
{
	int len_str = 0, i;
	char *product;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[len_str] != '\0')
	{
		len_str++;
	}
	product = (char *)malloc((len_str + 1) * sizeof(char));
	if (product == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= len_str; i++)
	{
		product[i] = str[i];
	}
	return (product);
}

/**
 * _isnumber - check if a string is a number
 * @status: string to be checked
 * Return: return an integer.
 */
int _isnumber(const char *status)
{
	if (status == NULL || status[0] == '\0')
		return (0);
	while (*status)
	{
		if (!_isdigit(*status))
			return (0);
		status++;
	}
	return (1);
}

/**
 * _isdigit - checks for a digit (0 through 9)
 * @c: int to be checked
 * Return: 1 if c is true, 0 if false
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

