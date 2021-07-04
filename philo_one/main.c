
#include "philo_one.h"

int	main(int argc, char *argv[])
{
	t_self	*self;

	if (is_validate_parametrs(argc, argv) != -1)
		return (1);
	self = ft_calloc(1, sizeof(t_self));
	self->param = get_parameters(argc, argv);
	self->mutex = init_mutex(self->param);
	self->arr_philo = init_philosophers(self->param, self->mutex);
	create_threads(self);
	printf("End of simulation\n");
	clear_all_malloc(self);
	return (0);
}
