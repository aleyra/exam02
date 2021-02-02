#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while(str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if(!(s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while(s1 && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while(s1 && s2[j])
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = 0;
	if(s1)
		free(s1);
	return (s);
}

int		get_next_line(char **line)
{
	int		ret;
	char	buf[2];

	if(!line)
		return (-1);
	if (*line)
		free(*line);
	buf[0] = 'a';
	buf[1] = 0;
	*line = NULL;
	while((ret = read(0, buf, 1) > 0 && buf[0] != '\n'))
	{
		*line = ft_strjoin(*line, buf);
		if(!line)
			return (-1);
	}
	if (ret == -1)
	{
		if (*line)
			free(*line);
		return (-1);
	}
	if(ret == 0 && buf[0] != '\n')
	{
		*line = ft_strjoin(*line, buf);
		if(!line)
			return (-1);
	}
	if(buf[0] == '\n' && *line == NULL)
	{
		*line = ft_strjoin(*line, "");
		if(!line)
			return (-1);
	}
	return (ret);
}