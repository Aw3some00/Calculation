#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cfloat>
#include <cmath>

bool isOverflow(double value) {
    return !std::isfinite(value);
}

bool isNumberTooLarge(const std::string& number) {
    try {
        double value = std::stod(number);
        return isOverflow(value) || value > DBL_MAX || value < -DBL_MAX;
    } catch (const std::invalid_argument& e) {
        return true;
    } catch (const std::out_of_range& e) {
        return true;
    }
}

double calculate(const std::vector<std::string>& numbers) {
    if (numbers.empty()) {
        throw std::runtime_error("некорректный ввод");
    }

    std::vector<std::string> intermediate;
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (numbers[i] == "*" || numbers[i] == "/") {
            if (intermediate.empty()) {
                throw std::runtime_error("некорректный ввод");
            }

            double a = std::stod(intermediate.back());
            intermediate.pop_back();
            double b = std::stod(numbers[i + 1]);

            if (isOverflow(a) || isOverflow(b)) {
                throw std::invalid_argument("число выходит за пределы");
            }

            if (numbers[i] == "*") {
                a *= b;
            } else {
                if (b == 0) {
                    throw std::runtime_error("деление на ноль");
                }
                a /= b;
            }

            if (isOverflow(a)) {
                throw std::invalid_argument("число выходит за пределы");
            }

            intermediate.push_back(std::to_string(a));
            ++i;
        } else {
            intermediate.push_back(numbers[i]);
        }
    }

    double result = std::stod(intermediate[0]);
    for (size_t i = 1; i < intermediate.size(); i += 2) {
        std::string op = intermediate[i];
        double value = std::stod(intermediate[i + 1]);

        if (isOverflow(result) || isOverflow(value)) {
            throw std::invalid_argument("число выходит за пределы");
        }

        if (op == "+") {
            result += value;
        } else if (op == "-") {
            result -= value;
        } else {
            throw std::runtime_error("некорректный ввод");
        }

        if (isOverflow(result)) {
            throw std::invalid_argument("число выходит за пределы");
        }
    }

    return result;
}

double input_func(const std::string& input) {
    if (input.empty()) {
        throw std::runtime_error("некорректный ввод");
    }

    std::vector<std::string> numbers;
    std::string number;
    bool last_was_operator = false;

    for (char ch : input) {
        if (isdigit(ch) || ch == '.') {
            number += ch;
            last_was_operator = false;
        } else if (ch == '-' && (number.empty() && (numbers.empty() || last_was_operator))) {
            number += ch;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (!number.empty()) {
                if (isNumberTooLarge(number)) {
                    throw std::invalid_argument("число слишком большое");
                }
                numbers.push_back(number);
                number.clear();
            }
            if (last_was_operator) {
                throw std::runtime_error("некорректный ввод");
            }
            numbers.push_back(std::string(1, ch));
            last_was_operator = true;
        } else if (ch == ' ') {
            continue;
        } else {
            throw std::runtime_error("некорректный ввод");
        }
    }

    if (!number.empty()) {
        if (isNumberTooLarge(number)) {
            throw std::invalid_argument("число слишком большое");
        }
        if(number.size()>=10) {
            throw std::invalid_argument("число слишком большое или слишком маленькое");
        }

        numbers.push_back(number);
    }

    if (numbers.empty() || last_was_operator) {
        throw std::runtime_error("некорректный ввод");
    }

    return calculate(numbers);
}