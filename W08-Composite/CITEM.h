

#ifndef _CITEM_H_
#define _CITEM_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CItem {
protected:
    string name;
    bool isReadOnly;
    bool isHidden;

public:
    CItem(const string& name);
    virtual ~CItem() {}

    virtual int getSize() const = 0;
    string getName() const;
    void setHidden(bool isHidden, bool isAlsoApplyToChildren);
    virtual void print(bool isPrintHiddenItems) const = 0;
    virtual bool isFolder() const = 0;
};

class CFile : public CItem {
    int size;

public:
    CFile(const string& name, int size); // 2
    int getSize() const override;
    void print(bool isPrintHiddenItems) const override;
    bool isFolder() const override;
};

class CFolder : public CItem {
    vector<CItem*> items;

public:
    CFolder(const string& name); // 1
    ~CFolder();

    void add(CItem* item); // 3
    void print(bool isPrintHiddenItems) const override; // 5
    CItem* removeByName(const string& name); // 6
    CItem* findByName(const string& name); // 7

    int getSize() const override;
    bool isFolder() const override;
};

#endif
