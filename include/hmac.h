#ifndef HMAC_H
#define HMAC_H
#include <openssl/evp.h>
extern HMAC_CTX* hmac_init(const void *key, int len, enum hmac_type type);
extern void hmac_update(HMAC_CTX* ctx, const void *data, unsigned long len);
extern void hmac_final(HMAC_CTX* ctx, unsigned char *hashmacbuf, unsigned int *len);
#endif