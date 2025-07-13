#include "libft.h"

void	ft_del(void *content)
{
	free(content);
	content = NULL;
}
