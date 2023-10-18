#include "shell.h"

/**
 * _strlen - return the length of the char string entered
 * @str: get input from stream.
 * Return: return an integer.
 */

unsigned int _strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strcmp - compare 2 strings
 * @s1: 1 placehold
 * @s2: 2 placehold
 * Return: return s1 and s2.
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strncmp - compares two distinct strings.
 * @s1: input const string
 * @s2: input const string
 * @n: input int
 *
 * Return: returns an integer
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{

		if (i >= n)
			break;
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}

/**
 * _strcpy - copy pointer
 * @dest: first variable
 * @src: second v.
 * Return: dest
 */

char *_strcpy(char *dest, const char *src)
{
	int len = 0;

	while (*(src + len) != '\0')
	{
		*(dest + len) = *(src + len);
			len++;
	}
	*(dest + len) = '\0';
return (dest);
}

/**
 * _strcat - concatenate 2 strings
 * @dest: first parameter
 * @src: 2 parameter
 * Return: return dest
 */

char *_strcat(char *dest, const char *src)
{
	int dlen = 0, i;

	while (dest[dlen])
	{
		dlen++;
	}
	for (i = 0; src[i] != 0; i++)
	{
		dest[dlen] = src[i];
		dlen++;
	}
	dest[dlen] = '\0';
	return (dest);
}

