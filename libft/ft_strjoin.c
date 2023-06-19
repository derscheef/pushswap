/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:05:24 by yscheef           #+#    #+#             */
/*   Updated: 2023/05/09 17:28:27 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		l;

	i = 0;
	if (s1 && s2)
	{
		l = ft_strlen(s1) + ft_strlen(s2);
		dst = malloc(sizeof(char) * l + 1);
		if (!dst)
			return (0);
		while (s1[i])
		{
			dst[i] = s1[i];
			i++;
		}
		while (*s2)
			dst[i++] = *s2++;
		dst[i] = '\0';
		return (dst);
	}
	else
		return (0);
}

// int	main(int argc, char const *argv[])
// {
// 	char	*s1;
// 	char	*s2;

// 	s1 = "This is the first string";
// 	s2 = "This is the second string";
// 	printf("These are the original strings:\nS1: %s\nS2:%s\n\n", s1, s2);
// 	printf("This is the joined String:\n%s", ft_strjoin(s1, s2));
// 	return (0);
// }
