#include "get_next_line.h"
char *get_buffer(int fd,char *result)
{
    int i;
    char *buff;
    buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if(!buff)
        return (NULL);
    while((i = read(fd,buff,BUFFER_SIZE)) > 0)
    {
        if(i == -1)
        {
            free(buff);
            free(result);
            return (NULL);
        }
        if(i == 0)
            break;
        buff[i] = '\0';
        result = ft_strjoin(result,buff);
        if(ft_strchr(buff,'\n'))
            break;
    }
    free(buff);
    return (result);
}
char *get_f(char *res)
{
    int i;
    char *line;

    i = 0;
    while(res[i] && res[i] != '\n')
        i++;
    while(res[i] == '\n')
        i++;
    line = ft_substr(res,0,i);
    return(line);
}
char *get_n(char *res)
{
    int i;
    char *line;

    i = 0;
    while(res[i] && res[i] != '\n')
        i++;
    while(res[i] == '\n')
        i++;
    line = ft_substr(res,i,ft_strlen(res) - i);
    free(res);
    return(line);
}
char *get_next_line(int fd)
{
    static char *res;
    char *line;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    res = get_buffer(fd,res);
    if(!res)
        return (NULL);
    line = get_f(res);
    res = get_n(res);
    return(line);
}
int main()
{ 
    int fd = open("test.txt",O_RDONLY);
    char *line;
    while((line = get_next_line(fd)))
    {
        printf("%s\n",line);
        free(line);
    }
    close(fd);
    return (0);
}

