/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:29:55 by aribesni          #+#    #+#             */
/*   Updated: 2020/05/01 11:53:40 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void		ft_size(pf_list *elem)
{
	char		*s1;
	char		*s2;

	s1 = "0123456789abcdef";
	s2 = "0123456789ABCDEF";
	if (elem->conv == 'x')
		elem->size = ft_strlen(ft_itoa_base(elem->u_integer, s1));
	else if (elem->conv == 'X')
		elem->size = ft_strlen(ft_itoa_base(elem->u_integer, s2));
	else if (elem->conv == 'u')
		elem->size = ft_strlen(ft_itoa(elem->u_integer));
	else if (elem->conv == 'i' || elem->conv == 'd')
		elem->size = ft_strlen(ft_itoa(elem->integer));
}

static void		ft_assign_2(pf_list *elem)
{
	if (elem->conv == 'i' || elem->conv == 'd')
	{
		elem->integer = va_arg(elem->pointer, int);
		elem->neg = (elem->integer < 0) ? elem->integer : elem->neg;
	}
	else if (elem->conv == 'u' || elem->conv == 'x'
		|| elem->conv == 'X')
	{
		elem->u_integer = va_arg(elem->pointer, int);
		if (elem->u_integer < 0)
			elem->u_integer += 4294967296;
	}
	if (elem->conv != 's')
		ft_size(elem);
}

void			ft_assign(int j, int **z, const char *str, pf_list *elem)
{
	if (((str[**z] == '0' && elem->conv != 's')
		|| str[**z] == '-') && str[**z + 1] == '*')
		**z += 1;
	while (str[**z] == '0' && elem->conv != 's' && str[**z] != '%')
		**z += 1;
	elem->tmp = (str[**z] == '*') ? va_arg(elem->pointer, int) : elem->tmp;
	while (str[j] && str[j] != '%')
	{
		if (str[j] == '.' && str[j + 1] == '*')
			elem->tmp2 = va_arg(elem->pointer, int);
		j++;
	}
	**z -= (str[**z - 1] == '-') ? 1 : 0;
	ft_assign_2(elem);
}