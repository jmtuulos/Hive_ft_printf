#include "ft_printf.h"
//#include <stdio.h>

void	ini_struct(t_printf *tab)
{

	tab->b_written = 0;
	tab->dash = 0;
	tab->percent = 0;
	tab->dot = 0;
	tab->preci = 0;
	tab->sign = 0;
	tab->space = 0;
	tab->width = 0;
	tab->zero = 0;
	tab->hh = 0;
	tab->L = 0;
	tab->ll = 0;
	tab->h = 0;
	tab->error = 0;
	tab->conversions = "udcsfuipxX%"; //allocate and free?

}
int	save_format(t_printf *tab, const char *str, int i)
{
	int	error;

	while (!ft_strchr(tab->conversions, str[i])) // Is this always done just once?
	{
		error = i; // Does the order of these matter here?
		i = is_dot(tab, str, i); // sets precision as well
		i = is_sign(tab, str, i);
		i = is_hash(tab, str, i);
		i = is_dash(tab, str, i);
		i = is_space(tab, str, i);
		i = is_width(tab, str, i);
		i = is_h(tab, str, i);
		i = is_l(tab, str, i);
		i = is_width(tab, str, i);
		i = is_L(tab, str, i);
		i = is_percent(tab, str, i);
		if (error == i)
		{
			tab->error = 1; // nothing is done with this yet
			break;
		}
	}
	if (!str[i]) // to print out the %
		i--;
	// Error checking here? If none of the parameters found and conversion not found exit()?
	return (i);
}

int	ft_printf(const char *str_format, ...)
{
	t_printf	*tab;
	int			ret;
	int			i;

	i = 0;
	ret = 0;
	tab = (t_printf *)malloc(sizeof(t_printf));
	if (!tab)
		return (0);
	ini_struct(tab);
	va_start(tab->args, str_format);
	while (str_format[i])
	{
		if (str_format[i] == '%')
		{
			i = save_format(tab, str_format, i + 1);
			ret += print_format(tab, str_format[i]);
			ini_struct(tab);
		}
		else
			ret += write(1, &str_format[i], 1);
		i++;
	}
	va_end(tab->args);
	free (tab);
	return (ret); // Return the number of bytes printed (write)
}
