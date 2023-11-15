#include "shell_main.h"


/**
 * _strncmp - This function compares two strings up to a specific length
 * @str1: string one
 * @str2: string two
 * @n: amount of bytes to compare
 *
 * Return: 0 if string two is found in string one.
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	int i = 0;

	while (n > 0)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		if ((str1[i] == '\0') || (str2[i] == '\0'))
			break;
		i++;
		n--;
	}

	return (0);
}


/**
 * _memcpy - This function copies memory area
 * @dest: destination
 * @src: source
 * @n: number of bytes to copy
 *
 * Return: a pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}


/**
 * _realloc - This function reallocates memory block using malloc and free
 * @ptr: pointer to the previoulsy allocated memory
 * @new_size: size of the new memory block
 *
 * Return: pointer to the newly allocated memory block
 */

void *_realloc(void *ptr, unsigned int new_size)
{
	size_t old_size;
	void *new_ptr;
	size_t copy_size;

	old_size = malloc_usable_size(ptr);

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_size));

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	copy_size = (new_size < old_size) ? new_size : old_size;
	_memcpy(new_ptr, ptr, copy_size);

	free(ptr);
	return (new_ptr);
}
