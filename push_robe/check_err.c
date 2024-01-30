/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:53:50 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/22 12:55:25 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	checkdoubles(t_stack *stack)
{
	int	k;
	int	z;

	k = 0;
	z = 0;
	while (z <= stack->last_a)
	{
		while (k <= stack->last_a)
		{
			if (stack->a[z] == stack->a[k] && k != z)
				return (1);
			k++;
		}
		z++;
		k = 0;
	}
	return (0);
}

void	ft_exit(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	exit(0);
}

int	ft_atoi(char *str, t_stack *stack)
{
	long int	r;
	int			s;
	int			i;

	r = 0;
	s = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			stack->error = 1;
		r = r * 10 + str[i++] - '0';
	}
	if (r > 2147483647 || r < -2147483647)
		stack->error = 1;
	return (r * s);
}

void	error(t_stack *stack)
{
	if (stack->error == 1)
	{
		write(2, "Error\n", 6);
		ft_exit(stack);
	}
	else if (checkdoubles(stack))
	{
		write(2, "Error\n", 6);
		ft_exit(stack);
	}
}
