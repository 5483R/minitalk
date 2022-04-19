/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoukou <schoukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:48:28 by schoukou          #+#    #+#             */
/*   Updated: 2022/03/17 15:33:50 by schoukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (str[i] == '-')
	{
		write(1, "Nn hh kayn error !", 19);
		exit(0);
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	if (nb == 0)
	{
		write(1, "Nn hh kayn error !", 19);
		exit(0);
	}
	return (nb);
}

void	sighandler(int pid, char str)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (b <= 7)
	{
		a = (str >> b) & 1;
		if (a == 1)
		{
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		usleep(500);
		b++;
	}
}

int	main(int ac, char **av)
{
	int				c;
	unsigned int	i;

	i = 0;
	if (ac == 3)
	{
		c = ft_atoi(av[1]);
		while (av[2][i])
		{
			sighandler(c, av[2][i]);
			i++;
		}
	}
	else
	{
		write(1, "Nn hh kayn error !", 19);
		exit(0);
	}	
	if (1)
	{
		write(1, "TAMAT AL3AMALIYA BINAJAH", 25);
		exit(1);
	}
	while (1)
		pause();
}
