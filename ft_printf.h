/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:59:48 by jole              #+#    #+#             */
/*   Updated: 2022/11/28 08:19:17 by jole             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		print_argument(va_list ap, const char *s, int ret);
int		print_argument2(va_list ap, const char *s, int ret);
int		putnbr_base(int nb, int base, char *str);
int		putnbr_base2(unsigned long long nb, int base, int caps);

#endif
