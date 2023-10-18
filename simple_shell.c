#include "shell.h"

/**
 * main - main entry point of code
 * @argc: size of the user input @argv
 * @argv: input array of cmd line arguments
 * Return: Always return 0.
 */
int main(int argc, char **argv)
{
	vandata d;
	(void)argc;
	initial_data(&d, argv[0]);
	evoke_cmd(&d);

	return (0);
}

