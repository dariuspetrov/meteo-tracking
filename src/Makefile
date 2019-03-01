TARGET = meteo-tracker
CC = gcc
CFLAGS = -O2 -Wall

default: meteo-tracker

server: server.o
	$(CC) $(CFLAGS) -o server server.o

client: client.o
	$(CC) $(CFLAGS) -o client client.o

meteo-tracker: client.o server.o
	# $(CC) $(CFLAGS) $@ client.o server.o
	$(CC) $(CFLAGS) -o client client.o
	$(CC) $(CFLAGS) -o server server.o

clean:
	rm *.o server client
