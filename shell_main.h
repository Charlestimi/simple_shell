#ifndef _SHELL_MAIN_H_
#define _SHELL_MAIN_H_


#define BUFFER_SIZE 1024
#define MAX_CMD_COUNT 64


/* Header files */
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdarg.h>
#include <limits.h>
#include <malloc.h>
#include <stddef.h>


extern char **environ;


/* Prototypes for custom printing functions */
int _putchar(char c);
void our_printf(char *str);



/* Prototypes for utility functions */
int _atoi(const char *s);
char *_strdup(char *str);
int _strlen(const char *s);
char *_getenv(const char *nom);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *str_concat(char *s1, char *s2);
char *_strchr(const char *s, char c);
char *_strtok(char *str, const char *delim);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
char *_memcpy(char *dest, char *src, unsigned int n);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _strncmp(const char *str1, const char *str2, size_t n);



/* Prototypes for helping functions */
void cleanup(char **cmd, int count);
int _delim(char c, const char *delim);



/* Function prototypes */
void blinking_prompt(void);
void print_env(char **environ);
void handle_cd(const char *dir);
void exit_shell(const char *status);
int _unsetenv(const char *var_name);
void exec_user_input(char *user_input);
void handle_path(char **cmd, int count);
void read_user_input(char *user_input, size_t len);
int _setenv(const char *var_name, const char *value, int overwrite);



#endif
