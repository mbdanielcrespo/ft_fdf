/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:53:02 by danalmei          #+#    #+#             */
/*   Updated: 2023/10/24 14:51:02 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef signed char				t_i8;
typedef unsigned char			t_u8;
typedef const unsigned char		t_cuc;
typedef signed int				t_i32;
typedef unsigned int			t_u32;
typedef signed long long int	t_i64;

typedef size_t					t_size;

/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;
*/

void	ft_bzero(void *str, t_size n);
void	*ft_calloc(t_size count, t_size size);
char	*ft_strdup(const char *str);
void	*ft_memset(void	*ptr, t_i32 ch, t_size n);
void	*ft_memcpy(void	*destptr, const void *srcptr, t_size n);
void	*ft_memchr(const void *s, t_i32 ch, t_size n);
void	*ft_memmove(void *destptr, const void *srcptr, t_size n);
int		ft_memcmp(const void *s1, const void *s2, t_size n);
t_i32	ft_isdigit(t_i32 c);
t_i32	ft_isascii(t_i32 c);
t_i32	ft_isprint(t_i32 c);
t_i32	ft_isalpha(t_i32 c);
t_i32	ft_isalnum(t_i32 c);
t_i32	ft_toupper(t_i32 ch);
t_i32	ft_tolower(t_i32 ch);
t_size	ft_strlen(const char *str);
t_size	ft_strlcpy(char *dest, const char *src, t_size size);
t_size	ft_strlcat(char *s1, const char *s2, t_size n);
t_i32	ft_strncmp(const char *s1, const char *s2, t_size n);
char	*ft_strnstr(const char *big, const char *str, t_size n);
char	*ft_strchr(const char *str, char ch);
char	*ft_strrchr(const char *str, char ch);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(const char *s, t_u32 start, t_size len);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char ch);
t_i32	ft_atoi(const char *str);
char	*ft_itoa(t_i32 n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(t_u32, char*));
void	ft_putchar_fd(t_i8 c, t_i32 fd);
void	ft_putendl_fd(char *s, t_i32 fd);
void	ft_putnbr_fd(t_i32 n, t_i32 fd);
void	ft_putstr_fd(char *s, t_i32 fd);
//void	ft_lstadd_back(t_list **lst, t_list *new);
//void	ft_lstadd_front(t_list **lst, t_list *new);
//void	ft_lstclear(t_list **lst, void (*del)(void *));
//void	ft_lstdelone(t_list *lst, void (*del)(void *));
//void	ft_lstiter(t_list *lst, void (*f)(void *));
//t_list	*ft_lstlast(t_list *lst);
//t_list	*ft_lstmap(t_list *lst, void*(*f)(void *), void (*del)(void *));
//t_list	*ft_lstnew(int *content);
//t_i32	ft_lstsize(t_list *lst);

int		ft_printf(const char *str, ...);
int		ft_print_ptr(unsigned long ptr);
int		ft_putchar_fdp(t_i8 c, t_i32 fd);
void	ft_putendl_fd(char *s, t_i32 fd);
int		ft_putnbr_fdp(t_i32 n, t_i32 fd);
int		ft_putstr_fdp(char *s, t_i32 fd);

int		ft_pow(int num, int pow);
void	ft_swap(int *x, int *y);
void	ft_error(char *msg);

#endif
