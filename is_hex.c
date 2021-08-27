/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 20:45:39 by alecasti          #+#    #+#             */
/*   Updated: 2021/08/27 14:44:25 by alecasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_puthexa_long(unsigned long long int num, char *str)
{
	unsigned long long int	new_num;
	int						i;
	char					*ret_str;

	i = 0;
	new_num = num;
	if (new_num == 0)
		i++;
	while (new_num > 0)
	{
		i++;
		new_num /= 16;
	}
	i += 2;
	ret_str = ft_strnew(i);
	while (--i >= 2)
	{
		ret_str[i] = str[(num % 16)];
		num /= 16;
	}
	ret_str[i] = 'x';
	ret_str[i - 1] = '0';
	return (ret_str);
}

char	*ft_puthexa(unsigned int num, char *str)
{
	unsigned int	new_num;
	int				i;
	char			*ret;

	i = 0;
	new_num = num;
	if (new_num == 0)
		i++;
	while (new_num > 0)
	{
		i++;
		new_num /= 16;
	}
	ret = ft_strnew(i);
	while (--i >= 0)
	{
		ret[i] = str[(num % 16)];
		num /= 16;
	}
	return (ret);
}

char	*create_hex_array(char specifier)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * 17);
	if (!str)
		return (NULL);
	str[16] = '\0';
	i = -1;
	while (++i < 10)
		str[i] = '0' + i;
	while (i > 9 && i < 16)
	{
		if (specifier == 'x')
			str[i] = 'a' + (i - 10);
		else
			str[i] = 'A' + (i - 10);
		i++;
	}
	return (str);
}

void	put_hexa_nbr(t_pf *obj)
{
	unsigned int	i;
	char			*str;
	char			*ret;

	i = va_arg(obj->list, unsigned int);
	if (obj->item == 'x')
		str = create_hex_array('x');
	else
		str = create_hex_array('X');
	ret = ft_puthexa(i, str);
	obj->size += ft_strlen(ret);
	ft_printstr(ret);
	free(str);
	free(ret);
}
