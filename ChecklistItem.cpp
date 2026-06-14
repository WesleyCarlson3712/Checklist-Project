#include "ChecklistItem.h"

using namespace std;

ChecklistItem::ChecklistItem(const string& t, const string& d, bool c)
    : title(t), description(d), checked(c)
{
}

const string& ChecklistItem::getTitle() const { return title; }
const string& ChecklistItem::getDescription() const { return description; }
bool ChecklistItem::isChecked() const { return checked; }

void ChecklistItem::setTitle(const string& t) { title = t; }
void ChecklistItem::setDescription(const string& d) { description = d; }
void ChecklistItem::setChecked(bool c) { checked = c; }
void ChecklistItem::toggleChecked() { checked = !checked; }
