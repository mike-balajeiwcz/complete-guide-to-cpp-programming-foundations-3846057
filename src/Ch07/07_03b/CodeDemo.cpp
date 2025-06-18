// Complete Guide to C++ Programming Foundations
// Exercise 07_03
// Function Members, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Inventory{
public:
    // Add an item to the inventory
    void addItem(const std::string &item){
        if(items->size() == capacity) {
            std::cout << "Cannot add " << item << " since invectory is full!" << std::endl;
        } else {
            items->push_back(item);
        }
    }

    // Remove item from inventory
    void removeItem(const std::string &item) {
        std::vector<std::string>::iterator it = std::find(items->begin(), items->end(), item);
        //or use auto!
        // auto it = std::find(items->begin(), items->end(), item);
        if(it != items->end()) {
            items->erase(it);
        } else {
            std::cout << "Cannot find " << item << "." << std::endl;
        }
    }

    // getItem() takes a int, depending: returns std::string or produces output.
    // const qualifier prevents objects inside this function from modification.
    std::string getItem(const int &index) const {
        if (index < 0 || index > items->size() - 1) {
            std::cout << "Index is not in range of inventory!" << std::endl;
        } else {
            return (*items)[index];
        }
    }

    // getItemCount() returns number of elements in items vector as int.
    int getItemCount(void) const {
        return items->size();
    }

    // displayInventory() returns void, depending: produced output.
    void displayInventory() const {
        std::cout << "Inventory: [ ";
        int size = items->size();
        for (int i = 0; i < size; ++i) {
            std::cout << (*items)[i];
            if(i != size - 1) {
               std::cout << ", "; 
            }
        }
        std::cout << " ]" << std::endl;
    }

private: 
    // Pointer to a vector of items (array of items)
    //without using namespace std;
    std::vector<std::string> *items; 
    int capacity; // Maximum number of items allowed
};

int main(){
    
    std::cout << std::endl << std::endl;
    return 0;
}
