/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeuget <audrey.peuget@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:07:00 by apeuget           #+#    #+#             */
/*   Updated: 2025/12/07 17:16:34 by apeuget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

ft_lstnew_addback()
{
	if (head && !*head)
			*head = new;
		else if (head && *head)
		{
			ft_lstnew_addback;
		}
}
