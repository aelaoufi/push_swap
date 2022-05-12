/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:11:33 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/13 00:16:53 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdlib.h>
# include<unistd.h>
# include<stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

typedef	struct s_vars
{
	int	mid;
	int	start;
	int	end;
	int	range;
	int ac2;
	int i;
	int rb;
	int ra;
}				t_vars;


t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_atoi(char *str);
void	swap(t_list *stack, int i);
void	rotate(t_list **stack, int i);
void	reverse_rotate(t_list **stack, int i);
void	push(t_list	**stack_1, t_list **stack_2, int i);
void	sort_three(t_list **lst);
int		comp_three(t_list *lst);
void	sort_four(t_list **lst, t_list **lst2);
int		small(char **av, int ac);
void	sort_five(t_list **lst, t_list **lst2);
int		small_sec(t_list *lst, int ac);
int		smallest(t_list *lst);
void	ft_putstr(char *str);
void	creat_list(t_list *lst, int ac, char **av);
void	creat_array(int *arr, int ac, char **av);
void    array_sort(int  *arr, int ac);
void	range(t_vars *var, int ac);
void	big_chunkus(t_list **lst, t_list **lst2, t_vars *var, int *arr);
void	print_action(int i);
void	a_to_b(t_list **lst, t_list **lst2, t_vars *var, int *arr);
void	big_b(t_list **lst2, t_vars *var, int *arr);
void	b_to_a(t_list **lst, t_list **lst2, t_vars *var, int *arr);
int		biggest(t_list *lst);
void	print_rotate(t_vars *var, t_list **lst, t_list **lst2);

#endif