#ifndef STRUCTS_H
# define STRUCTS_H

# define MAX_PHILOS 200

struct	s_data;

typedef struct s_philo
{
	pthread_t		t1;
	int				id;
	int				eating;
	int				meals_eaten;
	int				last_meal;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				start_time;
	int				philo_nb;
	int				eat_times;
	int				*dead;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_data
{
	int				dead;
	t_philo			*philos;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
}					t_data;

#endif
