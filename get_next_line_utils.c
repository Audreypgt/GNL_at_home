/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeuget <audrey.peuget@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:16:53 by apeuget           #+#    #+#             */
/*   Updated: 2025/12/02 15:36:09 by apeuget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *str)
{
	char	*dup;
	char	*res;
	int		i;

	//printf("str parameter in ft strdup = %s\n", str);
	i = 0;
	dup = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!dup)
	{
		printf("dup malloc is NULL :(");
		return (NULL);
	}
	res = dup;
	while (i < BUFFER_SIZE)
	{
		//printf("I love to loop\n");
		dup[i] = str[i];
		i++;
	}
	//printf("dup of str in ft strdup = %s\n", res);
	dup[i] = '\0';
	return (res);
}

int	ft_strlen_before_n(char *str)
{
	int	i;

	i = 0;
	while (!(str[i] == '\n' || str[i] == '\0'))
	{
		i++;
	}
	//printf("strlen before n of last buffer = %i", i);
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
	//printf("lstsize = %i\n", count);
	return (count);
}

t_list	*ft_lstnew(t_list **lst, char *buffer)
{
	t_list	*new;
	t_list	*temp;

	//printf("creating new node\n");
	new = malloc(sizeof(t_list));
	if (!new)
	{
		printf("malloc lstnew is NULL\n");
		return (NULL);
	}
	new -> read_content = ft_strdup(buffer); // faire un malloc de read_content ?
	new -> next = NULL;
	//new -> len = line_len; //comment utiliser cette valeur ?
	if (lst && *lst)
	{
		temp = *lst;
		//printf("this is the next node\n");
		while (temp -> next)
		{
			//printf("in boucle\n");
			temp = temp -> next;
		}
		temp -> next = new;
	}
	else if (lst && !*lst)
	{
		*lst = new;
		//printf("first creation\n");
	}
	return (new);
}

int	back_n_0_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\0')
		{
			//printf("there's a back n\n");
			return (0);
		}
		i++;
	}
	//printf("there's no back n\n");
	return (1);
}

// lst = adress of first node in list
// *lst = adress of content of node, first node itself
//first if : there is an existing node
// else if : the list exists, its adress, but not the node --> happens at first
// iteration of the function, when creating the list
