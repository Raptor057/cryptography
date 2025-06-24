## 🐳 How to Run Docker Images

```bash
# 🔧 Build the Docker image
docker build -t name-image .

# 🚀 Run non-interactive programs (e.g., print-only, no user input)
docker run --rm name-image

# 💬 Run interactive console programs (e.g., reads input from user)
docker run -it name-image

# 🧹 Run interactive AND auto-clean after exit (ideal for testing)
docker run -it --rm name-image

# 💾 Run with volume (to persist or read external files)
docker run -v $(pwd)/data:/app/data name-image

# 🛠️ Run with environment variables
docker run -e "MY_SECRET=value" name-image
```

---

### 📦 Notes:

* `--rm`: borra el contenedor al salir.
* `-it`: permite interacción en la terminal.
* `-v`: monta carpetas de tu host dentro del contenedor.
* `-e`: define variables de entorno dentro del contenedor.

---
