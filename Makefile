CC = gcc
CFLAGS = -Wall -pedantic -ansi -Werror
OBJ = pattern_matching_replacement.o my_strstr.o pattern.o replacement.o color.o visualized.o
EXEC = pattern_matching_replacement
  
$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)
  
my_strstr.o : my_strstr.c my_strstr.h
	$(CC) -c my_strstr.c $(CFLAGS) 
pattern.o : pattern.c my_strstr.h pattern.h color.h
	$(CC) -c pattern.c $(CFLAGS)
replacement.o : replacement.c my_strstr.h replacement.h color.h
	$(CC) -c replacement.c $(CFLAGS)
color.o : color.c my_strstr.h color.h
	$(CC) -c color.c $(CFLAGS)
visualized.o : visualized.c visualized.h my_strstr.h color.h
	$(CC) -c visualized.c $(CFLAGS)

pattern_matching_replacement.o : pattern_matching_replacement.c pattern.h replacement.h color.h
	$(CC) -c pattern_matching_replacement.c $(CFLAGS)

ifdef DEBUG
CFLAGS += -D DEBUG
DEBUG : clean $(EXEC)
endif

clean :
	rm -f $(EXEC) $(OBJ)
