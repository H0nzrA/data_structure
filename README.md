# libds

## Description

`libds` is a C library providing generic implementations of common data structures.

The library stores elements by value, copying their raw bytes into internal storage.
Each data structure is configured with the size of its elements at creation, allowing it
to store different C data types without being tied to a specific structure.

Currently implemented data structures:

- **Heap-based priority queue (`heapq`)** — supports minimum-heap and maximum-heap ordering
through a user-defined comparison function.
- **Doubly linked list (`list`)** — supports insertion and removal at both ends.
- **Stack (`stack`)** — supports last-in, first-out (LIFO) operations.

The project is developed as a personal learning project focused on data structures,
memory management, generic programming in C, and reusable software design.

## Instructions

### Requirements

- A C compiler
- `make`

### Compilation

Clone the repository and build the library:

```sh
make
```

The compiled library is generated in the `lib/` directory but also copied in the root of the repository.

Include the public headers from `includes/` when compiling programs that use the library.

### Linking

Link your program against the generated static library:

```sh
cc main.c -Iincludes -L. -lds -o main
```

### Usage

Each data structure requires the size of the stored elements during creation.
Elements are copied into the container rather than stored as pointers to the original values.

#### Stack

```c
#include "stack.h"

int main(void)
{
    t_stack *stack;
    int value = 42;
    int result;

    stack = stack_create(sizeof(int));
    if (!stack)
        return (1);
    stack_push(stack, &value);
    if (stack_pop(stack, &result))
        /* Use result here. */;
    stack_destroy(stack);
    return (0);
}
```

#### Doubly linked list

The list supports insertion and removal at both the front and back. Removed elements can be copied into a caller-provided buffer.

#### Priority queue

The priority queue supports minimum-heap and maximum-heap ordering. A comparison function determines the relative ordering of stored elements.

Refer to the public headers in `includes/` for the available functions and their contracts.

## Resources

- [The C Programming Language — ISO C working drafts](https://www.open-std.org/jtc1/sc22/wg14/www/docs/)
- [GNU Make Manual](https://www.gnu.org/software/make/manual/)
- [Valgrind User Manual](https://valgrind.org/docs/manual/manual.html)
