VAR = mpipe.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS = $(VAR:.c = .o)
SRC = TEST

all : $(SRC)

$(SRC) :$(OBJS)
	cc -o $(SRC) $(OBJS) libft.a
