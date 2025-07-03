PROGRAM = main              # ← 実行ファイル名（main.cに合わせる）
MAIN_SRC = main.c          # ← main関数があるファイル

OBJS = 	headerfiles/fp.o \
		headerfiles/fp2.o \
		headerfiles/efp2.o \
		headerfiles/fp6.o \
		headerfiles/fp12.o \
		headerfiles/efp12.o \
		headerfiles/miller.o

CC = gcc
LIBS = -lgmp

TARGET = $(PROGRAM)

all: $(TARGET)

$(TARGET): $(MAIN_SRC) $(OBJS)
	$(CC) -o $(TARGET) $(MAIN_SRC) $(OBJS) $(LIBS)

headerfiles/%.o: headerfiles/%.c miller_header.h
	$(CC) -c $< -o $@

clean:
	rm -f $(TARGET) headerfiles/*.o