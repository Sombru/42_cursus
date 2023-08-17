/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura < pkostura@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:30:15 by pkostura          #+#    #+#             */
/*   Updated: 2023/08/17 10:26:34 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

//        function allocates memory  for
//        an  array  of  "nmemb" elements of size bytes
// 		  each and returns a pointer to the allocated
//        memory.   The  memory  is  set to zero.  If
//        nmemb or size is 0, then  calloc()  returns
//        either NULL, or a unique pointer value that
//        can later be successfully passed to free().
//        If  the  multiplication  of  nmemb and size
//        would result in integer overflow, then cal‐
//        loc()  returns  an  error.