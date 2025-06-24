## 💻 Guía paso a paso – Criptografía clásica en C++

---

### 🔹 Semana 1: Aritmética modular y teoría de números

📘 **Temas**:

* Operaciones modulares
* Inverso modular con Euclides extendido
* MCD

🧪 **Código base**:

```cpp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int mod_inverse(int a, int m) {
    for (int x = 1; x < m; ++x)
        if ((a * x) % m == 1) return x;
    return -1;
}
```

✅ Aplica: RSA, Affine cipher, generación de claves

---

### 🔹 Semana 2: Cifrados clásicos (César, Affine, Vigenère)

📘 **Temas**:

* Manipulación de texto
* Cifrado letra a letra con aritmética modular

🧪 **Ejemplo**: Cifrado César

```cpp
std::string caesar_encrypt(std::string text, int key) {
    for (char &c : text)
        if (isalpha(c))
            c = (toupper(c) - 'A' + key) % 26 + 'A';
    return text;
}
```

✅ Aplica: compresión de lógica criptográfica clásica

---

### 🔹 Semana 3: Hashes (SHA-1, SHA-256)

📘 **Temas**:

* Hashing de mensajes
* Verificación de integridad

🧪 **Bibliotecas recomendadas**:

* [`OpenSSL`](https://www.openssl.org/)
* [`Crypto++`](https://cryptopp.com/)
* [`Botan`](https://botan.randombit.net/)

🔧 **Ejemplo con OpenSSL**:

```cpp
#include <openssl/sha.h>

void hash_sha256(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)data.c_str(), data.size(), hash);
}
```

✅ Aplica: passwords, firmas, integridad de archivos

---

### 🔹 Semana 4: Cifrado simétrico (AES)

📘 **Temas**:

* Modos: ECB, CBC, CTR
* Relleno (padding)
* Clave y IV

🧪 **OpenSSL AES example**:

```cpp
#include <openssl/evp.h>

EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
// Luego usa EVP_EncryptUpdate y EVP_EncryptFinal_ex
```

✅ Aplica: cifrado de archivos y datos sensibles

---

### 🔹 Semana 5–6: Criptografía asimétrica (RSA)

📘 **Temas**:

* Clave pública/privada
* Cifrado y descifrado
* Padding PKCS#1

🧪 **Ejemplo con OpenSSL**:

```cpp
RSA *rsa = RSA_generate_key(2048, RSA_F4, NULL, NULL);
RSA_public_encrypt(...);
RSA_private_decrypt(...);
```

🔧 También puedes cargar claves desde archivos `.pem`.

✅ Aplica: firma de documentos, comunicación segura

---

### 🔹 Semana 7–8: Firmas digitales

📘 **Temas**:

* SHA256 + RSA
* Firmar un hash y verificarlo

🧪 OpenSSL con `RSA_sign` y `RSA_verify`:

```cpp
RSA_sign(NID_sha256, hash, hash_len, sig, &sig_len, rsa_private);
RSA_verify(NID_sha256, hash, hash_len, sig, sig_len, rsa_public);
```

✅ Aplica: autenticación, blockchain, tokens firmados

---

## 🔧 Herramientas y bibliotecas recomendadas

| Biblioteca    | ¿Para qué sirve?                                        |
| ------------- | ------------------------------------------------------- |
| **OpenSSL**   | Criptografía estándar: AES, RSA, SHA                    |
| **Crypto++**  | Biblioteca completa en C++ puro (AES, RSA, ECC, etc.)   |
| **Botan**     | Modular, segura, multiplataforma                        |
| **libsodium** | Criptografía moderna y segura (más simple, estilo Rust) |

---

## 🧪 Proyecto sugerido

Crea un pequeño CLI en C++ que:

* Genere claves RSA
* Cifre/descifre un archivo de texto
* Firme un mensaje y lo verifique

Puedes compilarlo con CMake y usar `openssl` o `crypto++` como dependencia.

---

## 🧱 En resumen (comparado con otros lenguajes):

| Lenguaje | Dificultad    | Control  | Uso en producción                 |
| -------- | ------------- | -------- | --------------------------------- |
| Python   | 🟢 Fácil      | Bajo     | Scripts, prototipos               |
| Go       | 🟡 Media      | Medio    | Backend, microservicios           |
| Rust     | 🔵 Media-alta | Alto     | Criptografía segura, blockchain   |
| C++      | 🔴 Alta       | Muy alto | Infraestructura, bibliotecas core |

---