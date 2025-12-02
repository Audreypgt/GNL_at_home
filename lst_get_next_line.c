/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeuget <audrey.peuget@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:58:30 by apeuget           #+#    #+#             */
/*   Updated: 2025/12/02 01:23:14 by apeuget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*last_buffer_fill(char *final_line, char *buffer, int start_index)
{
	int i;

	i = 0;
	//printf("the buffer iiiiis : %s\n", buffer);
	while (buffer[i] != '\n')
	{
		final_line[start_index + i] = buffer[i];
		//printf("current final_line char : %c\n", final_line[start_index + i]);
		//printf("current buffer char : %c\n", buffer[i]);
		i++;
	}
	final_line[start_index + i] = '\0';
	//printf("final_line should be : %s\n", final_line);
	return (final_line);
}

ssize_t	finalline_fill(char *final_line, t_list *lst, char *buffer)
{
	ssize_t	line_index;
	ssize_t	buffer_index;

	line_index = 0;
	while (lst)
	{
		buffer_index = 0;
		while (buffer_index < BUFFER_SIZE)
		final_line[line_index++] = lst -> read_content[buffer_index++];
		lst = lst -> next;
	}
	//printf("final_line = %s\n", final_line);
	//printf("line_index = %zi\n", line_index);
	return (line_index);
}

void	malloc_free(t_list **lst)
{
	t_list	*tmp;

	printf("vole tu es libre petit malloc !!");
	if (*lst)
	{
		while (*lst)
		{
			tmp = (*lst) -> next;
			free(*lst);
			*lst = tmp;
		}
	}
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

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	t_list		*lst;
	char		*final_line;
	ssize_t		return_value;
	int			last_index;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		printf("GNL NULL");
		return (NULL);
	}
	lst = NULL;
	return_value = read(fd, buffer, BUFFER_SIZE);
	//printf("1st buffer is : %s\n", buffer);
	//printf("return_value = %i\n", return_value);
	while (back_n_0_check(buffer) && return_value == BUFFER_SIZE)
	{
		ft_lstnew(&lst, buffer, return_value);
		return_value = read(fd, buffer, BUFFER_SIZE);
		//printf("next buffer is : %s\n", buffer);
		//printf("return value is : %i\n", return_value);
		/*return_value = longueur pour connaitre longueur de la str read_content
		pour la prochaine while*/
	}
	final_line = (char *)malloc(sizeof(char) * (ft_lstsize(lst) * BUFFER_SIZE)
			+ ft_strlen_before_n(buffer) + 1);
	if (!final_line)
	{
		malloc_free(&lst);
		printf("malloc of final_line doesn't work :((");
		return (NULL); // a partir de la faire des free
	}
	last_index = finalline_fill(final_line, lst, buffer);
	final_line = last_buffer_fill(final_line, buffer, last_index);
	return (final_line);
}

// PB : ne garde pas le buffer en mémoire, si on execute plusieurs fois, il repart du début du fichier a chaque fois
// et print toujours la meme chose

//TO ADD correct return value when done reading and all

//dernire iteration n'est pas mise dans la liste, elle reste dans le buffer

/*read dans boucle while until \n ou \0
a chaque appel de read, mettre buffer dans node de linked list
des qu'on detecte un \n, lire toute la liste chainee pour avoir la taille
(multiplier la taille des buffers par le nombre de node et faire un strlen sur le
dernier pour pas compter apres le \n)
malloc de char * de la taille de la ligne envoyee (tous les maillons jusqu'au \n)


supprimer cette liste mais garder ce que la tete de lecture aura depassee du \n
pour prochain appel de la fonction puis return la ligne*/
