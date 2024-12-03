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
    
    string getName() const;
    
    virtual void setHidden(bool isHidden, bool isAlsoApplyToChildren) = 0; // 9, 10
    virtual int getSize() const = 0;
    virtual void print(bool isPrintHiddenItems) const = 0; // 5
    virtual CItem* removeByName(const string& name) = 0; // 6
    virtual CItem* findByName(const string& name) = 0; // 7
};

class CFile : public CItem {
private:
    int size;

public:
    CFile(const string& name, const int& size); // 2

    void setHidden(bool isHidden, bool isAlsoApplyToChildren) override; // 9, 10
    int getSize() const override;
    void print(bool isPrintHiddenItems) const override; // 5
    CItem* removeByName(const string& name) override; // 6
    CItem* findByName(const string& name) override; // 8
};

class CFolder : public CItem {
private:
    vector<CItem*> items;

public:
    CFolder(const string& name); // 1
    ~CFolder();

    void setHidden(bool isHidden, bool isAlsoApplyToChildren) override;
    int getSize() const override;
    void print(bool isPrintHiddenItems) const override; // 5
    CItem* removeByName(const string& name) override; // 6
    CItem* findByName(const string& name) override; // 7

    void add(CItem* item); // 3, 4
};

#endif
