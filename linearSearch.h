//
// Created by Caaaarl on 2022-06-30.
//

#ifndef DOA_LABB3_V1_LINEARSEARCH_H
#define DOA_LABB3_V1_LINEARSEARCH_H

//Time Complexity: O(N)
class linearSearch {
public:
    linearSearch() = default;

    template<typename It, typename T>
    bool operator()(It first, It last, const T& target) {
        for(; first != last; first++) {
            if(*first == target)
                return true;
        }
        return false;
    }
};
/*
template<typename It, typename T>
T linearSearch(It first, It last, const T& target) {
    for(; first != last; first++) {
        if(*first == target)
            return *first;
    }
    return -1;
}
 */


#endif //DOA_LABB3_V1_LINEARSEARCH_H
