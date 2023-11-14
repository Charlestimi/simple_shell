#include "shell_main.h"

/**
 * _strlen - Function that returns the length of a string
 * @s: string
 *
 * Return: length of string
 */

int _strlen(const char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}


/**
 * _strcpy - Function that copies the string pointed to by 'src',
 * including the terminating null byte (\0),
 * to the buffer pointed to by 'dest'.
 * @dest: destination buffer
 * @src: source buffer
 *
 * Return: the pointer to 'dest'
 */

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}


/**
 * _strcat - This function concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: a pointer to the resulting string (dest)
 */

char *_strcat(char *dest, const char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}


/**
 * _strcmp - This function compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if s1 and s2 is equal
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}

	if (*s1  == '\0' && *s2 != '\0')
		return (-1);
	else if (*s1 != '\0' && *s2 == '\0')
		return (1);
	else
		return (0);
}


/**
 * _strchr - This function locates a character in a string
 * @s: string
 * @c: character
 *
 * Return: s if character is  matched
 * or NULL if character is not found
 */

char *_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);

		s++;
	}

	if (c == '\0')
		return ((char *)s);

	return (NULL);
}
