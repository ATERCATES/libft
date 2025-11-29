# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javifer2 <javifer2@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 18:00:37 by javifer2          #+#    #+#              #
#    Updated: 2025/11/29 14:23:00 by javifer2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I include

# Directories
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include

# Source subdirectories
CHAR_DIR	= $(SRC_DIR)/char
STR_DIR		= $(SRC_DIR)/str
MEM_DIR		= $(SRC_DIR)/mem
CONV_DIR	= $(SRC_DIR)/conv
FD_DIR		= $(SRC_DIR)/fd
LST_DIR		= $(SRC_DIR)/lst

# Source files by category
CHAR_SRC	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			  ft_isprint.c ft_toupper.c ft_tolower.c

STR_SRC		= ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
			  ft_strnstr.c ft_strdup.c ft_strlcpy.c ft_strlcat.c \
			  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			  ft_strmapi.c ft_striteri.c

MEM_SRC		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			  ft_memchr.c ft_memcmp.c ft_calloc.c

CONV_SRC	= ft_atoi.c ft_itoa.c

FD_SRC		= ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

LST_SRC		= ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c \
			  ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# Full source paths
SRCS		= $(addprefix $(CHAR_DIR)/, $(CHAR_SRC)) \
			  $(addprefix $(STR_DIR)/, $(STR_SRC)) \
			  $(addprefix $(MEM_DIR)/, $(MEM_SRC)) \
			  $(addprefix $(CONV_DIR)/, $(CONV_SRC)) \
			  $(addprefix $(FD_DIR)/, $(FD_SRC))

BONUS_SRCS	= $(addprefix $(LST_DIR)/, $(LST_SRC))

# Object files
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS	= $(BONUS_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Output colors
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RESET		= \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)✓ $(NAME) compiled$(RESET)"

bonus: $(OBJS) $(BONUS_OBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "$(GREEN)✓ $(NAME) compiled with bonus$(RESET)"

# Create obj directories and compile .c to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/libft.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(YELLOW)Compiling: $<$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)✓ Objects removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)✓ $(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
