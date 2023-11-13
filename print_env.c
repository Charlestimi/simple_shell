#include "shell_main.h"

/**
 * print_env - This function handles the shell built-in 'env' command
 * @environ: environment variable
 *
 */

void print_env(char **environ)
{
	char **env = environ;

	for (; *env != NULL; env++)
		printf("%s\n", *env);
}
