/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 01:11:02 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/04 03:37:11 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../libft/includes/libft.h"

void	reconstruct_char(int signal)
{
	static int	bit_index;
	int 		bit;
	static char c;

	if (signal ==  SIGUSR1)
		bit = 1;
	if (signal == SIGUSR2)
		bit = 0;
	if (bit_index < 8)
		c = c + (bit << bit_index++);
	if (8 == bit_index)
	{
		ft_printf("%c", c);
		bit_index = 0;
		c = 0;
	}
}
int	main(void)
{
	ft_printf("SERVER PID= %d\n", getpid());
	signal(SIGUSR1, reconstruct_char);
	signal(SIGUSR2, reconstruct_char);
	while (1)
		pause();
	return (0);
}
