#pragma once
// not all compilers support pragma (but vscode does)
// include guard works with all compilers
#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Inventory{
public:
    // Default Constructor
    Inventory();

    // Overloaded Constructor
    Inventory(int capacity_i);

    // Destructor
    ~Inventory();

    // Add item to inventory
    Inventory &operator+=(const std::string& item);

    // Remove item from inventory
    Inventory &operator-=(const std::string& item);

    // Access item by index
    std::string operator[](int index) const;

    // Get number of items in the inventory
    int getItemCount() const;

    // Display inventory contents
    void displayInventory() const;

private:
    std::vector<std::string> *items; // Pointer to a vector of items
    int capacity; // Maximum number of items allowed
};


#endif // INVENTORY_H