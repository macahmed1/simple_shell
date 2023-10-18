#include "shell.h"

/**
 * evoke_builtin - check and evoke built-in functions
 * @d: stucture input
 * Return: regturn 1 if true, 0 if false
 */
int evoke_builtin(vandata *d)
{
	item_listener builtin[] = {
		{"exit", evoke_builtin_exit},
		{"env", evoke_builtin_env},
		{"setenv", evoke_builtin_setenv},
		{"unsetenv", evoke_builtin_unsetenv},
		{"cd", evoke_builtin_cd},
		{NULL, NULL},
	};
	int x = 0;

	for (x = 0; builtin[x].cmd; x++)
	{
		if (_strcmp(d->av[0], builtin[x].cmd) == 0)
		{
			builtin[x].f(d);
			return (1);
		}
	}
	return (0);
}

/**
 * evoke_builtin_exit - close the van_shell
 * @d: structure input
 * Return: return Nothing.
 */
void evoke_builtin_exit(vandata *d)
{
	const char *error_messg = "./hsh: 1: exit: Unaccepted number entered: ";

	if (d->av[1])
	{
		if (d->av[1][0] != '-' && _isnumber(d->av[1]))
			d->_lastExitStat = atoi(d->av[1]);
		else
		{
			write(STDERR_FILENO, error_messg, strlen(error_messg));
			write(STDERR_FILENO, d->av[1], strlen(d->av[1]));
			write(STDERR_FILENO, "\n", 1);
			d->_lastExitStat = 2;
		}
	}
	_free_array(d->av);
	free(d->cmd);
	if (d->_flag_setenv)
		_free_array(environ);
	exit(d->_lastExitStat);
}

/**
 * evoke_builtin_env - prints the working env
 * @d: structure input
 * Return: return Nothing.
 */
void evoke_builtin_env(vandata *d)
{
	int i;

	(void)d;
	for (i = 0; environ[i]; i++)
	{
		print_txt(environ[i]);
		print_txt("\n");
	}
}
/**
 * evoke_builtin_setenv - Initiate new env instance
 * @d: structure input
 * Return: return Nothing.
 */

void evoke_builtin_setenv(vandata *d)
{
	(void)d;
	if (d->av[1] && d->av[2])
	{
		if (_set_envi(d, d->av[1], d->av[2]) == -1)
		{
			perror("setenv");
		}
	}
}

/**
 * evoke_builtin_unsetenv - clear the old env viariable.
 * @d: structure input.
 * Return: return Nothing.
 */
void evoke_builtin_unsetenv(vandata *d)
{
	int i, j;
	int len_str;

	i = 0;
	(void)d;
	if (!d->av[1] || !getenv(d->av[1]))
	{
		_print_error(d->_shell, "Can't locate variable");
		return;
	}
	len_str = strlen(d->av[1]);
	while (environ[i])
	{
		if (strncmp(environ[i], d->av[1], len_str)
		== 0 && environ[i][len_str] == '=')
		{
			j = i;
			while (environ[j])
			{
				environ[j] = environ[j + 1];
				j++;
			}
		}
		i++;
	}
}

