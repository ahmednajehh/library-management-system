# Library Management System 📚

A simple console-based Library Management System built in **C++**, demonstrating core Object-Oriented Programming (OOP) principles.

## Features

- **Add Books** — record ID, title, author, and genre
- **Add Magazines** — record ID, title, and issue number
- **Add DVDs** — record ID, title, director, and duration
- **Show All Items** — view every book, magazine, and DVD in the library
- **Borrow Item** — search by ID and mark an item as borrowed (blocks re-borrowing if already taken)
- **Return Item** — search by ID and mark an item as available again
- **Search by ID** — find any item in the library by its ID, regardless of type

## OOP Concepts Used

| Concept | How it's applied |
|---|---|
| **Encapsulation** | Data members (`id`, `title`, `isAvailable`, etc.) are `protected`/`private`, accessed via getters/setters |
| **Abstraction** | `Item` is an abstract base class with a pure virtual `displayInfo()` function |
| **Inheritance** | `Book`, `Magazine`, and `DvD` all inherit from the base class `Item` |
| **Polymorphism** | Each derived class overrides `displayInfo()` with its own implementation |

## Tech Stack

- **Language:** C++
- **Data Structure:** `std::vector` for dynamic storage of books, magazines, and DVDs
- **Interface:** Console-based menu system

## How to Run

1. Make sure you have a C++ compiler installed (e.g., g++, Code::Blocks, Visual Studio)
2. Compile the file:
   ```bash
   g++ library_system.cpp -o library_system
   ```
3. Run the executable:
   ```bash
   ./library_system
   ```
4. Follow the on-screen menu to add, view, search, borrow, or return items

## Menu Options

```
1. Add Book
2. Add Magazine
3. Add DVD
4. Show All Items
5. Borrow Item
6. Return Item
7. Search by ID
8. Exit
```

## Possible Future Improvements

- Use `getline()` to support multi-word titles and author names
- Save/load data to a file so records persist between runs
- Add input validation (e.g., prevent duplicate IDs or negative values)
- Add a `calculateLateFee()` function for overdue borrowed items
- Use a single `vector<Item*>` to demonstrate polymorphism more directly

## Author

Built as a practice project while learning C++ and Object-Oriented Programming.
