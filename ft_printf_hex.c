/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:17:38 by stakan            #+#    #+#             */
/*   Updated: 2022/12/18 12:17:41 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_hex(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void	ft_put_hex(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_put_hex(n / 16, format);
		ft_put_hex(n % 16, format);
	}
	else
	{
		if (n > 9)
		{
			if (format == 'x')
				ft_putchar(n - 10 + 'a');
			if (format == 'X')
				ft_putchar(n - 10 + 'A');
		}
		else
			ft_putchar(n + 48);
	}
}

int	ft_print_hex(unsigned int n, const char format)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_put_hex(n, format);
	return (ft_len_hex(n));
}
