//
// Created by Caaaarl on 2022-06-30.
//

#ifndef DOA_LABB3_V1_BINARYSEARCH_H
#define DOA_LABB3_V1_BINARYSEARCH_H

#include <iterator>

class binarySearch {
public:
    binarySearch() = default;

    template<typename It, typename T>
    bool operator()(It first, It last, const T& target) {
        while(last >= first) {
            auto mid = first + (std::distance(first, last) / 2);

            if(*mid == target) { return true; }
            else if(*mid > target) { return (first, mid - 1, target); }
            else { return (mid + 1, last, target); }
        }
        return false;
    }
};

/*
template<typename It, typename T>
T binarySearch(It first, It last, const T& target) {
    while(last >= first) {
        auto mid = first + (std::distance(first, last) / 2);

        if(*mid == target)
            return *mid;

        if(*mid > target)
            return binarySearch(first, mid - 1, target);

        return binarySearch(mid + 1, last, target);
    }
    return -1;
}
 */

#endif //DOA_LABB3_V1_BINARYSEARCH_H
