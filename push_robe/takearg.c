/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takearg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:05:57 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/19 15:53:14 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"



void	takeints(t_stack *stack, int ac, char **av)
{
    int j;

    stack->a = (int *)malloc(sizeof(int) * (ac - 1));
    stack->b = (int *)malloc(sizeof(int) * (ac - 1));
    //stack->copy = (int *)malloc(sizeof(int) * (ac - 1));
    j = 0;
    while (j <= ac - 2)
	{
		stack->a[j] = ft_atoi(av[j + 1], stack);
		//stack->copy[j] = ft_atoi(av[j + 1]);
		stack->last_a = j;
		j++;
	}
	//printarray(stack->a, stack);
}

void	printarray(int *i, t_stack *stack)
{
	int k;

	k = 0;
	while (k <= stack->last_a)
	{
		ft_printf("stack a[%d] : %d \n", k, i[k]);
		k++;
	}

}

void	printarrayb(int *i, t_stack *stack)
{
	int k;

	k = 0;
	while (k <= stack->last_b)
	{
		ft_printf("stack b[%d] : %d \n", k, i[k]);
		k++;
	}
}

int controlst(t_stack *stack)
{
	int k;

	k = 0;
	while (k <= stack->last_a)
	{
		if (k == 0 && stack->a[k] > stack->a[k+1])
		{
			return(0);
		}
		if (k == stack->last_a && stack->a[k] < stack->a[k-1])
		{
			return(0);
		}
		if (k != 0 && k != stack->last_a && stack->a[k] < stack->a[k-1])
		{
			printf("nope error pos %d\n", k);
			return(0);
		}
		if (stack->a[0] > stack->a[1] && stack->a[2] < stack->a[1])
		{
			printf("nope error pos %d\n", k);
			return(0);
		}
		k++;
	}
	printf("ok\n");
	return (1);
}
