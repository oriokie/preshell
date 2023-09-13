#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);

		if (read != -1)
		{
			printf("%s", line);
		}
		else
		{
			perror("getline");
			break;
		}
	}
	free(line);
	return (0);
}

