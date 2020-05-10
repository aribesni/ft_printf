/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:36:35 by aribesni          #+#    #+#             */
/*   Updated: 2020/04/28 20:36:37 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		p_list
{
	va_list			pointer;
	int				size;
	int				prec;
	int				wid;
	int				space;
	char			charac;
	char 			*string;
	long int		integer;
	long int		u_integer;
	void			*p_integer;
	int				ret;
	int				tmp;
	int				tmp2;
	long int		neg;
	char			conv;
}					pf_list;
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putendl(char *s);
void				ft_putnbr(long nb);
void				ft_putnbr_base(long nbr, char *base);
void				ft_flags(const char *str, int **i);
void    			ft_reset(pf_list *elem);
void				ft_display(int k, const char *str, pf_list *elem);
void				ft_ret(int k, const char *str, pf_list *elem);
void				ft_rest(int j, int **z, const char *str, pf_list *elem);
void				ft_zero(int l, const char *str, pf_list *elem);
void				ft_assign(int j, int **z, const char *str, pf_list *elem);
void				ft_dot_bis(int i, const char *str, pf_list *elem);
void				ft_wildcard(int j, int k, const char *str, pf_list *elem);
int					ft_print_c(pf_list *elem, const char *str, int *z, char c);
int					ft_print_s(pf_list *elem, const char *str, int *z, char c);
int					ft_print_i_u(pf_list *elem, const char *str, int *z, char c);
int					ft_print_p(pf_list *elem, const char *str, int *z, char c);
int					ft_strlen(const char *str);
int					ft_atoi(const char *str);
int					ft_printf(const char *str, ...);
int					ft_dot_s(int i, int **z, const char *str, pf_list *elem);
char				*ft_substr(const char *str, unsigned int start, size_t len);
char				*ft_itoa(long int n);
char				*ft_itoa_base(long int value, char *base);

#endif
