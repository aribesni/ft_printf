/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:35:14 by aribesni          #+#    #+#             */
/*   Updated: 2020/05/01 11:55:04 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void		ft_dot_tmp(pf_list *elem)
{
	int			i;
	int			j;

	i = elem->prec;
	j = elem->wid;
	if (elem->size == 0)
	{
		while (j--)
			ft_putchar(' ');
	}
	else if (elem->prec > 0)
	{
		while (i--)
			ft_putchar(*elem->string++);
	}
	else if (elem->prec < 0)
		ft_putstr(elem->string);
}

static int		ft_wildcard_s2(int i, int **z, const char *str, pf_list *elem)
{
	i++;
	if (str[**z + 1] == '*')
	{
		elem->wid = (elem->tmp < 0) ? -elem->tmp : elem->tmp;
		if (str[i + 1] == '.')
		{
			ft_dot_bis(i, str, elem);
			ft_dot_tmp(elem);
			while (elem->space-- > 0 && elem->size != 0)
				ft_putchar(' ');
			return (1);
		}
		elem->size = ft_strlen(elem->string);
		elem->space = elem->wid - elem->size;
		ft_putstr(elem->string);
		while (elem->space-- > 0)
			ft_putchar(' ');
		elem->ret += (elem->wid < elem->size) ? elem->size : elem->wid;
		return (1);
	}
	return (1);
}

static int		ft_wildcard_s(int i, const char *str, pf_list *elem)
{
	elem->wid = (elem->tmp < 0) ? -elem->tmp : elem->tmp;
	if (str[i + 1] == '.')
	{
		ft_dot_bis(i, str, elem);
		if (elem->tmp < 0)
			ft_dot_tmp(elem);
		while (elem->space-- > 0 && elem->size > 0 && elem->prec >= 0)
			ft_putchar(' ');
		if (elem->tmp >= 0)
			ft_dot_tmp(elem);
		return (1);
	}
	elem->space = elem->wid - ft_strlen(elem->string);
	if (elem->tmp < 0)
		ft_putstr(elem->string);
	while (elem->space-- > 0)
		ft_putchar(' ');
	if (elem->tmp >= 0)
		ft_putstr(elem->string);
	elem->ret += (elem->wid < elem->size) ? elem->size : elem->wid;
	return (1);
}

static void		ft_rest_s(int i, int **z, const char *str, pf_list *elem)
{
	char		*s1;

	if (str[**z] == '-')
		s1 = ft_substr(str, **z + 1, (i - **z));
	else
		s1 = ft_substr(str, **z, (i - **z));
	elem->wid = ft_atoi(s1);
	elem->size = ft_strlen(elem->string);
	elem->space = elem->wid - elem->size;
	if (str[**z] == '-' && elem->size > 0)
		ft_putstr(elem->string);
	while (elem->space-- > 0)
		ft_putchar(' ');
	if (str[**z] != '-' && elem->size > 0)
		ft_putstr(elem->string);
	elem->ret += (elem->wid < elem->size) ? elem->size : elem->wid;
}

int				ft_print_s(pf_list *elem, const char *str, int *z, char c)
{
	int			i;
	char		*tmp;

	*z += 1;
	i = *z;
	ft_assign(i, &z, str, elem);
	elem->conv = c;
	tmp = va_arg(elem->pointer, char*);
	elem->string = (tmp == NULL) ? "(null)" : tmp;
	elem->size = ft_strlen(elem->string);
	if (str[*z] == '*')
		return (ft_wildcard_s(i, str, elem));
	if (str[*z] == '-' && str[*z + 1] == '*')
		return (ft_wildcard_s2(i, &z, str, elem));
	else if (str[*z] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
		i++;
	if (str[i] == '.')
		return (ft_dot_s(i, &z, str, elem));
	ft_rest_s(i, &z, str, elem);
	ft_reset(elem);
	return (1);
}
