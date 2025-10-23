CC = gcc
CFLAGS = -Wall -Wextra -O2
.PHONY: all clean
all: score temp
score: score.c
	$(CC) $(CFLAGS) -o score score.c

temp: temp.c
	$(CC) $(CFLAGS) -o temp temp.c
clean:
	rm -f score temp *.o