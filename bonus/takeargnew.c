/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takeargnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:53:50 by mcamilli          #+#    #+#             */
/*   Updated: 2024/04/04 12:10:12 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	takemalloc(int ac, char **av)
{
	int	j;
	int	i;

	i = 0;
	j = 1;
	while (j <= ac - 1)
	{
		if (!takenumbers(av[j]))
			return (0);
		i += takenumbers(av[j]);
		j++;
	}
	return (i);
}

int	takenumbers(char *avx)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (avx[i])
	{
		while (avx[i] == ' ')
			i++;
		if (avx[i] == '-' || avx[i] == '+')
			i++;
		if (avx[i] == '\0')
			return (n);
		if (ft_isdigit(avx[i]))
		{
			n++;
			while (ft_isdigit(avx[i]))
				i++;
		}
		else
			return (0);
	}
	return (n);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	onesplit(char *av, t_stack *stack)
{
	char		**tmp;
	int			i;
	int			j;
	static int	n;

	tmp = NULL;
	i = 0;
	j = 0;
	tmp = ft_split(av, ' ');
	while (tmp[i] != NULL)
		i++;
	while (j < i)
	{
		stack->a[n] = ft_atoi(tmp[j], stack);
		n++;
		stack->last_a = n;
		j++;
	}
	free_matrix(tmp);
	return (1);
}

int	takearg(char **av, int ac, t_stack *stack)
{
	int	i;

	i = 1;
	if (takemalloc(ac, av))
	{
		if (takemalloc(ac, av) == 1)
			return (0);
		stack->a = (int *)malloc(sizeof(int) * (takemalloc(ac, av)));
		stack->b = (int *)malloc(sizeof(int) * (takemalloc(ac, av)));
		while (i <= ac - 1)
		{
			onesplit(av[i], stack);
			i++;
		}
		stack->last_a--;
		return (1);
	}
	else
	{
		write(2, "Error\n", 6);
		return (0);
	}
}
