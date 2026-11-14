#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* top = NULL;

bool isEmpty() {
    return top == NULL;
}

void visitPage(string page) {
    Node* newNode = new Node;
    newNode->data = page;
    newNode->next = top;
    top = newNode;
    cout << "Visited: " << page << endl;
}

void goBack() {
    if (isEmpty()) {
        cout << "History is empty." << endl;
        return;
    }
    if (top->next == NULL) {
        cout << "Cannot go back" << endl;
    } else {
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "Back -> Current page: " << top->data << endl;
    }
}

void peekCurrent() {
    if (isEmpty())
        cout << "No current page." << endl;
    else
        cout << "Current page: " << top->data << endl;
}

void displayHistory() {
    if (isEmpty()) {
        cout << "No browsing history." << endl;
        return;
    }
    cout << "--- Browsing History (Top to Bottom) ---" << endl;
    Node* current = top;
    while (current != NULL) {
        cout << "[" << current->data << "]" << endl;
        current = current->next;
    }
}

int main() {
    int choice;
    string page;
    do {
        cout << "\n1.Visit Page 2.Back 3.Current Page 4.History 0.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter page name: ";
                cin >> page;
                visitPage(page);
                break;
            case 2:
                goBack();
                break;
            case 3:
                peekCurrent();
                break;
            case 4:
                displayHistory();
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 0);

    return 0;
}
