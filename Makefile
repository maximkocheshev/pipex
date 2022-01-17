
NAME		=	pipex

LIB_PATH	=	libft/

LIB_FILE	=	ft_split.c ft_strdup.c ft_strjoin.c ft_strncmp.c ft_strrchr.c ft_strlen.c

SRCS		=	pipex.c ft_get_path.c ft_child.c ft_free_struct.c

LIB			= 	$(addprefix $(LIB_PATH), $(LIB_FILE))

HEADER		=	pipex.h
OBJ			=	${SRCS:%.c=%.o}
LIB_OBJ		=	${LIB:%.c=%.o}

CC			=	gcc
CGLAGS		=	-Wall -Wextra -Werror -I${HEADER}

.PHONY		:	all clean fclean re

all			:	${NAME}

$(NAME)		:	$(OBJ) ${LIB_OBJ} ${HEADER}
	$(CC) $(CFLAGS) $(OBJ) $(LIB_OBJ) -o $(NAME)

clean		:
	${RM} ${OBJ} ${LIB_OBJ}

fclean		:	clean
	${RM} ${NAME}

re			: 	fclean all