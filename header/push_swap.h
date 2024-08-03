#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <limits.h>

int     all_digits(char *s);
int     check_double(int *num, int count);
void	lst_print(t_list *lst);
int     int_overflow(const char *nptr);
void	ft_lstclear_nfunc(t_list **lst);

void    sa(t_list **lsta, t_list **lstb);
void    sb(t_list **lsta, t_list **lstb);
void    ss(t_list **lsta, t_list **lstb);
void    pa(t_list **lst1, t_list **lst2);
void    pb(t_list **lst1, t_list **lst2);
void    ra(t_list **lsta, t_list **lstb);
void    rb(t_list **lsta, t_list **lstb);
void    rr(t_list **lsta, t_list **lstb);
void    rra(t_list **lsta, t_list **lstb);
void    rrb(t_list **lsta, t_list **lstb);
void    rrr(t_list **lsta, t_list **lstb);

int	    lst_sorted(t_list *lst);
void	lst_sort(t_list **lsta, t_list **lstb);
void	free_tab(char **tab);
void	print_stack(t_list *lsta, t_list *lstb);
int     lst_value(t_list **lst);
int     lst_index_value(t_list *lst, int index);
void	lst_sort_small(t_list **lsta, t_list **lstb);
void    push_low_cost(t_list **lsta, t_list **lstb);
int     target_index(t_list *lsta, t_list *lstb, int indexa);

int    step_move_top(t_list *lst, int index);
int     ft_abs(int num);

# endif
