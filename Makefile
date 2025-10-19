CC = gcc
CRFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/playlist.c 
OBJ = main.o playlist.o 
EXEC = Playlist

$(EXEC): $(OBJ)
	$(CC) $(CRFLAGS) -o $(EXEC) $(OBJ)

main.o: src/main.c include/playlist.h
	$(CC) $(CRFLAGS) -c src/main.c -o main.o 

playlist.o: src/playlist.c include/playlist.h
	$(CC) $(CRFLAGS) -c src/playlist.c -o playlist.o 

clean:
	rm -f $(OBJ) $(EXEC)