/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:31:41 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/16 18:10:10 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_rra(t_stack *stack)
{
	int	len;
	int	tmp;

	tmp = stack->a[stack->last_a];
	len = stack->last_a;
	while (len > 0)
	{
		stack->a[len] = stack->a[len - 1];
		len--;
	}
	stack->a[0] = tmp;
	write(1, "rra\n", 4);
		stack->mosse++;
	return (1);
}

int	ft_rrb(t_stack *stack)
{
	int	len;
	int	tmp;

	tmp = stack->b[stack->last_b];
	len = stack->last_b;
	while (len > 0)
	{
		stack->b[len] = stack->b[len - 1];
		len--;
	}
	stack->b[0] = tmp;
	write(1, "rrb\n", 4);
        stack->mosse++;
	//printarray(stack->a, stack);
	//printarrayb(stack->b, stack);
	return (1);
}

/*rra and rrb at the same time.*/
int	ft_rrr(t_stack *stack)
{
	int	len;
	int	tmp;

	tmp = stack->a[stack->last_a];
	len = stack->last_a;
	while (len > 0)
	{
		stack->a[len] = stack->a[len - 1];
		len--;
	}
	stack->a[0] = tmp;
	tmp = stack->b[stack->last_b];
	len = stack->last_b;
	while (len > 0)
	{
		stack->b[len] = stack->b[len - 1];
		len--;
	}
	stack->b[0] = tmp;
	write(1, "rrr\n", 4);
        stack->mosse++;
	//printarray(stack->a, stack);
	//printarrayb(stack->b, stack);
	return (1);
}
