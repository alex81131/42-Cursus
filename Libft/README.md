# Libft
This project aims to code a C library regrouping usual functions that we’ll be allowed to use in all our other 42 projects.

# Resources
1. https://github.com/48d31kh413k/1337-Libft-42
2. https://github.com/pasqualerossi/Libft?tab=readme-ov-file#functions-from-ctypeh

# Libft Functions

## Functions from `<ctype.h>`
- [`ft_isalpha`](https://github.com/alex81131/Libft/blob/main/ctype.h/ft_isalpha.c) - checks for an alphabetic character.
- [`ft_isdigit`](https://github.com/alex81131/Libft/blob/main/ctype.h/ft_isdigit.c) - checks for a digit (0 through 9).
- [`ft_isalnum`](https://github.com/alex81131/Libft/blob/main/ctype.h/ft_isalnum.c) - checks for an alphanumeric character.
- [`ft_isascii`](https://github.com/alex81131/Libft/blob/main/ctype.h/ft_isascii.c) - checks whether c fits into the ASCII character set.
- [`ft_isprint`](https://github.com/alex81131/Libft/blob/main/ctype.h/ft_isprint.c) - checks for any printable character.
- [`ft_toupper`](https://github.com/alex81131/Libft/blob/main/ctype.h/ft_toupper.c) - convert char to uppercase.
- [`ft_tolower`](https://github.com/alex81131/Libft/blob/main/ctype.h/ft_tolower.c) - convert char to lowercase.

## Functions from `<string.h>`
- [`ft_strlen`](https://github.com/alex81131/Libft/blob/main/string.h/ft_strlen.c) - computes the length of the string.
- [`ft_strcpy`](https://github.com/alex81131/Libft/blob/main/string.h/ft_strlcpy.c) - copies the string src to dst.
- [`ft_strcmp`](#ft_strcmp) - compares two strings.
- [`ft_strdup`]() - duplicates a string.
- [`ft_strcat`](#ft_strcat) - concatenates two strings.
- [`ft_strrchr`](#ft_strrchr) - locate character in string.
- [`ft_strncmp`](#ft_strncmp) - compare two strings.
- [`ft_memchr`](#ft_memchr) - scan memory for a character.
- [`ft_memcmp`](#ft_memcmp) - compare memory areas.
- [`ft_strnstr`](#ft_strnstr) - locate a substring in a string.
- [`ft_strdup`](#ft_strdup) - creates a duplicate for the string passed as parameter.

## Functions from `<stdlib.h>`
- [`ft_atoi`](#ft_atoi) - convert a string to an integer.
- [`ft_calloc`](#ft_calloc) - allocates memory and sets its bytes' values to 0.

## Non-standard functions
- [`ft_substr`](#ft_substr) - returns a substring from a string.
- [`ft_strjoin`](#ft_strjoin) - concatenates two strings.
- [`ft_strtrim`](#ft_strtrim) - trims the beginning and end of string with specific set of chars.
- [`ft_split`](#ft_split) - splits a string using a char as parameter.
- [`ft_itoa`](#ft_itoa) - converts a number into a string.
- [`ft_strmapi`](#ft_strmapi) - applies a function to each character of a string.
- [`ft_striteri`](#ft_striteri) - applies a function to each character of a string.
- [`ft_putchar_fd`](#ft_putchar_fd) - output a char to a file descriptor.
- [`ft_putstr_fd`](#ft_putstr_fd) - output a string to a file descriptor.
- [`ft_putendl_fd`](#ft_putendl_fd) - output a string to a file descriptor, followed by a new line.
- [`ft_putnbr_fd`](#ft_putnbr_fd) - output a number to a file descriptor.

## Linked list functions
- [`ft_lstnew`](#ft_lstnew) - creates a new list element.
- [`ft_lstadd_front`](#ft_lstadd_front) - adds an element at the beginning of a list.
- [`ft_lstsize`](#ft_lstsize) - counts the number of elements in a list.
- [`ft_lstlast`](#ft_lstlast) - returns the last element of the list.
- [`ft_lstadd_back`](#ft_lstadd_back) - adds an element at the end of a list.
- [`ft_lstclear`](#ft_lstclear) - deletes and free list.
- [`ft_lstiter`](#ft_lstiter) - applies a function to each element of a list.
- [`ft_lstmap`](#ft_lstmap) - applies a function to each element of a list. 
