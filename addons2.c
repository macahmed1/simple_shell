#include "shell.h"

/**
 * _print_error - print standard error
 * @str1: van_shell
 * @str2: special error message
 * Return: return Nothing
 */
void _print_error(const char *str1, const char *str2)
{
	if (!str1 || !str2)
		return;

	while (*str1)
	{
		write(STDERR_FILENO, str1, 1);
		str1++;
	}

	write(STDERR_FILENO, ": ", 2);

	while (*str2)
	{
		write(STDERR_FILENO, str2, 1);
		str2++;
	}
	write(STDERR_FILENO, "\n", 1);
}


/**
 * trim_txt - clean leading and trailing spaces from user input.
 * @str: string to be trimed
 * Return: return Nothing.
 */

void trim_txt(char *str)
{
	int i, j, len = _strlen(str);

	for (i = 0; i < len && (str[i] == ' ' || str[i] == '\t'); i++)
		;

	for (j = 0; i < len ; i++, j++)
		str[j] = str[i];

	str[j] = '\0';

	for (i = _strlen(str) - 1; i > 0 && (str[i] == ' ' || str[i] == '\t'); i--)
		str[i] = '\0';
}


/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr: void pointer
 * @new_size: size of the pointer
 *
 * Return: results of the pointer
 */
void *_realloc(void *ptr, unsigned int new_size)
{
	char *m;
	unsigned int i, temp, old_size;

	temp = new_size;
	old_size = sizeof(ptr);
	if (ptr == NULL)
		return (malloc(new_size));
	if (old_size == new_size)
		return (ptr);
	if (new_size > old_size)
	{
		temp = old_size;
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	m = malloc(new_size);

	for (i = 0; i < temp; i++)
		m[i] = ((char *)ptr)[i];
	free(ptr);
	return (m);
}

