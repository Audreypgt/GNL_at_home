/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeuget <audrey.peuget@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:16:53 by apeuget           #+#    #+#             */
/*   Updated: 2025/12/05 16:45:11 by apeuget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *str, ssize_t *len)
{
	char	*dup;
	char	*res;

	*len = 0;
	dup = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!dup)
		return (NULL);
	res = dup;
	while (*len < BUFFER_SIZE && str[*len])
	{
		dup[*len] = str[*len];
		*len += 1;
		if (*len && str[*len - 1] == '\n')
			break ;
	}
	dup[*len] = '\0';
	return (res);
}

int	ft_strlen_before_n(char *str)
{
	int	i;

	i = 0;
	while (!(str[i] == '\n' || str[i] == '\0'))
		i++;
	return (i);
}

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*nodeptr;

	count = 0;
	nodeptr = lst;
	while (nodeptr)
	{
		nodeptr = nodeptr -> next;
		count++;
	}
	return (count);
}

ssize_t	ft_lstnew(t_list **lst, char *buffer)
{
	t_list	*new;
	t_list	*temp;
	ssize_t	len;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	len = 0;
	new -> read_content = ft_strdup(buffer, &len);
	new -> next = NULL;
	if (lst && *lst)
	{
		temp = *lst;
		while (temp -> next)
			temp = temp -> next;
		temp -> next = new;
	}
	else if (lst && !*lst)
		*lst = new;
	return (len);
}

int	back_n_0_check(char *str, char c)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

// lst = adress of first node in list
// *lst = adress of content of node, first node itself
//first if : there is an existing node
// else if : the list exists, its adress, but not the node --> happens at first
// iteration of the function, when creating the list
