# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plang <plang@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 12:00:13 by plang             #+#    #+#              #
#    Updated: 2025/02/24 18:04:30 by plang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CXX = c++

CXXFLAGS = -Werror -Wall -Wextra -g -std=c++20 #-fsanitize=address

SRCS = main.cpp PmergeMe.cpp

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
