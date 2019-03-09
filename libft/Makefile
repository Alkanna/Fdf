# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dshults <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 18:34:55 by dshults           #+#    #+#              #
#    Updated: 2018/02/13 00:03:18 by klouer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.ONESHELL:

ifneq ($(words $(MAKECMDGOALS)),1) # if no argument was given to make...
.DEFAULT_GOAL = all # set the default goal to all
%:                   # define a last resort default rule
	  @$(MAKE) $@ --no-print-directory -rRf $(firstword $(MAKEFILE_LIST)) # recursive make call,
else
ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
	  -nrRf $(firstword $(MAKEFILE_LIST)) \
	  ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
N := x
C = $(words $N)$(eval N := x $N)
ifneq ($T,0)
ECHO = echo -ne "\b\b`expr $C '*' 100 / $T`%\r"
else
ECHO = echo -ne "\b\b...\r"
endif
endif

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"
RUN_STRING	 = "Running"
COLS := $(shell tput cols)
COLS_ADAPTED := $(shell expr $(COLS) - 3)
HEADER_DISPLAYED = 0

characters := A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
characters += a b c d e f g h i j k l m n o p q r s t u v w y z
characters += 0 1 2 3 4 5 6 7 8 9 : / ! . ' '

sp :=
sp +=

strlen = $(strip $(eval __temp := $(subst $(sp),x,$1))$(foreach a,$(characters),$(eval __temp := $$(subst $a,x,$(__temp))))$(eval __temp := $(subst x,x ,$(__temp)))$(words $(__temp)))

NAME = libft.a

FLAGS = -Wall -Werror -Wextra -I ./includes/

