CC = g++
CFLAGS = -I.

RM = rm -rf

DEPS = mytype.h equationEvaluator.h equationParser.h
OBJS = equationEvaluator.o equationParser.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
equationEvaluator: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)
	
all: equationEvaluator

.PHONY: clean
		
clean: 
	$(RM) Tesla *.o
