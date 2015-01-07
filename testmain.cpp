#include <cstdio>
#include <string>

using namespace std;

#include "aescpp.h"

void print_hex(const void* ptr, int len) {
	const unsigned char* p = (const unsigned char*)ptr;
	for (int i = 0; i < len; ++i)
		printf("%02x", *p++);
	printf("\n");
}

int main() {
	string res = encrypt_cbc("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "1111111111111111", "2011121211143000");
	print_hex(res.c_str(), res.length());
	return 0;
}

