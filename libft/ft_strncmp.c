/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:06:07 by yscheef           #+#    #+#             */
/*   Updated: 2023/06/19 16:29:20 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	compare;

	if (!s1 || !s2)
		return (0);
	compare = 0;
	while ((s1[compare] == s2[compare]) && (s1[compare] != '\0'
			&& s2[compare] != '\0'))
	{
		compare++;
	}
	return (s1[compare] - s2[compare]);
}

// int	main(int argc, char const *argv[])
// {
// 	int	test;

// 	test = 0;
// 	while (test != 8)
// 	{
// 		printf("Test: %d\n", test);
// 		printf("Mine: %d\n", ft_strncmp("test\200", "test\0", test));
// 		printf("Original: %d\n\n", strncmp("test\200", "test\0", test));
// 		test++;
// 	}
// }
