## 🐍 Guía paso a paso – Criptografía clásica en Python

---

### 🔹 Semana 1: Aritmética modular y teoría de números

📘 **Temas**:

* Operaciones modulares (`%`, `pow`)
* Inverso modular con Euclides extendido
* MCD y primalidad

🧪 **Ejemplo en Python**:

```python
def mod_inverse(a, m):
    for x in range(1, m):
        if (a * x) % m == 1:
            return x
    return None
```

🔧 Usa `sympy` para operaciones más avanzadas:

```python
from sympy import mod_inverse, gcd, isprime
```

✅ Aplica: RSA, Diffie-Hellman, Affine cipher

---

### 🔹 Semana 2: Cifrados clásicos (César, Affine, Vigenère)

📘 **Temas**:

* Manipulación de texto con cifrado modular
* Introducción a cifrados por sustitución

🧪 **Ejemplo: cifrado César**:

```python
def caesar_encrypt(text, key):
    return ''.join(chr((ord(c.upper()) - 65 + key) % 26 + 65) if c.isalpha() else c for c in text)
```

✅ Aplica: primeros pasos en cifrado, visualización de patrones

---

### 🔹 Semana 3: Hashes (SHA-256, HMAC)

📘 **Temas**:

* Hashing seguro
* Integridad de mensajes

🧪 **Librerías**: `hashlib`, `hmac`

```python
import hashlib

hash = hashlib.sha256(b"mensaje").hexdigest()
print(hash)
```

✅ Aplica: almacenamiento de contraseñas, verificación de datos

---

### 🔹 Semana 4: Cifrado simétrico (AES)

📘 **Temas**:

* Clave y vector de inicialización (IV)
* Modos de operación (CBC, ECB)

🧪 **Librerías**: `cryptography`, `pycryptodome`

```python
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

key = get_random_bytes(16)
cipher = AES.new(key, AES.MODE_ECB)
```

✅ Aplica: cifrado de archivos, comunicaciones privadas

---

### 🔹 Semana 5–6: Criptografía asimétrica (RSA)

📘 **Temas**:

* Clave pública/privada
* Cifrado, firma, padding

🧪 **Librería**: `cryptography`

```python
from cryptography.hazmat.primitives.asymmetric import rsa

private_key = rsa.generate_private_key(public_exponent=65537, key_size=2048)
public_key = private_key.public_key()
```

✅ Aplica: envío seguro, almacenamiento cifrado, claves compartidas

---

### 🔹 Semana 7–8: Firmas digitales

📘 **Temas**:

* Hash + firma con clave privada
* Verificación con clave pública

🧪 **Librería**: `cryptography`

```python
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.asymmetric import padding

message = b"mensaje"
signature = private_key.sign(
    message,
    padding.PSS(mgf=padding.MGF1(hashes.SHA256()), salt_length=padding.PSS.MAX_LENGTH),
    hashes.SHA256()
)

public_key.verify(signature, message, padding.PSS(...), hashes.SHA256())
```

✅ Aplica: autenticación, validación de documentos

---

## 🔧 Librerías útiles en Python

| Librería       | ¿Para qué sirve?                                     |
| -------------- | ---------------------------------------------------- |
| `cryptography` | Criptografía moderna (RSA, AES, firmas)              |
| `pycryptodome` | Alternativa compatible con `pycrypto`                |
| `hashlib`      | Hashes SHA, MD5                                      |
| `sympy`        | Operaciones matemáticas simbólicas (modular, primos) |
| `secrets`      | Generación segura de claves aleatorias               |

---

## 🧪 Proyecto sugerido

Crea un script que:

* Genere claves RSA
* Cifre/descifre mensajes
* Firme archivos y verifique su integridad
* Genere hashes para contraseñas y los compare

---
