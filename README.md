# meteo-tracker

A real-time meteo tracking program based on a client-server architecture.

## building

You can use GNU make to compile the program like this:

```cd meteo-tracker/src```

```make```

## connecting to the server using netcat

Once the application is compiled you can start the server with ./meteo-tracker

you can then use netcat to connect with it via TCP port 5000

```nc localhost 5000```
