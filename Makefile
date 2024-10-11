PROGRAM = miller_main
OBJS = 	headerfiles/prime_field.o \
		headerfiles/secondary_expansion.o \
		headerfiles/secondary_expansion_ellipse.o \
		headerfiles/sixth_expansion.o \
		headerfiles/twelfth_expansion.o \
		headerfiles/twelfth_expansion_BLS_ellipse.o \
		headerfiles/miller.o
CC = gcc
LIBS = -lgmp

TARGET = miller_main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) -c $< -o $@

$(OBJS) $(PROGRAM).o: miller_header.h

clean:
	rm -f *.o headerfiles/*.o