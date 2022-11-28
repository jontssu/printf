/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:50:23 by jole              #+#    #+#             */
/*   Updated: 2022/11/24 14:01:14 by jole             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		calculate_digits(int n, int base);
static char		*allocate_nb_to_str(char *p, long n, int is_negative, int base);
static char		*strrev(char *p);
size_t			ft_strlen(const char *s);

char	*ft_itoa_base(int n, int base)
{
	char	*p;
	int		digits;
	int		is_negative;

	is_negative = 0;
	digits = calculate_digits(n, base);
	if (n < 0)
		is_negative = 1;
	p = malloc((digits + is_negative + 1) * sizeof(char));
	if (!p)
		return (0);
	p = allocate_nb_to_str(p, n, is_negative, base);
	return (strrev(p));
}

static int	calculate_digits(int n, int base)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (digits + 1);
	if (n < 0)
	{
		digits++;
		n = n / -base;
	}
	while (n > 0)
	{
		digits++;
		n = n / base;
	}
	return (digits);
}

static char	*allocate_nb_to_str(char *p, long n, int is_negative, int base)
{
	int		i;
	char	*chars;

	chars = "012345679abcdef";
	i = 0;
	if (is_negative)
		n = n * -1;
	if (n == 0)
		p[i++] = '0';
	while (n > 0)
	{
		p[i++] = chars[n % base];
		n = n / base;
	}
	if (is_negative)
		p[i++] = '-';
	p[i] = '\0';
	return (p);
}

static char	*strrev(char *p)
{
	int		i;
	int		k;
	char	tmp;

	i = 0;
	k = ft_strlen(p) - 1;
	while (i < k)
	{
		tmp = p[i];
		p[i++] = p[k];
		p[k--] = tmp;
	}
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
