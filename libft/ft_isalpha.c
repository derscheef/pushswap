/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:54:48 by yscheef           #+#    #+#             */
/*   Updated: 2022/12/06 21:07:37 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

// int	main(int argc, char *argv[])
// {
// 	int alph = '0';
// 	printf("Normale Funktion: %d\n", isalpha(alph));
// 	printf("Meine Funktion: %d", ft_isalpha(alph));
// 	return (0);
// }