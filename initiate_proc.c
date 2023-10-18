#include "shell.h"

/**
 * _signal_handler - Handle signials here in this func.
 * @signal: initial input to be considered
 * Return: return Nothing.
 */

void _signal_handler(int signal)
{
	/*const char prompt[] = PROMPT;*/
	(void)signal;
	exit(EXIT_FAILURE);
	/*_printf(prompt);*/
}

/**
 * begin_procs - begin a session in shell.
 * @d: Data structure
 * Return: return Nothing
 */

void begin_procs(vandata *d)
{
	pid_t _ch_pid = fork();
	int stats = 0;

	if (_ch_pid == -1)
		goto free;
	if (_ch_pid == 0 && execve(d->av[0], d->av, NULL) == -1)
		goto free;
	else if (wait(&stats) == -1)
		goto free;
	if (WIFEXITED(stats))
		d->_lastExitStat = WEXITSTATUS(stats);
	return;
free:
	perror(d->_shell);
	_free_array(d->av);
	free(d->cmd);
	exit(EXIT_FAILURE);
}

