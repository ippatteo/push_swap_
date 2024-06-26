/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:18 by mcamilli          #+#    #+#             */
/*   Updated: 2024/04/04 16:20:06 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	apply_instruction(char *cmd, t_stack *stack)
{
	if (ft_strncmp(cmd, "sa", ft_strlen(cmd) -1) == 0)
		ft_sa(stack);
	else if (ft_strncmp(cmd, "sb", ft_strlen(cmd) -1) == 0)
		ft_sb(stack);
	else if (ft_strncmp(cmd, "ss", ft_strlen(cmd) -1) == 0)
		ft_ss(stack);
	else if (ft_strncmp(cmd, "ra", ft_strlen(cmd) -1) == 0)
		ft_ra(stack);
	else if (ft_strncmp(cmd, "rb", ft_strlen(cmd) -1) == 0)
		ft_rb(stack);
	else if (ft_strncmp(cmd, "rr", ft_strlen(cmd) -1) == 0)
		ft_rr(stack);
	else if (ft_strncmp(cmd, "rra", ft_strlen(cmd) -1) == 0)
		ft_rra(stack);
	else if (ft_strncmp(cmd, "rrb", ft_strlen(cmd) -1) == 0)
		ft_rrb(stack);
	else if (ft_strncmp(cmd, "rrr", ft_strlen(cmd) -1) == 0)
		ft_rrr(stack);
	else if (ft_strncmp(cmd, "pb", ft_strlen(cmd) -1) == 0)
		ft_pb(stack);
	else if (ft_strncmp(cmd, "pa", ft_strlen(cmd) -1) == 0)
		ft_pa(stack);
}

int	main(int ac, char **av)
{
	t_stack	stack;
	char	*cmd;

	stack.error = 0;
	if (ac >= 2)
	{
		stack.last_b = -1;
		if (!takearg(av, ac, &stack))
			return (0);
		setmain(&stack);
		while (1)
		{
			cmd = get_next_line(0);
			if (cmd == NULL)
				break ;
			apply_instruction(cmd, &stack);
			free(cmd);
		}
		free(cmd);
		ft_print_okko(&stack);
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
