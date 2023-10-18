#include "shell.h"

/**
 * evoke_cmd - evoke the command
 * @d: data structure
 * Return: return Nothing.
 */

void evoke_cmd(vandata *d)
{
	const char _prmpt[] = PROMPT;
	bool keep_running = true;

	signal(SIGINT, _signal_handler);

	while (keep_running)
	{
		if (isatty(STDIN_FILENO))
			print_txt(_prmpt);

		read_user_cmd(d);
		if (_strlen(d->cmd) != 0)
		{
			split_txt(d, " ");
			if (!evoke_builtin(d))
			{
				_find(d);
				if (access(d->av[0], F_OK) == -1)
				{
					perror(d->_shell);
				}
				else
				{
					begin_procs(d);
				}
			}
			_free_array(d->av);
		}
		free(d->cmd);
	}
}

