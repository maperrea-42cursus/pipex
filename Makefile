# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 14:18:02 by maperrea          #+#    #+#              #
#    Updated: 2021/09/15 16:52:16 by maperrea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.h inc
vpath %.c src
vpath %.o obj

NAME			= pipex

SRCDIR			= src

SRCS			= $(shell find $(SRCDIR)/*.c)

OBJDIR			= obj

OBJS			= $(subst $(SRCDIR), $(OBJDIR), $(SRCS:.c=.o))

INCDIR			= inc

LIBFT			= libft.a

LIBFTDIR		= libft

CC				= gcc

RM				= rm -f

CFLAGS			= -Wall -Werror -Wextra

DEBUG			= #-g -fsanitize=address #-D CHECK_LEAKS

$(OBJDIR)/%.o: $(SRCDIR)/%.c
				$(CC) $(DEBUG) -O3 $(CFLAGS) -I$(INCDIR) -c $^ -o $@

all:			pipex

$(LIBFTDIR)/$(LIBFT):
				make -C $(LIBFTDIR)

$(OBJDIR):
				mkdir -p $(OBJDIR) 

$(NAME):		$(OBJDIR) $(LIBFTDIR)/$(LIBFT) $(OBJS)
				$(CC) $(DEBUG) -O3 $(CFLAGS) -I$(INCDIR) $(LIBFTDIR)/$(LIBFT)\
					$(OBJS) -o $(NAME)

bonus:			all

clean:
				$(RM) -r $(OBJDIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
