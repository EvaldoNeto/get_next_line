/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:42:22 by eneto             #+#    #+#             */
/*   Updated: 2018/05/01 13:43:44 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree
{
	void			*data;
	size_t			data_size;
	struct s_btree	*right;
	struct s_btree	*left;
}					t_btree;

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putendl(char const *s);
size_t				ft_strlen(const char *str);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *big,
					const char *little, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_btree				*btree_create_node(void const *data, size_t data_size);
void				btree_apply_postorder(t_btree *root,
					void (*applyf)(void *));
int					btree_node_level(t_btree *root, t_btree *node, int i);
int					ft_max(int a, int b);
int					btree_height(t_btree *root);
void				btree_print(t_btree *root, int n, void (*print)(void *));
void				btree_print_level(t_btree *root, int level);
int					ft_power(int base, int n);
int					btree_nodes_per_level(t_btree *root, int level);
void				btree_nodes_in_level(t_btree **dest, t_btree *root,
					int level);
t_btree				*btree_insert_data(t_btree *root, void *data,
					size_t data_size, int (*cmpf)(void *, void *));
t_btree				*btree_right_rotate(t_btree *node);
t_btree				*btree_left_rotate(t_btree *node);
t_btree				*btree_insert_avl(t_btree **root, void *data,
					size_t data_size, int (*cmpf)(void *, void *));
t_btree				*btree_search_data(t_btree *root, void *data,
					int (*cmpf)(void *, void *));
t_btree				*btree_min(t_btree *root);
char				*ft_strjoin_free(char *s1, char *s2);
t_btree				*btree_deletenode_avl(t_btree **root, void *data,
							int (*cmpf)(void *, void *), void (*del)(void *));

#endif
