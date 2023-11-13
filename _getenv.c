#include "shell_main.h"


/**
 * _getenv - gets an environment variable.
 * @nom: variable name.
 *
 * Return: returns pointer to value in environment or NUll if not found.
 */

char *_getenv(const char *nom)
{
	char **envcpy, *cur_var;
	unsigned int len = _strlen(nom);

	envcpy = environ;
	while (*envcpy != NULL)
	{
		cur_var = *envcpy;

		if ((_strncmp(cur_var, nom, len) == 0) &&
				(cur_var[len] == '='))
		{
			return (cur_var + len + 1);
		}

		envcpy++;
	}

	return (NULL);
}
