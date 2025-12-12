#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct CoffeeCustomerNode{

string name;
string drink;
CoffeeCustomerNode* next;
};

void enqueueCoffee(CoffeeCustomerNode*& head, CoffeeCustomerNode*& tail, const string& name, const string& drink){
    coffeeCustomer* newNode = new CoffeeCustomerNode{name, drink, nullptr};

     if(tail == nullptr){
         head = tail = newNode;
     }
    else {
         tail->next = newNode;
         tail = newNode;
    }
}
bool dequque(CoffeeCustomerNode*& head, CoffeeCustomerNode*& tail, string& servedName, string& servedDrink){
     if(head == nullptr){
         return false;
     }
    coffeeCustomerNode* temp = head;
    servedName = head->name;
    servedDrink = head->drink;

    head = head->next;
     if(head == nullptr){
         tail = nullptr;
     }
     delete temp;
    return true; 
}

bool isCoffeeQueueEmpty(CoffeeCustomerNode* head){
     return head == nullptr;
}
void printCoffeeQueue(CoffeeCustomerNode* head){
     cout << "[Coffee Queue]: ";

    if (head == nullptr){
         cout << "Empty" << endl;
    } else{
         CoffeeCustomerNode* current = head;
         while(current != nullptr){
             cout << "(" <<current->name << current->drink << ") ";
             if(current->next != nullptr)
                 cout << "-> ";
             current = current->next;
         }
    }
    cout << endl;
}
