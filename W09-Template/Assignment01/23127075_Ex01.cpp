#include "MyVector.h"

int main()
{
    MyVector<int>* intVec = new MyVector<int>();
    MyVector<Fraction>* fracVec = new MyVector<Fraction>();
    cout << "Default constructor:\n";
    cout << "Int Vector: " << intVec->toString() << endl;
    cout << "Frac Vector: " << fracVec->toString() << "\n\n";
    delete intVec;
    delete fracVec;

    intVec = new MyVector<int>(5);
    fracVec = new MyVector<Fraction>(5);
    cout << "5 elemnets size-para constructor:\n";
    cout << "Int Vector: " << intVec->toString() << endl;
    cout << "Frac Vector: " << fracVec->toString() << "\n\n";
    delete intVec;
    delete fracVec;

    int intArr[] = {2, 1, 3, 5 ,4};
    Fraction fracArr[] = {{2,3}, {1,2}, {3,4}, {5,6}, {4,5}};
    intVec = new MyVector<int>(intArr, 5);
    fracVec = new MyVector<Fraction>(fracArr, 5);
    cout << "5 elemnets arr-para constructor:\n";
    cout << "Int Vector: " << intVec->toString() << endl;
    cout << "Frac Vector: " << fracVec->toString() << "\n\n";

    MyVector<int>* newIntVec = new MyVector<int>(*intVec);
    MyVector<Fraction>* newFracVec = new MyVector<Fraction>(*fracVec);
    delete intVec;
    delete fracVec;
    cout << "Copy constructor:\n";
    cout << "New int Vector: " << newIntVec->toString() << endl;
    cout << "New frac Vector: " << newFracVec->toString() << "\n\n";


    cout << "Size int vector: " << newIntVec->getSize() << endl;
    cout << "Size frac vector: " << newFracVec->getSize() << "\n\n";

    int index = 3;
    cout << "Item at index " << index << " of int vector: " << newIntVec->getItem(index) << endl;
    cout << "Item at index " << index << " of frac vector: " << newFracVec->getItem(index) << "\n\n";

    int integer = 100;
    Fraction *fraction = nullptr;
    try
    {
        fraction = new Fraction(7, 0);
    }
    catch(const std::invalid_argument& error)
    {
        std::cerr << error.what() << "\n\n";
    }
    fraction = new Fraction(7, 49);
    index = 2;
    newIntVec->setItem(integer, index);
    newFracVec->setItem(*fraction, index);
    cout << "After setting value at index " << index << " of Int Vector to " << integer << endl;
    cout << "Int Vector: " << newIntVec->toString() << endl;
    cout << "After setting value at index " << index << " of Frac Vector to " << *fraction << endl;
    cout << "Frac Vector: " << newFracVec->toString() << "\n\n";

    newIntVec->add(integer);
    newFracVec->add(*fraction);
    cout << "After adding value " << integer << " to Int Vector\n";
    cout << "Int Vector: " << newIntVec->toString() << endl;
    cout << "After adding value " << *fraction << " to Frac Vector\n";
    cout << "Frac Vector: " << newFracVec->toString() << "\n\n";

    int newIntArr[] = {6, 7, 8};
    Fraction newFracArr[] = {{6, 7}, {7, 8}, {8, 9}};
    newIntVec->addRange(newIntArr, 3);
    newFracVec->addRange(newFracArr, 3);
    cout << "After adding range:\n";
    cout << "Int Vector: " << newIntVec->toString() << endl;
    cout << "Frac Vector: " << newFracVec->toString() << "\n\n";

    cout << "Int Vec " << (newIntVec->contains(integer) ? "contains " : "doesn't contain ") << integer << endl;
    cout << "Frac Vec " << (newFracVec->contains(*fraction) ? "contains " : "doesn't contain ") << *fraction << "\n\n";

    cout << "Comparing:\n";
    cout << "New Int Vec equals to itself: " << newIntVec->equals(*newIntVec) << endl;
    cout << "New Frac Vec equals to itself: " << newFracVec->equals(*newFracVec) << "\n\n";

    cout << "In Int Vec, first and last index of " << integer << ": " << newIntVec->indexOf(integer) << " & " << newIntVec->lastIndexOf(integer) << endl;
    cout << "In frac Vec, first and last index of " << *fraction << ": " << newFracVec->indexOf(*fraction) << " & " << newFracVec->lastIndexOf(*fraction) << "\n\n";

    index = 0;
    newIntVec->insert(integer, index);
    newFracVec->insert(*fraction, index);
    cout << "After inserting value " << integer << " to index " << index << " of Int Vector\n";
    cout << "Int Vector: " << newIntVec->toString() << endl;
    cout << "After inserting value " << *fraction << " to index " << index << " of Frac Vector\n";
    cout << "Frac Vector: " << newFracVec->toString() << "\n\n";

    newIntVec->remove(integer);
    newFracVec->remove(*fraction);
    cout << "After removing value " << integer << " of Int Vector\n";
    cout << "Int Vector: " << newIntVec->toString() << endl;
    cout << "After removing value " << *fraction << " of Frac Vector\n";
    cout << "Frac Vector: " << newFracVec->toString() << "\n\n";

    index = 1;
    newIntVec->removeAt(index);
    newFracVec->removeAt(index);
    cout << "After removing value at index " << index << " of Int Vector\n";
    cout << "Int Vector: " << newIntVec->toString() << endl;
    cout << "After removing value at index " << index << " of Frac Vector\n";
    cout << "Frac Vector: " << newFracVec->toString() << "\n\n";

    cout << "After reversing:\n";
    newIntVec->reverse();
    newFracVec->reverse();
    cout << "Int Vector: " << newIntVec->toString() << endl;
    cout << "Frac Vector: " << newFracVec->toString() << "\n\n";

    cout << "Sort Ascending:\n";
    newIntVec->sortAsc();
    newFracVec->sortAsc();
    cout << "Int Vector: " << newIntVec->toString() << endl;
    cout << "Frac Vector: " << newFracVec->toString() << "\n\n";

    cout << "Sort Descending:\n";
    newIntVec->sortDesc();
    newFracVec->sortDesc();
    cout << "Int Vector: " << newIntVec->toString() << endl;
    cout << "Frac Vector: " << newFracVec->toString() << "\n\n";

    cout << "Clear:\n";
    newIntVec->clear();
    newFracVec->clear();
    cout << "Int Vector: " << newIntVec->toString() << endl;
    cout << "Frac Vector: " << newFracVec->toString() << "\n\n";

    delete fraction;
    delete newIntVec;
    delete newFracVec;

    return 0;
}