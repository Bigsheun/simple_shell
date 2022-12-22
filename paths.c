#include "main.h"
/**
* get_absolute_path - translates sybolic path
* @info: structure containts environ variables used
* @p: path to translate
*
* Return: absolute path representation
*/
char *get_absolute_path(info_t *info, char *p)
{
	char *tmp, *tmp2;

	if (starts_with(p, "/"))
		return (str_dup(p));
	else if (!_strcmp("..", p))
	{
		tmp = _getenv(info, "PWD");
		tmp2 = parent_dir(tmp);
		free(tmp);
		return (tmp2);
	}
	else if (!_strcmp("~", p))
		return (_getenv(info, "HOME"));
	else if(starts_with(p, "~/"))
	{
		tmp = _getenv(info, "HOME");
		tmp2 = path_join(tmp, p);
		free(tmp);
		return (tmp2);
	}
	else if(starts_with(p, "../"))
	{
		tmp2 = _getenv(info, "PWD");
		tmp = parent_dir(tmp2);
		free(tmp2);
		tmp2 = path_join(tmp, p + 1);
		free(tmp);
		return (tmp2);
	}
	else if(starts_with(p, "./"))
	{
		tmp = _getenv(info, "PWD");
		tmp2 = path_join(tmp, p);
		free(tmp);
		return (tmp2);
	}
	return (NULL);
}

/**
* parent_dir - converts string-path to parent string-path
* @dir: String representation of path
*
* Return: parent path
*/
char *parent_dir(char* dir)
{
	int last_index_of = -1, i;
	char *ret;

	for (i = 0; dir[i] != '\0'; ++i)
		if (dir[i] == '/')
			last_index_of = i;

	if (last_index_of == -1)
		last_index_of = i;

	ret = malloc(sizeof(char) * (last_index_of + 1));
	if (ret == NULL)
		exit(1);

	for (i = 0; i < last_index_of; i++)
		ret[i] = dir[i];

	ret[i] = '\0';

	return (ret);
}

/**
* path_join - join two path with '/'
* @p1: first
* @p2: second path
*
* Return: joined path
*/
char *path_join(char *p1, char *p2)
{
	int len;
	char *tmp2;

	len = _strlen(p1) + _strlen(p2);

	tmp2 = malloc(sizeof(char) * (len + 1));
	if (tmp2 == NULL)
		exit(1);

	_strcpy(tmp2, p1);
	_strcat(tmp2, "/");
	_strcat(tmp2, p2 + 2);

	return (tmp2);
}

