/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:08:32 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/12 23:35:16 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}				t_list;

typedef struct s_malloc
{
	void				*ptr;
	struct s_malloc		*next;
}				t_malloc;

# ifndef BIG_NUMBER_H

typedef struct s_dbl
{
	char				sign;
	unsigned long		mantissa;
	int					exponent;
}				t_dbl;
# endif

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			ft_memswap(void *p1, void *p2, size_t bytes);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
long long		ft_atoi(const char *str);
long long		ft_atoi_base(const char *str, const char *base);
int				ft_strlen(const char *s);
int				ft_nbrlen(long long nbr);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, int size);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strdup(const char *str);
char			*ft_reverse_str(char *str);
void			*ft_calloc(size_t count, size_t size);
void			*ft_realloc(void **ptr, size_t orig_size, size_t new_size);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(char c);
int				ft_tolower(int c);
int				ft_toupper(int c);

long long		ft_exp(long long nbr, int exp);

char			*ft_substr(const char *s, unsigned int start, int len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s1, const char *set);
char			**ft_split(const char *s, char c);
char			*ft_itoa(long long n);
char			*ft_utoa(unsigned long long n);
char			*ft_itoa_base(long long n, const char *base);
char			*ft_utoa_base(unsigned long long n, const char *base);
char			*ftoa(double nbr);
char			*ft_ftoa(double d, int precision);
char			*ft_convert_base(char *str, char *base_from, char *base_to);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putendl_fd(char *str, int fd);
void			ft_putnbr_fd(int nbr, int fd);
void			ft_putfloat(double f, int precision);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **list, t_list *new);
int				ft_lstsize(t_list *list);
t_list			*ft_lstlast(t_list *list);
void			ft_lstadd_back(t_list **list, t_list *new);
void			ft_lstdelone(t_list *list, void (*del)(void *));
void			ft_lstclear(t_list **list, void (*del)(void *));
void			ft_lstiter(t_list *list, void (*f)(void *));
t_list			*ft_lstmap(t_list *list,
					void *(*f)(void *), void (*del)(void *));

void			*malloc_list(size_t size);
void			free_list(void);
void			free_one(void *ptr);

#endif
