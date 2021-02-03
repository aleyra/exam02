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
	int		len;

	i = 0;
	if (str == NULL)
	{
		str = "(null)";
	}
	len = 0;
	while(str[len])
		len++;
	if(len >= tpf->width)
	{
		tpf->ret += len;
	}
	else
		tpf->ret += tpf->width;
	if(tpf->vpre > len || tpf->vpre == 0)
		tpf->vpre = len;
	while(i < tpf->width - tpf->vpre)
	{
		write(1, " ", 1);
		i++;
	}
	i = 0;
	while(i < tpf->vpre)
		write(1, &str[i++], 1);
}

void	ft_display_d(t_pf *tpf, int d)
{
	int		i;
	int		len;
	long	p;
	long	n;
	char	z;

	i = 0;
	len = 0;
	p = 1;
	z = '0';
	n = (d < 0) ? d * -1 : d;
	while(10 * p < n)
	{
		len++;
		p *= 10;
	}
	if(len >= tpf->width)
	{
		tpf->ret += len;
	}
	else
		tpf->ret += tpf->width;
	if(tpf->vpre < len)
		tpf->vpre = len;
	if (d > 0)
	{
		while(i < tpf->width - tpf->vpre)
		{
			write(1, " ", 1);
			i++;
		}
	}
	else
	{
		while(i < tpf->width - tpf->vpre - 1)
		{
			write(1, " ", 1);
			i++;
		}
	}
	if (d < 0)
		write(1, "-", 1);
	while(i < tpf->vpre - len)
	{
		i++;
		write(1, "0", 1);
	}
	while (n > 9)
	{
		z = '0' + n / p;
		n = n % p;
		p /=10;
		write(1, &z, 1);
	}
	z = '0' + n;
	write(1, &z, 1);
}

void	ft_display_x(t_pf *tpf, unsigned int u)
{
	int		i;
	int		len;
	long unsigned		p;
	char	*b;

	i = 0;
	len = 0;
	p = 1;
	b = "0123456789abcdef";
	while(16 * p < u)
	{
		len++;
		p *= 16;
	}
	if(len >= tpf->width)
	{
		tpf->ret += len;
	}
	else
		tpf->ret += tpf->width;
	if(tpf->vpre < len)
		tpf->vpre = len;
	while(i < tpf->width - tpf->vpre)
	{
		write(1, " ", 1);
		i++;
	}
	i = 0;
	while(i < tpf->vpre - len)
	{
		i++;
		write(1, "0", 1);
	}
	while (u > 15)
	{
		write(1, &b[u / p], 1);
		u = u % p;
		p /= 16;
	}
	write(1, &b[u], 1);
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
	tpf->vpre = 0;
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
	else if (s[i] == 'x')
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
			i += ft_scan(&tpf, s + i + 1);
	}
	va_end(tpf.lst);
	return (tpf.ret); 
}