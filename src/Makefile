TARGET = meteo-tracker
CC = gcc
CFLAGS = -O2 -Wall

default: meteo-tracker

meteo-tracker: main.o server.o
	$(CC) $(CFLAGS) -o $@ main.o server.o

clean:
	rm *.o meteo-tracker 
