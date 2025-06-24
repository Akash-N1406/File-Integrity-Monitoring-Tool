# 🛡️ File Integrity Monitoring Tool (C++ & Linux)

A lightweight, real-time File Integrity Monitoring (FIM) tool built using **C++** and the **inotify** API on **Linux**. This tool watches a specified directory and logs any file **creation**, **deletion**, or **modification** events.

---

## 📌 Features

- ✅ Real-time monitoring of a specified directory
- ✅ Detects file:
  - Creation
  - Deletion
  - Modification
- ✅ Uses native Linux `inotify` API
- ✅ Minimal and efficient C++ codebase

---

## 🚀 Getting Started

### 🔧 Prerequisites

- Linux OS (inotify is Linux-specific)
- C++ compiler (`g++` or `clang++`)

### 🛠️ Build

```bash
g++ file_monitor.cpp -o file_monitor
