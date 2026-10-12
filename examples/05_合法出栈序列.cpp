#include <iostream>
#include "applications.h"

int main() {
    std::cout << "1,2,3 的合法出栈序列；S=入栈，X=出栈\n";
    for (const StackSequence& sequence : stack_sequences(3)) {
        for (int value : sequence.output) std::cout << value;
        std::cout << "  " << sequence.actions << '\n';
    }
}
