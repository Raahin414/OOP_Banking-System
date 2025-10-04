# Banking System in C++

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [Objectives](#2-objectives)
3. [System Features](#3-system-features)

   * [Customer Functionalities](#customer-functionalities)
   * [Administrator Functionalities](#administrator-functionalities)
4. [System Design](#4-system-design)
5. [Tools and Technologies](#5-tools-and-technologies)
6. [How to Compile and Run](#6-how-to-compile-and-run)
7. [Limitations](#7-limitations)
8. [Future Enhancements](#8-future-enhancements)
9. [Learning Outcomes](#9-learning-outcomes)
10. [Conclusion](#10-conclusion)

---

## 1. Introduction

This project is a **console-based Banking System** developed in C++.
It models essential banking operations, including account creation, deposits, withdrawals, fund transfers, loan processing, and statement generation.

Unlike a fully automated banking application, this project is designed to require **user interference at key decision points** (for example, loan applications must be processed manually by the administrator). This design reflects the academic goal of demonstrating **logical flows and human-controlled decision-making** within an object-oriented program.

---

## 2. Objectives

* To design and implement a simplified banking system using **Object-Oriented Programming (OOP)**.
* To apply **inheritance, polymorphism, and encapsulation** in real-world inspired scenarios.
* To simulate both **customer** and **administrator** operations.
* To demonstrate the use of **C++ Standard Library data structures** for system functionality.
* To provide an interactive system requiring **manual decision-making**, simulating real administrative control.

---

## 3. System Features

### Customer Functionalities

* Create accounts of different types:

  * Checking Account
  * Savings Account (with annual interest)
  * Business Account (with overdraft facility)
* Secure login using account number and password.
* Deposit and withdraw funds.
* Transfer funds to another account.
* Apply for loans (requests sent to admin for approval).
* Repay outstanding loans with interest.
* View account balance and transaction statement.

### Administrator Functionalities

* Create and manage customer accounts.
* View details of all accounts (owner, balance, loan status).
* Manually process loan requests: **approve or reject applications**.
* Release annual interest for savings accounts.
* Modify customer account details.

> **Note:** The system is **not self-operating**. Administrative operations such as loan approvals, account modifications, and interest releases require **direct admin input**. This reflects the concept of **human-supervised banking systems**.

---

## 4. System Design

The system is built using OOP principles:

* **Class `Person`**: Stores customer/admin details such as name, phone number, NIC, address, and next-of-kin.
* **Abstract Class `BankAccount`**: Defines account attributes (account number, password, balance, loan) and common methods (deposit, balance inquiry).
* **Derived Classes**:

  * `SavingsAccount`: Supports interest calculation.
  * `CheckingAccount`: Provides basic deposit/withdrawal/transfer.
  * `BusinessAccount`: Supports overdraft loans in addition to standard operations.
* **Class `Admin`**: Provides system-level control (loan approvals, releasing interest, account modifications).
* **Class `Transaction`**: Maintains a transaction log using a `map`.
* **Helper Classes/Functions**:

  * `IndexFinder`: Locates accounts within a vector.
  * Input validation utilities (e.g., check numeric values, string validation).

Data structures used:

* `vector` → Stores accounts.
* `stack` → Manages loan applications queue.
* `map` → Stores transaction histories.

---

## 5. Tools and Technologies

* **Programming Language**: C++ (C++17 or later)
* **Core Concepts**: OOP (Inheritance, Polymorphism, Encapsulation)
* **Data Structures**: vector, map, stack
* **Compiler**: g++ or any C++ compatible compiler

---

## 6. How to Compile and Run

1. Save the file as `FINAL_SUBMIT.cpp`.
2. Open a terminal in the project directory.
3. Compile the project:

   ```bash
   g++ -o banking FINAL_SUBMIT.cpp
   ```
4. Run the program:

   ```bash
   ./banking
   ```
5. Log in as:

   * **Admin** → Can create accounts, release interest, approve/reject loans.
   * **Customer** → Can deposit, withdraw, transfer, apply for loans, and view statements.

---

## 7. Limitations

* No file/database storage: data is lost when the program ends.
* Passwords are stored as plain integers (not secure).
* Console-only interface: requires text-based interaction.
* Loan approvals require manual admin action (no automated system).

---

## 8. Future Enhancements

* Introduce persistent storage (files or database).
* Add encryption for account security.
* Automate loan approval logic (based on credit rules).
* Build a GUI interface for better usability.
* Support multiple administrators with roles and permissions.

---

## 9. Learning Outcomes

Through the development of this project, the following were achieved:

* Applied **OOP principles** effectively in designing a real-world inspired system.
* Learned how to implement **class hierarchies** and abstract classes.
* Gained experience with **C++ Standard Library containers** (`vector`, `stack`, `map`).
* Practiced **user input validation** and exception handling.
* Understood the **importance of manual decision points** in system workflows.
* Developed skills in **modular programming and system design**.

---

## 10. Conclusion

The Banking System project demonstrates how **object-oriented programming** and **data structures** can be applied to simulate real-world financial operations.
Although simplified, the system reflects the **division of roles** between customers and administrators, and highlights the necessity of **manual user interference** for critical banking operations (such as loan approvals and interest release).

This project fulfills its academic purpose by showcasing both **technical proficiency in C++** and **conceptual understanding of banking workflows**.

---
