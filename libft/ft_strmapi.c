/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:05:55 by yscheef           #+#    #+#             */
/*   Updated: 2022/12/06 21:09:03 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned long int	len;
	unsigned long int	i;
	char				*ret;

	i = -1;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	while (++i < len)
		ret[i] = f(i, s[i]);
	ret[i] = '\0';
	return (ret);
}
