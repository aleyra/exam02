#include "unistd.h"
#include "stdarg.h"

typedef struct	s_pf
{
	va_list		lst;
	int			width;
	int			fpre;
	int			vpre;
	char		type;
	int			ret;
}				t_pf;

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_display_s(t_pf *tpf, char *str)
{
	int		i;

	i = 0;
	//40 min
}

void	ft_display_d(tpf *tpf, int d)
{
	int		i;

	i = 0;
}

void	ft_display_x(t_pf *tpf, unsigned int u)
{
	int		i;
	
	i = 0;
}

int		ft_scan(t_pf *tpf, const char *s)
{
	int		i;

	i = 0;
	tpf->width = 0;
	while(ft_isdigit(s[i]))
	{
		tpf->width = tpf->width * 10 + s[i] - '0';
		i++;
	}
	tpf->fpre = 0;
	if(s[i] == '.')
	{
		tpf->fpre++;;
		i++;
	}
	tpf->vpre = 0
	if(s[i] != '-')
		while(ft_isdigit(s[i]))
		{
			tpf->vpre = tpf->vpre * 10 + s[i] - '0';
			i++;
		}
	else
	{
		i++;
		while(ft_isdigit(s[i]))
			i++;
	}
	if(s[i] == 's')
	{
		ft_display_s(tpf, va_arg(tpf->lst, char *));
		i++;
	}
	else if(s[i] == 'd')
	{
		ft_display_d(tpf, va_arg(tpf->lst, int));
		i++;
	}
	else if (s(i) == 'x')
	{
		ft_display_x(tpf, va_arg(tpf->lst, unsigned int));
		i++;
	}
	return (i);
}

int		ft_printf(const char *s, ... )
{
	t_pf	tpf;
	int		i;

	i = -1;
	va_start(tpf.lst, s);
	if(!s)
		return (-1);
	while(s[++i])
	{
		if(s[i] != '%')
			write(1, &s[i], 1);
		else
			i += ft_scan(&tpf, s + i);
	}
	va_end(tpf.lst);
	return (tpf.ret); 
}