## STYLE ##
ECHO	:=	/bin/echo
DEF_	:=	\e[0m
BOLD_	:=	\e[1m
RED_	:=	\e[31m
GREEN_	:=	\e[32m
CYAN_	:=	\e[36m

## KEYWORDS ##
CC	=	gcc
AR	=	ar rcs
RM	=	rm -f

## NAMES ##
NAME	=	test_piscine

## DAY
ifdef DAY
	DAY	=	$(DAY)
else
	DAY	=	Day03
endif

## FILES ##
SRCS	=	$(shell find . -type f -name '*.c' ! -name '*_tester.c')	\
			$(shell [ -d "$(DAY)" ] && find $(DAY) -type f -name '*_tester.c')

## TRANSFORMATIONS ##
OBJS	=	$(SRCS:%.c=%.o)

## FLAGS ##
CFLAGS	=	-I./Include/
CFLAGS	+=	-Wall
CFLAGS	+=	-Wextra
CFLAGS	+=	-Wpedantic
CFLAGS	+=	-Wunused
CFLAGS	+=	-Wunused-parameter
ifeq ($(ENV), dev)
	CFLAGS	+=	-g3 -DENV_DEV
else
	CFLAGS	+=	-O2 -fno-builtin
endif

###############################################################################
###	MESSAGES
###############################################################################

define PRINT
    $(ECHO) -e "[$(GREEN_)✔$(DEF_)] $(1): $(GREEN_)$(2)$(DEF_)"
endef
define ERROR
    $(ECHO) -e "[$(RED_)✘$(DEF_)]$(RED_) $(1) ($(2))$(DEF_)"
endef
define REMOVE
    $(ECHO) -e "[$(CYAN_)✔$(DEF_)] $(1): $(CYAN_)$(2)$(DEF_)"
endef

###############################################################################
###	CALLS
###############################################################################

### How to use: make [all|clean|fclean|re|github] ENV=[dev|prod] day=[day03|day04|...]
all:	$(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS)	\
	&& $(call PRINT,COMPILED,$(BOLD_)$(NAME))	\
	|| $(call ERROR,BUILD FAILED,$@)

%.o:	%.c
	@$(CC) -o $@ -c $< $(CFLAGS)	\
	&& $(call PRINT,COMPILED,$@)	\
	|| $(call ERROR,BUILD FAILED,$@)

### clean
clean:
	@$(RM) $(OBJS)	\
	&& $(call REMOVE,REMOVE,.o files)

### fclean
fclean: clean
	@$(RM) $(shell find . -type f -name '*.o')	\
	@$(RM) $(NAME)	\
	&& $(call REMOVE,REMOVE,$(NAME))

### re
re:	fclean all

### test
test:	re
	@./$(NAME)

github:
	git remote get-url origin |	\
	sed 's/git@github.com:/https:\/\/github.com\//' |	\
	xargs xdg-open

.PHONY: all clean fclean re	\
		test	\
		github
