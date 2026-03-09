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
    ReviewNode* head = nullptr; //Points to head
    ReviewNode* current;        //Points to current node when traversing list
    ReviewNode* newNode;        //Points to new nodes
    ReviewNode* prev;           //Points to last node when traversing list
    int choice;                 //Holds user choice for list method
    double tempR;               //Holds user input for rating
    string tempC;               //Holds user input for comment
    char inputC;                //Collects input for Y/N choice

    //Gather input for linked list method
    cout << "Which linked list method should we use?" << endl;
    cout << "\t[1] New nodes are added at the head of the linked list" << endl;
    cout << "\t[2] New nodes are added at the tail of the linked list" << endl;
    cout << "\t    Choice: ";
    cin >> choice;

    while (choice != 1 && choice != 2){     //Validate user input
        cout << "\tError! Enter 1 or 2: ";
        cin >> choice;
    }

    do {
        //Enter input for review
        cout << "Enter review rating 0-5: ";
        cin >> tempR;
        cout << "Enter review comments: ";
        getline(cin, tempC);
        cin.ignore();

        //Add node according to chosen method
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
            if(!head) {
                head = newNode;
                newNode->next = nullptr;
                newNode->rating = tempR;
                newNode->comment = tempC;
            }
            else {
                while(current) {
                    prev = current;
                    current = current->next;
                }
                prev->next = newNode;
                newNode->rating = tempR;
                newNode->comment = tempC;
                newNode->next = nullptr;
            }
        }

        cout << "Enter another review? Y/N: ";
        cin >> inputC;
        while (inputC != 'n' && inputC != 'N' && inputC != 'Y' && inputC != 'y') {
            cout << "\tError! Please enter Y/N: ";
            cin >> inputC;
        }
    } while (inputC != 'n' && inputC != 'N');

    return 0;
}
