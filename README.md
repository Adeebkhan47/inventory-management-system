# Inventory Management System

A comprehensive C++ console-based inventory management system developed as an Object-Oriented Programming (OOP) project. This system provides functionality for both managers and buyers to handle product inventory, user registration, shopping cart operations, and file-based data persistence.

## 📋 Table of Contents

- [Features](#features)
- [System Architecture](#system-architecture)
- [Classes Overview](#classes-overview)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [File Structure](#file-structure)
- [Requirements](#requirements)
- [Compilation and Execution](#compilation-and-execution)

## ✨ Features

### Manager Features
- **Product Management**
  - Add new products to inventory
  - Remove products from inventory
  - Update product prices
  - View detailed product information
  - Display all products in stock
  
- **Inventory Control**
  - Monitor product quantities
  - Track product categories
  - Manage product IDs (auto-generated starting from 3000)

### Buyer Features
- **User Account Management**
  - User registration with email validation
  - Secure login system
  - Auto-generated user IDs and passwords
  
- **Shopping Experience**
  - Browse available products
  - Add products to shopping cart
  - Remove items from cart
  - View cart contents and total bill
  - Purchase products (reduces inventory)

### System Features
- **File-Based Data Persistence**
  - Save user credentials
  - Store purchase history
  - Maintain transaction records
  
- **Input Validation**
  - Email format validation
  - Numeric input validation
  - Error handling for invalid inputs

## 🏗️ System Architecture

The system follows Object-Oriented Programming principles with the following design patterns:
- **Encapsulation**: Private data members with public getter/setter methods
- **Inheritance**: Specialized classes inheriting from base classes
- **Data Abstraction**: Clean interfaces for complex operations
- **File Handling**: Persistent data storage using file streams

## 📚 Classes Overview

### Core Classes

1. **`productData`**
   - Stores individual product information (name, price, quantity, category, ID)
   - Auto-generates unique product IDs starting from 3000

2. **`Product`**
   - Manages collection of products using vectors
   - Handles product operations (add, remove, update, display)
   - Checks product availability and stock levels

3. **`cartData`**
   - Represents items in shopping cart
   - Stores item details and quantities

4. **`Cart`**
   - Manages shopping cart operations
   - Calculates total bill
   - Handles item addition/removal

5. **`BuyerData`**
   - Stores buyer information (email, ID, password)
   - Auto-generates unique buyer credentials

6. **`Buyer`**
   - Manages buyer operations and authentication
   - Handles login/registration process
   - Provides customer menu interface

7. **`Manager`**
   - Handles manager authentication
   - Provides administrative interface
   - Default credentials: manager123@gmail.com

8. **`File`**
   - Handles file I/O operations
   - Saves user credentials and transaction data
   - Manages data persistence

## 🚀 Getting Started

### Prerequisites
- C++ compiler (GCC, Clang, or MSVC)
- Windows operating system (uses `unistd.h` for sleep function)
- Basic understanding of console applications

### Installation

1. Clone or download the project files
2. Ensure you have a C++ compiler installed
3. Navigate to the project directory

## 💻 Usage

### Running the Application

1. Compile the program:
   ```bash
   g++ -o inventory "Project(OOP).cpp"
   ```

2. Run the executable:
   ```bash
   ./inventory
   ```

### System Navigation

#### Main Menu Options:
1. **Login as Manager**
   - Default email: `manager123@gmail.com`
   - Default ID: `1001`
   - Default password: `1234`

2. **Login/Register as Buyer**
   - Register new account with email validation
   - Login with existing credentials
   - Auto-generated user ID and password

3. **Exit**
   - Terminate the application

#### Manager Functions:
- Add Product
- Remove Product
- Change Product Price
- Display All Products
- Display Specific Product Details
- View Buyer Information

#### Buyer Functions:
- View Available Products
- Add Items to Cart
- Remove Items from Cart
- View Cart Contents
- Purchase Items
- Logout

## 📁 File Structure

```
OOP Project/
├── Project(OOP).cpp    # Main source code file
├── README.md          # Project documentation
└── output/
    └── Project(OOP).exe   # Compiled executable
```

## 🔧 Requirements

- **Compiler**: C++11 or later
- **Operating System**: Windows (due to `unistd.h` dependency)
- **Memory**: Minimal (console application)
- **Storage**: Small amount for data files

## ⚙️ Compilation and Execution

### Using GCC:
```bash
g++ -std=c++11 -o inventory "Project(OOP).cpp"
./inventory
```

### Using Visual Studio:
1. Create a new Console Application project
2. Replace the generated code with the project code
3. Build and run the solution

### Using Dev-C++ or Code::Blocks:
1. Create a new project
2. Add the source file
3. Compile and run

## 🛠️ Technical Details

- **Language**: C++
- **Paradigm**: Object-Oriented Programming
- **Data Structures**: STL Vectors for dynamic arrays
- **File Handling**: fstream for data persistence
- **Input Validation**: Comprehensive error checking
- **Memory Management**: Automatic via STL containers

## 🔮 Future Enhancements

- Database integration for better data management
- GUI interface using Qt or similar framework
- Advanced search and filtering options
- Detailed reporting and analytics
- Multi-user concurrent access
- Enhanced security features

## 📝 Notes

- The system uses file-based storage for simplicity
- Product IDs are auto-generated starting from 3000
- User passwords are auto-generated for security
- The system includes comprehensive input validation
- Manager credentials are hardcoded for demonstration purposes

## 👨‍💻 Development

This project demonstrates key OOP concepts including:
- Class design and implementation
- Inheritance and polymorphism
- File I/O operations
- Data validation and error handling
- User interface design
- System architecture planning

---

*This project was developed as part of the Object-Oriented Programming course curriculum.*