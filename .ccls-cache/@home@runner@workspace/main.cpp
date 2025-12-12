#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct CoffeeCustomerNode{

string name;
string drink;
CoffeeCustomerNode* next;
};

void enqueueCoffee(CoffeeCustomerNode*& head, CoffeeCustomerNode*& tail, const string& name, const string& drink){
    CoffeeCustomerNode* newNode = new CoffeeCustomerNode{name, drink, nullptr};

     if(tail == nullptr){
         head = tail = newNode;
     }
    else {
         tail->next = newNode;
         tail = newNode;
    }
}
bool dequeueCoffee(CoffeeCustomerNode*& head, CoffeeCustomerNode*& tail, string& servedName, string& servedDrink){
    
     if(head == nullptr){
         return false;
     }
    
    CoffeeCustomerNode* temp = head;
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

const int NUM_NAMES = 5;
const int NUM_DRINKS = 5;

string coffeeNames [NUM_NAMES] = {"Alice", "Bob", "Charlie", "David", "Eve"
};

string coffeeDrinks [NUM_DRINKS] = {
    "Latte", "Cappuccino", "Espresso", "Americano","Mocha" 
     };

void addRandomCoffeeCustomer(CoffeeCustomerNode*& head, CoffeeCustomerNode*& tail){
    int nameIndex = rand() % NUM_NAMES;
    int drinkIndex = rand() % NUM_DRINKS;

    enqueueCoffee(head, tail, coffeeNames[nameIndex], coffeeDrinks[drinkIndex]);
}

int main(){
    srand(static_cast<unsigned int>(time(nullptr)));

    CoffeeCustomerNode* coffeeHead = nullptr;
     CoffeeCustomerNode* coffeeTail = nullptr;

    for (int i = 0; i < 3; ++i){
        addRandomCoffeeCustomer(coffeeHead, coffeeTail);
    }
    cout << "Initial coffee queue:\n ";
    
    printCoffeeQueue(coffeeHead);
    cout << "----------------------\n";
    for(int round = 1; round <= 10; ++round){
        cout << "=== Round " << round << " ===\n";

        int joined = rand() % 2;
        if (joined == 1){
            addRandomCoffeeCustomer(coffeeHead, coffeeTail);
                cout << "A new coffee customer joined the queue.\n";  
        } else {
             cout << "No new coffee customer joined the queue.\n";
        }

        string name, drink;
        if (dequeueCoffee(coffeeHead, coffeeTail, name, drink)){
             cout << "Served customer: " << name << " (" << drink << ")\n"; }
        else{
             cout << "No customers to serve(queue is empty).\n";
        }
        printCoffeeQueue(coffeeHead);
        cout << "----------------------\n";
    }
    string name, drink;
    while (!isCoffeeQueueEmpty(coffeeHead)){
        dequeueCoffee(coffeeHead, coffeeTail, name, drink);
    }
    
    return 0;
}// milestone 1