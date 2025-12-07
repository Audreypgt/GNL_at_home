/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeuget <audrey.peuget@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:07:00 by apeuget           #+#    #+#             */
/*   Updated: 2025/12/07 23:12:35 by apeuget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew_addback(t_list **head, char *buffer)
{
	t_list *new;
	t_list *curr;

	curr = *head;
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> content = buffer;
	new -> next = NULL;
	if (head && !*head)
			*head = new;
	else if (head && *head)
	{
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
	return (new);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_memmove(char *dest, char *src, int size)
{
	while (size != 0)
	{
		dest[size - 1] = src[size - 1];
		size--;
	}
	dest[size] = '\0';
	return (dest);
}
