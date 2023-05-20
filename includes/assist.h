#ifndef ASSIST_H
# define ASSIST_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_characters
{
	int *types;
	struct s_characters *next;

}	t_characters;

typedef struct s_type_list
{
	int	index;
	char *type;
	struct s_type_list *next;

}	t_type_list;

int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char const *s1);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void 	make_output(t_characters *c_head, t_type_list *t_head);
void 	clean_up(t_characters *c_head, t_type_list *t_head);
t_characters *make_characters_list(char *file_name);
int *get_char_types(char *line);
int get_character_size(char *line);
t_type_list *make_types_list(char *file_name);
char *take_type(char *line);
int take_index(char *line);
int is_txt(char *file_name);


#endif