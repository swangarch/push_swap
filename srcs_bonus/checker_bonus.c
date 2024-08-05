/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:42:27 by shuwang           #+#    #+#             */
/*   Updated: 2024/08/05 18:42:29 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int is_instruction(char *str)
{
    if (!ft_strcmp(str, "sa\n") || !ft_strcmp(str, "sb\n") || !ft_strcmp(str, "ss\n"))
        return (1);
    if (!ft_strcmp(str, "pa\n") || !ft_strcmp(str, "pb\n"))
        return (1);
    if (!ft_strcmp(str, "ra\n") || !ft_strcmp(str, "rb\n") || !ft_strcmp(str, "rr\n"))
        return (1);
    if (!ft_strcmp(str, "rra\n") || !ft_strcmp(str, "rrb\n") || !ft_strcmp(str, "rrr\n"))
        return (1);
    return (0);
}

void run_instruct(t_list **lsta, t_list **lstb, char *instruct)
{
    if (!ft_strcmp(instruct, "sa\n"))
        sa_bonus(lsta, lstb);
    if (!ft_strcmp(instruct, "sb\n"))
        sb_bonus(lsta, lstb);
    if (!ft_strcmp(instruct, "ss\n"))
        ss_bonus(lsta, lstb);
    if (!ft_strcmp(instruct, "pa\n"))
        pa_bonus(lsta, lstb);
    if (!ft_strcmp(instruct, "pb\n"))
        pb_bonus(lsta, lstb);
    if (!ft_strcmp(instruct, "ra\n"))
        ra_bonus(lsta, lstb);
    if (!ft_strcmp(instruct, "rb\n"))
        rb_bonus(lsta, lstb);
    if (!ft_strcmp(instruct, "rr\n"))
        rr_bonus(lsta, lstb);
    if (!ft_strcmp(instruct, "rra\n"))
        rra_bonus(lsta, lstb);
    if (!ft_strcmp(instruct, "rrb\n"))
        rrb_bonus(lsta, lstb);
    if (!ft_strcmp(instruct, "rrr\n"))
        rrr_bonus(lsta, lstb);
}

void check(t_list **lsta, t_list **lstb, int *inputs)
{
    char	*instruct;

	if (lst_sorted(*lsta) && ft_lstsize(*lstb) == 0)
		return ;
	instruct = get_next_line(STDIN_FILENO);
    while(instruct != NULL)
    {
        if (!is_instruction(instruct))
        {
			free(instruct);
			delete_stack(lsta, lstb, inputs);
            write(2, "Error\n", 6);
            exit(EXIT_FAILURE);
        }
        run_instruct(lsta, lstb, instruct);
		free(instruct);
		instruct = get_next_line(STDIN_FILENO);
    }
	free(instruct);
    if (lst_sorted(*lsta) && ft_lstsize(*lstb) == 0)
        ft_putstr_fd("OK\n", 1);
    else
        ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	int			*inputs;
	t_list		*lsta;
	t_list		*lstb;
	int 		num_elements;

	inputs = NULL;
	lsta = NULL;
	lstb = NULL;
	num_elements = 0;
	if (argc == 2)
		input_save_argvinquote(argv, &inputs, &num_elements);
	else
		input_save_multiargv(argc, argv, &inputs, &num_elements);
	copy_tab_tolst(&lsta, inputs, num_elements);

	check(&lsta, &lstb, inputs);
	delete_stack(&lsta, &lstb, inputs);
	return (0);
}

