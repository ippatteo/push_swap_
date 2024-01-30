/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:18 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/22 14:56:51 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack;

	stack.error = 0;
	if (ac >= 2)
	{
		stack.last_b = -1;
		if (!takearg(av, ac, &stack))
			return (0);
		setmain(&stack);
		sorts(&stack);
		ft_exit(&stack);
		return (0);
	}
	else
		return (0);
}

void	setmain(t_stack *stack)
{
	error(stack);
	if (controlst(stack))
	{
		ft_exit(stack);
		return ;
	}
	stack->mosse = 0;
	stack->maxb = 0;
	if (stack->last_a == 1)
	{
		ft_sa(stack);
		ft_exit(stack);
		return ;
	}
}

int	controlst(t_stack *stack)
{
	int	k;

	k = 0;
	while (k <= stack->last_a)
	{
		if (k == 0 && stack->a[k] > stack->a[k + 1])
			return (0);
		else if (k == stack->last_a && stack->a[k] < stack->a[k - 1])
			return (0);
		else if (k != 0 && k != stack->last_a && stack->a[k] < stack->a[k - 1])
			return (0);
		else if (stack->a[0] > stack->a[1] && stack->a[2] < stack->a[1])
			return (0);
		k++;
	}
	return (1);
}
