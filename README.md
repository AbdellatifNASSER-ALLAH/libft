# 42 Cursus | | 1333 Cursus

# libft

**libft** is a custom implementation of a subset of the C standard library functions, plus additional utilities, created as part of the 42 School curriculum.

---

## Project Structure
```markdown
libft/
├── Makefile
├── includes/
│   └── libft.h
├── objdir/
├── srcs/
│   ├── ft\_\*.c
│   ├── GetNextLine/
│   │   ├── get\_next\_line.c
│   │   └── get\_next\_line\_utils.c
│   └── ft\_printf/
│       ├── ft\_printf.c
│       ├── ft\_putchar.c
│       ├── ft\_puthex.c
│       ├── ft\_putnbr.c
│       ├── ft\_putptr.c
│       ├── ft\_putstr.c
│       ├── ft\_putunbr.c
│       └── ft\_utils.c

```

---

## Features

- Reimplementation of standard C library functions (e.g., `ft_memset`, `ft_strlen`, `ft_strncmp`, etc.)
- String manipulation utilities (`ft_split`, `ft_strjoin`, `ft_strtrim`, etc.)
- Memory management (`ft_calloc`, `ft_memcpy`, etc.)
- Character checks and conversions (`ft_isalpha`, `ft_isdigit`, `ft_tolower`, `ft_toupper`, etc.)
- Linked list management functions (bonus part) with the `ft_lst*` functions.
- Extras: `get_next_line` and `ft_printf` implementations.

---

## Installation and Usage

1. Clone the repo:

   ```bash
   git clone https://github.com/AbdellatifNASSER-ALLAH/libft.git
   cd libft
   ```
   
2. Build the library:

   ```bash
   make
   ```

   This will create the static library `libft.a`.

3. To compile bonus (linked list) functions as well:

   ```bash
   make bonus
   ```

4. Clean build files:

   ```bash
   make clean
   ```

5. Remove all generated files including the library:

   ```bash
   make fclean
   ```

6. Rebuild from scratch:

   ```bash
   make re
   ```

---

## Usage in Your Projects

Include the header:

```c
#include "libft.h"
```

Link against `libft.a` during compilation:

```bash
gcc -L. -lft your_program.c -o your_program
```

## Author

Abdellatif NASSER-ALLAH
