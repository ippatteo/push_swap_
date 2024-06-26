/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:18 by mcamilli          #+#    #+#             */
/*   Updated: 2024/04/04 12:09:25 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_downup(t_stack *stack)

{
	int	i;

	i = stack->last_b - stack->defb + 1;
	while (i > 0)
	{
		ft_rrb(stack);
		i--;
	}
	i = stack->defa;
	while (i > 0)
	{
		ft_ra(stack);
		i--;
	}
	ft_pb(stack);
}
