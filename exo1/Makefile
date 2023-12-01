FLAGS := -o
NAME := test
CC := g++
DEBUG := -fsanitize=address -g

BLK =    \e[30m
RED    =    \e[31m
GRN =    \e[32m
YLW =    \e[33m
BLU    =    \e[34m
PPL    =    \e[35m
CYA    =    \e[36m
END    =    \e[0m

$(NAME): main.o 
	@$(CC) main.o  $(DEBUG) $(FLAGS) $(NAME)
	@printf "\t$(GRN)compiling [$(PPL)$(NAME)$(GRN)] complete$(END)\n"
	

all: $(NAME)

main.o: main.cpp
	@printf "\t$(GRN)compiling [$(PPL)main.cpp$(GRN)]$(END)\n"
	@$(CC) -c main.cpp $(DEBUG)
	

utils.o: utils.cpp
	@$(CC) -c utils.cpp $(DEBUG)

clean:
	@printf "\t$(CYA)deleting executable [$(PPL)$(NAME)$(CYA)]$(END)\n"
	@rm -f $(NAME)
	@printf "\t$(CYA)deleting object files$(END)\n"
	@rm -f *.o

re: clean $(NAME)