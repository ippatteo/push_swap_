/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:31:21 by mcamilli          #+#    #+#             */
/*   Updated: 2023/12/30 14:08:01 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sa(t_stack *stack)
{
	int		tmp;

	if (!stack->a[0] || !stack->a[1])
		return (0);
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	write(1, "sa\n", 3);
	stack->mosse++;
	return (1);
}

int	ft_sb(t_stack *stack)
{
	int		tmp;

	if (stack->last_b == 0 || stack->last_b == 1)
		return (0);
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	write(1, "sb\n", 3);
    stack->mosse++;
	return (1);
}

/*sa and sb at the same time.*/
int	ft_ss(t_stack *stack)
{
	int	tmp;

	if (!stack->a[0] || !stack->a[1] || !stack->b[0] || !stack->b[1])
		return (0);
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	write(1, "ss\n", 3);
    stack->mosse++;
	return (1);
}
