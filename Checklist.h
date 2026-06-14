#include <vector>
#include <string>
#include "ChecklistItem.h"
using namespace std;

class Checklist {
public:
    Checklist();

    void addItem(const ChecklistItem& item);
    bool removeItem(int index);
    void toggleItem(int index);
    bool editItem(int index, const string& newTitle, const string& newDescription);
    void clear();

    void printList() const;

    int size() const { return static_cast<int>(items.size()); }
    const vector<ChecklistItem>& getItems() const { return items; }

    bool saveToFile(const string& filename) const;
    bool loadFromFile(const string& filename);

private:
    vector<ChecklistItem> items;
};
