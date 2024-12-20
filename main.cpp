#include <iostream>
#include <vector>
#include <string>
#include "calc.h"

int main() {
    std::string input;
    double result;

    std::cout << "вводите выражение(в случае ошибки ввод будет будет возможен)\n";

    while (std::getline(std::cin, input)) {

        if(input == "exit") {
            break;
        }
        try {
            result = input_func(input);
            std::cout << "результат: " << result << "\n";

        } catch(const std::exception&error){
            std::cerr << "результат: "<<error.what()<<"\n";
        }


        }

    return 0;
}
