#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

#include "../libft/libft.h"
#include <limits.h>

int     all_digits(char *s);
int     check_double(int *num, int count);
void	lst_print(t_list *lst);
int     int_overflow(const char *nptr);
void	ft_lstclear_nfunc(t_list **lst);

void    sa_bonus(t_list **lsta, t_list **lstb);
void    sb_bonus(t_list **lsta, t_list **lstb);
void    ss_bonus(t_list **lsta, t_list **lstb);
void    pa_bonus(t_list **lst1, t_list **lst2);
void    pb_bonus(t_list **lst1, t_list **lst2);
void    ra_bonus(t_list **lsta, t_list **lstb);
void    rb_bonus(t_list **lsta, t_list **lstb);
void    rr_bonus(t_list **lsta, t_list **lstb);
void    rra_bonus(t_list **lsta, t_list **lstb);
void    rrb_bonus(t_list **lsta, t_list **lstb);
void    rrr_bonus(t_list **lsta, t_list **lstb);

int	    lst_sorted(t_list *lst);
void	lst_sort(t_list **lsta, t_list **lstb);

void	free_tab(char **tab);

void	in_fail_multiargv(int **inputs);
void	in_fail_argvinquote(int **inputs, char **args_inquote);
void	delete_stack(t_list **lsta, t_list **lstb, int	*inputs);

void	input_save_multiargv(int argc, char **argv, int **inputs, int *num_elements);
char	**split_args_inquote(char **argv, int **inputs, int *count);
void	input_save_argvinquote(char **argv, int **inputs, int *num_elements);
void	copy_tab_tolst(t_list **lst, int *inputs, int num_elements);

# endif
