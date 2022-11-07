/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 00:48:13 by hferraud          #+#    #+#             */
/*   Updated: 2022/08/21 22:45:46 by hferraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

struct	s_int {
	char			*number;
	struct s_int	*next;
};

typedef struct s_dict {
	char			*key;
	char			*data;
	struct s_dict	*next;
}	t_dict;

struct s_int	*parse_int(char *nbr);
t_dict			*parse_dict(char *file_name);
t_dict			*push_dict_elem(t_dict **head, char *key, char *data);
char			**ft_split(char *str, char *charset);
char			*ft_pos_itoa(unsigned int nb);
char			*ft_ten_power(int power);
char			*ft_strdup(char *src);
char			*ft_atoa(char *nbr);
void			ft_putstr(char *str);
void			free_dict_list(t_dict *head);
void			free_nbr_list(struct s_int *head);
int				check_parsed_int(struct s_int *nbr_head, t_dict *dict_head);
int				display_full_nbr(char *nbr, t_dict *dict_head);
int				ft_strcmp(char *s1, char *s2);
int				check_args(char *str);
int				ft_puterr(char *str);
int				ft_strlen(char *str);

#endif
