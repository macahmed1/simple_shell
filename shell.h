#ifndef SHELL_H
#define SHELL_H


#define PROMPT "#van_shell$ "

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>

extern char **environ;

/**
 * struct vandata -  struct to holds main input.
 * @av: Array array tokenizer to hold all execution
 * @cmd: The user input, the command line
 * @_shell: the name of my shell (van_shell).
 * @_lastExitStat: last command entered before exiting shell
 * @_flag_setenv: flag shell when user enter a command setenv
 */
typedef struct vandata
{
	char **av;
	char *cmd;
	const char *_shell;
	int _lastExitStat;
	int _flag_setenv;
} vandata;

/**
 * struct item_listener - holds the main data.
 * @cmd: built in cmd
 * @f: function of builtin cmd
 */
typedef struct item_listener
{
	const char *cmd;
	void (*f)(vandata *d);
} item_listener;

/* builtin.c */
int evoke_builtin(vandata *d);
void evoke_builtin_exit(vandata *d);
void evoke_builtin_env(vandata *d);
void evoke_builtin_setenv(vandata *d);
void evoke_builtin_unsetenv(vandata *d);
void evoke_builtin_cd(vandata *d);

/* addons.c */
void print_txt(const char *usr_message);
void _free_array(char **arr);
void split_txt(vandata *d, const char *delim);
void initial_data(vandata *d, const char *shell_name);
void read_user_cmd(vandata *d);

/* addons2.c */
void _print_error(const char *str1, const char *str2);
void trim_txt(char *str);
void *_realloc(void *ptr, unsigned int new_size);

/* evoke.c */
void begin_procs(vandata *d);
void _signal_handler(int sig);
void evoke_cmd(vandata *d);

/* file_path.c */
char *recall_envi(char *cmd);
int _find(vandata *d);
char *_cr_new_ent(char *cmd, char *result);
char **newEnviron(char *cmd, char *result);
int _set_envi(vandata *d, char *cmd, char *result);

/* string_utils.c */
unsigned int _strlen(char *str);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, int n);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);


/* string_utils2.c */
char *_strdup(const char *str);
int _isnumber(const char *status);
int _isdigit(int c);

/* get_userdata.c */
#define READ_BUF_SIZE 1024
int get_user_assist(char **_line_ptr, size_t *n);
ssize_t get_userdata(char **_line_ptr, size_t *n, FILE *stream);

#endif

