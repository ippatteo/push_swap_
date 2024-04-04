/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_okko.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:18 by mcamilli          #+#    #+#             */
/*   Updated: 2024/04/04 16:21:49 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_print_okko(t_stack *stack)
{
	if (is_array_sorted(stack->a, stack->last_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_exit(stack);
	return (0);
}

int	is_array_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
