/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura < pkostura@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:43:07 by pkostura          #+#    #+#             */
/*   Updated: 2023/10/26 18:13:39 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// int	main(void)
// {
// 	int		fd;
// 	int		lines;
// 	char	*line;

// 	lines = 1;
// 	fd = open("file.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 		printf("%d-st line:%s\n", lines++, line);
// }

//sets the list for next occurance of \n
//malloc new node
//copy chars after \n
//free all
//buff stands for all chars in last node
void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (NULL == buff || NULL == clean_node)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->str_buff[i]
		&& last_node->str_buff[i] != '\n')
		++i;
	while (last_node->str_buff[i]
		&& last_node->str_buff[++i])
		buff[k++] = last_node->str_buff[i];
	buff[k] = '\0';
	clean_node->str_buff = buff;
	clean_node->next = NULL;
	dealloc(list, clean_node, buff);
}

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (NULL == next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	append(t_list **list, char *buff)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buff = buff;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int		chars_read;
	char	*buff;

	while (found_newline(*list) == 0)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (NULL == buff)
			return ;
		chars_read = read(fd, buff, BUFFER_SIZE);
		if (!chars_read)
		{
			free(buff);
			return ;
		}
		buff[chars_read] = '\0';
		append(list, buff);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0
		|| read (fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line(list);
	polish_list(&list);
	return (next_line);
}
