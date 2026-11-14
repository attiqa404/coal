#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

bool isEmpty() {
    return top == NULL;
}

void push(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void popAndPrintBinary(int decimalNum) {
    cout << "Enter number: " << decimalNum << " -> ";
    if (decimalNum == 0) {
        cout << "Binary: 0" << endl;
        return;
    }

    int tempNum = decimalNum;
    while (tempNum > 0) {
        push(tempNum % 2);
        tempNum /= 2;
    }

    cout << "Binary: ";
    while (!isEmpty()) {
        Node* temp = top;
        cout << temp->data;
        top = top->next;
        delete temp;
    }
    cout << endl;
}

int main() {
    popAndPrintBinary(13);
    popAndPrintBinary(0);
    return 0;
}
