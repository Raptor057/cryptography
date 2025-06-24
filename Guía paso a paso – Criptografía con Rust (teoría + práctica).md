## 🦀 Guía paso a paso – Criptografía con Rust (teoría + práctica)

---

### 🔹 Semana 1: Fundamentos matemáticos en Rust

📘 **Temas**:

* Aritmética modular
* Inverso modular (Euclides extendido)

🧪 **Rust básico**:

```rust
fn mod_inverse(a: i64, m: i64) -> Option<i64> {
    for x in 1..m {
        if (a * x) % m == 1 {
            return Some(x);
        }
    }
    None
}
```

🔧 Usa crates útiles: `num`, `num-bigint`, `num-traits`

✅ Aplica: RSA, Diffie-Hellman, Affine cipher

---

### 🔹 Semana 2: Teoría de números

📘 **Aprender**:

* Números primos, MCD, phi de Euler
* Algoritmo de Euclides

🧪 Con el crate `num`:

```toml
[dependencies]
num = "0.4"
```

```rust
use num::integer::gcd;
```

✅ Aplica: claves RSA, generación de primos grandes

---

### 🔹 Semana 3: Hashes

📘 **Temas**:

* SHA256, HMAC
* Verificación de integridad

🧪 Usar `sha2` crate:

```toml
[dependencies]
sha2 = "0.10"
```

```rust
use sha2::{Sha256, Digest};

fn main() {
    let mut hasher = Sha256::new();
    hasher.update(b"mensaje");
    let result = hasher.finalize();
    println!("{:x}", result);
}
```

✅ Aplica: firmas digitales, JWTs, passwords

---

### 🔹 Semana 4: Cifrado simétrico (AES)

📘 **Temas**:

* Bloques, modos (CBC, CTR)

🧪 Crate: `aes` + `block-modes` + `rand`

```toml
aes = "0.8"
block-modes = "0.8"
rand = "0.8"
```

```rust
use aes::Aes128;
use block_modes::{BlockMode, Cbc};
use block_modes::block_padding::Pkcs7;

type Aes128Cbc = Cbc<Aes128, Pkcs7>;
```

✅ Aplica: cifrado de archivos y mensajes

---

### 🔹 Semana 5–6: Criptografía asimétrica (RSA)

📘 **Temas**:

* Generación de claves
* Cifrado con clave pública

🧪 Crate: `rsa` + `rand` + `sha2`

```toml
rsa = "0.8"
rand = "0.8"
sha2 = "0.10"
```

```rust
use rsa::{RsaPrivateKey, RsaPublicKey, PaddingScheme};
use rand::rngs::OsRng;

let mut rng = OsRng;
let bits = 2048;
let priv_key = RsaPrivateKey::new(&mut rng, bits)?;
let pub_key = RsaPublicKey::from(&priv_key);
```

✅ Aplica: cifrado seguro, intercambio de claves

---

### 🔹 Semana 7–8: Firmas digitales

📘 **Temas**:

* Firmar y verificar mensajes

🧪 Criptografía con `rsa::pkcs1v15_sign` y SHA256

```rust
let msg = b"mensaje";
let hashed = Sha256::digest(msg);
let sig = priv_key.sign(PaddingScheme::PKCS1v15Sign { hash: None }, &hashed)?;
pub_key.verify(PaddingScheme::PKCS1v15Sign { hash: None }, &hashed, &sig)?;
```

✅ Aplica: tokens, validación de identidad

---

### 🔧 Bonus: Curvas elípticas (ECC)

🧪 Usa el crate [`k256`](https://crates.io/crates/k256) para trabajar con secp256k1.

---

### 🛠 Crates útiles de Rust para criptografía

| Crate                | ¿Para qué sirve?                         |
| -------------------- | ---------------------------------------- |
| `rsa`                | RSA clásico                              |
| `sha2`, `blake3`     | Hashes seguros                           |
| `aes`, `block-modes` | Cifrado simétrico                        |
| `k256`, `p256`       | ECC modernas                             |
| `ring`               | Alternativa todo-en-uno, rápida y segura |
| `zeroize`, `secrecy` | Manejo seguro de secretos en memoria     |

---

### 🧪 Proyecto sugerido

Crea un CLI con `clap` para:

* Generar claves RSA
* Cifrar/descifrar mensajes
* Firmar/verificar archivos
* Hashear contraseñas

---