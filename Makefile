CC=gcc
CFLAGS=-I.

all: encrypt decrypt

encrypt:
	$(CC) -o encrypt encrypt_cmd.c ipcrypt.c -I.
decrypt:
	$(CC) -o decrypt decrypt_cmd.c ipcrypt.c -I.

clean:
	rm encrypt decrypt
