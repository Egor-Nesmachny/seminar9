// 10.1.3. Кольцевая очередь в массиве из шести ячеек.
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const int capacity = 6;

void enqueue(int queue[], bool written[], int& tail, int value) {
    queue[tail] = value;
    written[tail] = true;
    tail = (tail + 1) % capacity;
}

int dequeue(const int queue[], int& head) {
    int value = queue[head];
    head = (head + 1) % capacity;
    return value;
}

void print_queue(const int queue[], const bool written[], int head, int tail,
                 const string& operation) {
    cout << left << setw(15) << operation;
    int size = (tail - head + capacity) % capacity;
    for (int i = 0; i < capacity; ++i) {
        string cell = "-";
        int offset = (i - head + capacity) % capacity;
        if (offset < size) {
            cell = to_string(queue[i]);
        } else if (written[i]) {
            cell = "(" + to_string(queue[i]) + ")";
        }
        cout << setw(5) << cell;
    }
    // В таблице нумерация ячеек начинается с 1, как в учебнике.
    cout << "head = " << head + 1 << ", tail = " << tail + 1 << '\n';
}

int main() {
    int queue[capacity] = {};
    bool written[capacity] = {};
    int head = 0;
    int tail = 0;

    cout << "Операция       1    2    3    4    5    6\n";
    cout << "-  свободная ячейка, (x)  значение после удаления\n";
    print_queue(queue, written, head, tail, "Start");

    enqueue(queue, written, tail, 4);
    print_queue(queue, written, head, tail, "ENQUEUE(4)");
    enqueue(queue, written, tail, 1);
    print_queue(queue, written, head, tail, "ENQUEUE(1)");
    enqueue(queue, written, tail, 3);
    print_queue(queue, written, head, tail, "ENQUEUE(3)");

    int value = dequeue(queue, head);
    print_queue(queue, written, head, tail, "DEQUEUE -> " + to_string(value));

    enqueue(queue, written, tail, 8);
    print_queue(queue, written, head, tail, "ENQUEUE(8)");

    value = dequeue(queue, head);
    print_queue(queue, written, head, tail, "DEQUEUE -> " + to_string(value));
}
