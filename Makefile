all: list

CFLAGS := -Wall

list: main.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f .tags *.o list
