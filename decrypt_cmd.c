#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#include "ipcrypt.h"

int
main(int argc, char *argv[])
{
		
		unsigned char k[16];
		unsigned int i;
		
		if ( argc == 2 ) {
			strcpy(k, argv[1]);
		} 
		else {
			return 1;
		}
		
		unsigned char ip[4] = {0};
		unsigned char out[4];
		char ch;
		size_t index = 0;

		while(read(STDIN_FILENO, &ch, 1) > 0) {
			if (isdigit(ch)) {
				ip[index] *= 10;
				ip[index] += ch - '0';
			}
			else if (ch == '.' && ip[0] != 0 && index <= 3) { // We found a '.', we are indexing numbers and we don't have 4 indexes already
				index++;
			}
			else if (index > 2) { // no digit, no '.' and our ip is filled
				ipcrypt_decrypt(out, ip, k);
				printf("%d.%d.%d.%d%c",out[0],out[1],out[2],out[3],ch);
				index = 0;
				memset(ip, 0, 4);
			}
			else {
				printf("%c",ch);
			}
		}

		return 0;
}
