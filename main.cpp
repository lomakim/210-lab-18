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
    ReviewNode* current, prev, newNode;
    int choice;
    double tempR;
    string tempC;
    char inputC;


    cout << "Which linked list method should we use?" << endl;
    cout << "\t[1] New nodes are added at the head of the linked list" << endl;
    cout << "\t[2] New nodes are added at the tail of the linked list" << endl;
    cout << "\t    Choice: ";
    cin >> choice;
    while (choice != 1 && choice != 2){
        cout << "\tError! Enter 1 or 2: ";
        cin >> choice;
    }
    do {
        cout << "Enter review rating 0-5: ";
        cin >> tempR;
        cout << "Enter review comments: ";
        getline(cin, tempC);
        cin.ignore();
        cin >> inputC;
        if (choice == 1){
            newNode = new ReviewNode;
            if(!head) {
                head = newNode;
                newNode->next = nullptr;
                newNode->rating = tempR;
                newNode->comment = tempC;
            }
            else {
                newNode->next = head;
                newNode->rating = tempR;
                newNode->comment = tempC;
                head = newNode;
            }
        }
        if (choice == 2) {
            newNode = new ReviewNode;
            current = head;
            while(current) {

            }
        }
        while (inputC != 'n' && inputC != 'N' && inputC != 'Y' && inputC != 'y') {
            cout << "\tError! Please enter Y/N: ";
            cin >> inputC;
        }
        cout << "Enter another review? Y/N: ";
    } while (inputC != 'n' && inputC != 'N');



    return 0;
}
