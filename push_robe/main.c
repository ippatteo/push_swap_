/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:18 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/20 17:00:39 by mcamilli         ###   ########.fr       */
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
		if (ac > 2)
			takeints(&stack, ac, av);
		else if (ac == 2)
		{
			if (!splittone(av, &stack));
				return(0);
		}
		setmain(ac, &stack);
		sorts(&stack);
		ft_exit(&stack);
		return (0);
	}
	else
		return (0);

}



/*int	main(int ac, char **av)
{
	t_stack stack;

	stack.error = 0;
	if (ac >= 2)
	{
		stack.last_b = -1;
		if (ac > 2)
			takeints(&stack, ac, av);
		else if (ac == 2)
			av = ft_split(*av, ' ');
			if (!splittone(av, &stack))
				return (0);
		}
		setmain(ac, &stack);
		sorts(&stack);
		ft_exit(&stack);
		return (0);
	}
	else
		return (0);

}*/
void setmain(int ac, t_stack *stack)
{
	if (controlst(stack))
		{
			printf("uscito");
			ft_exit(stack);
			return ;
		}
		error(ac, stack);
		stack->mosse = 0;
		stack->maxb = 0;
		if (stack->last_a == 1)
		{
			//printf("uscito");
			ft_sa(stack);
			ft_exit(stack);
			return ;
		}
}
