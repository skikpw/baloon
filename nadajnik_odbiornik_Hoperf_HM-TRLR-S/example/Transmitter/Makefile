CC=g++
OBJS1 = rpi_main.o $(patsubst %.cpp,%.o,$(wildcard ../../lib/*.cpp))
LDFLAGS += -lwiringPi
CFLAGS += -I../../lib
all: rpi_main

rpi_main: $(OBJS1)
	echo $(OBJS1)
	$(CC) -o rpi_main $(CFLAGS) $(LDFLAGS) $(OBJS1) 

$(OBJS1) : %.o : %.cpp
	$(CC) -c $(CFLAGS) $(LDFLAGS) $< -o $@

clean:
	rm -f rpi_main *.o


