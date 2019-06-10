#include "lem_in.h"

int	initialize_data(t_li *t_li)
{

}
/*
* int	read_data(char *line)
*
* number_of_ants -> first line
* comments -> start with #
* start/end point -> start with ## and start/end
* room -> name loc_x lox_y (3 information seperated with space)
* link -> two rooms name is connected with '-'
*/

/*
**Input Redirection (" < ")
*
*Just as the output of a command can be redirected to a
*file, the less-than character < is used to redirect the
*input of a command.
*
*Instead of open the files as an argument, redirected file
*is automatically opened and comes as standard input. so,
*just read the standard input is enough
*https://www.tutorialspoint.com/unix/unix-io-redirections.htm
*/
int	read_data(char *line)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		FP("%s\n", line);
		free(line);
	}
}

