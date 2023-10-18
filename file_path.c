#include "shell.h"

/**
 * recall_envi - recollect environmental input.
 * @cmd: user's input message to be considered.
 * Return: return the product of the environment.
 */

char *recall_envi(char *cmd)
{
	int n = -1;
	size_t _lenofName;

	if (cmd == NULL || *cmd == '\0')
		return (NULL);
	if (environ == NULL)
		return (NULL);

	_lenofName = _strlen(cmd);

	while (environ[++n])
	{
		if (!_strncmp(environ[n], cmd, _lenofName) && environ[n][_lenofName] == '=')
		{
			return (environ[n] + _lenofName + 1);
		}
	}
	return (NULL);
}

/**
 * _find - find the executable entered assosiated with usr cmd.
 * @d: user data to be found.
 * Return: the product of the search.
 */
int _find(vandata *d)
{
	char *_token, *_path,
		*pa_ths = malloc(_strlen(recall_envi("PATH") ?
		recall_envi("PATH") : "") + 1);
	size_t _lenofToken;
	int _find_it = -1;

	if (!recall_envi("PATH"))
		goto step_out;
	_strcpy(pa_ths, recall_envi("PATH"));
	if (pa_ths == NULL)
		goto step_out;
	_token = strtok(pa_ths, ":");
	while (_token)
	{
		_lenofToken = _strlen(_token) + _strlen(d->av[0]) + 2;
		_path = malloc(_lenofToken);
		if (_path == NULL)
			return (_find_it);
		_strcpy(_path, _token);
		_strcat(_path, "/");
		_strcat(_path, d->av[0]);
		if (access(_path, F_OK) == 0)
		{
			free(d->av[0]);
			d->av[0] = _strdup(_path);
			free(_path);
			_find_it = 0;
			break;
		}
		free(_path);
		_token = strtok(NULL, ":");
	}
step_out:
	free(pa_ths);
	return (_find_it);
}

/**
 * _cr_new_ent - start new process, or modify the old one.
 * @cmd: name of the variable to be created.
 * @result: value of the variable created.
 * Return: return Nothing.
 */
char *_cr_new_ent(char *cmd, char *result)
{
	size_t _nlen = strlen(cmd) + strlen(result) + 2;
	char *new_data = malloc(_nlen);

	if (new_data == NULL)
		return (NULL);

	strcpy(new_data, cmd);
	strcat(new_data, "=");
	strcat(new_data, result);

	return (new_data);
}
/**
 * newEnviron - Initialize a new environment variable or modify an existing one
 * @cmd: name of the instance
 * @result: value of the instance.
 * Return: return results of the pointer
 */
char **newEnviron(char *cmd, char *result)
{
	int _lenofEnv = 0, i = 0;
	char *_n_entry;
	char **_new_envi;

	while (environ[_lenofEnv])
		_lenofEnv++;
	_n_entry = _cr_new_ent(cmd, result);
	if (_n_entry == NULL)
		return (NULL);
	_new_envi = recall_envi(cmd) ? malloc((_lenofEnv + 1) * sizeof(char *))
								: malloc((_lenofEnv + 2) * sizeof(char *));

	if (!_new_envi)
	{
		free(_n_entry);
		return (NULL);
	}
	for (i = 0; environ[i]; i++)
	{
		_new_envi[i] = malloc(strlen(environ[i]) + 1);
		if (!_new_envi[i])
		{
			_free_array(_new_envi);
			free(_n_entry);
			return (NULL);
		}
		if (strncmp(environ[i], cmd, strlen(cmd)) == 0
		&& environ[i][strlen(cmd)] == '=')
			strcpy(_new_envi[i], _n_entry);
		else
			strcpy(_new_envi[i], environ[i]);
	}
	if (!recall_envi(cmd))
	{
		_new_envi[_lenofEnv] = _n_entry;
		_new_envi[_lenofEnv + 1] = NULL;
	}
	else
		_new_envi[_lenofEnv] = NULL;
	return (_new_envi);
}

/**
 * _set_envi - start a new environmental instance, or modify an existing one
 * @d: struct being used as flag
 * @cmd: name of the new instance
 * @result: value of the new instance
 * Return: return the result of the pointer.
 */
int _set_envi(vandata *d, char *cmd, char *result)
{
	char **_new_envi;

	if (!cmd || !result)
		return (-1);

	_new_envi = newEnviron(cmd, result);
	if (!_new_envi)
		return (-1);
	environ = _new_envi;
	d->_flag_setenv = 1;

	return (0);
}

