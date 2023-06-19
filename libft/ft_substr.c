/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:14:41 by yscheef           #+#    #+#             */
/*   Updated: 2022/12/07 12:30:48 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i = i + 1;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen(s) > len)
		sub = malloc(len + 1);
	else
		sub = malloc(ft_strlen(s) + 1);
	if (!sub)
		return (NULL);
	while (i < len && start < ft_strlen(s))
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

// int	main(void)
// {
// 	char	*s;
// 	char	*sub;
// 	int		start;
// 	int		len;

// 	s = "12345678901234567890";
// 	start = 5;
// 	len = 10;
// 	sub = ft_substr(s, start, len);
// 	printf("Substr: %s\n", sub);
// }
