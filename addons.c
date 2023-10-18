#include "shell.h"

/**
 * print_txt - print user entered message from standard output
 * @usr_message: message input
 * Return: return Nothing.
 */
void print_txt(const char *usr_message)
{
	if (!usr_message)
		return;
	else if (*usr_message)
	{
		write(STDOUT_FILENO, usr_message, strlen(usr_message));
	}
}

/**
 * _free_array - free array to a pointer
 * @arr: array to ptn.
 * Return: return Nothing.
 */
void _free_array(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr);
}

/**
 * split_txt - split string and parse
 * @d: structure input
 * @delim: user input
 * Return: return Nothing
 */
void split_txt(vandata *d, const char *delim)
{
	char *token;
	int ntoken = 0;

	d->av = malloc(2 * sizeof(char *));
	if (d->av == NULL)
	{
		free(d->cmd);
		perror(d->_shell);
		exit(EXIT_FAILURE);
	}
	d->av[0] = NULL;
	d->av[1] = NULL;

	token = strtok(d->cmd, delim);
	while (token)
	{
		d->av = realloc(d->av, (ntoken + 2) * sizeof(char *));
		if (d->av == NULL)
			goto free;
		d->av[ntoken] = _strdup(token);
		if (d->av[ntoken] == NULL)
			goto free;
		ntoken++;
		token = strtok(NULL, delim);
	}
	d->av[ntoken] = NULL;
	return;
free:
	_free_array(d->av);
	free(d->cmd);
	perror(d->_shell);
	exit(EXIT_FAILURE);
}

/**
 * initial_data - initial input
 * @d: structure input
 * @shell_name: user input
 * Return: Nothing
 */

void initial_data(vandata *d, const char *shell_name)
{
	d->cmd = NULL;
	d->av = NULL;
	d->_shell = shell_name;
	d->_lastExitStat = EXIT_SUCCESS;
	d->_flag_setenv = 0;
}

/**
 * read_user_cmd - get user command int struct
 * @d: structure input
 * Return: return Nothing
 */
void read_user_cmd(vandata *d)
{
	size_t n = 0;
	ssize_t nread;
	int i = 0;

	nread = get_userdata(&d->cmd, &n, stdin);

	if (nread == -1)
	{
		free(d->cmd);
		exit(EXIT_SUCCESS);
	}

	d->cmd[nread - 1] = '\0';
	trim_txt(d->cmd);
	/* replace hashtag with end of line we can also do it with strtok*/
	for (i = 0; d->cmd[i] != '\0'; i++)
	{
		if (d->cmd[0] == '#' || (d->cmd[i] == '#' && d->cmd[i - 1] == ' '))
		{
			d->cmd[i] = '\0';
			break;
		}
	}
	trim_txt(d->cmd);
}

