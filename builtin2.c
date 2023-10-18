#include "shell.h"

/**
 * evoke_builtin_cd - change directory
 * @d: data struct input
 * Return: void
 */
void evoke_builtin_cd(vandata *d)
{
	char *dir_tory = d->av[1];
	char str[256];

	if (getcwd(str, sizeof(str)) == NULL)
		perror("getcwd() error");
	_set_envi(d, "PWD", str);
	if (!dir_tory)
		dir_tory = recall_envi("HOME");
	if (chdir(dir_tory) == -1)
		perror("cd");
	else
	{
		_set_envi(d, "OLDPWD", recall_envi("PWD"));
		if (getcwd(str, sizeof(str)) == NULL)
			perror("getcwd() error");
		_set_envi(d, "PWD", str);
	}
}

