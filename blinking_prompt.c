#include "shell_main.h"

/**
 * blinking_prompt - This function prints the command/shell prompt to stdout
 *
 */

void blinking_prompt(void)
{
	char *buff;

	buff = getcwd(NULL, 0);

	if (isatty(STDIN_FILENO))
	{
		our_printf("TZesh:~€ ");
		fflush(stdout);
	}
	free(buff);
}
