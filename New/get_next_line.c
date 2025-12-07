/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeuget <audrey.peuget@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:38:47 by apeuget           #+#    #+#             */
/*   Updated: 2025/12/07 23:12:30 by apeuget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_n(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	get_content(int fd, char *buffer, t_list **head)
{
	int		n_index;
	t_list	*new;

	if (buffer[0])
		n_index = ft_find_n(buffer); //on est d'accord que y'aura TOUJOURS un \n et
		// donc que memmove doit agir en overlap a chaque fois ?
		buffer = memmove(buffer, buffer + n_index, ft_str_len(buffer + n_index));
		ft_lstnew_addback(&head, buffer);
	if (ft_find_n(buffer) == -1)
	{
		while (read > 0) //comment avoir la valeur de read sans faire le read et
		// avant d'avoir fait un read ? créer variable int read ? (read = read(fd...))
		{
			read(fd, buffer, BUFFER_SIZE);
			ft_lstnew_addback(&head, buffer);
			if (ft_find_n(buffer) || ft_strlen(buffer) < BUFFER_SIZE)
				return ;
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer[BUFFER_SIZE + 1];
	char		*return_line;
	t_list		*head;

	head = NULL;
	get_content(fd, buffer, &head);
	fill_line(head, return_line);
}
