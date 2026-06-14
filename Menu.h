#include "Checklist.h"
#include <string>

using namespace std;

// Menu provides a simple console-based user interface for interacting
// with a Checklist instance. It handles input/output and user commands.
class Menu {
public:
    // Construct a Menu with an internal Checklist instance
    Menu();

    // Start the menu loop and handle user input until exit
    void run();

private:
    Checklist checklist; // The checklist managed by this menu

    // UI helpers
    void printMenu() const; // Print the available actions
    string readLine(const string& prompt) const; // Prompt and read a line
    int getOption(int min, int max) const; // Read a numeric menu option in range

    // Command implementations
    void listItems() const;
    void addItem();
    void removeItem();
    void toggleChecked();
    void editItem();
    void clear();
    void save();
    void load();

    // Clear the console screen in a cross-platform way
    void clearConsole();
};
