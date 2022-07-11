/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:28:51 by abara             #+#    #+#             */
/*   Updated: 2016/09/12 14:24:25 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 8

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memset(void *s, int c, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strcat(char *dest, char const *src);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strrchr(const char *s, int c);
int					ft_atoi(char *str);
int					ft_tolower(int c);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
void				ft_bzero(void *s, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_isalpha(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strcpy(char *dest, const char *src);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_toupper(int c);
int					ft_isprint(int c);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isalnum(int c);
int					ft_isascii(int c);
char				*ft_strchr(const char *s1, int c);
int					ft_isdigit(int c);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putstr(char const *s);
void				ft_putchar(char c);
void				ft_putendl(char const *s);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(long long n);
char				*ft_strncat(char *dest, char const *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				**ft_strsplit(const char *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_putendl_fd(char const *s, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_ispremier(int c);
int					ft_fact(int c);
int					get_next_line(int const fd, char **line);
char				*convert_to_base(unsigned long nb, int base, int maj);

#endif