# Libft
This project aims to code a C library regrouping usual functions that we’ll be allowed to use in all our other 42 projects.

# Resources
1. https://github.com/48d31kh413k/1337-Libft-42
2. https://github.com/pasqualerossi/Libft?tab=readme-ov-file#functions-from-ctypeh

# Libft Functions

## Functions from `<ctype.h>`
- [`ft_isalpha`](https://github.com/alex81131/42-Cursus/blob/main/Libft/ctype.h/ft_isalpha.c) - checks for an alphabetic character.
- [`ft_isdigit`](https://github.com/alex81131/42-Cursus/blob/main/Libft/ctype.h/ft_isdigit.c) - checks for a digit (0 through 9).
- [`ft_isalnum`](https://github.com/alex81131/42-Cursus/blob/main/Libft/ctype.h/ft_isalnum.c) - checks for an alphanumeric character.
- [`ft_isascii`](https://github.com/alex81131/42-Cursus/blob/main/Libft/ctype.h/ft_isascii.c) - checks whether c fits into the ASCII character set.
- [`ft_isprint`](https://github.com/alex81131/42-Cursus/blob/main/Libft/ctype.h/ft_isprint.c) - checks for any printable character.
- [`ft_toupper`](https://github.com/alex81131/42-Cursus/blob/main/Libft/ctype.h/ft_toupper.c) - convert char to uppercase.
- [`ft_tolower`](https://github.com/alex81131/42-Cursus/blob/main/Libft/ctype.h/ft_tolower.c) - convert char to lowercase.

## Functions from `<string.h>`
- [`ft_memset`](https://github.com/alex81131/42-Cursus/blob/main/Libft/string.h/ft_memset.c) - fill memory with a constant byte.
- [`ft_strlen`](https://github.com/alex81131/42-Cursus/blob/main/Libft/string.h/ft_strlen.c) - calculate the length of a string.
- [`ft_bzero`](https://github.com/alex81131/42-Cursus/blob/main/Libft/string.h/ft_bzero.c) - zero a byte string.
- [`ft_memcpy`](https://github.com/alex81131/42-Cursus/blob/main/Libft/string.h/ft_memcpy.c) - copy memory area.
- [`ft_memmove`](https://github.com/alex81131/42-Cursus/blob/main/Libft/string.h/ft_memmove.c) - copy memory area.
- [`ft_strlcpy`](https://github.com/alex81131/42-Cursus/blob/main/Libft/string.h/ft_strlcpy.c) - copy string to an specific size.
- [`ft_strlcat`](https://github.com/alex81131/42-Cursus/blob/main/Libft/string.h/ft_strlcat.c) - concatenate string to an specific size.
- [`ft_strchr`](https://github.com/alex81131/42-Cursus/blob/main/Libft/string.h/ft_strchr.c) - locate character in string.
- [`ft_strrchr`](https://github.com/alex81131/42-Cursus/blob/main/Libft/string.h/ft_strrchr.c) - locate character in string.
- [`ft_strncmp`](https://github.com/alex81131/42-Cursus/blob/main/Libft/string.h/ft_strncmp.c) - compare two strings.
- [`ft_memchr`](https://github.com/alex81131/42-Cursus/blob/main/Libft/string.h/ft_memchr.c) - scan memory for a character.
- [`ft_memcmp`](https://github.com/alex81131/42-Cursus/blob/main/Libft/string.h/ft_memcmp.c) - compare memory areas.
- [`ft_strnstr`](https://github.com/alex81131/42-Cursus/blob/main/Libft/string.h/ft_strnstr.c) - locate a substring in a string.
- [`ft_strdup`](https://github.com/alex81131/42-Cursus/blob/main/Libft/string.h/ft_strdup.c) - creates a duplicate for the string passed as parameter.

## Functions from `<stdlib.h>`
- [`ft_atoi`](https://github.com/alex81131/42-Cursus/blob/main/Libft/stdlib.h/ft_atoi.c) - convert a string to an integer.
- [`ft_calloc`](https://github.com/alex81131/42-Cursus/blob/main/Libft/stdlib.h/ft_calloc.c) - allocates memory and sets its bytes' values to 0.

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
