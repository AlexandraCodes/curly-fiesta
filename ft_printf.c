/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:47:33 by alecasti          #+#    #+#             */
/*   Updated: 2021/08/27 14:41:39 by alecasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_percent(t_pf *obj)
{
	ft_putchar(obj->item);
	obj->size += 1;
}

void	four_oh_four(t_pf *obj)
{
	write(1, "%", 1);
	ft_putchar(obj->item);
	obj->size += 2;
}

void	create_func_array(t_funcPtr *func)
{
	int		i;

	i = 0;
	while (i < 256)
		func[i++] = &four_oh_four;
	func['c'] = &put_char;
	func['s'] = &put_str;
	func['p'] = &put_ptr;
	func['d'] = &put_signed_nbr;
	func['i'] = &put_signed_nbr;
	func['u'] = &put_unsigned_nbr;
	func['x'] = &put_hexa_nbr;
	func['X'] = &put_hexa_nbr;
	func['%'] = &put_percent;
}

void	parse_char(t_pf *obj)
{
	t_funcPtr		func[256];

	create_func_array(func);
	obj->item = *obj->str;
	func[(unsigned char)obj->item](obj);
	obj->str++;
}

int	ft_printf(const char *str, ...)
{
	t_pf	details;

	details.size = 0;
	details.str = str;
	va_start(details.list, str);
	while (*details.str && details.str)
	{
		if (*details.str == '%')
		{
			++details.str;
			parse_char(&details);
		}
		else
		{
			write(1, (details.str)++, 1);
			details.size++;
		}
	}
	va_end(details.list);
	return (details.size);
}
