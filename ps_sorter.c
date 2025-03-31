#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_list
{
	int value;
	struct s_list *next;
} t_list;

// Function prototypes
t_list *create_stack(int argc, char **argv);
void print_stack(t_list *stack);
void free_stack(t_list *stack);
void apply_operation(t_list **stack_a, t_list **stack_b, const char *operation);
void execute_operations(t_list **stack_a, char *operations);

// Stack manipulation prototypes
void swap(t_list **stack);
void push(t_list **from, t_list **to);
void rotate(t_list **stack);
void reverse_rotate(t_list **stack);

int main(int argc, char **argv)
{
	FILE *pipe;
	char buffer[256];
	char command[1024];
	char *operations = NULL;
	size_t operations_size = 0;
	t_list *original_stack, *sorted_stack;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s [push_swap arguments]\n", argv[0]);
		return 1;
	}

	// Build the command string for push_swap execution
	snprintf(command, sizeof(command), "./push_swap");
	for (int i = 1; i < argc; i++)
		snprintf(command + strlen(command), sizeof(command) - strlen(command), " %s", argv[i]);

	// Open a pipe to the push_swap process
	pipe = popen(command, "r");
	if (!pipe)
	{
		perror("Error opening pipe");
		return 1;
	}

	// Read all operations from push_swap's output
	while (fgets(buffer, sizeof(buffer), pipe))
	{
		size_t len = strlen(buffer);
		operations = realloc(operations, operations_size + len + 1);
		if (!operations)
		{
			perror("Error allocating memory for operations");
			return 1;
		}
		memcpy(operations + operations_size, buffer, len);
		operations_size += len;
		operations[operations_size] = '\0';
	}

	// Close the pipe and check for errors
	if (pclose(pipe) == -1)
	{
		perror("Error closing pipe");
		return 1;
	}

	// Create the original stack
	original_stack = create_stack(argc, argv);
	if (!original_stack)
	{
		fprintf(stderr, "Error creating stack\n");
		free(operations);
		return 1;
	}

	// Duplicate the stack for sorting
	sorted_stack = create_stack(argc, argv);

	// Apply operations to sort the stack
	execute_operations(&sorted_stack, operations);

	// Print the original and sorted stacks
	printf("Original Stack:\n");
	print_stack(original_stack);
	printf("\nSorted Stack:\n");
	print_stack(sorted_stack);

	// Free allocated memory
	free_stack(original_stack);
	free_stack(sorted_stack);
	free(operations);

	return 0;
}

// Function to create a stack from command-line arguments
t_list *create_stack(int argc, char **argv)
{
	t_list *stack = NULL, *new_node;
	for (int i = argc - 1; i > 0; i--)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			return NULL;
		new_node->value = atoi(argv[i]);
		new_node->next = stack;
		stack = new_node;
	}
	return stack;
}

// Function to print the stack
void print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

// Function to free a stack
void free_stack(t_list *stack)
{
	t_list *tmp;
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

// Function to execute operations on the stacks
void execute_operations(t_list **stack_a, char *operations)
{
	t_list *stack_b = NULL;
	char *operation = strtok(operations, "\n");
	while (operation)
	{
		apply_operation(stack_a, &stack_b, operation);
		operation = strtok(NULL, "\n");
	}
	free_stack(stack_b);
}

// Function to apply a single operation to the stacks
void apply_operation(t_list **stack_a, t_list **stack_b, const char *operation)
{
	if (strcmp(operation, "sa") == 0)
		swap(stack_a);
	else if (strcmp(operation, "sb") == 0)
		swap(stack_b);
	else if (strcmp(operation, "ss") == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (strcmp(operation, "pa") == 0)
		push(stack_b, stack_a);
	else if (strcmp(operation, "pb") == 0)
		push(stack_a, stack_b);
	else if (strcmp(operation, "ra") == 0)
		rotate(stack_a);
	else if (strcmp(operation, "rb") == 0)
		rotate(stack_b);
	else if (strcmp(operation, "rr") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (strcmp(operation, "rra") == 0)
		reverse_rotate(stack_a);
	else if (strcmp(operation, "rrb") == 0)
		reverse_rotate(stack_b);
	else if (strcmp(operation, "rrr") == 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
}

// Stack manipulation operations
void swap(t_list **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return;
	t_list *first = *stack;
	t_list *second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void push(t_list **from, t_list **to)
{
	if (!from || !*from)
		return;
	t_list *node = *from;
	*from = (*from)->next;
	node->next = *to;
	*to = node;
}

void rotate(t_list **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return;
	t_list *first = *stack;
	t_list *last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void reverse_rotate(t_list **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return;
	t_list *prev = NULL;
	t_list *current = *stack;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *stack;
	*stack = current;
}
