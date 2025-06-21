//
// Created by mikesolar on 25-6-21.
//

#ifndef SORTBASE_H
#define SORTBASE_H
#include <memory>


class SortBase {
public:
    SortBase(int length) {
        data=new int[length];
        this->length=length;
    };
    virtual ~SortBase() {
        delete[] data;
    };
    virtual void sort() = 0;
    virtual void generate() = 0;

protected:
    int *data;
    int length;
};



#endif //SORTBASE_H
