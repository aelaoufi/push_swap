/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:15:27 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/15 16:19:56 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
#define CHECKER_BONUS_H

# include<stdlib.h>
# include<unistd.h>
# include<stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

void	creat_list(t_list *lst, int ac, char **av);
int     ft_atoi(char *str);
void	ft_putstr(char *str);
void	array_sort(int *arr, int ac);
void	creat_array(int *arr, int ac, char **av);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	swap(t_list *stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	push(t_list	**stack_1, t_list **stack_2);

#endif