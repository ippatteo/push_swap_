/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:18 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/22 12:02:40 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack stack;

	stack.error = 0;
	if (ac >= 2)
	{
		stack.last_b = -1;
		if (!takearg(av, ac, &stack))
			return(0);
		//printarray(stack.a, &stack);
		//printf(" 25 main\n");
		setmain(&stack);
		//printf(" 27 main\n");
		
		sorts(&stack);
		ft_exit(&stack);
		return (0);
	}
	else
		return (0);

}




void setmain(t_stack *stack)
{
	if (controlst(stack))
		{
			//printf("uscito\n");
			ft_exit(stack);
			return ;
		}
		
		error(stack);
		stack->mosse = 0;
		stack->maxb = 0;
		if (stack->last_a == 1)
		{
			//printf("uscito3\n");
			ft_sa(stack);
			ft_exit(stack);
			return ;
		}
}
