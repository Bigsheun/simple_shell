#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

/*extern char **environ;*/

/**
* struct list_str - singly linked list
* @index: index of environment
* @str: a string
* @next: pointer to the next node
*/
typedef struct list_str
{
	int index;
	char *str;
	struct list_str *next;
} list_t;

/**
* struct passinfo - contains pseudo-arguements to pass into a function,
* allowing uniform prototype for function pointer struct
*
* @arg: a string generated from getline containing arguements
* @argv: an array of strings generated from arg
* @path: a string path for the current command
* @argc: the argument count
* @line_count: the error count
* @err_num: the error code for exit()s
* @linecount_flag: if on count this line of input
* @fname: the program filename
* @env: linked list local copy of environ
* @history: the history node
* @alias: the alias node
* @env_changed: on if environ was changed
* @status: the return status of the last exec'd command
* @cmd_buf: address of pointer to cmd_buf, on if chaining
* @cmd_buf_type: CMD_type ||, &&, ;
* @readfd: the fd from which to read line input
* @histcount: the history line number count
*/


typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, 0, 0, \
NULL, 0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/*simple_shell.c*/
size_t get_line(char **lineptr, size_t *count, FILE *fd);
void show_prompt(void);
size_t get_line(char **lineptr, size_t *count, FILE *fd);

/*inbuilt_cmd*/
builtin_table *get_builtin_cmd_tbl();
short is_inbuilt(char *cmd);
int perform_inbuilt_cmd(info_t *info);

/*inbuilt_cmd2*/
int _myexit(info_t *);
int _mycd(info_t *);
int _myenv(info_t *);
int _mypwd(info_t *);

/*string_utils1.c*/
int _strcmp(char *src, char *dst);
void str_replace(char *s, char find, char replace);
int starts_with(const char *haystack, const char *needle);
char *str_dup(const char *);

/*string_utils2*/
int _strlen(const char *s);
char *_strcpy(char *, const char *);
char *_strcat(char *dst, const char *src);

/*arg_parse.c*/
short found_in(char c, char *s);
int wordstart(char *str, char *delims, int index);
int delimstart(char *str, char *delims, int index);
int wordcount(char *str, char *delims);
char **split_arg(char *arg, char *delims);

/*outputs.c*/
void write_stringz(char *s);
void write_strz_array(char **sa);
unsigned int s_array_len(char **arr);

/*env.c - env2.c*/
int populate_env(info_t *info, char const **envp);
list_t *add_node_end(list_t **head, const char *str, int index);
void print_list(list_t *list);
char *_getenv(info_t *info, const char *name);
char *extract_name(char *env_str);
char *extract_value(char *env_str);
int _setenv(info_t *info, char *var, char *value);
int _mysetenv(info_t *info);
int _mygetenv(info_t *info);

/*errors.c*/
void _eputs(char *);
int _eputchar(char);
void eprint_number(int n);

/*paths.c*/
char *get_absolute_path(info_t *info, char *p);
char *parent_dir(char *dir);
char *path_join(char *p1, char *p2);

int perform_external_cmd(info_t *info, char **envp);
#ifdef _WIN32
size_t getline(char **lineptr, size_t *n, FILE *stream);
unsigned int getppid(void);
int fork(void);
#endif

#endif
