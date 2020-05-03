#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/hmac.h>

enum hmac_type { HMAC_SHA1, HMAC_SHA256, HMAC_SHA512};
HMAC_CTX* hmac_init(const void *key, int len, enum hmac_type type) {
  HMAC_CTX*  ctx = NULL;

  ctx = HMAC_CTX_new();
  if (ctx == NULL) {
    return NULL;
  }
  switch(type) {
    case HMAC_SHA1:
      HMAC_Init_ex(ctx, key, len, EVP_sha1(), NULL);
      break;
    case HMAC_SHA256:
      HMAC_Init_ex(ctx, key, len, EVP_sha256(), NULL);
      break;
    case HMAC_SHA512:
      HMAC_Init_ex(ctx, key, len, EVP_sha512(), NULL);
      break;
    default:
      HMAC_CTX_free(ctx);
      ctx = NULL;
  }
  return ctx;
}
void hmac_update(HMAC_CTX* ctx, const void *data, unsigned long len) {
  HMAC_Update(ctx, data, len);
}

void hmac_final(HMAC_CTX* ctx, unsigned char *hashmacbuf, unsigned int *len) {
  HMAC_Final(ctx,hashmacbuf,len);

#if OPENSSL_VERSION_NUMBER > 0x10100000L
  HMAC_CTX_free(ctx);
  ctx = NULL;
#else
  HMAC_cleanup(ctx);
  SAFE_FREE(ctx);
  ctx = NULL;
#endif
}