#include "libft.h"

int ft_abs(int x)
{
    if (x < 0)
    {
        if (x == INT_MIN)
            return INT_MAX;
        return (-x);
    }
    else
        return (x);
}
