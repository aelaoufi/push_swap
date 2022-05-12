/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:11:35 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/12 18:05:54 by aelaoufi         ###   ########.fr       */
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
	// while(head != NULL)
	// {
	// 	printf("l3mara dial bstila :%d\n", head->content);
	// 	head = head->next;
	// }
	//ft_putstr("-----------------------------------\n");
	//sort_five(&lst, &lst2);
	//i = smallest(lst);
	//printf("i : %d\n", i);
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
	// for (int j = 0; j < ac - 1; j++)
	// 	printf("- %d\n", arr[j]);
	//ft_putstr("-----------------------------------\nsorted array\n");
	// for (int j = 0; j < ac - 1; j++)
	// 	printf("- %d\n", arr[j]);
	//leaks are in permutations
	return (0);
}
// lst2 :18
// lst2 :15
// lst2 :12
// lst2 :11
// lst2 :10
// lst2 :8
// lst2 :9
// lst2 :6
// lst2 :5
// lst2 :4
// lst2 :2
// lst2 :1
	//printf("ppspspspspspspsps");
	//printf("arr : %d",arr[var->ac2 - var->k]);
	//printf("i : %d\n", var->i);
		//exit (1);
		//printf("k : %d\n", var->k);
		//printf("9bl lkhr : %d\n", arr[var->ac2 - 1]);