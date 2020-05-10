/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 22:42:28 by aribesni          #+#    #+#             */
/*   Updated: 2020/05/04 22:52:19 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void			ft_putnbr(long int nb)
{
	long long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + 48);
	}
	if (nbr <= 9)
		ft_putchar(nbr + 48);
}

static int		check_base(char *base)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void			ft_putnbr_base(long int nb, char *base)
{
	int			size_base;
	int			nbr_final[100];
	int			i;
	intptr_t	nbr;

	nbr = nb;
	i = 0;
	size_base = 0;
	if (check_base(base))
	{
		nbr = (nbr < 0) ? -nbr : nbr;
		if (nbr < 0)
			ft_putchar('-');
		while (base[size_base])
			size_base++;
		while (nbr)
		{
			nbr_final[i] = nbr % size_base;
			nbr = nbr / size_base;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[nbr_final[i]]);
	}
}
