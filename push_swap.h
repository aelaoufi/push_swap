/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:11:33 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/04/02 15:03:04 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_atoi(char *str);
void    swap(t_list *stack);

#endif