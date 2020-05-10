/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:33:07 by aribesni          #+#    #+#             */
/*   Updated: 2020/05/04 22:55:42 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void		ft_zero_5(pf_list *elem)
{
	int			j;

	j = elem->wid - elem->size;
	while (j-- > 0 && elem->tmp >= 0)
		ft_putchar(' ');
	if (elem->integer < 0 && (elem->conv == 'i' || elem->conv == 'd'))
		ft_putchar('-');
}

static void		ft_zero_4(pf_list *elem)
{
	int			j;

	if (elem->integer < 0 && (elem->conv == 'i' || elem->conv == 'd'))
	{
		ft_putchar('-');
		elem->prec++;
	}
	j = (elem->wid - elem->size) - (elem->wid - elem->prec);
	while (j-- > 0)
		ft_putchar('0');
}

static void		ft_zero_3(pf_list *elem)
{
	int			j;
	int			k;

	k = elem->wid - elem->prec;
	if (elem->integer < 0 && (elem->conv == 'i' || elem->conv == 'd'))
	{
		k = elem->wid - (elem->prec + 1);
		if (elem->wid == elem->prec && elem->wid == elem->size)
			elem->ret++;
	}
	j = (elem->wid - elem->size) - k;
	if (elem->integer < 0 && (elem->conv == 'i' || elem->conv == 'd')
		&& elem->prec >= elem->size && elem->prec <= elem->wid)
	{
		k += (elem->size != elem->prec) ? 1 : 0;
		elem->ret += (elem->size != elem->prec) ? 1 : 0;
	}
	while (k-- > 0 && elem->tmp >= 0)
		ft_putchar(' ');
	if (elem->integer < 0 && (elem->conv == 'i' || elem->conv == 'd'))
		ft_putchar('-');
	while (j-- > 0)
		ft_putchar('0');
}

static void		ft_zero_2(pf_list *elem)
{
	int		j;

	if (elem->integer < 0 && (elem->conv == 'i' || elem->conv == 'd'))
		ft_putchar('-');
	j = elem->wid - elem->size;
	while (j-- > 0 && elem->tmp >= 0)
		ft_putchar('0');
}

void			ft_zero(int l, const char *str, pf_list *elem)
{
	int			j;

	if (elem->prec < 0 || str[l] != '.')
		ft_zero_2(elem);
	else if (elem->prec >= elem->size && elem->prec <= elem->wid
			&& str[l] == '.')
		ft_zero_3(elem);
	else if (elem->prec >= elem->size && elem->prec > elem->wid
			&& str[l] == '.')
		ft_zero_4(elem);
	else if ((elem->prec == 0 && str[l] == '.' && str[l - 1] == '*'
		&& elem->conv != 'i' && elem->conv != 'd') || (elem->prec == 0
		&& str[l] == '.' && elem->u_integer == 0 && elem->conv != 'i'
		&& elem->conv != 'd'))
	{
		j = (elem->u_integer == 0) ? elem->wid : elem->wid - elem->size;
		while (j-- > 0)
			ft_putchar(' ');
	}
	else
		ft_zero_5(elem);
	elem->integer *= (elem->integer < 0) ? -1 : 1;
}
