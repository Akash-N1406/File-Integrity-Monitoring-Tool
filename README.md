
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

## 📘 How to Use

### 🔧 Step 1: Compile the Program

Use `g++` to compile the source code:

```bash
g++ file_monitor.cpp -o file_monitor
````

---

### 📂 Step 2: Choose a Directory to Monitor

Create a test directory (optional):

```bash
mkdir ~/test_watch
```

---

### ▶️ Step 3: Run the Tool

Run the program and provide the path to the directory you want to monitor:

```bash
./file_monitor ~/test_watch
```

**Expected Output:**

```
Monitoring changes in: /home/your_user/test_watch
```

---

### 🧪 Step 4: Perform Some File Operations

In a **separate terminal window**, try the following inside the watched directory:

```bash
cd ~/test_watch
touch newfile.txt
echo "Hello" > newfile.txt
rm newfile.txt
```

**Real-Time Output from Monitor:**

```
Created: newfile.txt
Modified: newfile.txt
Deleted: newfile.txt
```

---

### ❗ Notes

* ✅ Only works on **Linux systems** (uses `inotify`)
* 🚫 Does **not** monitor subdirectories (non-recursive)
* 🔐 You may need `sudo` for protected directories (e.g., `/etc`, `/var/log`)

---

## 📂 Project Structure

```
.
├── file_monitor.cpp   # Main source file
├── README.md          # Project documentation
```

---

## 🌱 Future Enhancements

* [ ] Recursive directory monitoring
* [ ] Log events to a file
* [ ] Send email/notification alerts
* [ ] File checksum validation using SHA256
* [ ] Configurable via a JSON or INI file

---

