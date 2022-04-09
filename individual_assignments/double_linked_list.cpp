
// Индивидуальные задачи на тему "Двунаправленные списки"
// #15

// Условие:
// Даны два двунаправленных списка целых чисел.
// Сформировать однонаправленный список,
// содержащий сначала простые элементы исходных списков, а затем все остальные.

#include <iostream>

struct DLLNode {
    int Data;
    DLLNode* Prev;
    DLLNode* Next;
    DLLNode() = default;
    DLLNode(int data) : Data(data), Prev(nullptr), Next(nullptr) {};
    DLLNode(int data, DLLNode* prev, DLLNode* next) : Data(data), Prev(prev), Next(next) {};
};

struct SLLNode {
    int Data;
    SLLNode* Next;
    SLLNode() = default;
    SLLNode(int data) : Data(data), Next(nullptr) {};
    SLLNode(int data, SLLNode* next) : Data(data), Next(next) {};
};

bool isPrime(int n) {
    bool isPrimeSoFar = n > 1;
    for (int d = 2; d * d <= n && isPrimeSoFar; ++d) {
        isPrimeSoFar &= n % d != 0;
    }
    return isPrimeSoFar;
}

namespace LLUtils {

    SLLNode *InsertAfter(SLLNode *insertAfter, SLLNode *node) {
        node->Next = insertAfter->Next;
        insertAfter->Next = node;
        return node;
    }

    void Delete(SLLNode *head) {
        if (head == nullptr) return;
        Delete(head->Next);
        delete head;
    }

    void Delete(DLLNode *head) {
        if (head == nullptr) return;
        Delete(head->Next);
        delete head;
    }

    DLLNode *ReadAsDLLFrom(std::istream& istream, int count) {
        DLLNode *const dummyHead = new DLLNode();
        DLLNode *c = dummyHead;
        for (int i = 0; i < count; ++i) {
            int a;
            istream >> a;
            c->Next = new DLLNode(a, c, nullptr);
            c = c->Next;
        }
        dummyHead->Next->Prev = nullptr;
        return dummyHead->Next;
    }

    void CopyDLLToSLL(DLLNode *srcHead, SLLNode **insertAfter) {
        for (DLLNode *c = srcHead; c != nullptr; c = c->Next) {
            (*insertAfter)->Next = new SLLNode(c->Data, nullptr);
            (*insertAfter) = (*insertAfter)->Next;
        }
    }
}

namespace Reorder {
    void PrimesFirst(SLLNode *dummyHead) {
        SLLNode *primesPartDummyHead = new SLLNode();
        SLLNode *primesInsertAfter = primesPartDummyHead;

        SLLNode *restPartDummyHead = new SLLNode();
        SLLNode *restInsertAfter = restPartDummyHead;

        SLLNode* c = dummyHead->Next;
        while (c != nullptr) {
            SLLNode *toBeMoved = c;
            c = c->Next;

            if (isPrime(toBeMoved->Data))
                primesInsertAfter = LLUtils::InsertAfter(primesInsertAfter, toBeMoved);
            else
                restInsertAfter = LLUtils::InsertAfter(restInsertAfter, toBeMoved);
        }

        // Link the parts.
        dummyHead->Next = primesPartDummyHead->Next;
        primesInsertAfter->Next = restPartDummyHead->Next;
    }
}

int main() {
    int n, m;

    std::cout << "Enter list size: ";
    std::cin >> n;
    std::cout << '\n';

    std::cout << "Enter list (" << n << "): ";
    DLLNode *const inputList1Head = LLUtils::ReadAsDLLFrom(std::cin, n);
    std::cout << '\n';

    std::cout << "Enter list size: ";
    std::cin >> m;
    std::cout << '\n';

    std::cout << "Enter list (" << m << "): ";
    DLLNode *const inputList2Head = LLUtils::ReadAsDLLFrom(std::cin, m);
    std::cout << '\n';

    SLLNode *const resultListDummyHead = new SLLNode();
    SLLNode *insertAfter = resultListDummyHead;
    LLUtils::CopyDLLToSLL(inputList1Head, &insertAfter);
    LLUtils::CopyDLLToSLL(inputList2Head, &insertAfter);

    Reorder::PrimesFirst(resultListDummyHead);

    std::cout << "Result: ";
    for (const SLLNode* c = resultListDummyHead->Next; c != nullptr; c = c->Next)
        std::cout << c->Data << (c->Next != nullptr ? " -> " : "");
    std::cout << '\n';

    LLUtils::Delete(inputList1Head);
    LLUtils::Delete(inputList2Head);
    LLUtils::Delete(resultListDummyHead);

    system("pause");
}