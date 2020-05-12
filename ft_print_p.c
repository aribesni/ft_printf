/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:35:06 by aribesni          #+#    #+#             */
/*   Updated: 2020/04/28 20:35:07 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void		ft_pos_p(char *base, t_list *elem)
{
	ft_putstr("0x");
	if (elem->p_integer == NULL)
		ft_putchar('0');
	else
		ft_putnbr_base_u((intptr_t)elem->p_integer, base);
}

static void		ft_rest_p(int j, int **z, const char *str, t_list *elem)
{
	char	*s1;

	while (str[j] >= '0' && str[j] <= '9' && str[j])
		j++;
	if (str[**z] == '-')
		s1 = ft_substr(str, **z + 1, (j - **z));
	else
		s1 = ft_substr(str, **z, (j - **z));
	if (str[**z] == '*' || (str[**z] == '-' && str[**z + 1] == '*'))
		elem->wid = elem->tmp;
	else
		elem->wid = ft_atoi(s1);
	elem->wid = (elem->wid < 0) ? -elem->wid : elem->wid;
	j = (elem->p_integer == NULL) ? elem->wid - 3 : elem->wid - elem->size;
	while (j-- > 0)
		ft_putchar(' ');
	if (elem->p_integer != NULL)
		elem->ret += (elem->wid > elem->size) ? elem->wid : elem->size;
	else
		elem->ret += (elem->wid < 3) ? 3 : elem->wid;
}

static void		ft_neg_p(int *j, char *base, t_list *elem)
{
	*j += 1;
	ft_putstr("0x");
	if (elem->p_integer == NULL)
		ft_putchar('0');
	else
		ft_putnbr_base_u((intptr_t)elem->p_integer, base);
}

static void		ft_assign_p(int **z, char *base, const char *str, t_list *elem)
{
	while (str[**z] == '-' && str[**z] != '%')
		**z += 1;
	if (str[**z] == '*' || (str[**z] == '-' && str[**z + 1] == '*'))
		elem->tmp = va_arg(elem->pointer, int);
	elem->p_integer = va_arg(elem->pointer, void*);
	elem->size = ft_strlen(ft_uitoa_base((intptr_t)elem->p_integer, base)) + 2;
}

int				ft_print_p(t_list *elem, const char *str, int *z, char c)
{
	int			j;
	char		*base;

	*z += 1;
	j = *z;
	base = "0123456789abcdef";
	ft_assign_p(&z, base, str, elem);
	elem->conv = c;
	j = (str[*z] == '-') ? *z : j;
	if (str[j] == '-' || elem->tmp < 0)
	{
		ft_neg_p(&j, base, elem);
		ft_rest_p(j, &z, str, elem);
		return (1);
	}
	ft_rest_p(j, &z, str, elem);
	if (str[*z] != '-' && elem->tmp >= 0)
		ft_pos_p(base, elem);
	return (1);
}
