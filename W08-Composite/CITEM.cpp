#include "CITEM.h"

CItem::CItem(const string& name)
    : name(name), isReadOnly(false), isHidden(false) {}

string CItem::getName() const {
    return name;
}

CFile::CFile(const string& name, const int& size)
    : CItem(name), size(size) {}

void CFile::setHidden(bool isHidden, bool isAlsoApplyToChildren)
{
    this->isHidden = isHidden;
}

int CFile::getSize() const {
    return size;
}

void CFile::print(bool isPrintHiddenItems) const {
    if (isHidden && !isPrintHiddenItems)
        cout << "\t - Hiden file\n";
    else
        cout << "\t- File: " << name << " (" << size << " KB)" << endl;
}

CItem *CFile::removeByName(const string &name) {
    return NULL;
}

CItem *CFile::findByName(const string &name) {
    return (this->name == name ? this : NULL);
}

CFolder::CFolder(const string& name)
    : CItem(name) {}

CFolder::~CFolder() {
    for (CItem* item : items)
        delete item;
    items.clear();
}

void CFolder::setHidden(bool isHidden, bool isAlsoApplyToChildren)
{
    this->isHidden = isHidden;

    if (isAlsoApplyToChildren)
        for (CItem* item : items)
            item->setHidden(isHidden, isAlsoApplyToChildren);
}

int CFolder::getSize() const {
    int totalSize = 0;
    for (CItem* item : items)
        totalSize += item->getSize();
    return totalSize;
}

void CFolder::print(bool isPrintHiddenItems) const {
    if (isHidden && !isPrintHiddenItems)
        cout << "+ Hidden Folder\n";
    else
        cout << "+ Folder: " << name << " (" << getSize() << " KB)" << endl;
    
    for (CItem* item : items) {
        cout << '\t';
        item->print(isPrintHiddenItems);
    }
}

CItem* CFolder::removeByName(const string& name) {
    int len = items.size();
    for (int i = 0; i < len; ++i) {
        if (items[i]->getName() == name) {
            CItem* removedItem = items[i];
            items.erase(items.begin() + i);
            return removedItem;
        }
        else {
            CItem* found = items[i]->removeByName(name);
            if (found)
                return found;
        }
    }
    return NULL;
}

CItem* CFolder::findByName(const string& name) {
    if (this->name == name) return this;
 
    for (CItem* item : items) {
        CItem* found = item->findByName(name);
        if (found != NULL) return found;
    }
    return NULL;
}

void CFolder::add(CItem* item) {
    items.push_back(item);
}