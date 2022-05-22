/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:15:27 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/22 10:38:02 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include<stdlib.h>
# include<unistd.h>
# include<stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

typedef struct s_line
{
	int			reader;
	char		*line;
	char		*buf;
	char		*temp;
}				t_line;

void	creat_list(t_list *lst, int ac, char **av);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	swap(t_list *stack, int i);
void	rotate(t_list **stack, int i);
void	reverse_rotate(t_list **stack, int i);
void	push(t_list	**stack_1, t_list **stack_2, int i);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(char *str, int c);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *dst, size_t n);
void	ft_isdigit(char *str, long res, int sign);
void	check_dupl(t_list *lst);
void	print_error(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif