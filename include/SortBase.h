//
// Created by Mike Solar on 25-6-21.
//

#ifndef SORTBASE_H
#define SORTBASE_H
#include <memory>


class SortBase {
public:
    SortBase() = default;
    virtual ~SortBase() = default;
    virtual void sort() = 0;
    virtual void generate(int length) = 0;
    int compareTime() const {
        return compareTime_;
    }
    int swapTime() const {
        return swapTime_;
    }
    int length() const {
        return length_;
    }
    virtual std::unique_ptr<int[]> array() = 0;
protected:
    int compareTime_=0;
    int swapTime_=0;
    int length_=0;
};



#endif //SORTBASE_H
