FROM rust:1.78

WORKDIR /app

# Copiar manifiesto
COPY Cargo.toml .

# Crear src y copiar main.rs
RUN mkdir src
COPY main.rs src/

# Compilar
RUN cargo build --release

# Ejecutar
CMD ["./target/release/hello"]
