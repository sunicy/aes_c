#pragma once

#include <string>

using namespace std;

// AES/CBC/PKCS5Padding
string encrypt_cbc(
	const string& plaintext, 
	const string& key_,
	const string& iv
);

string decrypt_cbc(
	const string& ciphertext, 
	const string& key_, 
	const string& iv
);
