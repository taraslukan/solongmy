#include "solong.h"

int main()
{
	int		fd;
	char	*str;
	char	**map;
	char	*path = "maps.ber";
	t_first	file;

	 fd = open(path, O_RDONLY);
	 str = strfromfile(fd);

}
