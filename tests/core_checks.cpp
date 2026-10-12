#include <stdexcept>
#include <string>
#include "queue.h"
#include "expression.h"
#include "stack.h"
#include "applications.h"

void check(bool condition, const std::string& message) {
    if (!condition) throw std::runtime_error(message);
}

int main() {
    FixedStack fixed(2);
    check(!fixed.pop().has_value(), "empty fixed stack");
    check(fixed.push(1) && fixed.push(2) && !fixed.push(3), "fixed stack overflow");
    check(*fixed.pop() == 2 && *fixed.pop() == 1, "fixed stack LIFO");

    LinkedStack linked_stack;
    linked_stack.push(5);
    check(*linked_stack.pop() == 5 && linked_stack.empty(), "linked stack single node");

    CircularQueue circular(2);
    check(circular.enqueue(1) && circular.enqueue(2) && !circular.enqueue(3), "circular full");
    check(*circular.dequeue() == 1 && circular.enqueue(3), "circular wrap");
    check(*circular.dequeue() == 2 && *circular.dequeue() == 3 && circular.empty(), "circular FIFO");

    CountingQueue counted(2);
    check(counted.enqueue(1) && counted.enqueue(2) && counted.full(), "all slots used");
    check(*counted.dequeue() == 1 && counted.enqueue(3), "counted wrap");
    check(*counted.dequeue() == 2 && *counted.dequeue() == 3, "counted FIFO");

    LinkedQueue linked_queue;
    linked_queue.enqueue(8);
    check(*linked_queue.dequeue() == 8 && linked_queue.empty(), "linked queue last node");
    linked_queue.enqueue(9);
    check(*linked_queue.dequeue() == 9, "linked queue reuse");

    check(evaluate_infix("4+2*3-10/5") == 8, "infix precedence");
    check(evaluate_postfix(to_postfix("(12-3)*4")) == 36, "postfix parentheses");
    check(evaluate_infix("-8+5*2") == 2, "negative literal");
    bool caught = false;
    try { evaluate_infix("1/0"); }
    catch (const std::domain_error&) { caught = true; }
    check(caught, "division by zero");

    check(stack_sequences(3).size() == 5, "stack sequences");
    check(convert_base(-31, 16) == "-1F", "base conversion");
    check(brackets_match("{[()]}") && !brackets_match("([)]"), "brackets");
    check(edit_line("ab#cd") == "acd", "line editing");
    check(solve_n_queens(4).size() == 2, "four queens");
    KStepResult result = k_step_fibonacci(3, 20);
    check(result.terms.back() == 13 && result.next == 24, "k-step bound");
    check(result.window == std::vector<int>({4, 7, 13}), "k-step queue window");
}
