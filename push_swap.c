/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:11:35 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/12 19:19:47 by aelaoufi         ###   ########.fr       */
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
	creat_array(arr, ac, av);
	array_sort(arr, ac);
	big_chunkus(&lst, &lst2, var, arr);
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
	return (0);
}