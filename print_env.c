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


/**
 * _setenv - This function sets an environment variable
 * @var_name: name of variable
 * @value: the value to set the environment variable to
 * @overwrite: overwrites existing variable if its non-zero
 *
 * Return: 0 on success, -1 on failure
 */

int _setenv(const char *var_name, const char *value, int overwrite)
{
	char *env_var;

	(void)overwrite;

	if (var_name == NULL || value == NULL)
	{
		perror("Invalid arguments for setenv\n");
		return (-1);
	}


	env_var = malloc(_strlen(var_name) + _strlen(value) + 2);
	if (env_var == NULL)
	{
		perror("Error allocating memory");
		return (-1);
	}
	_strcpy(env_var, var_name);
	_strcat(env_var, "=");
	_strcat(env_var, value);

	if (putenv(env_var) != 0)
	{
		perror("Failed to set environment variable\n");
		free(env_var);
		return (-1);
	}

	return (0);
}


/**
 * _unsetenv - This function unsets an environment variable
 * @var_name: name of variable
 *
 * Return: 0 on success, -1 on failure
 */

int _unsetenv(const char *var_name)
{

	if (var_name == NULL)
	{
		perror("Invalid argument for unsetenv\n");
		return (-1);
	}

	if (unsetenv(var_name) != 0)
	{
		perror("Failed to unset environment variable\n");
		return (-1);
	}

	return (0);
}


/**
 * _getenv - gets an environment variable.
 * @nom: variable name.
 *
 * Return: returns pointer to value in environment or NULL if not found.
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
