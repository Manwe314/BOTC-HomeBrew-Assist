#include "assist.h"

int take_index(char *line)
{
	int i = 0;
	char *index;
	int number;

	while (line[i] != '.' && line[i] != '\0')
		i++;
	if (i == 0)
	{
		printf("This line does not have an index:\n%s\n",line);
		return -1;
	}
	if (line[i] == '\0')
		return -1;
	index = ft_substr(line, 0, i);
	number = ft_atoi(index);
	if (number < 0)
	{
		printf("Please use a positive index on this line:\n%s\n", line);
		return -1;
	}
	return number;
}

char *take_type(char *line)
{
	int i = 0;
	while (line[i] != '.' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return 0;
	i++;
	while (line[i] == ' ' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (ft_strdup("[EMPTY]"));
	else
		return (ft_strdup(line + i));
}

t_type_list *make_types_list(char *file_name)
{
	int fd;
	char *line;
	t_type_list *head;
	t_type_list *traverse;

	if (!is_txt(file_name))
	{
		printf("File %s is not a .txt file\n", file_name);
		return 0;
	}
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		printf("Failed opening the file: %s\n", file_name);
		return 0;
	}
	traverse = (t_type_list *)malloc(sizeof(t_type_list));
	head = traverse;
	line = get_next_line(fd);
	while (line != 0)
	{
		traverse->index = take_index(line);
		traverse->type = take_type(line);
		line = get_next_line(fd);
		if (line != 0)
			traverse->next = (t_type_list *)malloc(sizeof(t_type_list));
		else
			traverse->next = 0;
		traverse = traverse->next;
	}
	close(fd);
	return (head);
}
