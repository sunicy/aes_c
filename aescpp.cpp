#include <cstring>
#include <string>

using namespace std;

#include "aescpp.h"
#include "aes.h"

void memxor(void* dst, void* src, int len) {
	unsigned char *d = (unsigned char*)dst,
		*s = (unsigned char*)src;
	for (int i = 0; i < len; ++i)
		*d++ ^= *s++;
}

string encrypt_cbc(
	const string& plaintext, 
	const string& key_,
	const string& iv_
) {
	int plain_len = plaintext.length();
	int block_count = plaintext.length() / 16;
	int padding_len = 16 - plaintext.length() % 16;
	unsigned char key[16];
	unsigned char iv[16];
	unsigned char* data = new unsigned char[block_count * 16 + 16];
	memcpy(data, plaintext.c_str(), plain_len);
	memset(data + plain_len, (char)padding_len, padding_len);

	memcpy(key, key_.c_str(), 16);
	memcpy(iv, iv_.c_str(), 16);

	{
		for (int i = 0; i <= block_count; ++i) {
			// 1. block XOR iv
			memxor(data + i * 16, iv, 16);
			// 2. ECB encrypt the block
			AES_Encrypt(data + i * 16, key);
			// 3. Update iv
			memcpy(iv, data + i * 16, 16);
		}
	}
	string res((char*)data, block_count * 16 + 16);
	delete[] data;
	return res;
}

string decrypt_cbc(
	const string& ciphertext, 
	const string& key, 
	const string& iv_
) {
	return string();
}
