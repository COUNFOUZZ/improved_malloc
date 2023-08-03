
# Improved Malloc with Linked List

Improved Malloc is a custom memory allocation implementation in C that uses a linked list to keep track of allocated pointers, making memory deallocation (freeing) more efficient and organized.
## Features

- Efficient memory allocation using malloc with a linked list tracking mechanism.
- Easy deallocation (freeing) of all allocated memory through the linked list.
- Memory tracking details can be displayed for debugging purposes.

## Usage/Exemple

1. Clone the repository:
```bash
git clone https://github.com/counfouzz/improved_malloc.git
cd improved_malloc
```

2. Create a file main.c
```bash
touch main.c
```
3. In main.c, copy and paste the code bellow
```c
#include "./improved_malloc.h"
#include <stdio.h>

// Function to print the linked list of memory blocks and the associated pointers
static void	ft_print_linked_list_and_str(t_malloc_lst *lst)
{
	t_malloc_lst	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("===================================\n");
		printf("[%p] <- prev [%p] next -> [%p]\n", tmp->prev, tmp, tmp->next);
		printf("tmp->address = [%p]\n", tmp->address);
		printf("===================================\n");
		tmp = tmp->next;
	}
}

int	main(void)
{
	t_malloc_lst	*lst;		// Pointer to the head of the linked list
	char			*str;		// Pointer to a character buffer
	char			*str2;		// Another pointer to a character buffer
	char			**str3;		// Pointer to a pointer-to-character buffer

	lst = NULL;		// Initializing the linked list to be empty

	// Malloc all pointers using the improved_malloc function
	str = improved_malloc(&lst, 10);						// Allocate 10 bytes for str and add the block to the linked list
	str2 = improved_malloc(&lst, 10);						// Allocate 10 bytes for str2 and add the block to the linked list
	str3 = improved_malloc(&lst, sizeof(char *) * 3);		// Allocate memory for 3 char pointers and add the block to the linked list
	str3[0] = improved_malloc(&lst, sizeof(char) * 10);		// Allocate 10 bytes for str3[0] and add the block to the linked list
	str3[1] = improved_malloc(&lst, sizeof(char) * 10);		// Allocate 10 bytes for str3[1] and add the block to the linked list

	// Print the addresses of all pointers
	printf("Address of pointer str: [%p]\n", str);
	printf("Address of pointer str2: [%p]\n", str2);
	printf("Address of pointer str3: [%p]\n", str3);
	printf("Address of pointer str3[0]: [%p]\n", str3[0]);
	printf("Address of pointer str3[1]: [%p]\n", str3[1]);

	// Print all nodes in the linked list along with the addresses of the pointers they represent
	ft_print_linked_list_and_str(lst);

	// Free the memory block associated with pointer str from the linked list
	lst_free_bloc(&lst, str);
	printf("\n");
	// Print the linked list after freeing the block
	ft_print_linked_list_and_str(lst);
	return (0);
}

```

4. Compile the improved_malloc.c file:
```bash
gcc improved_malloc.c main.c -o improved_malloc
```

5. Run the program and see the result:
```bash
./improved_malloc
```
## Contributing

Contributions are welcome! Please fork the repository and submit a pull request.

