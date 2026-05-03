# 🧠 Mini-C Compiler (Flex & Bison Based)

## 📌 Overview

The **Mini-C Compiler** is a simplified compiler designed to process a subset of the C programming language.
It demonstrates the working principles of compiler design including **lexical analysis, syntax analysis, semantic validation, and intermediate code generation**.

The project is implemented using **C, Flex, and Bison**, and helps visualize how source code is transformed step-by-step inside a compiler pipeline.

This project was developed as part of a **Compiler Design academic coursework project**.

---

# 🚀 Key Features

* Lexical analysis using **Flex**
* Syntax parsing using **Bison**
* Token recognition system
* Grammar validation support
* Symbol table generation
* Error detection and reporting
* Intermediate code generation support
* Handles subset of C language constructs
* Modular compiler architecture

---

# 🧩 Supported Mini-C Constructs

The compiler supports:

### Data Types

* int
* float
* char

### Statements

* Variable declarations
* Assignment statements
* Arithmetic expressions
* Conditional statements
* Loops (if implemented)
* Functions (if implemented)

### Operators

* Arithmetic operators (+ − × ÷)
* Relational operators
* Logical operators

---

# ⚙️ Compiler Architecture

The Mini-C compiler follows standard compiler phases:

```text
Source Code
   ↓
Lexical Analysis (Flex)
   ↓
Syntax Analysis (Bison)
   ↓
Semantic Checking
   ↓
Symbol Table Creation
   ↓
Intermediate Representation
```

---

# 🧠 Technologies Used

Programming Language:

* C

Compiler Tools:

* Flex (Lexical Analyzer Generator)
* Bison (Parser Generator)

Environment:

* GCC Compiler
* Linux / WSL / Git Bash / VS Code Terminal

---

# 📂 Project Structure

```text
Mini-C-Compiler/
│
├── lexer.l
├── parser.y
├── symbol_table.c
├── symbol_table.h
├── intermediate_code.c
├── Makefile
└── test_cases/
```

(Project structure may vary slightly depending on implementation)

---

# ⚙️ Installation & Setup

## Step 1 — Install Dependencies

Linux / WSL:

```bash
sudo apt install flex bison gcc make
```

---

## Step 2 — Clone Repository

```bash
git clone https://github.com/YOUR_USERNAME/Mini-C-compiler.git
cd Mini-C-compiler
```

---

## Step 3 — Compile Project

```bash
make
```

---

## Step 4 — Run Compiler

```bash
./compiler input.c
```

Example:

```bash
./compiler test.c
```

---

# 🧪 Example Input Program

```c
int main() {
    int a = 5;
    int b = 10;
    int c;

    c = a + b;

    return 0;
}
```

---

# 📊 Output Generated

The compiler performs:

✔ Token generation
✔ Syntax validation
✔ Symbol table creation
✔ Intermediate representation output

---

# 🎯 Project Objectives

The main objectives of this project:

* Understand compiler design workflow
* Implement lexical analyzer using Flex
* Implement parser using Bison
* Construct symbol table
* Detect syntax errors
* Generate intermediate code

---

# 📈 Future Enhancements

Possible improvements:

* Full semantic analysis support
* Optimization phase implementation
* Assembly code generation
* Function parameter handling
* Array support
* Scope management enhancements

---

# 🎓 Academic Relevance

This project demonstrates:

* Compiler construction principles
* Context-free grammar implementation
* Tokenization techniques
* Syntax tree generation
* Parsing strategies

Useful for subjects like:

* Compiler Design
* System Programming
* Programming Languages

---

# 👨‍💻 Author

**Aryan Tomar**
B.Tech Computer Science Engineering

---

# 📄 License

This project is developed for academic and educational purposes.
