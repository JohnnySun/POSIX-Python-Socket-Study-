#include <stdio.h>
#include <string.h>
#include <sodium.h>
#include <crypt.h>

char *encrypt(char *message) {
	/* encrypt */
	char nonce[crypto_stream_chacha20_NONCEBYTES];
	char key[crypto_stream_chacha20_KEYBYTES];
	static char *output = NULL;

	memset(key, '\0', sizeof(key));
	strcpy(key,"test123");
	randombytes_buf(nonce, sizeof nonce);
	uint64_t n_len = crypto_stream_chacha20_NONCEBYTES * sizeof(nonce);
	uint64_t m_len = strlen(message) * sizeof(message);
	//printf("n_len:%d, m_len:%d\n", (int)n_len, (int)m_len);
	output = (char *)malloc(n_len + m_len);

	char *ciph = output;
	memcpy(ciph, nonce, n_len);

	/* encrypt message */
	crypto_stream_chacha20_xor((uint8_t *)(ciph + n_len)
							, (uint8_t *)message, m_len, (uint8_t *)nonce, (uint8_t *)key);

	return ciph;
}

char *decrypt(char *stream_ciph) {
	/* decrypt */

	char nonce[crypto_stream_chacha20_NONCEBYTES];
	//printf("size:%d\n", crypto_stream_chacha20_NONCEBYTES);
	char key[crypto_stream_chacha20_KEYBYTES];
	static char *output = NULL;

	memset(key, '\0', sizeof(key));
	strcpy(key,"test123");
	strncpy(nonce, stream_ciph, sizeof(nonce));
	uint64_t n_len = crypto_stream_chacha20_NONCEBYTES * sizeof(nonce);
	uint64_t m_len = strlen(stream_ciph + n_len) * sizeof(stream_ciph);
	//printf("n_len:%d, m_len:%d\n", (int)n_len, (int)m_len);
	output = (char *)malloc(m_len);

	char *message = output;

	/* encrypt message */
	crypto_stream_chacha20_xor((uint8_t *)message, (uint8_t *)(stream_ciph + n_len) , m_len, (uint8_t *)nonce, (uint8_t *)key);

	return message;
}

size_t get_crypt_len(char *stream_ciph) {

	char nonce[crypto_stream_chacha20_NONCEBYTES];
	strncpy(nonce, stream_ciph, sizeof(nonce));
	uint64_t n_len = crypto_stream_chacha20_NONCEBYTES * sizeof(nonce);
	uint64_t m_len = strlen(stream_ciph + n_len) * sizeof(stream_ciph);
	//printf("n_len:%d, m_len:%d\n", (int)n_len, (int)m_len);
	size_t len = (size_t)n_len + (size_t)m_len;
	return len;
}
