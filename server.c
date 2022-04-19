/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoukou <schoukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:59:26 by schoukou          #+#    #+#             */
/*   Updated: 2022/03/17 15:16:51 by schoukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	ft_putchar(char x)
{
	write(1, &x, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + 48);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	handler(int x)
{
	static int	i;
	static int	v;

	if (x == SIGUSR1)
		i += 1 << v;
	v++;
	if (v == 8)
	{
		ft_putchar(i);
		v = 0;
		i = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	write(1, "Process is running, PID is : ", 30);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
