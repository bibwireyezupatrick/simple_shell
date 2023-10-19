#include "shell.h"

/**
 * my_history - displays the history list.
 *           
 * @info: Structure containing potential arguments.
 *        
 *  Return: Always 0
 */
int my_history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *k, s;
	int ret;

	k = _strchr(str, '=');
	if (!k)
		return (1);
	s = *k;
	*k = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*k = s;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *k;

	k = _strchr(str, '=');
	if (!k)
		return (1);
	if (!*++k)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *k = NULL, *b = NULL;

	if (node)
	{
		k = _strchr(node->str, '=');
		for (b = node->str; b <= k; b++)
		_putchar(*b);
		_putchar('\'');
		_puts(k + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * my_alias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int my_alias(info_t *info)
{
	int v = 0;
	char *k = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (v = 1; info->argv[v]; v++)
	{
		k = _strchr(info->argv[v], '=');
		if (k)
			set_alias(info, info->argv[v]);
		else
			print_alias(node_starts_with(info->alias, info->argv[v], '='));
	}

	return (0);
}
