// COMSC-210 | Lab 18 | Loma Kim
#include <iostream>
using namespace std;

struct ReviewNode {
    double rating;
    string comment;

    ReviewNode* next;
};

int main() {
    //DECLARATIONS
    ReviewNode* head = nullptr;
    ReviewNode* current = head;
    int choice;
    double tempR;
    string tempC;

    cout << "Which linked list method should we use?" << endl;
    cout << "\t[1] New nodes are added at the head of the linked list" << endl;
    cout << "\t[2] New nodes are added at the tail of the linked list" << endl;
    cout << "\t    Choice: ";
    cin >> choice;
    cout << "Enter review rating 0-5: ";
    cin >> tempR;
    cout << "Enter review comments: ";
    getline(cin, tempC);
    cin.ignore();

    return 0;
}
