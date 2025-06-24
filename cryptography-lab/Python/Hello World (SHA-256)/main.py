import hashlib

message = b"Hello, World!"
hash_object = hashlib.sha256(message)
hex_dig = hash_object.hexdigest()

print(f"SHA-256 (Python): {hex_dig}")
