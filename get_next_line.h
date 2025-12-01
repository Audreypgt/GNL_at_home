/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeuget <audrey.peuget@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 22:34:20 by apeuget           #+#    #+#             */
/*   Updated: 2025/12/01 22:13:53 by apeuget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h> //to delete

typedef struct s_list
{
	char			*read_content;
	struct s_list	*next;
	int				len;
}	t_list;

char	*get_next_line(int fd);
int		back_n_0_check(char *str);
ssize_t	lst_str_join(char *final_line, t_list *lst, char *buffer);
int		ft_lstsize(t_list *lst);
int		ft_strlen_before_n(char *str);
t_list	*ft_lstnew(t_list **lst, char *buffer, ssize_t line_len);
char	*ft_strdup(char *str);
void	malloc_free(t_list **lst);

#endif
