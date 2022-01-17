/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:33:05 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/06 18:54:08 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n - 1 && str1[i] == str2[i] && \
			str1[i] != '\0' && str2[i] != '\0')
		i++;
	if (n == 0 || (str1[i] == '\0' && str2[i] == '\0'))
		return (0);
	return (str1[i] - str2[i]);
}
