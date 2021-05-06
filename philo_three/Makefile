# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tilda <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 20:12:34 by tilda             #+#    #+#              #
#    Updated: 2021/04/20 20:12:35 by tilda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_three
CC = gcc
P_THREAD = -lpthread
C_FILES = $(shell find . -name "*.c" $(IGNORE_PATHS) -execdir echo {} ';')
OBJ = $(C_FILES:%.c=%.o)
O_FILES = $(addprefix $(OBJDIR)/, $(OBJ))
IGNORE_PATHS = ! -path "./cmake-build-debug/*"

OBJDIR = ./src/obj
INCLUDE = ./Includes
SRC_PATHS = ./src \
			./src/lifecycle \
			./src/utils \
			./src/validate

vpath %.c $(SRC_PATHS)
vpath %.o $(OBJDIR)
vpath %.h $(INCLUDE)

#Tools to edit text
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
UNDERLINE = \033[0;4m
TEXT_RESET = \033[0;0m

.PHONY: all clean fclean re

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJ)
	@$(CC) -I$(INCLUDE) $(P_THREAD) $(O_FILES) -o $@
	@echo "$(GREEN)Success!"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

%.o: %.c $(INCLUDE)
	@echo "$(CYAN)Compiling $<"
	@$(CC) -I$(INCLUDE) -c $< -o $(OBJDIR)/$@

clean:
	@echo "$(TEXT_RESET)"
	@rm -rf $(OBJDIR) ./Includes/*.h.gch
	@echo "$(YELLOW)Delete 'o' files"

fclean: clean
	@echo "$(TEXT_RESET)"
	@rm -f $(NAME)
	@echo "$(YELLOW)Delete the binary file '$(NAME)'"

re: fclean all

