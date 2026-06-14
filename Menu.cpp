#include "Menu.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

Menu::Menu() = default;

void Menu::printMenu() const
{
    cout << "\n--- Checklist Menu ---\n";
    cout << "1) Add item\n";
    cout << "2) Remove item\n";
    cout << "3) Toggle item checked/unchecked\n";
    cout << "4) Edit item\n";
    cout << "5) Clear all items\n";
    cout << "6) Save items to file\n";
    cout << "7) Load items from file\n";
    cout << "0) Exit\n";
    cout << "Choose an option: ";
}

void Menu::clearConsole() {
   #ifdef _WIN32
      system("cls"); // Windows
   #else
      system("clear"); // Linux, macOS, Unix
   #endif
}

string Menu::readLine(const string& prompt) const
{
    cout << prompt;
    string line;
    getline(cin, line);
    return line;
}

int Menu::getOption(int min, int max) const
{
    while (true) {
         string line;
         getline(cin, line);
        
         try {
               int parsedNumber = stoi(line);
               if (parsedNumber >= min && parsedNumber <= max) {
                  return parsedNumber;
               }
         } catch (...) {
         }
         cout << "\x1b[1A\x1b[2K";
         cout << "Invalid input. Enter a number from " << min << " to " << max << ": ";
    }
}

void Menu::listItems() const
{
   cout << "\n--- Items ---\n";
   cout << "---------------------------------------------------------------" << endl;
   checklist.printList();
   cout << "---------------------------------------------------------------" << endl;
}

void Menu::addItem()
{
    string title = readLine("Title: ");
    string description = readLine("Description: ");
    checklist.addItem(ChecklistItem(title, description));
    cout << "Item added." << endl;
    readLine("Press Enter to continue...");
}

void Menu::removeItem()
{
    if (checklist.size() == 0) return;

    cout << "Enter item number to remove or 0 to cancel: ";
    int itemNumber = getOption(0,checklist.size());
    if (itemNumber != 0)
    {
      checklist.removeItem(itemNumber - 1);
      cout << "Item removed." << endl;
      readLine("Press Enter to continue...");
    }
}

void Menu::toggleChecked()
{
    if (checklist.size() == 0) return;

    cout << "Enter item number to toggle or 0 to cancel: ";
    int itemNumber = getOption(0, checklist.size());

    if (itemNumber != 0)
    {
       string checkedOrUnchecked = checklist.getItems()[itemNumber - 1].isChecked() ? "Unchecked." : "Checked.";
       checklist.toggleItem(itemNumber - 1);
       cout << "Item " << checkedOrUnchecked << endl;
       readLine("Press Enter to continue...");
    }
}

void Menu::editItem()
{
    if (checklist.size() == 0) return;

    cout << "Enter item number to edit or 0 to cancel: ";

    int itemNumber = getOption(0, checklist.size());
    if (itemNumber != 0)
    {
       string title = readLine("New title (leave empty to keep): ");
       string description = readLine("New description (leave empty to keep): ");

       const auto& items = checklist.getItems();

       string newTitle = title.empty() ? items[itemNumber - 1].getTitle() : title;
       string newDescription = description.empty() ? items[itemNumber - 1].getDescription() : description;

       checklist.editItem(itemNumber - 1, newTitle, newDescription);
       cout << "Item edited." << endl;
       readLine("Press Enter to continue...");
    }
}

void Menu::clear()
{
    checklist.clear();
    cout << "List cleared." << endl;
    readLine("Press Enter to continue...");
}

void Menu::save()
{
    string filename = readLine("Save filename: ");
    if (filename.empty()) {
        cout << "Save cancelled." << endl;
        return;
    }
    if (checklist.saveToFile(filename)) cout << "Saved to " << filename << endl;
    else cout << "Failed to save file." << endl;
    readLine("Press Enter to continue...");
}

void Menu::load()
{
    string filename = readLine("Load filename: ");
    if (filename.empty()) {
        cout << "Load cancelled." << endl;
        return;
    }
    if (checklist.loadFromFile(filename)) cout << "Loaded from " << filename << endl;
    else cout << "Failed to load file." << endl;
    readLine("Press Enter to continue...");
}

void Menu::run()
{
    bool running = true;
    while (running) {
        clearConsole();
        listItems();
        printMenu();
        int menuChoice = getOption(0,7);
        switch (menuChoice) {
        case 1:
            addItem();
            break;
        case 2:
            removeItem();
            break;
        case 3:
            toggleChecked();
            break;
        case 4:
            editItem();
            break;
        case 5:
            clear();
            break;
        case 6:
            save();
            break;
        case 7:
            load();
            break;
        case 0:
            running = false;
            break;
        default:
            cout << "Unknown option.\n";
            break;
        }
    }
    cout << "Exiting Program\n";
}
