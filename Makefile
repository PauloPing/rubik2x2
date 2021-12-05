
# Variable pour compiler
CC = gcc
CCFLAGS = -Wall -g

# Chemin
SRCDIR = src/
BINDIR = bin/
MODELEDIR = src/


OBJS = $(BINDIR)main.o $(BINDIR)rotation.o $(BINDIR)rubik.o $(BINDIR)listeChainee.o

all : $(OBJS) exec

$(BINDIR)%.o : $(SRCDIR)%.c 
	$(CC) $(CCFLAGS) -c $< -o $@
	$(CC) $(CCFLAGS) $(SRCDIR)main.c -o main

exec :
	./main
	
clean :
	@ rm $(BINDIR)*.o main mainVue 2> /dev/null || true
	@ echo "cleaning done"