# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plang <plang@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 16:58:33 by plang             #+#    #+#              #
#    Updated: 2024/11/07 16:59:05 by plang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ArrayTemplate

CXX = c++

CXXFLAGS = -Werror -Wall -Wextra -g #-fsanitize=address

SRCS = main.cpp 

OBJS =	$(SRCS:.cpp=.o)

all:			$(NAME)

%.o: %.cpp
	@$(CXX) -o $@ -c $< $(CXXFLAGS)	

$(NAME): 		$(OBJS)
	$(CXX)		$(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f		$(OBJS)

fclean:	clean
	@rm -f		$(NAME)

re:	fclean		$(NAME)

.PHONY:	all clean fclean re
