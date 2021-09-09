/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:22:24 by gabriel           #+#    #+#             */
/*   Updated: 2021/08/30 14:11:43 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strncpy(char *dst, const char *src, size_t n)// função para copiar a string com o limite de n caracteres
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src [i];
		i++;
	}
	while (i < n)//caso src acabe e o n não, adicionaremos caracteres nulos ate que n acabe
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

int	lenint(int n)
{
	int	len;

	if (n >= 0)
		len = 0;
	else
		len = 1;//caso nosso numero seja negativo, devemos garantir que teremos um caract
			//ere a mais pelo sinal -
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = lenint(n);
	str = ft_calloc(len, sizeof(char));
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n == -2147483648)
		return (ft_strncpy(str, "-2147483648\0", 12));
	if (n < 0)
	{
		n = n * (-1);
		str[0] = '-';
	}
	str[len--] = '\0';
	while (n > 0)
	{
		str[len--] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}