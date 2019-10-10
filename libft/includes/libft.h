/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 22:19:38 by ahorker           #+#    #+#             */
/*   Updated: 2019/02/06 19:02:05 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
	size_t			content_size;
}					t_list;

typedef struct		s_2lst
{
	void			*con;
	size_t			*sz;
	struct s_2lst	*prv;
	struct s_2lst	*nxt;
}					t_2lst;

char				**ft_strsplit(const char *c, char s);

char				*ft_itoa(int n);

char				*ft_strcat(char *d, const char *s);

char				*ft_strccpy(char *d, const char *s, char c);

char				*ft_strchr(const char *d, int c);

char				*ft_strcpy(char *d, const char *s);

char				*ft_strdup(const char *c);

char				*ft_strjoin(const char *c1, const char *c2);

char				*ft_strmap(char const *a, char(*f)(char));

char				*ft_strmapi(char const *a, char(*f)(unsigned int, char));

char				*ft_strncat(char *d, const char *s, size_t n);

char				*ft_strncpy(char *d, const char *s, size_t l);

char				*ft_strnew(size_t n);

char				*ft_strnstr(const char *s1, const char *s2, size_t n);

char				*ft_strrev(char *s);

char				*ft_strrchr(const char *d, int c);

char				*ft_strstr(const char *s1, const char *s2);

char				*ft_strsub(const char *c, unsigned int s, size_t l);

char				*ft_strtrim(const char *c);

double				ft_atof(char *str);

int					ft_atoi(const char *str);

int					ft_atoi_base(const char *str, int str_base);

int					ft_chrcnt(char *s, char c);

int					ft_isalnum(int c);

int					ft_isalpha(int c);

int					ft_isascii(int c);

int					ft_isdigit(int c);

int					ft_isprint(int c);

int					ft_lstdelemp(t_list **lst, t_list *delel);

int					ft_memcmp(const void *a, const void *b, size_t n);

int					ft_sqrtrup(int a);

int					ft_strcmp(const char *c1, const char *c2);

int					ft_strequ(const char *c1, const char *c2);

int					ft_strncmp(const char *c1, const char *c2, size_t n);

int					ft_strnequ(const char *c1, const char *c2, size_t n);

int					ft_tolower(int c);

int					ft_toupper(int c);

int					ft_wrdcount(char *c, char s);

size_t				ft_strlen(const char *c);

size_t				ft_strlcat(char *d, const char *s, size_t l);

size_t				ft_strnlen(const char *c, size_t l);

t_list				*ft_lstaddend(t_list *lst, t_list *n);

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *el));

t_list				*ft_lstnew(void const *con, size_t sc);

t_list				*ft_lstsearch(t_list *list, int (*f)(void *data,\
									t_list elem), void *data);

void				**ft_arrnew(size_t m, size_t n, unsigned char c);

void				*ft_free2d(void ***x);

void				*ft_free3d(void ****x);

void				*ft_memalloc(size_t n);

void				*ft_memccpy(void *d, const void *s, int c, size_t n);

void				*ft_memchr(const void *a, int c, size_t n);

void				*ft_memcpy(void *d, const void *s, size_t n);

void				*ft_memmove(void *d, const void *s, size_t n);

void				*ft_memset(void *s, int c, size_t n);

void				*ft_realloc(void **p, size_t n);

void				*ft_strdel(char **c);

void				ft_bzero(void *s, size_t n);

void				ft_lstadd(t_list **lst, t_list *n);

void				ft_lstdel(t_list **lst, void (*del) (void *, size_t));

void				ft_lstdelone(t_list **lst, void (*del) (void *, size_t));

void				ft_lstiter(t_list *lst, void (*f)(t_list *el));

void				ft_lstpst(t_list **lst, t_list *n, unsigned int p);

void				ft_memdel(void **c);

void				ft_memswap(void *a, void *b, size_t n);

void				ft_putchar_fd(char c, int fd);

void				ft_putchar(char c);

void				ft_putendl_fd(char *c, int fd);

void				ft_putendl(char *c);

void				ft_putnbr_fd(int n, int fd);

void				ft_putnbr(int n);

void				ft_putstr_fd(char *c, int fd);

void				ft_putstr(char *c);

void				ft_strclr(char *c);

void				ft_striter(char *a, void(*f)(char *));

void				ft_striteri(char *a, void(*f)(unsigned int i, char *));

#endif
