# Secure-View

# 🔐 SecureView

**SecureView** is a simple Qt-based desktop application that lets you encrypt any password using an XOR cipher, copy the encrypted result to your clipboard, and save it to a local file for later use or decryption.

---

## ✨ Features

- Password input (hidden by default)
- XOR-based encryption
- Base64-encoded output
- Auto-copy to clipboard
- Auto-save encrypted result to `data/final.file` in the app directory

---

## 🖥 How to Use

1. Launch `SecureView.exe`
2. Enter your password in the input box
3. Press **Enter** or click the **Enter** button
4. The app will:
   - Encrypt your input using a static key
   - Copy the encrypted string to clipboard
   - Save it as `final.file` in the `data/` folder
   - Display a success message

---

## 🔑 Encryption Key

The encryption is performed using a static XOR key:

ZZZBESTGAME/


> **Important:** You must use this exact key in any decryptor app for correct decryption (e.g., SecureDecryptor).

---

## 📁 Output File Location

After encryption, the result is saved to:

[App_Directory]/data/final.file


If the folder doesn't exist, SecureView will automatically create it.

---

## 🛠 Build & Deployment

### Requirements

- Qt 6.9.1 or compatible version
- C++17 compiler (e.g., MinGW 64-bit)
