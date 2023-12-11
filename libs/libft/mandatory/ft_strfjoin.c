/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:15:47 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/11/27 18:32:09 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strfjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (0);
	while (*s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
