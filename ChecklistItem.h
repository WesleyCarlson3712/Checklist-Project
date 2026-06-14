#include <string>
using namespace std;

// ChecklistItem represents a single entry in the checklist with a
// title, an optional description and a checked/unchecked state.
class ChecklistItem {
public:
    // Default constructor creates an empty, unchecked item
    ChecklistItem();

    // Create an item with title, optional description and optional checked state
    ChecklistItem(const string& title, const string& description = "", bool checked = false);

    // Accessors
    const string& getTitle() const;
    const string& getDescription() const;
    bool isChecked() const;

    // Mutators
    void setTitle(const string& title);
    void setDescription(const string& description);
    void setChecked(bool checked);
    void toggleChecked();

private:
    // The title shown to the user
    string title;
    // Optional longer description for the item
    string description;
    // Whether the item is checked/completed
    bool checked{false};
};
