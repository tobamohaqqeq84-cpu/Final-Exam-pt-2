#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct CoffeeCustomerNode{

string name;
string drink;
CoffeeCustomerNode* next;
};

void enqueue(CoffeeCustomerNode*& head, CoffeeCustomerNode*& tail, const string& name, const string& drink){
    coffeeCustomerNode* newNode = new CoffeeCustomerNode{name, drink, nullptr};

     if(tail == nullptr){
         head = tail = newNode;
     }
    else {
         tail->next = newNode;
         tail = newNode;
    }
}
bool dequque(CoffeeCustomerNode*& head, CoffeeCustomerNode*& tail, string& name, string& drink)