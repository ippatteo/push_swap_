/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takeargnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:53:50 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/21 20:50:30 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	takemalloc(t_stack *stack, int ac, char **av)
{
	int j;
	int i;

	i = 0;
	j = 1;
    while (j <= ac - 2)
	{
		if (takenumbers(av[j], stack))
			return (0);
		i += takenumbers(av[j], stack);
		j++;
	}
	return(i); //da questo dipende see error o no, 0  error, 1 newline
}

int takenumbers(char *avx,t_stack *stack)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while(avx[i])
	{
		while (avx[i] == 32)
			i++;
		if (isdigit(avx[i]))
		{
			n++;
			while (isdigit(avx[i]))
				i++;
		}
		else
			return(0);
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
int onesplit(char *av,t_stack *stack)
{
	char	**tmp;
	int i;
	int j;

	tmp = NULL;
	i = 0;
	j = 0;
	tmp = ft_split(av, ' ');
	while (tmp[i] != NULL)
		i++;
	while (j < i)
	{
		stack->a[j] = ft_atoi(tmp[j], stack);
		stack->last_a = j;
		j++;
	}
	free_matrix(tmp);
	return (1);
}
int takearg(char **av, int ac, t_stack *stack)
{
	if (takemalloc(stack, ac, av))
	{
		if (takemalloc(stack, ac, av) == 1)
			return (0);
		stack->a = (int *)malloc(sizeof(int) * (takemalloc(stack, ac, av)) + 1);
		stack->b = (int *)malloc(sizeof(int) * (takemalloc(stack, ac, av)) + 1);
	}
	else
	{
		write(2, "Error\n", 6);
		return(0);
	}

}
