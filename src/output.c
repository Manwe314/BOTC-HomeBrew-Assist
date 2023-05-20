#include "assist.h"

void make_output(t_characters *c_head, t_type_list *t_head)
{
	t_characters *c_temp = c_head;
	t_type_list *t_temp = t_head;
	int fd = open("OutPut.txt", O_TRUNC | O_CREAT | O_RDWR, 0644);
	int j = 1;
	int i;

	while (c_temp != 0)
	{
		ft_putstr_fd("character ", fd);
		ft_putnbr_fd(j, fd);
		ft_putstr_fd(" : ", fd);
		i = 0;
		while (c_temp->types[i] != -2)
		{
			t_temp = t_head;
			while (t_temp != 0)
			{
				if (t_temp->index == c_temp->types[i])
				{
					ft_putstr_fd(t_temp->type, fd);
					if (c_temp->types[i + 1] != -2)
						ft_putstr_fd(" | ", fd);
					break ;
				}
				t_temp = t_temp->next;
			}
			i++;
		}
		j++;
		ft_putstr_fd("\n\n", fd);
		c_temp = c_temp->next;
	}
	close(fd);
}

void clean_up(t_characters *c_head, t_type_list *t_head)
{
	t_characters *c_temp;
	t_type_list *t_temp;

	if (c_head != 0)
	{
		while (c_head != 0)
		{
			c_temp = c_head;
			c_head = c_head->next;
			free(c_temp->types);
			free(c_temp);
		}
	}
	if (t_head != 0)
	{
		while (t_head != 0)
		{
			t_temp = t_head;
			t_head = t_head->next;
			free(t_temp->type);
			free(t_temp);
		}
	}
}