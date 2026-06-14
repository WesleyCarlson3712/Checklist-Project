#include <string>
using namespace std;

class ChecklistItem {
public:
    ChecklistItem();
    ChecklistItem(const string& title, const string& description = "", bool checked = false);

    const string& getTitle() const;
    const string& getDescription() const;
    bool isChecked() const;

    void setTitle(const string& title);
    void setDescription(const string& description);
    void setChecked(bool checked);
    void toggleChecked();

private:
    string title;
    string description;
    bool checked{false};
};
