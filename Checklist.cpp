#include "Checklist.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

Checklist::Checklist() = default;

void Checklist::addItem(const ChecklistItem& item)
{
    items.push_back(item);
}

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
    ofs << j.dump(4);
    return true;
}

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
        return false;
    }
    return true;
}

bool Checklist::removeItem(int index)
{
    if (index < 0 || index >= static_cast<int>(items.size())) return false;
    items.erase(items.begin() + index);
    return true;
}

void Checklist::toggleItem(int index)
{
    if (index < 0 || index >= static_cast<int>(items.size())) return;
    items[index].toggleChecked();
}

bool Checklist::editItem(int index, const string& newTitle, const string& newDescription)
{
    if (index < 0 || index >= static_cast<int>(items.size())) return false;
    items[index].setTitle(newTitle);
    items[index].setDescription(newDescription);
    return true;
}

void Checklist::clear()
{
    items.clear();
}

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
