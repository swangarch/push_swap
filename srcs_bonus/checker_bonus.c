#include "push_swap.h"
#include "libft/libft.h"

int	*save_inputs(int *inputs, int argc, char **argv, int i)
{
	inputs = malloc(sizeof(int) * (argc - 1));
	if (inputs == NULL)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	while(i < argc)
	{
		if (all_digits(argv[i]) && !int_overflow(argv[i]))
			inputs[i - 1] = ft_atoi(argv[i]);
		else
		{
			write(2, "Error\n", 6);
			free(inputs);
			return (NULL);
		}
		i++;
	}
	if (check_double(inputs, i - 1))
	{
		write(2, "Error\n", 6);
		free(inputs);
		return (NULL);
	}
	return (inputs);
}

int	input_error(int argc, char **argv, int *inputs)
{
	int	i;

	i = 1;
	while(i < argc)
	{
		if (all_digits(argv[i]) && !int_overflow(argv[i]))
			inputs[i - 1] = ft_atoi(argv[i]);
		else
		{
			write(2, "Error\n", 6);
			free(inputs);
			return (1);
		}
		i++;
	}
	if (check_double(inputs, i - 1))
	{
		write(2, "Error\n", 6);
		free(inputs);
		return (1);
	}
	return (0);
}

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

int	lst_sorted(t_list *lst)
{
	t_list *currnode;
	
	currnode = lst;
	if (ft_lstsize(lst) <= 1)
        return (1);
	while (currnode->next)
    {
        if (*((int *)(currnode->content)) > *((int *)(currnode->next->content)))
            return (0);
        currnode = currnode->next;
    } 
    return (1);
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

void check(t_list **lsta, t_list **lstb)
{
    char *instruct;

    while(instruct = get_next_line(STDIN_FILENO))
    {
        if (!is_instruction(instruct))
        {
            ft_putstr_fd("Error\nNot a instruction\n");
            exit(EXIT_FAILURE);
        }
        run_instruct(lsta, lstb, instruct);
    }
    if (lst_sorted(lsta))
    {
        ft_putstr_fd("OK\n", 1);
    }
    else
    {
        ft_putstr_fd("KO\n", 1);
    }
}

while(instruct = get_next_line(STDIN_FILENO))
{
    if (!is_instruction(instruct))
    {
        ft_putstr_fd("Error\nNot a instruction\n");
        exit(EXIT_FAILURE);
    }
}

int	main(int argc, char **argv)
{
	int	i;
	int	*inputs;
	t_list	*lsta;
	t_list	*lstb;

	lsta = NULL;
	lstb = NULL;
	inputs = malloc(sizeof(int) * (argc - 1));
	if (inputs == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (input_error(argc, argv, inputs))
		return (1);
	i = 0;
	while (i < argc - 1)
	{
		ft_lstadd_back(&lsta, ft_lstnew((void *) (&inputs[i])));  //此处如果lstnew fail 有可能leak
		i++;
	}
    free(inputs);

	check(lsta, lstb);
	ft_lstclear_nfunc(&lsta);
    ft_lstclear_nfunc(&lstb);
	return (0);
}