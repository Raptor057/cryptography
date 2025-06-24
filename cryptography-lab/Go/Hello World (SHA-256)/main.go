package main

import (
	"crypto/sha256"
	"fmt"
)

func main() {
	message := []byte("Hello, World!")
	hash := sha256.Sum256(message)
	fmt.Printf("SHA-256 (Go): %x\n", hash)
}
