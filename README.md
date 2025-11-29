# 📚 Libft

Mi propia biblioteca de C — el primer proyecto de 42.

[![42](https://img.shields.io/badge/42-libft-blue)](https://42.fr)

## 📋 Descripción

**Libft** es una biblioteca de funciones de C que reimplementa funciones estándar de la libc junto con funciones adicionales útiles para proyectos futuros en 42.

## 🗂️ Estructura del Proyecto

```
libft/
├── Makefile
├── include/
│   └── libft.h
├── src/
│   ├── char/     # Funciones de caracteres
│   ├── str/      # Funciones de strings
│   ├── mem/      # Funciones de memoria
│   ├── conv/     # Funciones de conversión
│   ├── fd/       # Funciones de file descriptors
│   └── lst/      # Funciones de listas enlazadas (bonus)
└── obj/          # Objetos compilados
```

## 🔧 Funciones Implementadas

### Parte 1 - Funciones de libc

| Caracteres | Strings | Memoria |
|------------|---------|---------|
| `ft_isalpha` | `ft_strlen` | `ft_memset` |
| `ft_isdigit` | `ft_strchr` | `ft_bzero` |
| `ft_isalnum` | `ft_strrchr` | `ft_memcpy` |
| `ft_isascii` | `ft_strncmp` | `ft_memmove` |
| `ft_isprint` | `ft_strnstr` | `ft_memchr` |
| `ft_toupper` | `ft_strlcpy` | `ft_memcmp` |
| `ft_tolower` | `ft_strlcat` | `ft_calloc` |
| | `ft_strdup` | |

### Parte 2 - Funciones adicionales

| Strings | Conversión | File Descriptors |
|---------|------------|------------------|
| `ft_substr` | `ft_atoi` | `ft_putchar_fd` |
| `ft_strjoin` | `ft_itoa` | `ft_putstr_fd` |
| `ft_strtrim` | | `ft_putendl_fd` |
| `ft_split` | | `ft_putnbr_fd` |
| `ft_strmapi` | | |
| `ft_striteri` | | |

### Bonus - Listas Enlazadas

| Función | Descripción |
|---------|-------------|
| `ft_lstnew` | Crea un nuevo nodo |
| `ft_lstadd_front` | Añade nodo al inicio |
| `ft_lstadd_back` | Añade nodo al final |
| `ft_lstsize` | Cuenta nodos de la lista |
| `ft_lstlast` | Retorna el último nodo |
| `ft_lstdelone` | Elimina un nodo |
| `ft_lstclear` | Elimina toda la lista |
| `ft_lstiter` | Itera y aplica función |
| `ft_lstmap` | Itera, aplica y crea nueva lista |

## 🚀 Uso

### Compilar la biblioteca

```bash
# Compilar sin bonus
make

# Compilar con bonus (listas enlazadas)
make bonus

# Limpiar objetos
make clean

# Limpiar todo
make fclean

# Recompilar
make re
```

### Usar en tu proyecto

```c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hello, 42!");
    ft_putendl_fd(str, 1);
    free(str);
    return (0);
}
```

### Compilar tu proyecto con libft

```bash
cc -Wall -Wextra -Werror main.c -I libft/include -L libft -lft -o programa
```

O en tu Makefile:

```makefile
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I $(LIBFT_DIR)/include

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)
```

## 📝 Norminette

El código cumple con la [Norma de 42](https://github.com/42School/norminette).

```bash
norminette src/ include/
```

## 👤 Autor

**javifer2** - 42 Barcelona

---

⭐ Si te ha sido útil, ¡dale una estrella al repo!
