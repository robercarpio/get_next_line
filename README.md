# 📄 get_next_line

## 🎯 Project Goals

The `get_next_line` project, developed as part of the 42 curriculum by student **robercarpio**, focuses on building a function capable of reading a file **line by line**. This project is essential for understanding file handling at a low level in C and mastering memory management and buffer control.

The objective is to implement a function called `get_next_line` that reads from a file descriptor and returns each line of text one at a time, including the newline character (`\n`) if it exists. The function must behave correctly regardless of the size of the lines or the number of file descriptors in use.

This project is a mandatory part of the 42 core curriculum and is designed to enhance understanding of file I/O operations, dynamic memory allocation, and static variable usage.

---

## 📖 Line-by-Line Reading

The main feature of `get_next_line` is the ability to read a text file or input **one line at a time**, returning a newly allocated string each time the function is called. A line is considered to end either with a newline character (`\n`) or the end-of-file (`EOF`).

📌 To achieve this, the function must:
- 🔄 Handle **incomplete reads**
- 🧠 Store **leftover data** between function calls
- ➕ Append newly read data to previous buffer content

📥 The function supports reading from:
- 📄 A file
- 🧑‍💻 Standard input (e.g., terminal)
- 🔁 Multiple consecutive calls

---

## 🧩 File Descriptor Management

The function must support **reading from multiple file descriptors simultaneously** 🧵

This means that the internal state for each file descriptor must be managed independently to avoid data conflicts when switching between different sources.

| Feature                            | Description                                              |
|------------------------------------|----------------------------------------------------------|
| 🔀 Independent state per fd        | Each file has its own static buffer                     |
| 📚 No data mixing                  | Switching files does not lose previously read data       |
| 🛠️ Bonus compliant (if done)       | Uses separate source files for multi-fd support          |

---

## 🧠 Buffer Management and Memory Safety

Managing memory dynamically is a critical part of the implementation:

- 🔢 The read size is determined by the `BUFFER_SIZE` macro
- 📐 Must handle lines **longer than `BUFFER_SIZE`**
- ✅ Must **free memory** appropriately to avoid memory leaks

| Requirement            | Details                                         |
|------------------------|--------------------------------------------------|
| 🔁 Multiple reads       | Loop if a line spans more than one buffer       |
| 🧼 Proper cleanup       | Free memory when no longer needed               |
| 💾 Efficient allocation | Use only as much memory as needed for each line |

---

## 📏 Technical Constraints

Your implementation must respect the **42 Norm**:

| ✅ Allowed Functions | ❌ Forbidden Items               |
|----------------------|----------------------------------|
| `read`               | ❌ Global variables              |
| `malloc`             | ❌ Variable declarations in loops|
| `free`               | ❌ Ternary operators             |

📌 Additional Norm rules:
- Max **25 lines per function**  
- Max **5 variables per function**  
- No ternary operators  
- Use of `static` variables is permitted

---

## 📚 Educational Purpose

This project is designed to help students:

- 📂 Understand how reading from a file descriptor works at a low level
- 🧠 Learn how to manage persistent state inside a function using `static` variables
- 💡 Improve skills in:
  - Dynamic memory allocation
  - String manipulation
  - Handling buffers
- 🧱 Follow strict code style and function limitations imposed by the 42 Norm

---

## ✅ Summary

The `get_next_line` project is a great opportunity to practice low-level programming concepts, memory control, and structured coding. It lays a strong foundation for handling more advanced file manipulation and buffer-based I/O in C.

---

© 2025 **robercarpio** – 42 Cursus | `get_next_line`
