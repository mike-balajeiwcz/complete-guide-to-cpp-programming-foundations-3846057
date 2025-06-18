// Complete Guide to C++ Programming Foundations
// Exercise 07_04
// Constructors and Destructors, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Inventory{
public:
    // Default Constructor
    Inventory(): capacity(10){
        // the ": capacity(10" is equivalient to "capacity = 10;" written in body of code.

        // another way to initalize capacity without using the intalizer list thing
        // capacity = 10;

        // since we have no parameters we can also say:
        // this->capacity = 10;
        // since we are refering to "this" particular instance/object of this class.
        // but we dont need to since data members will always be able to be used 
        // within functions within its class. (even if private or protected)

        items = new std::vector<std::string>();
    }

    // a constructor has no return type and must be the same name as the class (Inventory in this case)
    // the new keyword is similar to malloc() in C. It returns a pointer to allocated memory 
    // in the heap based on the size of memory needed. In this case we are allocating memory for 
    // a vector of strings. (malloc requires you to specify the exact size in bytes)
    // the new keyword must somehow dynamicaly re-size.
    // when the new keyword is used, the memory must be freed with the delete keyword.

    // this keyword is a pointer to "this" particular instance of the class.
    // so you can access the data or function members of "this" instance of the class (this object)

    // Overloaded Constructor
    Inventory(int capacity_i): capacity(capacity_i){
        // we add "_i" for redability as the parameter we are using to intialize hence the "i".

        // again we can use this instead of the intialize list in the constructor declaration line
        // this->capacity = capacity_i;
        items = new std::vector<std::string>();
    }

    // Destructor
    ~Inventory(){
        // tilde charachter "~" indicates a destructor (same syntax as constructor other than that) 
        delete items;

        // as I mentioned before, whenever the "new" keyword is used, "delete" needs to be used
        // its the same as using free() for whatever you malloc()
        // if not familiar with free, esential the "delete" keyword will de-allocate the memoray in the heap that was allocated using "new"
    }

    // Add item to inventory
    void addItem(const std::string& item){
        if (items->size() < capacity)
            items->push_back(item);
        else
            std::cout << "Inventory is full, cannot add " << item << std::endl;
    }

    // Remove item from inventory
    void removeItem(const std::string& item){
        auto it = std::find(items->begin(), items->end(), item);
        if (it != items->end())
            items->erase(it);
        else
            std::cout << "Item " << item << " not found in inventory" << std::endl;
    }

    // Access item by index
    std::string getItem(int index) const{
        if (index >= 0 && index < items->size())
            return (*items)[index];
        else
            return "Index out of bounds";
    }

    // Get number of items in the inventory
    int getItemCount() const{
        return items->size();
    }

    // Display inventory contents
    void displayInventory() const{
        std::cout << "Inventory: [ ";
        for (size_t i = 0; i < items->size(); ++i){
            std::cout << (*items)[i];
            if (i < items->size() - 1) std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
    }

private:
    std::vector<std::string> *items; // Pointer to a vector of items
    int capacity; // Maximum number of items allowed
};

int main(){
    
    std::cout << std::endl << std::endl;
    return 0;
}
