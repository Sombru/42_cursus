/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura < pkostura@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:35:19 by pkostura          #+#    #+#             */
/*   Updated: 2023/09/04 09:39:31 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	n;

	if (*small == 0)
		return ((char *)big);
	n = ft_strlen(small);
	while (*big && n <= len)
	{
		if (*big == *small && ft_strncmp(big, small, n) == 0)
			return ((char *)big);
		++big;
		--len;
	}
	return (NULL);
}
