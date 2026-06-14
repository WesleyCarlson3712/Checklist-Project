#include "Checklist.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

// Default constructor - nothing to initialize beyond the vector default
Checklist::Checklist() = default;

// Append an item to the internal vector
void Checklist::addItem(const ChecklistItem& item)
{
    items.push_back(item);
}

// Serialize checklist to JSON and write to a file. Returns false on IO error.
bool Checklist::saveToFile(const string& filename) const
{
    json j;
    j["items"] = json::array();
    for (const auto &it : items) {
        j["items"].push_back({
            {"title", it.getTitle()},
            {"description", it.getDescription()},
            {"checked", it.isChecked()}
        });
    }

    ofstream ofs(filename);
    if (!ofs) return false;
    ofs << j.dump(4); // pretty-print with 4-space indent
    return true;
}

// Load checklist from JSON file. Returns false on parse/IO errors.
bool Checklist::loadFromFile(const string& filename)
{
    ifstream ifs(filename);
    if (!ifs) return false;
    json j;
    try {
        ifs >> j;
        if (!j.contains("items") || !j["items"].is_array()) return false;
        items.clear();
        for (const auto &elem : j["items"]) {
            string title = elem.value("title", string());
            string description = elem.value("description", string());
            bool checked = elem.value("checked", false);
            items.emplace_back(title, description, checked);
        }
    } catch (...) {
        // Any exception during parsing or element access is treated as failure
        return false;
    }
    return true;
}

// Remove item at index. Index must be zero-based and within range.
bool Checklist::removeItem(int index)
{
    if (index < 0 || index >= static_cast<int>(items.size())) return false;
    items.erase(items.begin() + index);
    return true;
}

// Toggle the checked state for an item at the given index. No-op on invalid index.
void Checklist::toggleItem(int index)
{
    if (index < 0 || index >= static_cast<int>(items.size())) return;
    items[index].toggleChecked();
}

// Replace title and description for the item at index. Returns false if index invalid.
bool Checklist::editItem(int index, const string& newTitle, const string& newDescription)
{
    if (index < 0 || index >= static_cast<int>(items.size())) return false;
    items[index].setTitle(newTitle);
    items[index].setDescription(newDescription);
    return true;
}

// Remove all items from the checklist
void Checklist::clear()
{
    items.clear();
}

// Print the checklist in a numbered format with checked state and optional description.
void Checklist::printList() const
{
    if (items.empty()) {
        cout << "(no items)\n";
        return;
    }

    for (int i = 0; i < static_cast<int>(items.size()); ++i) {
        const auto &it = items[i];
        cout << (i+1) << ") [" << (it.isChecked() ? 'x' : ' ') << "] " << it.getTitle();
        if (!it.getDescription().empty()) cout << " - " << it.getDescription();
        cout << "\n";
    }
}
