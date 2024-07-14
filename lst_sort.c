#include "push_swap.h"
#include "libft.h"

void	lst_sort(t_list **lsta, t_list **lstb)
{
	int	size = ft_lstsize(*lsta);
	int	i = 0;
	
	ft_printf("list a size is %d\n", size);

	if (size >= 2)
	{
        /*
		while (i < size / 2)先随机等分成两组
		{
            pb(lsta, lstb);
            print_stack(*lsta, *lstb);
			i++;
		}
        */
        i = 0;

        while (i < ft_lstsize(*lsta) * ft_lstsize(*lsta) * ft_lstsize(*lsta))
        {
            if (*((int *)((*lsta)->content)) > *((int *)((*lsta)->next->content)))
	        {
                sa(lsta, lstb);
		        rra(lsta, lstb);
            }
            else
	        {
		        rra(lsta, lstb);
            }
            print_stack(*lsta, *lstb);
            if (lst_sorted(*lsta))
            {
                ft_printf("Sorted\n");
                print_stack(*lsta, *lstb);
                return;
            }
            i++;
        }
    }    
    ft_printf("\nList sorted: %s\n\n\n", (lst_sorted(*lsta) ? "Yes" : "No"));
	ft_printf("list a size is %d\n", ft_lstsize(*lsta));
}
/*
void	lst_sort(t_list **lsta, t_list **lstb)
{
	int	size = ft_lstsize(*lsta);
	int	i = 0;
	int	j = 0;
	
	ft_printf("list a size is %d\n", size);

	if (size >= 2)
	{
		while (i < 100)
		{
			j = 0;
			while (j < 100)
			{
				ft_printf("Before condition: size = %d\n", ft_lstsize(*lsta));
				print_stack(*lsta, *lstb);
				if (*((int *)((*lsta)->content)) > *((int *)((*lsta)->next->content)))
				{
					sa(lsta, lstb);
					ra(lsta, lstb);
				}
				//else
				//	ra(lsta, lstb);
				ft_printf("After condition: size = %d\n", ft_lstsize(*lsta));
				print_stack(*lsta, *lstb);
				j++;
			}
			i++;
		}
	}

    ft_printf("\nList sorted: %s\n\n\n", (lst_sorted(*lsta) ? "Yes" : "No"));
	ft_printf("list a size is %d\n", ft_lstsize(*lsta));
}*/