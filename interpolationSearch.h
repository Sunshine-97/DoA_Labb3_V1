//
// Created by Caaaarl on 2022-06-30.
//

#ifndef DOA_LABB3_V1_INTERPOLATIONSEARCH_H
#define DOA_LABB3_V1_INTERPOLATIONSEARCH_H

#include <iterator>

template<typename It, typename T>
T interpolationSearch(It first, It last, const T& target) {
    while(first <= last && target >= *first && target <= *std::prev(last)) {
        if(first == last) {
            if(*first == target) return *first;
            return -1;
        }

        // TODO - solve this
        auto pos = first + (((last - first) / (*last - *first)) * (target - *first));

        if(*pos == target)
            return *pos;
        if(*pos < target)
            first = std::next(pos);
        else
            last = std::prev(pos);
    }
    return -1;
}

#endif //DOA_LABB3_V1_INTERPOLATIONSEARCH_H
