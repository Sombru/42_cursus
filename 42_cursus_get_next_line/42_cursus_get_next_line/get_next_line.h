/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura < pkostura@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:43:11 by pkostura          #+#    #+#             */
/*   Updated: 2023/10/26 18:05:51 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

//node of linkd list
typedef struct s_list
{
	char			*str_buff;
	struct s_list	*next;
}					t_list;

void	polish_list(t_list **list);
char	*get_line(t_list *list);
void	append(t_list **list, char *buff);
void	create_list(t_list **list, int fd);
char	*get_next_line(int fd);

int		found_newline(t_list *list);
t_list	*find_last_node(t_list *list);
void	copy_str(t_list *list, char *str);
int		len_to_newline(t_list *list);
void	dealloc(t_list **list, t_list *clean_node, char *buff);

#endif