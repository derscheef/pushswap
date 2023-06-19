/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:06:15 by yscheef           #+#    #+#             */
/*   Updated: 2022/12/06 21:09:06 by yscheef          ###   ########.fr       */
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

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!ft_strlen(find))
		return ((char *)str);
	i = -1;
	while (++i < len && *(str + i))
	{
		j = -1;
		while ((i + ++j) < len && *(str + i + j) == *(find + j))
			if (!*(find + j + 1))
				return ((char *)(str + i));
	}
	return (NULL);
}

// int	main(int argc, char const *argv[])
// {
// 	char haystack[30] = "aaabcabcd";
// 	char needle[10] = "aabc";
// 	char * empty = (char*)"";
// 	printf("Mine:\n");
// 	printf("%s\n", ft_strnstr(haystack, needle, -1));
// 	printf("%s\n", ft_strnstr(haystack, "a", -1));
// 	printf("%s\n", ft_strnstr(haystack, "c", -1));
// 	printf("Original:\n");
// 	printf("%s\n", strnstr(haystack, needle, -1));
// 	printf("%s\n", strnstr(haystack, "a", -1));
// 	printf("%s\n", strnstr(haystack, "c", -1));
// }
