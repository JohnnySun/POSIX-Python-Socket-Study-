#ifndef _CRYPT_H
#define _CRYPT_H

#define BUF_SIZE 4096

char *encrypt(char *);
char *decrypt(char *);
size_t  get_crypt_len(char *);

#endif //_CRYPT_H
