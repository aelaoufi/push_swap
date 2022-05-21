/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:20:03 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/21 16:18:49 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{	
	if (s1 == NULL)
		return 0;
	while ((*s1 != '\0') || (*s2 != '\0'))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

int	check_actions(char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		return(1);
	else if (ft_strcmp(str, "sb\n") == 0)
		return(1);
	else if (ft_strcmp(str, "ra\n") == 0)
		return(1);
	else if (ft_strcmp(str, "rb\n") == 0)
		return(1);
	else if (ft_strcmp(str, "pb\n") == 0)
		return(1);
	else if (ft_strcmp(str, "pa\n") == 0)
		return(1);
	else if (ft_strcmp(str, "rra\n") == 0)
		return(1);
	else if (ft_strcmp(str, "rrb\n") == 0)
		return(1);
	else if (ft_strcmp(str, "ss\n") == 0)
		return(1);
	else if (ft_strcmp(str, "rr\n") == 0)
		return(1);	
	else if (ft_strcmp(str, "rrr\n") == 0)
		return(1);
	return (0);
}

void	do_actions(char *str, t_list **lst, t_list **lst2)
{
	if (ft_strcmp(str, "sa\n") == 0)
		swap(*lst, 0);
	if (ft_strcmp(str, "sb\n") == 0)
		swap(*lst2, 0);
	if (ft_strcmp(str, "ra\n") == 0)
		rotate(lst, 0);
	if (ft_strcmp(str, "rb\n") == 0)
		rotate(lst2, 0);
	if (ft_strcmp(str, "pb\n") == 0)
		push(lst, lst2, 0);
	if (ft_strcmp(str, "pa\n") == 0)
		push(lst2, lst, 0);
	if (ft_strcmp(str, "rra\n") == 0)
		reverse_rotate(lst, 0);
	if (ft_strcmp(str, "rrb\n") == 0)
		reverse_rotate(lst2, 0);
	if (ft_strcmp(str, "ss\n") == 0)
	{
		swap(*lst, 0);
		swap(*lst2, 0);
	}
	if (ft_strcmp(str, "rr\n") == 0)
	{
		rotate(lst, 0);
		rotate(lst2, 0);
	}
	if (ft_strcmp(str, "rrr\n") == 0)
	{
		reverse_rotate(lst, 0);
		reverse_rotate(lst2, 0);
	}
}

int	is_sorted(t_list *lst, t_list *lst2)
{
	t_list	*head;

	head = lst;
	if (ft_lstsize(lst2) != 0)
	{
		ft_putstr("KO\n");
		exit(0);
	}		
	while (head->next)
	{
		if (head->content > (head->next)->content)
			return (0);
		head = head->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	*str;
	t_list	*lst;
	t_list	*lst2;

	lst = ft_lstnew(ft_atoi(av[1]));
	creat_list(lst, ac, av);
	int i = 0;
	str =  get_next_line(0);
	while (str)
	{
		if (check_actions(str) == 0)
		{
			ft_putstr("error\n");
			exit(0);
		}
		do_actions(str, &lst, &lst2);
		str =  get_next_line(0);
	}
	t_list *tmp = lst;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	if (is_sorted(lst, lst2) == 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}
