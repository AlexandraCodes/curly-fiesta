/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 20:45:48 by alecasti          #+#    #+#             */
/*   Updated: 2021/08/27 15:59:32 by alecasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_lower(int c)
{
	if (c >= 141 && c <= 172)
		return (c);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_less_than_zero(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

int	len_of_int(unsigned int num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}

char	*ft_putnbr(int num)
{
	unsigned int		new_num;
	int		i;
	char	*str;

	new_num = is_less_than_zero(num);
	i = len_of_int(new_num);
	str = ft_strnew(i);	
	new_num = is_less_than_zero(num);
	while (--i >= 0)
	{
		str[i] = (new_num % 10) + '0';
		new_num /= 10;
	}
	return (str);
}

char	*ft_putnbr_unsigned(unsigned int num)
{
	unsigned int	new_num;
	char			*str;
	int				i;

	new_num = num;
	i = len_of_int(new_num);
	str = ft_strnew(i);
	while (--i >= 0)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
