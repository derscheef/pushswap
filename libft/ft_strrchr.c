/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:06:23 by yscheef           #+#    #+#             */
/*   Updated: 2022/12/06 21:30:18 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char str[] = "http://www.tutorialspoint.com";
// 	const char ch = '.';
// 	char *ret;

// 	ret = strrchr(str, ch);
// 	printf("String after |%c| is - |%s|\n", ch, ret);
// 	ret = ft_strrchr(str, ch);
// 	printf("String after |%c| is - |%s|\n", ch, ret);

// 	return (0);
// }