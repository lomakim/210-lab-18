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
        while (tempR > 5 || tempR < 0) {
            cout << "\tError! Please enter a # 0-5: ";
            cin >> tempR;
        }
        cin.ignore();
        cout << "Enter review comments: ";
        getline(cin, tempC);

        //Add node according to chosen method
        if (choice == 1){                   //add new node to head of list
            newNode = new ReviewNode;       //dynamically allocate new node
            if(!head) {                     //if list is empty
                head = newNode;             //head points to new node  
                newNode->next = nullptr;    //new node points to nullptr
                newNode->rating = tempR;    //assign values to new node
                newNode->comment = tempC;   
            }
            else {                          //if list is not empty
                //assign head pointer location to new node
                newNode->next = head;
                newNode->rating = tempR;    //assign values to newnode
                newNode->comment = tempC;
                head = newNode;             //head points to new node
            }
        }
        if (choice == 2) {                  //add new node to end of list
            newNode = new ReviewNode;       //dynamically allocate new node
            current = head;         //assign head pointer location to current
            if(!head) {                     //if list is empty
                head = newNode;             //head points to new node
                newNode->next = nullptr;    //new node points to nullptr
                newNode->rating = tempR;    //assign values to new node
                newNode->comment = tempC;
            }
            else {                          //if list is not empty
                while(current) {            //traverse list
                    prev = current;         //prev points to current node
                    current = current->next;//current points to next node
                }
                //assign the last node's pointer to newe node
                prev->next = newNode;
                newNode->rating = tempR;    //assign values to new node;
                newNode->comment = tempC;
                newNode->next = nullptr;    //new node points to nullptr;
            }
        }

        //Gather input
        cout << "Enter another review? Y/N: ";
        cin >> inputC;
        cin.ignore();
        //Validate input data
        while (inputC != 'n' && inputC != 'N' 
                && inputC != 'Y' && inputC != 'y') {
            cout << "\tError! Please enter Y/N: ";
            cin >> inputC;
        }
        cout << endl;
    } while(inputC != 'n' && inputC != 'N');

    //Print list information
    double count = 1;                          //counter to track number of nodes
    double totalR= 0.0;
    current = head;                         //reset current pointer to head
    cout << "Outputting all reviews:" << endl;
    while(current) {
        cout << "\t> Review #" << count << ": ";
        cout << current->rating << ": " << current->comment << endl;          
        totalR += current->rating;          //add rating to total
        count++;                            //increment count #
        current = current->next;            //go to next node
    }
    cout << "\t> Average: " << (totalR / --count);

    return 0;
}

