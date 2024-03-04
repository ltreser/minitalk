/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 01:30:43 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/04 04:10:00 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../libft/includes/libft.h"

int	main(int ac, char **av)
{
	int server_pid;
	int i;
	int bit_index;

	i = -1;
	if (ac != 3)
		return (ft_printf("Error: Wrong argument count\n"), 0);
	server_pid = ft_atoi(av[1]);
	if (kill(server_pid, 0) == -1)
		return (ft_printf("Error: Signal can not be sent\n"), 0);
	while (av[2][++i])
	{
		bit_index = 0;
		while(bit_index++ < 8)
		{
			if (((av[2][i] & 1) == 1) && (kill(server_pid, SIGUSR1), 1))
				;
			else if (((av[2][i] & 1) == 0) && (kill(server_pid, SIGUSR2), 1))
				;
			usleep(1000);
			av[2][i] >>= 1;
		}
	}
	return (0);
}
