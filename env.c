#include "main.h"
/**
* populate_env - populates the environ of info_t
* @info: pointer to info_t instance
* @envp: environment
*
* Return: return 1 or crash
*/
int populate_env(info_t *info, char **envp)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; envp[i]; i++)
		add_node_end(&node, envp[i], i);

	info->env = node;

	return (1);
}
/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	char *buf = NULL;
	list_t *node = info->env;

	buf = malloc(_strlen(name) + 2);
	if (buf == NULL)
		return (NULL);

	_strcpy(buf, name);
	_strcat(buf, "=");

	while (node)
	{
		if (starts_with(node->str, buf))
		{
			free(buf);
			return (extract_value(node->str));
		}
		node = node->next;
	}

	return (NULL);
}

/**
* _setenv - Initialize a new environment variable,
*             or modify an existing one
* @info: Structure containing potential arguments
* @var: String env property-name
* @value: env value
*  Return:  0
*/
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	unsigned int node_count = 0;

	if (!var || !value)
		return (1);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (buf == NULL)
		return (1);

	node = info->env;
	_strcpy(buf, var);
	_strcat(buf, "=");
	while (node)
	{

		if (starts_with(node->str, buf))
		{
			_strcat(buf, value);

			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
		node_count++;
	}

	_strcat(buf, value);
	add_node_end(&(info->env), buf, node_count);
	free(buf);
	info->env_changed = 1;

	return (0);
}
/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @index: node index
 *
 * Return: last node inserted
 */
list_t *add_node_end(list_t **head, const char *str, int index)
{
	list_t *new_node, *temp;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		exit(1);

	if (str)
		new_node->str = _strdup(str);
	else
		new_node->str = NULL;

	new_node->index = index;
	new_node->next = NULL;

	temp = *head;
	if (temp == NULL)
		*head = new_node;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}

	return (new_node);
}

/**
* print_list - print the strings in a list_t
* @list: list head
*
* Description: Useful for printing environment variable
* in env command
*/
void print_list(list_t *list)
{

	list_t *temp;

	temp = list;
	while (temp->next != NULL)
	{
		write_stringz(temp->str);
		write_stringz("\n");
		temp = temp->next;
	}
}
