/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:06:38 by yscheef           #+#    #+#             */
/*   Updated: 2023/06/20 11:36:27 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_shitstr(const char *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (0);
	if ((unsigned int)ft_strlen(s) < start)
		len = 0;
	if ((unsigned int)ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	ft_strlcpy(sub, (char *)s + start, len + 1);
	return (sub);
}

char	*ft_start(char *s_pos, char *set)
{
	char	*chk;
	size_t	i;

	i = 0;
	while (*s_pos && *set)
	{
		chk = ft_strchr(s_pos, set[i]);
		if (i == ft_strlen(set) - 1)
		{
			if (chk != s_pos)
				break ;
			i = 0;
		}
		if (chk == s_pos)
		{
			s_pos++;
			i = 0;
		}
		else
			i++;
	}
	return (s_pos);
}

int	ft_end(char *s1, char *set)
{
	size_t	i;
	size_t	end;
	char	*chk;

	i = 0;
	end = 0;
	while (*s1 && *set)
	{
		chk = ft_strchr(s1, set[i]);
		if (i == ft_strlen(set) - 1)
		{
			if (chk != s1)
				break ;
			i = 0;
		}
		if (chk == s1)
		{
			s1--;
			end++;
			i = 0;
		}
		else
			i++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	char	*s_pos;

	if (s1 && set)
	{
		s_pos = (char *)s1;
		s_pos = ft_start(s_pos, (char *)set);
		s1 += ft_strlen(s1) - 1;
		end = ft_end((char *)s1, (char *)set);
		return ((char *)ft_shitstr(s_pos, 0, ft_strlen(s_pos) - end));
	}
	else
		return (0);
}

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	if (!s1 && !set)
// 		return (NULL);
// 	while (s1 && ft_strchr(set, s1[i]))
// 		i++;
// 	j = ft_strlen(s1);
// 	while (*s1 && ft_strchr(set, s1[j - 1]))
// 		j--;
// 	return (ft_substr(s1, i, (j - i)));
// }

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;

// 	s1 = "lorem \n ipsum \t dolor \n sit \t amet";
// 	s2 = "lorem ipsum dolor sit amet";
// 	printf("%s\n", ft_strtrim(s1, " "));
// 	printf("\nNext:\n\n");
// 	printf("%s\n", ft_strtrim(s2, "te"));
// 	printf("\nNext:\n\n");
// 	printf("%s\n", ft_strtrim(s2, "l "));
// 	printf("\nNext:\n\n");
// 	printf("%s\n", ft_strtrim(s2, "tel"));
// 	printf("\nNext:\n\n");
// 	printf("%s\n", ft_strtrim("", ""));
// 	printf("%s\n", ft_strtrim("tripouille   xxx", " x"));
// 	printf("%s\n", ft_strtrim("   xxx   xxx", " x"));
// 	printf("%s\n", ft_strtrim("aaatestatestaaa", "abc"));
// 	printf("%s\n", ft_strtrim("xavocadoyz", "xyz"));
// 	return (0);
// }
