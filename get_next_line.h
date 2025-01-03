#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H 
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2
#endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <stdio.h> 

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
char *get_buffer(int fd,char *result);
char *get_f(char *res);
char *get_n(char *res);
char *get_next_line(int fd);
#endif