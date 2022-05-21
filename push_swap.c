/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:11:35 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/21 23:23:46 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_method(int ac, t_list *lst, t_list *lst2)
{
	if (ac - 1 == 2)
		swap(lst, 1);
	else if (ac - 1 == 3)
		sort_three(&lst);
	else if (ac - 1 == 4)
		sort_four(&lst, &lst2);
	else if (ac - 1 == 5)
		sort_five(&lst, &lst2);
}

int	main(int ac, char **av)
{
	t_list	*lst;
	t_list	*lst2;
	t_vars	*var;
	int		arr[ac - 1];

	var = malloc(sizeof(t_vars));
	range(var, ac);
	if (ac == 1)
		return (0);
	lst = ft_lstnew(ft_atoi(av[1]));
	creat_list(lst, ac, av);
	is_sorted(lst, lst2);
	check_dupl(lst);
	sorting_method(ac, lst, lst2);
	if (ac - 1 > 5)
	{
		creat_array(arr, ac, av);
		array_sort(arr, ac);
		big_chunkus(&lst, &lst2, var, arr);
	}
	return (0);
}
