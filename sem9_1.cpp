// 10.1.1. Стек в массиве из шести ячеек.
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const int capacity = 6;

// top — количество элементов, written — сколько ячеек хотя бы раз заполняли.
void push(int stack[], int& top, int& written, int value) {
    stack[top] = value;
    ++top;
    if (top > written) {
        written = top;
    }
}

int pop(const int stack[], int& top) {
    --top;
    return stack[top];
}

void print_stack(const int stack[], int top, int written, const string& operation) {
    cout << left << setw(15) << operation;
    for (int i = 0; i < capacity; ++i) {
        string cell = "-";
        if (i < top) {
            cell = to_string(stack[i]);
        } else if (i < written) {
            cell = "(" + to_string(stack[i]) + ")";
        }
        cout << setw(5) << cell;
    }
    cout << "top = " << top << '\n';
}

int main() {
    int stack[capacity] = {};
    int top = 0;
    int written = 0;

    cout << "Операция       1    2    3    4    5    6\n";
    cout << "-  свободная ячейка, (x)  значение после удаления\n";
    print_stack(stack, top, written, "Start");

    push(stack, top, written, 4);
    print_stack(stack, top, written, "PUSH(4)");
    push(stack, top, written, 1);
    print_stack(stack, top, written, "PUSH(1)");
    push(stack, top, written, 3);
    print_stack(stack, top, written, "PUSH(3)");

    int value = pop(stack, top);
    print_stack(stack, top, written, "POP -> " + to_string(value));

    push(stack, top, written, 8);
    print_stack(stack, top, written, "PUSH(8)");

    value = pop(stack, top);
    print_stack(stack, top, written, "POP -> " + to_string(value));
}
