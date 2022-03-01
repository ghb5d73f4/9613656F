INCDIR = -I.
#/fasterac 
SOURCES := $(wildcard ./*.c)
OBJS := $(patsubst %.c,../../lib/%.o,$(SOURCES))
INCLUDES := $(wildcard fasterac/*.h)


CFLAGS := $(INCDIR) -O3 -Wall -g -fpermissive
LDFLAGS := -g

target: $(OBJS)

../../lib/%.o: %.c
	$(CXX) $< -c $(CFLAGS) $(INC) -o $@

