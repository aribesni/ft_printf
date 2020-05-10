/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:34:47 by aribesni          #+#    #+#             */
/*   Updated: 2020/04/30 15:06:50 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void		ft_assign_c(int **z, const char *str, pf_list *elem)
{
	if (str[**z] == '-' && str[**z + 1] == '*')
		**z += 1;
	if (str[**z] == '*')
		elem->tmp = va_arg(elem->pointer, int);
	if (str[**z - 1] == '-')
		**z -= 1;
	elem->charac = va_arg(elem->pointer, int);
}

static void		ft_rest_c(int j, int **z, const char *str, pf_list *elem)
{
	char		*s1;

	while (str[j] >= '0' && str[j] <= '9' && str[j])
		j++;
	s1 = ft_substr(str, **z, (j - **z));
	if (str[**z] == '*' || str[**z - 1] == '*')
		elem->wid = elem->tmp;
	else
		elem->wid = ft_atoi(s1);
	elem->wid = (elem->wid < 0) ? -elem->wid : elem->wid;
	j = elem->wid - 1;
	while (j-- > 0)
		ft_putchar(' ');
	**z -= 1;
	elem->ret += (elem->wid) ? elem->wid : 1;
}

int				ft_print_c(pf_list *elem, const char *str, int *z, char c)
{
	int			j;

	*z += 1;
	j = *z;
	ft_assign_c(&z, str, elem);
	elem->conv = c;
	if (str[j] == '-' || elem->tmp < 0)
	{
		j++;
		*z += 1;
		ft_putchar(elem->charac);
		ft_rest_c(j, &z, str, elem);
		return (1);
	}
	ft_rest_c(j, &z, str, elem);
	if (str[*z] != '-')
		ft_putchar(elem->charac);
	return (1);
}