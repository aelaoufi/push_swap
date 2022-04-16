/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:11:35 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/04/16 21:14:29 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int ac, char **av)
{
	t_list  *lst;
    t_list  *head;
	t_list	*lst2;
	int	i;
	
	i = 1;
	if (ac == 1)
		return(0);
    lst = ft_lstnew(ft_atoi(av[i]));
    head = lst;
    while (i < ac - 1)
    {
        ft_lstadd_back(&lst, ft_lstnew(ft_atoi(av[i + 1])));
        i++;
    }
	while(head != NULL)
	{
		printf("%d\n", head->content);
		head = head->next;
	}
	printf("-----------------------------------\n");
	sort_four(&lst, &lst2, av, ac);
	while(lst != NULL)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
	printf("-----------------------------------\n");
	while(lst2 != NULL)
	{
		printf("%d\n", lst2->content);
		lst2 = lst2->next;
	}
	//leaks are in permutations
	return (0);
}