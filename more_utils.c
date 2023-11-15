#include "shell_main.h"

/**
 * _strdup - This function creates returns a pointer
 * to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: string to duplicate
 *
 * Return: pointer to the copied string if successful, else NULL
 */

char *_strdup(char *str)
{
	char *d;
	unsigned int i = 0;
	unsigned int j = 0;

	if (str == NULL)
		return (NULL);

	while (str[j])
		j++;

	d = (char *)malloc((j + 1) * sizeof(char));

	if (d == NULL)
		return (NULL);

	while ((d[i] = str[i]) != '\0')
		i++;

	return (d);
}


/**
 * str_concat - This function concatenates two strings
 * @s1: string one
 * @s2: string two
 *
 * Return: pointer to allocated memory if successful, else NULL
 */

char *str_concat(char *s1, char *s2)
{
	char *s;
	unsigned int i = 0, j = 0, strl1 = 0, strl2 = 0;

	while (s1 && s1[strl1] != '\0')
		strl1++;

	while (s2 &&  s2[strl2] != '\0')
		strl2++;

	s = (char *)malloc((strl1 + strl2 + 1) * sizeof(char));

	if (s == NULL)
		return (NULL);

	if (s1)
	{
		for (; i < strl1; i++)
			s[i] = s1[i];
	}

	if (s2)
	{
		for (; i < (strl1 + strl2); i++, j++)
			s[i] = s2[j];
	}

	s[i] = '\0';

	return (s);
}


/**
 * _atoi - Function that converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */

int _atoi(const char *s)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
		sign = (s[i++] == '-') ? -1 : 1;
	while (_isdigit(s[i]))
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (sign * result);
}


/**
 * _delim - This function checks if a given character is a delimiter
 * @c: character to check
 * @delim: string of delimiters
 *
 * Return: 1 if character is found, otherwise 0
 */

int _delim(char c, const char *delim)
{
	while (*delim)
	{
		if (*delim++ == c)
			return (1);
	}

	return (0);
}


/**
 * _strtok - This function tokenizes a string
 * @str: string to tokenize
 * @delim: string of delimiters
 *
 * Return: the starting position of the token
 */

char *_strtok(char *str, const char *delim)
{
	static char *input;
	char *tok_start;

	if (str != NULL)
		input = str;
	else if (input == NULL)
		return (NULL);

	while (*input != '\0' && _delim(*input, delim))
		input++;

	if (*input == '\0')
	{
		input = NULL;
		return (NULL);
	}

	tok_start = input;

	while (*input != '\0' && !_delim(*input, delim))
		input++;

	if (*input != '\0')
		*input++ = '\0';

	return (tok_start);
}

