#include "lem_in.h"



// int	main()
// {
// 	t_li	*t_li;

// 	t_li = ft_memalloc(sizeof(t_li));
// 	if (!initialize_data(t_li))
// 		return (0);
// 	return (0);
// }

// /* for debuging */
// int	main(int ac, char *av[])
// {
// 	t_vec *v;
// 	int fd = open(av[ac - 1], O_RDONLY);

// 	v = init_vector();
// 	initialize_data(v, fd);
// 	return (0);
// }


int	main()
{
	t_vec *v;

	v = init_vector();
	initialize_data(v, 0);
	return (0);
}
