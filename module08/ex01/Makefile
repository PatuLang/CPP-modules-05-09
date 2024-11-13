# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plang <plang@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 13:30:34 by plang             #+#    #+#              #
#    Updated: 2024/11/13 13:31:22 by plang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Span

CXX = c++

CXXFLAGS = -Werror -Wall -Wextra -g #-fsanitize=address

SRCS = main.cpp \
		Span.cpp

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
