/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 20:45:05 by alecasti          #+#    #+#             */
/*   Updated: 2021/08/27 15:51:54 by alecasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char(t_pf *obj)
{
	int		item;

	item = va_arg(obj->list, int);
	obj->size += (write(1, &item, 1));
}

void	put_str(t_pf *obj)
{
	char	*str;
	int		i;

	str = va_arg(obj->list, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		obj->size += 6;
	}
	else
	{
		i = 0;
		while (str[i] != '\0')
			i++;
		write(1, str, i);
		obj->size += i;
	}
}

void	put_signed_nbr(t_pf *obj)
{
	int		i;
	char	*str;

	i = va_arg(obj->list, int);
	if (i != 0)
	{
		if (i < 0)
		{
			ft_putchar('-');
			obj->size += 1;
		}
		str = ft_putnbr(i);
		obj->size += ft_strlen(str);
		ft_printstr(str);
		free(str);
	}
	else
	{
		ft_putchar('0');
		obj->size += 1;
	}
}

void	put_unsigned_nbr(t_pf *obj)
{
	unsigned int	i;
	char			*str;

	i = va_arg(obj->list, unsigned int);
	if (i == 0)
	{
		ft_putchar('0');
		obj->size += 1;
	}
	else
	{
		str = ft_putnbr_unsigned(i);
		obj->size += ft_strlen(str);
		ft_printstr(str);
		free(str);
	}
}

void	put_ptr(t_pf *obj)
{
	void					*p;
	char					*str;
	char					*ret;
	unsigned long long int	i;

	i = 0;
	p = va_arg(obj->list, void *);
	str = create_hex_array('x');
	ret = ft_puthexa_long((unsigned long long int)p, str);
	obj->size += ft_strlen(ret);
	ft_printstr(ret);
	free(str);
	free(ret);
}
