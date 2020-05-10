/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:33:07 by aribesni          #+#    #+#             */
/*   Updated: 2020/04/28 20:37:15 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int		main(void)
{
/*	ft_printf("%d\n", ft_printf("%-u%-15u%-6.1i\n", 2147483647, 0, 0));
	printf("%d\n", printf("%-u%-15u%-6.1i\n", 2147483647, 0, 0));
	ft_printf("%d\n", ft_printf("%-20.*i\n", 10, -362628618));
	printf("%d\n", printf("%-20.*i\n", 10, -362628618));
	ft_printf("%d\n", ft_printf("%-17.2x%11X\n", 0, -2147483647));
	printf("%d\n", printf("%-17.2x%11X\n", 0, -2147483647));
	ft_printf("%d\n", ft_printf("%2u%15u%-9.2x\n", 2147483647, -2147483647, 0));
	printf("%d\n", printf("%2u%15u%-9.2x\n", 2147483647, -2147483647, 0));
	ft_printf("%d\n", ft_printf("%-10.*x\n", 8, 2147483647));
	printf("%d\n", printf("%-10.*x\n", 8, 2147483647));
	ft_printf("%d\n", ft_printf("%18.*i\n", 10, -71987106));
	printf("%d\n", printf("%18.*i\n", 10, -71987106));
	ft_printf("%d\n", ft_printf("%16.*d\n", 9, -31491405));
	printf("%d\n", printf("%16.*d\n", 9, -31491405));
	ft_printf("%d\n", ft_printf("eBVJ%10.*d\n", 10, -642121507));
	printf("%d\n", printf("eBVJ%10.*d\n", 10, -642121507));
	ft_printf("%d\n", ft_printf("%*.*d\n", 5, 10, -9679925));
	printf("%d\n", printf("%*.*d\n", 5, 10, -9679925));
	ft_printf("%d\n", ft_printf("%-.*i\n", 10, -892085999));
	printf("%d\n", printf("%-.*i\n", 10, -892085999));
	ft_printf("%d\n", ft_printf("%-10.*d\n", 10, -35340750));
	printf("%d\n", printf("%-10.*d\n", 10, -35340750));
	ft_printf("%d\n", ft_printf("%015.*i\n", 10, -386247));
	printf("%d\n", printf("%015.*i\n", 10, -386247));
	ft_printf("%d\n", ft_printf("%0.*d\n", 10, -33135841));
	printf("%d\n", printf("%0.*d\n", 10, -33135841));
	ft_printf("%d\n", ft_printf("%012.*d\n", 10, -857407110));
	printf("%d\n", printf("%012.*d\n", 10, -857407110));
	ft_printf("%d\n", ft_printf("%010.*i\n", 10, -389214821));
	printf("%d\n", printf("%010.*i\n", 10, -389214821));
	ft_printf("%d\n", ft_printf("%018.*d\n", 10, -786061905));
	printf("%d\n", printf("%018.*d\n", 10, -786061905));
	ft_printf("%d\n", ft_printf("%*.*d\n", 16, 10, -501408437));
	printf("%d\n", printf("%*.*d\n", 16, 10, -501408437));
	ft_printf("%d\n", ft_printf("%04.*i\n", 3, -43303315));
	printf("%d\n", printf("%04.*i\n", 3, -43303315));
*/	ft_printf("%d\n", ft_printf("%-26p", 0x5d6f9a29));
	printf("%d\n", printf("%-26p", 0x5d6f9a29));
	return (0);
}

// | "%%wA9GD%-u%-15u%-6.1iH6nbI5xwS", 2147483647, 0, 0 | when precision == size and negative width
// | "%-20.*iH%0X%-15.*x%6sD6WQTK%%\n", 10, -362628618, -2147483647, 0, -1830011137, ""