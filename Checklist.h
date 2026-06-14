#include <vector>
#include <string>
#include "ChecklistItem.h"
using namespace std;

// Checklist manages a collection of ChecklistItem objects and
// provides basic operations like add/remove/edit/toggle and
// persistence to/from a JSON file.
class Checklist {
public:
    // Default constructor
    Checklist();

    // Add a new item to the end of the checklist
    void addItem(const ChecklistItem& item);

    // Remove the item at the given zero-based index. Returns true on success.
    bool removeItem(int index);

    // Toggle the checked state of the item at the given zero-based index.
    void toggleItem(int index);

    // Edit the item at index, replacing title and description. Returns true on success.
    bool editItem(int index, const string& newTitle, const string& newDescription);

    // Remove all items from the checklist
    void clear();

    // Print the checklist to stdout in a human-readable format
    void printList() const;

    // Convenience accessors
    int size() const { return static_cast<int>(items.size()); }
    const vector<ChecklistItem>& getItems() const { return items; }

    // Persistence helpers - return true on success
    bool saveToFile(const string& filename) const;
    bool loadFromFile(const string& filename);

private:
    // Backing container for checklist items. Indexing is zero-based.
    vector<ChecklistItem> items;
};
