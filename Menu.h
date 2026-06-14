#include "Checklist.h"
#include <string>

using namespace std;

class Menu {
public:
    Menu();
    void run();

private:
    Checklist checklist;

    void printMenu() const;
    string readLine(const string& prompt) const;
    int getOption(int min, int max) const;

    void listItems() const;
    void addItem();
    void removeItem();
    void toggleChecked();
    void editItem();
    void clear();
    void save();
    void load();
    void clearConsole();
};
