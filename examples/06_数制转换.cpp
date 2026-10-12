#include <iostream>
#include "applications.h"

int main() {
    for (int value : {1348, 0, -31}) {
        std::cout << value << " 的二进制=" << convert_base(value, 2)
                  << "，八进制=" << convert_base(value, 8)
                  << "，十六进制=" << convert_base(value, 16) << '\n';
    }
}
