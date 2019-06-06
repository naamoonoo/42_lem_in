NAME	=	LEM_IN

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -Iincludes
DEBUG	=	-g -fsanitize=address

S_SRD	=	$(wildcard src/shared/*.c)
O_SRD	=	$(patsubst src/shared/%.c, obj/shared/%.o, $(S_SRD))
S_PSS	=	$(wildcard src/push_swap/*.c)
O_PSS	=	$(patsubst src/push_swap/%.c, obj/push_swap/%.o, $(S_PSS))
S_CHK	=	$(wildcard src/checker/*.c)
O_CHK	=	$(patsubst src/checker/%.c, obj/checker/%.o, $(S_CHK))

PS_S	=	$(S_SRD)	$(S_PSS)
PS_O	=	$(O_SRD)	$(O_PSS)

CH_S	=	$(S_SRD)	$(S_CHK)
CH_O	=	$(O_SRD)	$(O_CHK)

all		:	$(NAME)

obj/%.o	: 	src/%.c
			@$(CC) $(CFLAGS) $(OPTION) -c -o $@ $<

$(NAME)	:	obj $(CH_O) $(PS_O)
			@cd lib && make
			@mv lib/libftprintf.a .
			@$(CC) -o $(CH) $(CFLAGS) $(CH_O) libftprintf.a
			@$(CC) -o $(PS) $(CFLAGS) $(PS_O) libftprintf.a
			@echo "excutable file $(PS) and $(CH) has been made"

obj		:
			@mkdir obj
			@mkdir obj/shared
			@mkdir obj/push_swap
			@mkdir obj/checker

clean	:
			-cd lib && make clean
			-rm -rf obj

fclean	: clean
			-rm -f $(PS) $(CH)
			-rm -f libftprintf.a

re		: fclean $(PS) $(CH)

.PHONY	: clean fclean re
