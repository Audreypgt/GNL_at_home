/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeuget <audrey.peuget@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:38:47 by apeuget           #+#    #+#             */
/*   Updated: 2025/12/07 17:23:37 by apeuget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_content(int fd, char *buffer, t_list **head)
{
	int		n_index;
	t_list	*curr;
	t_list	*new;

	if (buffer[0])
		n_index = ft_find_n(buffer);
		memmove(buffer, buffer + n_index, str_len(buffer + n_index)); //on veut copier
		// buffer + n_index au debut de buffer, si on a "hi \n hello", on veut copier
		// a partir du \n + 1, pour une taille de 'hello' puis on met le \0
		ft_lstnew_addback(buffer, lst);
}

char	*get_next_line(int fd)
{
	static char	*buffer[BUFFER_SIZE + 1];
	char		*return_line;
	t_list		*head;

	lst = NULL;
	get_content(fd, buffer, &head);
}
