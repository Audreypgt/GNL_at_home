/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeuget <audrey.peuget@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:58:30 by apeuget           #+#    #+#             */
/*   Updated: 2025/12/05 16:19:50 by apeuget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	last_buffer_fill(char *final_line, char *buffer, int start_index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		final_line[start_index + i] = buffer[i];
		i++;
		if (i && buffer[i - 1] == '\n')
			break ;
	}
	final_line[start_index + i] = '\0';
	while (buffer[i + j])
	{
		buffer[j] = buffer[i + j];
		j++;
	}
	buffer[j] = '\0';
	return (i);
}

ssize_t	finalline_fill(char *final_line, t_list *lst, char *buffer)
{
	ssize_t	line_index;
	ssize_t	buffer_index;

	line_index = 0;
	while (lst)
	{
		buffer_index = 0;
		while (lst -> read_content[buffer_index] && buffer_index < BUFFER_SIZE)
			final_line[line_index++] = lst -> read_content[buffer_index++];
		lst = lst -> next;
	}
	malloc_free(&lst);
	return (line_index);
}

char	*malloc_free(t_list **lst)
{
	t_list	*tmp;

	if (*lst)
	{
		while (*lst)
		{
			tmp = (*lst)-> next;
			free(*lst);
			*lst = tmp;
		}
	}
	return (NULL);
}

char	*get_content(int fd, char *buffer, t_list **lst, int i)
{
	ssize_t		return_value;
	ssize_t		line_len;

	if (i) //mettre autre condition
	{
		line_len = ft_lstnew(lst, buffer + i);
		printf("line_len = %i\n", line_len);
		if (line_len < BUFFER_SIZE - i)
			return ((char *)malloc(sizeof(char) * (line_len + 1))); //ne pas return ici, trouver quoi return
			//et comment malloc line sans ce return
	}
	return_value = read(fd, buffer, BUFFER_SIZE); //doit etre une condition, envoyer dans liste chainee si
	// ya un truc dans buffer, sinon read
	while (return_value == BUFFER_SIZE && back_n_0_check(buffer))
	{
		printf("jsp\n");
		buffer[BUFFER_SIZE] = '\0';
		ft_lstnew(lst, buffer);
		return_value = read(fd, buffer, BUFFER_SIZE);
	}
	return ((char *)malloc(sizeof(char) * (ft_lstsize(*lst) * BUFFER_SIZE)
			+ ft_strlen_before_n(buffer) + 1));
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static int	i;
	t_list		*lst;
	char		*final_line;
	int			last_index;
	//static int	test;

	if (fd < 0 || BUFFER_SIZE <= 0)
	return (NULL);
	printf("i start = %d\n", i);
	lst = NULL;
	final_line = get_content(fd, buffer, &lst, i);
	if (!final_line)
		return (malloc_free(&lst));
	last_index = finalline_fill(final_line, lst, buffer);
	i = last_buffer_fill(final_line, buffer, last_index);
	printf("i end = %d\n", i);
	//test = 1;
	return (final_line);
}

//TO ADD correct return value when done reading and all
//derniere iteration n'est pas mise dans la liste, elle reste dans le buffer

/*return_value = longueur pour connaitre longueur de la str read_content
		pour la prochaine while*/

/*read dans boucle while until \n ou \0
a chaque appel de read, mettre buffer dans node de linked list
des qu'on detecte un \n, lire toute la liste chainee pour avoir la taille
(multiplier la taille des buffers par le nombre de node et faire un strlen sur le
dernier pour pas compter apres le \n)
malloc de char * de la taille de la ligne envoyee (tous les maillons jusqu'au
\n)*/
