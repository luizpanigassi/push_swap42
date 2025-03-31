#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	FILE *pipe;
	char buffer[256];
	int count = 0;
	char command[1024];

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s [push_swap arguments]\n", argv[0]);
		return 1;
	}

	// Build the command string for push_swap execution
	snprintf(command, sizeof(command), "./push_swap %s", argv[1]);
	for (int i = 2; i < argc; i++)
		snprintf(command + strlen(command), sizeof(command) - strlen(command), " %s", argv[i]);

	// Open a pipe to the push_swap process
	pipe = popen(command, "r");
	if (!pipe)
	{
		perror("Error opening pipe");
		return 1;
	}

	// Read each line from the output and count operations
	while (fgets(buffer, sizeof(buffer), pipe))
		count++;

	// Close the pipe
	if (pclose(pipe) == -1)
	{
		perror("Error closing pipe");
		return 1;
	}

	// Print the count of operations
	printf("Number of operations: %d\n", count);

	return 0;
}
