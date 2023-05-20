#include "assist.h"

int get_character_size(char *line)
{
	int i = 0;
	int size = 0;

	while (line[i] != '\0')
	{
		while (line[i] == ' ' && line[i] != '\0')
			i++;
		if (line[i] == '\0')
			break ;
		while (line[i] != ' ' && line[i] != '\0')
			i++;
		size++;
	}
	return size;
}

int *get_char_types(char *line)
{
	int size = get_character_size(line);
	int *types = (int *)malloc(sizeof(int) * (size + 1));
	int i = 0;
	int j = 0;

	while (line[i] != '\0')
	{
		types[j] = ft_atoi(line + i);
		if (types[j] < 0)
		{
			printf("Please only use positive indexes on this line:\n%s\n", line);
			free(types);
			return 0;
		}
		j++;
		while(line[i] == ' ' && line[i] != '\0')
			i++;
		while (line[i] != ' ' && line[i] != '\0')
			i++;
	}
	types[j] = -2;
	return (types);
}

t_characters *make_characters_list(char *file_name)
{
	int fd;
	char *line;
	t_characters *head;
	t_characters *traverse;

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
	traverse = malloc(sizeof(t_characters));
	head = traverse;
	line = get_next_line(fd);
	while (line != 0)
	{
		traverse->types = get_char_types(line);
		line = get_next_line(fd);
		if (line != 0)
			traverse->next = malloc(sizeof(t_characters));
		else
			traverse->next = 0;
		traverse = traverse->next;
	}
	close(fd);
	return (head);
}