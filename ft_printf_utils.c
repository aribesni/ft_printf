/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 22:42:21 by aribesni          #+#    #+#             */
/*   Updated: 2020/05/04 22:51:52 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int					ft_atoi(const char *str)
{
	int				j;
	int				k;

	j = 1;
	k = 0;
	while (*str == ' ' || *str == '\t'
		|| *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			j = -j;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		k = k * 10 + (*str - 48);
		str++;
	}
	return (j * k);
}

static int			ft_len(long int nb)
{
	int				len;

	len = 0;
	if (nb == 0)
		len = 1;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(long int n)
{
	char			*str;
	int				i;
	long long		nb;

	nb = n;
	i = ft_len(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (nb > 0)
	{
		str[i--] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (str);
}

char				*ft_itoa_base(long int value, char *base)
{
	int				count;
	long long		tmp;
	unsigned int	base_length;
	char			*res;

	base_length = ft_strlen(base);
	count = (value < 0) ? 2 : 1;
	tmp = (value < 0) ? -value : value;
	while (tmp >= base_length && (tmp /= base_length))
		++count;
	tmp = (value < 0) ? -value : value;
	if (!(res = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	if (value < 0)
		res[0] = '-';
	res[count] = '\0';
	while (tmp >= base_length)
	{
		--count;
		res[count] = base[tmp % base_length];
		tmp /= base_length;
	}
	res[--count] = base[tmp % base_length];
	return (res);
}

char				*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t			i;
	char			*cpy;

	if (!str)
		return (NULL);
	if (!len || (ft_strlen(str) < (int)start))
	{
		if (!(cpy = (char*)malloc(sizeof(char))))
			return (NULL);
		cpy[0] = '\0';
		return (cpy);
	}
	if (!(cpy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && str[start])
		cpy[i++] = str[start++];
	cpy[i] = '\0';
	return (cpy);
}
