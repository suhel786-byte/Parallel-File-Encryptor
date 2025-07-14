# 🔐 Parallel File Encryptor

A high-performance C++ application for encrypting and decrypting files using multithreaded (parallel) processing. Designed to handle large files efficiently and securely.

---

## 📌 Features

- ⚡ **Fast encryption/decryption** using parallel processing
- 🔐 **Custom encryption logic** implemented in C++
- 🧵 **Multithreading support** for improved performance
- 🖥️ **Cross-platform compatible**
- 💡 Simple command-line usage
- 🛠️ Includes precompiled Windows `.exe` files

---

## ⚙️ Build Instructions

### 🧱 Requirements

- C++ compiler (e.g., `g++`)
- `make` utility (optional, but recommended)

### 🏗️ Compile

To compile the project using the provided `Makefile`, run the following command in the terminal:

```bash
make
```

This will build the project and generate the required executables.

---

## 🚀 How to Use

Use the following command to run the tool:

```bash
./encrypt_decrypt <encrypt|decrypt> <input_file> <output_file>
```

### 🔄 Example

```bash
./encrypt_decrypt encrypt sample.txt encrypted.dat
./encrypt_decrypt decrypt encrypted.dat decrypted.txt
```

This will encrypt the contents of `sample.txt` into `encrypted.dat`, and then decrypt it back to `decrypted.txt`.

---

## 📦 Binaries

The folder includes the following precompiled executables (for Windows):

- `encrypt_decrypt.exe` — Binary to run encryption/decryption
- `cryption.exe` — Possibly a supporting tool used internally for cryptographic functions

> If you're on Linux or macOS, you may need to compile the project using `make` or a C++ compiler.

---

## 👨‍💻 Author

Developed by [Suhel Baig]  
Feel free to fork, enhance, or use it for learning purposes!

---



