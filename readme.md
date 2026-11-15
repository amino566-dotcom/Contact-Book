# Dynamic Contact Management System in C

A command-line contact management system built in C to practice dynamic memory allocation, pointers, structures, and array manipulation.

## Features

- Add new contacts dynamically.
- Store contact information using structures.
- Resize the contacts array using `realloc()`.
- Manage memory allocation using `malloc()`.
- Handle memory allocation failures.
- Keep track of the number of contacts.
- Practice working with pointers to pointers.

## Technologies

- **Language:** C
- **Libraries:** `stdio.h`, `stdlib.h`, `string.h`
- **Concepts:** 
  - Structures (`struct`)
  - Pointers and pointer-to-pointer
  - Dynamic memory allocation
  - `malloc()`
  - `realloc()`
  - `free()`
  - Arrays and functions

## Project Structure

```text
contact-management/
│
├── main.c
└── README.md
```

## How It Works

The program uses a dynamically allocated array of `Contact` structures.

Instead of defining a fixed-size array, memory is allocated and resized whenever new contacts are added.

For example:

```c
Contact *contacts = NULL;
int size = 0;
```

When adding a contact, `realloc()` increases the allocated memory:

```c
Contact *temp = realloc(
    contacts,
    (size + 1) * sizeof(Contact)
);

if (temp == NULL)
{
    printf("Memory allocation failed\n");
    return;
}

contacts = temp;
```

This allows the program to grow dynamically without defining a maximum number of contacts in advance.

## Compilation

Compile the project using GCC:

```bash
gcc -Wall -Wextra -std=c11 main.c -o contacts
```

## Execution

```bash
./contacts
```

## Learning Objectives

This project focuses on understanding:

1. How dynamic memory allocation works in C.
2. The difference between stack and heap memory.
3. How pointers reference dynamically allocated memory.
4. How pointer-to-pointer parameters allow functions to modify pointers.
5. How `realloc()` resizes dynamically allocated arrays.
6. Why checking allocation failures is important.
7. How to prevent memory leaks using `free()`.

## Future Improvements

- Search for contacts by name.
- Delete existing contacts.
- Update contact information.
- Display all contacts.
- Save contacts to a file.
- Load contacts when the program starts.

## Author

**Amine**

A C programming practice project focused on strengthening fundamentals in memory management, pointers, and data structures.
