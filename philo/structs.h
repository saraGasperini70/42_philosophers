#ifndef STRUCTS_H
# define STRUCTS_H

struct	s_data;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t1;
	int				id;
	int				time_to_eat;
	int				status;
	int				eating;
	__uint64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
}	t_philo;

typedef struct s_data
{
	pthread_t		*tid;
	int				philo_nb;
	int				meals_nb;
	int				dead;
	int				finished;
	t_philo			*philos;
	__uint64_t		death_time;
	__uint64_t		eat_time;
	__uint64_t		sleep_time;
	__uint64_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_data;

#endif
