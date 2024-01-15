/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takearg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:05:57 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/15 20:50:41 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack stack;

	if (ac >= 2)
	{
		stack.last_b = -1;
		if (ac > 2)
			takeints(&stack, ac, av);
		else if (ac == 2)
			return (0); //per ora lasciamo cosi
		error(ac, &stack);
		//renum(&stack, ac);
		stack.error = 0;
		stack.mosse = 0;
		stack.maxb = 0;
		//mecha_torc(&stack);
		ft_pb(&stack);
		ft_pb(&stack);
		ft_pb(&stack);
		ft_pb(&stack);
		ft_pb(&stack);
		//ft_rrr(&stack);
    	//ft_printf("\ndisordine = %d\n", controldisord(&stack));
		//bubble(&stack);
		//ft_printf("last a = %d\n", stack.last_a);
		//ordinededdio(&stack, ac);
		printarray(stack.a, &stack);
		ft_printf("\n");
    	//ft_printf("\ndisordine = %d\n", controldisord(&stack));
    	ft_printf("mosse = %d\n", stack.mosse);
		return (0);
	}
	else
	{
		//write(2, "Error\n", 6);
		return (0);
	}

}

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
	printarray(stack->a, stack);
}

void	printarray(int *i, t_stack *stack)
{
	int k;

	k = 0;
	while (k <= stack->last_a)
		ft_printf("stack a : %d \n", i[k++]);
}

void	printarrayb(int *i, t_stack *stack)
{
	int k;

	k = 0;
	while (k <= stack->last_b)
		ft_printf("stack b: %d \n", i[k++]);
}

