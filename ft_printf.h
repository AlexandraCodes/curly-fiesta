/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 21:04:18 by alecasti          #+#    #+#             */
/*   Updated: 2021/08/27 15:52:39 by alecasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_pf
{
	const char	*str;
	va_list		list;
	char		item;
	int			size;
}				t_pf;

typedef void		(*t_funcPtr)(t_pf*);

int		ft_printf(const char *str, ...);
void	parse_char(t_pf *obj);
void	create_func_array(t_funcPtr *func);
void	four_oh_four(t_pf *obj);
void	put_percent(t_pf *obj);
void	put_ptr(t_pf *obj);
void	put_hexa_nbr(t_pf *obj);
void	put_unsigned_nbr(t_pf *obj);
void	put_signed_nbr(t_pf *obj);
void	put_str(t_pf *obj);
void	put_char(t_pf *obj);
char	*create_hex_array(char specifier);
char	*ft_puthexa(unsigned int num, char *str);
char	*ft_puthexa_long(unsigned long long int num, char *str);
char	*ft_putnbr(int num);
char	*ft_putnbr_unsigned(unsigned int num);
void	ft_putchar(char c);
int		is_lower(int c);
int		len_of_int(unsigned int num);
char	*ft_strnew(int size);
int		ft_strlen(char *str);
void	ft_printstr(char *str);
int		is_less_than_zero(int i);

#endif
