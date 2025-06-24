## 🧭 Guía paso a paso – Criptografía clásica con Go

---

### 🔹 Semana 1: Fundamentos y aritmética modular en Go

📘 **Conceptos matemáticos**:

* Módulo (`%`), potenciación modular, MCD.
* Inverso modular con Euclides extendido (lo implementas tú).

🧪 **Ejercicio en Go**:

```go
func modInverse(a, m int) int {
	for x := 1; x < m; x++ {
		if (a*x)%m == 1 {
			return x
		}
	}
	return -1 // no existe
}
```

✅ Aplica: bases para RSA, Affine cipher, Diffie-Hellman.

---

### 🔹 Semana 2: Teoría de números

📘 **Temas clave**:

* Números primos.
* Algoritmo de Euclides.
* Teorema de Euler.

🧪 **Ejercicio en Go**:

```go
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

✅ Aplica: generación de claves, validación de seguridad.

---

### 🔹 Semana 3: Hashes y firmas

📘 **Temas**:

* Hash SHA256/SHA512.
* Entropía.
* Firmas y verificación de integridad.

🧪 **Go con `crypto/sha256` y `crypto/hmac`**:

```go
import (
	"crypto/sha256"
	"fmt"
)

func main() {
	data := []byte("mensaje")
	hash := sha256.Sum256(data)
	fmt.Printf("%x\n", hash)
}
```

✅ Aplica: Verificación de datos, autenticación.

---

### 🔹 Semana 4: Cifrado simétrico (AES)

📘 **Temas**:

* Bloques, relleno, CBC, ECB, CTR.
* Clave y IV.

🧪 **Go con `crypto/aes` y `crypto/cipher`**:

```go
import (
	"crypto/aes"
	"crypto/cipher"
)

func encryptAES(key, plaintext []byte) []byte {
	block, _ := aes.NewCipher(key)
	ciphertext := make([]byte, len(plaintext))
	mode := cipher.NewCBCEncrypter(block, key[:aes.BlockSize])
	mode.CryptBlocks(ciphertext, plaintext)
	return ciphertext
}
```

✅ Aplica: Cifrado de mensajes o archivos.

---

### 🔹 Semana 5–6: Cifrado asimétrico (RSA)

📘 **Temas**:

* Claves públicas/privadas.
* Cifrado, firma y verificación.
* Padding: PKCS#1 v1.5 vs OAEP.

🧪 **Go con `crypto/rsa`**:

```go
import (
	"crypto/rand"
	"crypto/rsa"
	"crypto/sha256"
)

func main() {
	priv, _ := rsa.GenerateKey(rand.Reader, 2048)
	pub := &priv.PublicKey
	msg := []byte("secreto")
	ciphertext, _ := rsa.EncryptOAEP(sha256.New(), rand.Reader, pub, msg, nil)
}
```

✅ Aplica: Comunicación segura, identidad digital.

---

### 🔹 Semana 7–8: Firmas digitales

📘 **Temas**:

* RSA-SHA256.
* Verificación de integridad y autenticidad.

🧪 **Go con `rsa.SignPKCS1v15`**:

```go
hashed := sha256.Sum256([]byte("mensaje"))
signature, _ := rsa.SignPKCS1v15(rand.Reader, priv, crypto.SHA256, hashed[:])
```

✅ Aplica: Firmas de documentos, tokens, autenticación.

---

### 🔧 Extras para reforzar

| Tema                        | Recurso                             |
| --------------------------- | ----------------------------------- |
| ECC (Elliptic Curve Crypto) | Paquete `crypto/ecdsa`              |
| TLS/SSL                     | Usa `crypto/tls` para simular HTTPS |
| JWTs firmados               | Usa `github.com/golang-jwt/jwt`     |

---
