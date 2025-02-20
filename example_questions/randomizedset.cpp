#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class RandomizedSet {
private:
    vector<int> values;  // Stores the elements
    unordered_map<int, int> valToIndex; // Maps values to their indices

public:
    RandomizedSet() {
        // Constructor
    }
    
    bool insert(int val) {
        if (valToIndex.find(val) != valToIndex.end()) return false; // If already exists, return false
        
        values.push_back(val);  // Add to the end of vector
        valToIndex[val] = values.size() - 1;  // Store index in map
        return true;
    }
    
    bool remove(int val) {
        if (valToIndex.find(val) == valToIndex.end()) return false; // If not present, return false

        int lastElement = values.back();  // Last element in the vector
        int idx = valToIndex[val];  // Index of element to be removed

        // Swap with the last element
        values[idx] = lastElement;
        valToIndex[lastElement] = idx; // Update index of last element

        // Remove last element from vector and map
        values.pop_back();
        valToIndex.erase(val); 

        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % values.size(); // Generate random index
        return values[randomIndex]; // Return random element
    }
};
