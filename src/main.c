#include "assist.h"

int is_txt(char *file_name)
{
	int i = ft_strlen(file_name);

	i -= 4;
	if (ft_strncmp((file_name + i), ".txt", 4) != 0)
		return 0;
	return 1;
}

int main(int argc, char *argv[])
{
	t_type_list *type_head;
	t_characters *charater_head;

	if (argc < 3 || argc > 4)
	{
		printf("Invalid number of arguments\n");
		printf("please enter:\n[type categories file].txt [character types distribution].txt [optional flag]\n");
		printf("reead README.md for more information\n");
		return 0;
	}
	type_head = make_types_list(argv[1]);
	charater_head = make_characters_list(argv[2]);

	if (type_head == 0 || charater_head == 0)
	{
		clean_up(charater_head, type_head);
		printf("Error encountered with files\n");
		return 0;
	}
	make_output( charater_head, type_head );
	clean_up(charater_head, type_head );
	return 0;
}