
// Индивидуальные задачи на тему "Однонаправленные списки"
// #15

// Условие:
// Даны два однонаправленных списка целых чисел.
// Сформировать третий список, содержащий числа исходных списков, сумма делителей которых не менее 10.

#include <iostream>

struct Node {
    int Data;
    Node *Next;
    Node(int data, Node *next)
    : Data(data),
      Next(next) {}
};

int SumOfDivisorsOf(int n) {
    int s = 0;
    for (int d = 1; d * 2 <= n; ++d)
        s += d * (n % d == 0);
    return s;
}

void ProcessAndInsert(const Node *const dummyHead, Node **insertAfter) {
    for (const Node *c = dummyHead->Next; c != nullptr; c = c->Next) {
        if (SumOfDivisorsOf(c->Data) >= 10) {
            (*insertAfter)->Next = new Node(c->Data, (*insertAfter)->Next);
            *insertAfter = (*insertAfter)->Next;
        }
    }
}

Node* ReadAsLinkedList(int count) {
    Node *const dummyHead = new Node(0, nullptr);
    Node *c = dummyHead;
    for (int i = 0; i < count; ++i) {
        int a;
        std::cin >> a;
        c->Next = new Node(a, nullptr);
        c = c->Next;
    }
    return dummyHead;
}

void DeleteLinkedList(Node *head) {
    if (head == nullptr) return;
    DeleteLinkedList(head->Next);
    delete head;
}

int main() {
    int n, m;

    std::cout << "Enter list size: "; std::cin >> n;
    std::cout << "Enter list (" << n << "): ";
    Node *const inputList1DummyHead = ReadAsLinkedList(n);

    std::cout << "Enter list size: "; std::cin >> m;
    std::cout << "Enter list (" << m << "): ";
    Node *const inputList2DummyHead = ReadAsLinkedList(m);

    Node *const resultListDummyHead = new Node(0, nullptr);
    Node *insertAfter = resultListDummyHead;
    ProcessAndInsert(inputList1DummyHead, &insertAfter);
    ProcessAndInsert(inputList2DummyHead, &insertAfter);

    std::cout << "Result: ";
    for (const Node *c = resultListDummyHead->Next; c != nullptr; c = c->Next)
        std::cout << c->Data << (c->Next != nullptr ? " -> " : "");
    std::cout << '\n';

    DeleteLinkedList(inputList1DummyHead);
    DeleteLinkedList(inputList2DummyHead);
    DeleteLinkedList(resultListDummyHead);

    system("pause");
}