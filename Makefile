# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmeera-r <kmeera-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 19:22:42 by hgreenfe          #+#    #+#              #
#    Updated: 2020/01/17 19:01:33 by kmeera-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# used variables
NAME = SCOP
MY_DIR = $(shell pwd)
SRCDIR = srcs/
OBJDIR = objs/
INCDIR1 = incs/
LIBDIR = libs/libft
GLFWDIR = libs/glfw
INCDIR2 = $(GLFWDIR)/include
 #SDL2_image
# used applications

CC = gcc
CCFLAGS = -g -Wall -Wextra -Werror -pedantic-errors -I $(INCDIR1) -I $(INCDIR2) -O 
RM = rm
RMFLAGS = -rf

#used directories and files

FILES := main\
		 shader\
		 scop \
		 atof \
		 load_obj \
		 load_obj_2 \
		 counting_elements \
		 matrix_sum \
		 matrix_sub \
		 matrix_translate \
		 matrix_projection \
		 matrix_mul \
		 matrix_init \
		 matrix_rotate
		 
		 #converter


SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))
FULL_SRCS = $(addprefix $(SRCDIR), $(SRCS))
FULL_OBJS = $(addprefix $(OBJDIR), $(OBJS))
FULL_LIBS = $(addprefix -l, $(LIBS))
FRAMEWORK = -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
#  -framework iconv
LIBFLAGS = -L$(LIBDIR) -lft -L$(GLFWDIR)/lib-macos -lglfw3

# vpath %.c $(SRCDIR)/
# vpath %.o $(OBJDIR)/

.PHONY:  all re clean fclean $(LIBDIR)

all: $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(LIBDIR): $(OBJDIR)
	make -C $(LIBDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CCFLAGS) -c -o $@ $<


$(NAME):  $(LIBDIR) $(FULL_OBJS)
	@$(CC) $(CCFLAGS) -o $(NAME) $(FRAMEWORK) $(LIBFLAGS) $(FULL_OBJS)

clean:
	make -C $(LIBDIR) clean
	$(RM) $(RMFLAGS) $(FULL_OBJS)

fclean: clean
	make -C $(LIBDIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all
