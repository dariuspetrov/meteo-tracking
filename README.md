# meteo-tracker

A real-time meteo tracking program based on a client-server architecture.

## building

You can use GNU make to compile the program like this:

```cd meteo-tracker/src```

```make```

It will compile both server.c and client.c (at the moment)

## connecting to the server using netcat

Once the application is compiled you can start the server with ./meteo-tracker

you can then use netcat to connect with it via TCP port 1042:

```nc localhost 1042```
