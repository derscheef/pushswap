/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:14:50 by yscheef           #+#    #+#             */
/*   Updated: 2022/12/06 21:15:09 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_uppercase(char l)
{
	if (l >= 'A' && l <= 'Z')
		return (1);
	else
		return (0);
}

int	ft_tolower(int c)
{
	if (ft_is_uppercase(c))
		c += 32;
	return (c);
}

// int	main(void)
// {
// 	char ch;

// 	ch = 'g';
// 	printf("Original: %c\n", tolower(ch));
// 	ch = 'g';
// 	printf("Mine: %c", ft_tolower(ch));
// 	return (0);
// }