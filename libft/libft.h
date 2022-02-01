/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:59:08 by jahuang           #+#    #+#             */
/*   Updated: 2022/02/01 12:30:11 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;

int		ft_arraylen(char **str);
int		ft_is_prime(int nbr);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
int		ft_next_prime(int nbr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
int		ft_index_of(char *str, char c);
void	ft_putstr_array(char **str_array);
void	ft_putstr_fd(char *s, int fd);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
void	ft_free_char_array(char **char_array);
long	ft_atoi(const char *str);
char	*ft_itoa(int n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t n);

#endif