SRC_NAME =  ft_iswhitespace.c	ft_memcmp.c			ft_putstr.c			ft_striter.c		ft_strnstr.c \
			ft_abs.c			ft_itoa.c			ft_memcpy.c			ft_putstr_fd.c		ft_striteri.c \
			ft_strrchr.c \
			ft_atoi.c           ft_itoa_base.c      ft_memdel.c         ft_squareplusplus.c ft_strjoin.c \
			ft_strrev.c \
			ft_atoi_base.c      ft_lstadd.c         ft_memmove.c        ft_stradd.c         ft_strlcat.c \
			ft_strsplit.c \
			ft_bzero.c          ft_lstdel.c         ft_memset.c         ft_strcat.c         ft_strlen.c \
			ft_strstr.c \
			ft_ctoi.c           ft_lstdelone.c      ft_nbrendl.c        ft_strchr.c         ft_strmap.c \
			ft_strsub.c \
			ft_isalnum.c        ft_lstget.c         ft_pow.c            ft_strclr.c         ft_strmapi.c \
			ft_strtrim.c \
			ft_isalpha.c        ft_lstiter.c        ft_putchar.c        ft_strcmp.c         ft_strnadd.c \
			ft_tolower.c \
			ft_isascii.c        ft_lstmap.c         ft_putchar_fd.c     ft_strcpy.c         ft_strncat.c \
			ft_toupper.c \
			ft_isdigit.c        ft_lstnew.c         ft_putendl.c        ft_strdel.c         ft_strncmp.c \
			ft_islower.c        ft_memalloc.c       ft_putendl_fd.c     ft_strdup.c         ft_strncpy.c \
			ft_isprint.c        ft_memccpy.c        ft_putnbr.c         ft_strequ.c         ft_strnequ.c \
			ft_isupper.c        ft_memchr.c         ft_putnbr_fd.c      ft_strinit.c        ft_strnew.c \
			ft_isspace.c		ft_wcslen.c			ft_putstrc.c		ft_isinstr.c		ft_instr.c \
			ft_strcutat.c		ft_strjoinfree.c	ft_sqrt.c
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = ./
INC_PATH = ./src/
LFT_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(SRC_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

## Compiles the lib
all:
ifneq ("$(wildcard $(OBJ))","")
all: $(NAME)
else
all: header $(NAME)
endif


$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "%b" "                                              $(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n";
	@printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n";
	@printf "%-60b%b" "$(OK_COLOR)\nCompilation successful." "$(NO_COLOR)\n\n";

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	@printf "%-60b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) libft" && \
	gcc $(FLAGS) $(INC) -o $@ -c $< && \
	printf "%b" "\b\b\b\b\b$(OK_COLOR)$(NO_COLOR)" \
	$(ECHO)

## Cleans the previously generated object files
clean: header
	@rm -f $(OBJ)
	@rm -rf a.out.dYSM
	@printf "%-60b%b" "$(COM_COLOR)$(RUN_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n";

## Cleans the object files and the executable itself
fclean: header clean
	@rm -f $(NAME)
	@printf "%-60b%b" "$(COM_COLOR)$(RUN_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n\n";

## Runs a full clean and compiles the lib
re: header fclean all

## COLORS
GREEN  := $(shell tput -Txterm setaf 2)
YELLOW := $(shell tput -Txterm setaf 3)
WHITE  := $(shell tput -Txterm setaf 7)
RESET  := $(shell tput -Txterm sgr0)


TARGET_MAX_CHAR_NUM=20
## Show help
help: header
	@echo ''
	@echo 'Usage:'
	@echo '  ${YELLOW}make${RESET} ${GREEN}<target>${RESET}'
	@echo ''
	@echo 'Targets:'
	@awk '/^[a-zA-Z\-\_0-9]+:/ { \
		helpMessage = match(lastLine, /^## (.*)/); \
		if (helpMessage) { \
			helpCommand = substr($$1, 0, index($$1, ":")-1); \
			helpMessage = substr(lastLine, RSTART + 3, RLENGTH); \
			printf "  ${YELLOW}%-$(TARGET_MAX_CHAR_NUM)s${RESET} ${GREEN}%s${RESET}\n", helpCommand, helpMessage; \
		} \
	} \
	{ lastLine = $$0 }' $(MAKEFILE_LIST)


define NEWLINE


endef

define TAB

endef

Authors=Author : klouer
Version=Version : 2.01
Function=Function : My own C library
RunHelp =Help : Run 'make help' to see usage
Git =Git : https://github.com/Alkanna/libft
AUTHORS_LEN := $(call strlen,$(Authors))
VERSION_LEN := $(call strlen,$(Version))
FUNCTION_LEN := $(call strlen,$(Function))
RUNHELP_LEN := $(call strlen,$(RunHelp))
GIT_LEN := $(call strlen,$(Git))
PAD_FLENGTH_AUTHORS := $(shell expr $(COLS_ADAPTED) - $(AUTHORS_LEN))
PAD_FLENGTH_VERSION := $(shell expr $(COLS_ADAPTED) - $(VERSION_LEN))
PAD_FLENGTH_FUNCTION := $(shell expr $(COLS_ADAPTED) - $(FUNCTION_LEN))
PAD_FLENGTH_RUNHELP := $(shell expr $(COLS_ADAPTED) - $(RUNHELP_LEN))
PAD_FLENGTH_GIT := $(shell expr $(COLS_ADAPTED) - $(GIT_LEN))
PAD_ADLENGTH_AUTHORS := $(shell expr $(PAD_FLENGTH_AUTHORS) / 2)
PAD_ADLENGTH_VERSION := $(shell expr $(PAD_FLENGTH_VERSION) / 2)
PAD_ADLENGTH_FUNCTION := $(shell expr $(PAD_FLENGTH_FUNCTION) / 2)
PAD_ADLENGTH_RUNHELP := $(shell expr $(PAD_FLENGTH_RUNHELP) / 2)
PAD_ADLENGTH_GIT := $(shell expr $(PAD_FLENGTH_GIT) / 2)

header:

ifeq ($(HEADER_DISPLAYED), 0)
	@printf '%s' "╔"
	@printf '%*s' "$(COLS_ADAPTED)" '' | tr ' ' ═
	@printf '%s\n' "╗"
	@printf ' %*s' "$(PAD_ADLENGTH_AUTHORS)" '' | tr ' ' ' '
	@printf '%s' " ${YELLOW}$(Authors)${RESET} "
	@printf '%*s\n' "$(PAD_ADLENGTH_AUTHORS)" '' | tr ' ' ' '
	@printf ' %*s' "$(PAD_ADLENGTH_VERSION)" '' | tr ' ' ' '
	@printf '%s' " ${GREEN}$(Version)${RESET} "
	@printf '%*s\n' "$(PAD_ADLENGTH_VERSION)" '' | tr ' ' ' '
	@printf '%*s' "$(PAD_ADLENGTH_FUNCTION)" '' | tr ' ' ' '
	@printf '%s' " ${YELLOW}$(Function)${RESET} "
	@printf '%*s\n' "$(PAD_ADLENGTH_FUNCTION)" '' | tr ' ' ' '
	@printf '%*s' "$(PAD_ADLENGTH_RUNHELP)" '' | tr ' ' ' '
	@printf '%s' " ${GREEN}$(RunHelp)${RESET} "
	@printf '%*s\n' "$(PAD_ADLENGTH_RUNHELP)" '' | tr ' ' ' '
	@printf '%*s' "$(PAD_ADLENGTH_GIT)" '' | tr ' ' ' '
	@printf '%s' " ${YELLOW}$(Git)${RESET}  "
	@printf '%*s\n' "$(PAD_ADLENGTH_GIT)" '' | tr ' ' ' '
	@printf '%s' "╚"
	@printf '%*s' "$(COLS_ADAPTED)" '' | tr ' ' ═
	@printf '%s\n\n' "╝"
	$(eval HEADER_DISPLAYED = 0)
endif

endif
