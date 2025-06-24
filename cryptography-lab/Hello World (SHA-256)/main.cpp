//g++ main.cpp -lcrypto -o hello


#include <openssl/sha.h>
#include <iostream>
#include <iomanip>

int main() {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    std::string message = "Hello, World!";

    SHA256(reinterpret_cast<const unsigned char*>(message.c_str()), message.length(), hash);

    std::cout << "SHA-256 (C++): ";
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    std::cout << std::endl;

    return 0;
}
