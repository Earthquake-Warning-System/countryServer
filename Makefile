CROSS_COMPILE =
AR = $(CROSS_COMPILE)ar
CC = $(CROSS_COMPILE)gcc
CFLAGS = -fPIC -W -Wno-unused-result -D_REENTRANT -DDEBUG -g -s -Wall -Wextra

INCLUDE =
INCLUDE += -I../
INCLUDE += -I./EQ_header_v0.5.1
INCLUDE += -I/usr/include/postgresql/
INCLUDE += -I/usr/include/hiredis/

LIBS =
LIBS += -L./EQ_header_v0.5.1 -lev -lstdc++ -lpthread -lhiredis -lprotobuf-c

obj = EQ_redis.o EQ_judgement.o EQ_interface.o EQ_server.o interface.pb-c.o

all: clean main romfs fclean

main: $(obj)
	$(CC) $(CFLAGS) -o server $(obj) $(LIBS) $(INCLUDE)

clean:
	rm -f *.o server
	@echo --- all references deleted

romfs:
	@echo --- make done

%.o:%.c
	gcc -c $< $(INCLUDE) $(CFLAGS)

fclean:
	rm -f *.o
	@echo --- all references deleted
