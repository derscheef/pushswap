/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:04:21 by yscheef           #+#    #+#             */
/*   Updated: 2022/12/06 21:12:43 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	word_count;
	int	i;

	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			word_count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (word_count);
}

static void	*ft_taballoc(char const *s, char **str_tab, char c)
{
	int	i;
	int	wl;

	i = 0;
	while (s[i])
	{
		wl = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			wl++;
			i++;
		}
		if (wl != 0)
			*str_tab++ = (char *)malloc((wl + 1) * sizeof(char));
		if (!(str_tab - 1))
			return (NULL);
	}
	return (*str_tab);
}

char	**ft_split(char const *s, char c)
{
	char	**str_tab;
	int		i;
	int		i2;
	int		i3;
	int		wc;

	i = 0;
	i3 = 0;
	wc = ft_wordcount(s, c);
	str_tab = (char **)malloc((wc + 1) * sizeof(char *));
	if (!str_tab)
		return (NULL);
	ft_taballoc(s, str_tab, c);
	while (i != wc)
	{
		i2 = 0;
		while (s[i3] == c && s[i3] != '\0')
			i3++;
		while (s[i3] != c && s[i3] != '\0')
			str_tab[i][i2++] = s[i3++];
		str_tab[i][i2] = '\0';
		i++;
	}
	str_tab[i] = NULL;
	return (str_tab);
}

// int	main(void)
// {
// 	int		i;
// 	char	**tab;

// 	i = 0;
// 	tab = ft_split("Hallo This is a Test    and thistooo", ' ');
// 	while (tab[i] != NULL)
// 	{
// 		printf("string %d : %s\n", i, tab[i]);
// 		i++;
// 	}
// 	return (0);
// }
