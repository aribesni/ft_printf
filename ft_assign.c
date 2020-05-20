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

static void		ft_size_2(char *s1, char *s2, char *s3, t_list *elem)
{
	if (elem->conv == 'x')
	{
		s3 = ft_uitoa_base(elem->u_integer, s1);
		elem->size = ft_strlen(s3);
		free(s3);
	}
	else if (elem->conv == 'X')
	{
		s3 = ft_uitoa_base(elem->u_integer, s2);
		elem->size = ft_strlen(s3);
		free(s3);
	}
	else if (elem->conv == 'u')
	{
		s3 = ft_itoa(elem->u_integer);
		elem->size = ft_strlen(s3);
		free(s3);
	}
	else if (elem->conv == 'i' || elem->conv == 'd')
	{
		s3 = ft_itoa(elem->integer);
		elem->size = ft_strlen(s3);
		free(s3);
	}
}

static void		ft_size(t_list *elem)
{
	char		*s1;
	char		*s2;
	char		*s3;

	s1 = "0123456789abcdef";
	s2 = "0123456789ABCDEF";
	s3 = NULL;
	ft_size_2(s1, s2, s3, elem);
}

static void		ft_assign_2(t_list *elem)
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

void			ft_assign(int j, int **z, const char *str, t_list *elem)
{
	while (str[**z] == '-' && str[**z] != '%')
		**z += 1;
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
