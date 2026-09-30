# 🧱 CppModules

![42 Project](https://img.shields.io/badge/42%20Network-C++%20Modules-blue?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++98-blue?style=for-the-badge)
![Concepts](https://img.shields.io/badge/Concepts-OOP%20%26%20STL-yellowgreen?style=for-the-badge)

## 📚 Project Summary

**C++ Modules (00–09)** is a series of 10 modules in the 42 curriculum that introduces **C++** and **object-oriented programming** step by step, strictly in the **C++98** standard.

Each module focuses on a new concept, starting from classes and member functions and moving up to inheritance, polymorphism, templates and the Standard Template Library (STL). Every exercise is compiled with `-Wall -Wextra -Werror -std=c++98`.

---

## 🧠 What I Learned in the C++ Modules

### 🔹 Module 00–01: Basics, Classes, Memory
* Namespaces, `iostream`, streams and basic input/output
* Classes, member functions, `static` members and `const` correctness
* **Stack vs heap** allocation with `new` / `delete`, and arrays of objects
* **References vs pointers**, and file streams with `std::ifstream` / `std::ofstream`
* Using a `switch` and pointers to member functions to select behavior

### 🔹 Module 02: Ad-hoc Polymorphism and Canonical Form
* The **Orthodox Canonical Form** (default constructor, copy constructor, copy assignment operator, destructor)
* **Operator overloading** (`+ - * /`, comparison, `++` / `--`, `<<`)
* Fixed-point number representation

### 🔹 Module 03–04: Inheritance and Polymorphism
* Single and **multiple inheritance**, and the diamond problem (`virtual` inheritance)
* **Virtual functions**, virtual destructors and abstract classes
* **Interfaces** as pure abstract classes
* **Deep copy vs shallow copy** when a class owns dynamic memory (e.g. `Brain`)

### 🔹 Module 05: Exceptions
* `try` / `catch`, custom exception classes derived from `std::exception`
* Designing class hierarchies around rules (e.g. `Bureaucrat` and `AForm`)
* Using the **Factory pattern** with the `Intern` class

### 🔹 Module 06: C++ Casts
* `static_cast`, `reinterpret_cast`, `dynamic_cast` and when to use each
* Type conversion and detection from string input
* Pointer serialization

### 🔹 Module 07–09: Templates and the STL
* **Function and class templates**, including template specialization of behavior
* Iterators and **STL containers** (`vector`, `deque`, `list`, `map`, `stack`, ...)
* **STL algorithms** (`std::find`, `std::sort`, ...)
* Choosing the right container for the problem and comparing their performance

---

## 📁 Project Structure

```bash
CppModules/
├── cpp00/   # ex00 Megaphone · ex01 PhoneBook · ex02 Account
├── cpp01/   # ex00 Zombie · ex01 Zombie Horde · ex02 Pointers/Refs · ex03 HumanA/HumanB
│            # ex04 Sed is for losers · ex05 Harl · ex06 Harl filter
├── cpp02/   # ex00–ex03 Fixed-point number · Point · BSP (point in triangle)
├── cpp03/   # ex00 ClapTrap · ex01 ScavTrap · ex02 FragTrap · ex03 DiamondTrap
├── cpp04/   # ex00 Animal · ex01 Brain · ex02 Abstract class · ex03 Materia (interfaces)
├── cpp05/   # ex00 Bureaucrat · ex01 Form · ex02 AForm · ex03 Intern
├── cpp06/   # ex00 ScalarConverter · ex01 Serializer · ex02 Identify real type
├── cpp07/   # ex00 whatever · ex01 iter · ex02 Array
├── cpp08/   # ex00 easyfind · ex01 Span · ex02 MutantStack
└── cpp09/   # ex00 BitcoinExchange · ex01 RPN · ex02 PmergeMe
```

Each exercise has its own `Makefile`.

---

## ⚙️ Highlights

* **cpp02 – Fixed:** a fixed-point number class with full operator overloading and a `bsp` function that checks whether a point lies inside a triangle
* **cpp04 – Animal / Materia:** polymorphism with deep copies and interface-based design
* **cpp05 – Bureaucrat & Forms:** exception-driven workflow with `ShrubberyCreationForm`, `RobotomyRequestForm` and `PresidentialPardonForm`
* **cpp09 – BitcoinExchange:** reads a CSV price database and calculates the value of a given amount of Bitcoin on a given date using `std::map`
* **cpp09 – RPN:** a Reverse Polish Notation calculator using `std::stack`
* **cpp09 – PmergeMe:** the **Ford–Johnson merge-insertion sort**, implemented with both `std::vector` and `std::deque` and compared by processing time

---

## 🚀 How to Run

```bash
git clone https://github.com/exhilarin/CppModules.git
cd CppModules/cpp09/ex02

make
./PmergeMe 3 5 9 7 4
```

---

## 🚀 Key Takeaways

The C++ Modules taught me how to think in objects: designing clean class hierarchies, owning memory responsibly and choosing the right STL container for the job.  
They are also a solid foundation for game development, where these same ideas appear in every engine.

---

> _“In C, you manage memory. In C++, you design who is responsible for it.”_
