#include "CITEM.h"

CItem::CItem(const string& name)
    : name(name), isReadOnly(false), isHidden(false) {}

string CItem::getName() const {
    return name;
}

void CItem::setHidden(bool isHidden, bool isAlsoApplyToChildren) {
    this->isHidden = isHidden;
}

CFile::CFile(const string& name, int size)
    : CItem(name), size(size) {}

int CFile::getSize() const {
    return size;
}

void CFile::print(bool isPrintHiddenItems) const {
    if (isHidden && !isPrintHiddenItems) return;
    cout << "- File: " << name << " (" << size << " KB)" << endl;
}

bool CFile::isFolder() const {
    return false;
}

CFolder::CFolder(const string& name)
    : CItem(name) {}

CFolder::~CFolder() {
    for (CItem* item : items) {
        delete item;
    }
    items.clear();
}

void CFolder::add(CItem* item) {
    items.push_back(item);
}

CItem* CFolder::removeByName(const string& name) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getName() == name) {
            CItem* removedItem = *it;
            items.erase(it);
            return removedItem;
        }
    }
    return nullptr;
}

CItem* CFolder::findByName(const string& name) {
    for (CItem* item : items) {
        if (item->getName() == name) {
            return item;
        }
    }
    return nullptr;
}

int CFolder::getSize() const {
    int totalSize = 0;
    for (CItem* item : items) {
        totalSize += item->getSize();
    }
    return totalSize;
}

void CFolder::print(bool isPrintHiddenItems) const {
    if (isHidden && !isPrintHiddenItems) return;

    cout << "+ Folder: " << name << " (" << getSize() << " KB)" << endl;
    for (CItem* item : items) {
        item->print(isPrintHiddenItems);
    }
}

bool CFolder::isFolder() const {
    return true;
}