/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:11:35 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/14 16:28:46 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int ac, char **av)
{
	t_list  *lst;
    t_list  *head;
	t_list	*lst2;
	t_vars	*var;
	int		arr[ac - 1];
	
	var = malloc(sizeof(t_vars));
	range(var, ac);
	if (ac == 1)
		return(0);
    lst = ft_lstnew(ft_atoi(av[1]));
    head = lst;
	creat_list(lst, ac, av);
	if (ac - 1 == 3)
		sort_three(&lst);
	else if (ac - 1 == 4)
		sort_four(&lst, &lst2);
	else if (ac - 1 == 5)
		sort_five(&lst, &lst2);
	else
	{
		creat_array(arr, ac, av);
		array_sort(arr, ac);
		big_chunkus(&lst, &lst2, var, arr);
	}
	// while(lst != NULL)
	// {
	// 	printf("lst :%d\n", lst->content);
	// 	lst = lst->next;
	// }
	// ft_putstr("-----------------------------------\n");
	// while(lst2 != NULL)
	// {
	// 	printf("lst2 :%d\n", lst2->content);
	// 	lst2 = lst2->next;
	// }
	//leaks are in permutations
	// system("leaks push_swap");
	return (0);
}