CC = g++
CFLAGS = -std=c++17 -g -Wall -I. -Isrc/app/encryptDecrypt -Isrc/app/fileHandling -Isrc/app/processes 

MAIN_TARGET = encrypt_decrypt
CRYPTION_TARGET = cryption

MAIN_SRC = main.cpp \
			src/app/processes/Process.cpp \
			src/app/fileHandling/IO.cpp \
			src/app/fileHandling/ReadEnv.cpp \
			src/app/encryptDecrypt/Cryption.cpp

			
CRYPTION_SRC =  src/app/encryptDecrypt/Cryption.cpp \
				src/app/encryptDecrypt/CryptionMain.cpp \
				src/app/fileHandling/IO.cpp \
				src/app/fileHandling/ReadEnv.cpp


MAIN_OBJ = $(MAIN_SRC:.cpp=.o)
CRYPTION_OBJ = $(CRYPTION_SRC:.cpp=.o)

all: $(MAIN_TARGET) $(CRYPTION_TARGET)

$(MAIN_TARGET): $(MAIN_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(CRYPTION_TARGET): $(CRYPTION_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MAIN_OBJ) $(CRYPTION_OBJ) $(MAIN_TARGET) $(CRYPTION_TARGET)

.PHONY: clean all