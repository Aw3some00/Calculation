# 💥 **Custom Calculator** 💥

[![Build Status](https://img.shields.io/badge/build-passing-darkgreen)](https://shields.io/)
[![License](https://img.shields.io/badge/license-MIT-blue)](https://opensource.org/licenses/MIT)
![Last Commit](https://img.shields.io/github/last-commit/Aw3some00/Bomb_explosion)
![Version](https://img.shields.io/badge/version-v1.0.1-blue)

![Stars](https://img.shields.io/github/stars/username/repository?style=social)

Welcome to **Custom Calculator**! This simple, powerful calculator lets you perform basic arithmetic operations with error handling, including addition, subtraction, multiplication, and division. It's built to handle edge cases like **overflow** and **invalid input**, so you can focus on the math!

---

## 📝 **Description**

This C++ command-line program takes arithmetic expressions as input, validates them, and performs the calculations while handling potential issues such as:
- **Overflow errors** (when numbers exceed the allowed range)
- **Invalid input** (malformed expressions, unsupported characters)
- **Division by zero**

---
## **Calculation Logic:**
- **Stage 1:** Handle multiplication (`*`) and division (`/`) operations from left to right. Results replace the operations in the list.
   - Division checks if the divisor is zero to avoid errors.
- **Stage 2:** Handle addition (`+`) and subtraction (`-`) operations from left to right.
- The final result is stored and returned.

---

## ⚡ **Features**

✨ **Full Support for Arithmetic Operations:**
- Add, subtract, multiply, and divide in a single expression!

🔒 **Safe Computation:**
- Automatically handles overflow situations where numbers exceed the limits.
- Prevents division by zero.

⚙️ **Easy-to-use Interface:**
- Just input an arithmetic expression, and the calculator does the rest!

💡 **Real-time Input Validation:**
- Corrects and prompts for invalid inputs to ensure proper formatting.

---

## 🌟 **Example Usage**
### **Input Parsing:**
- The program accepts a mathematical expression as a string, e.g., `"5 + 10 * 2"`.
- The string can include numbers, operators (`+`, `-`, `*`, `/`), and spaces.

---

### **Basic Calculation**

```cpp
std::string input = "5 + 10 * 3 - 4 / 2"; 
std::cout << "Input: " << input << std::endl;
double result = input_func(input); 
std::cout << "Result: " << result << std::endl;  // Expected output: 26
```
---

### **Error Handling Examples:**
#### **Division by Zero**{
```cpp
std::string input = "10 / 0"; 
std::cout << "Input: " << input << std::endl;
double result = input_func(input); 
std::cout << "Result: " << result << std::endl;

```
#### **output**
```cpp
Error: Division by zero
```
---

}
#### **Number is too large**{
```cpp 
std::string input = "1e500 * 1"; 
std::cout << "Input: " << input << std::endl;
double result = input_func(input); 
std::cout << "Result: " << result << std::endl;
```
#### **output**
```cpp
Error: Number exceeds limits
```
}

---
#### **Invalid Input (Multiple Operators)**{
```cpp
std::string input = "5 + + 10"; 
std::cout << "Input: " << input << std::endl;
double result = input_func(input); 
std::cout << "Result: " << result << std::endl;
```
#### **output**
```cpp
Error: 2 operators fault
```
}





## 🔨 **Installation**

Follow these simple steps to get the calculator up and running on your machine:

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/yourusername/your-repository.git
2. **Navigate to the Project Directory:**
    ```bash
   cd your-repository

3. **Compile the Program:**
    ```bash
   g++ -o calculator main.cpp calc.cpp
4. **Run the Calculator:**
    ```bash 
    ./calculator
   
---

## 🛠️ Installation on Cmake compiler

To use the Chain Reaction Simulator, you need to have **Cmake** installed on your machine. Follow these steps to run the program:

1. Clone the repository:

   ```bash
   git clone https://github.com/Aw3some00/Bomb_explosion.git
2. Navigate into the project folder:
   ```bash 
   cd Bomb_explosion
3. Create and navigate to the build folder
   ```bash 
   mkdir build && cd build
4. Run CMake to configure and build:   
    ```bash 
   cmake ..
    cmake --build .
5. Run the project: After the build is complete, run the project:
   ```bash 
   ./main

---





## 🤝 Contributing

We welcome contributions! To contribute to the project:

1. Fork the repository 🍴
2. Create a new branch for your feature or fix 🌱
3. Commit your changes 📝
4. Push your branch🚀
5. Open a pull request🔄

Please ensure your code follows the project's coding standards and includes tests for any new functionality. If your pull request fixes an issue or adds a feature, be sure to reference the issue number in the pull request description.

---

## 📝 License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT). 🎉

You are free to use, modify, and distribute this project as long as you retain the original license and copyright notice.

---

## 📞 Contact

For any inquiries, please reach out to
### **kotnarkot962@gmail.com**

---
## ♥️ Support us on Patreon
If you like this project, feel free to support it via donations! 🙌

[![Support me on Patreon](https://img.shields.io/badge/Support_Patreon-FF424D?style=for-the-badge&logo=patreon&logoColor=white)](https://www.patreon.com/c/Aw3some?fromConcierge=true)


