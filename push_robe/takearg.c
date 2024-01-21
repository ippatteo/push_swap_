/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takearg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:05:57 by mcamilli          #+#    #+#             */
/*   Updated: 2024/01/21 19:56:25 by mcamilli         ###   ########.fr       */
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
	return(i);
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
int onesplit(char git add ,*av,t_stack *stack)
{
	char	**tmp;
	int i;
	int j;

	tmp = NULL;
	i = 0;
	j = 0;
	tmp = ft_split(av[1], ' ');
	while (tmp[i] != NULL)
		i++;
	if (i <= 1)
	{
		free_matrix(tmp);
		return (0);
	}
	stack->a = (int *)malloc(sizeof(int) * (i) + 1);
	stack->b = (int *)malloc(sizeof(int) * (i) + 1);
	while (j <= i - 1)
	{
		stack->a[j] = ft_atoi(tmp[j], stack);
		stack->last_a = j;
		j++;
	}
	free_matrix(tmp);
	return (1);
}

int splittone(char **av,t_stack *stack)
{
	char	**tmp;
	int i;
	int j;

	tmp = NULL;
	i = 0;
	j = 0;
	tmp = ft_split(av[1], ' ');
	while (tmp[i] != NULL)
		i++;
	if (i <= 1)
	{
		free_matrix(tmp);
		return (0);
	}
	stack->a = (int *)malloc(sizeof(int) * (i) + 1);
	stack->b = (int *)malloc(sizeof(int) * (i) + 1);
	while (j <= i - 1)
	{
		stack->a[j] = ft_atoi(tmp[j], stack);
		stack->last_a = j;
		j++;
	}
	free_matrix(tmp);
	return (1);
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
			//printf("nope error pos %d\n", k);
			return(0);
		}
		if (stack->a[0] > stack->a[1] && stack->a[2] < stack->a[1])
		{
			//printf("nope error pos %d\n", k);
			return(0);
		}
		k++;
	}
	//printf("ok\n");
	return (1);
}
