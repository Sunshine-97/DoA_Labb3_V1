#include <iostream>
#include <cstring>
#include <vector>
#include <memory>
#include <random>
#include <fstream>
#include <iomanip>
#include <cassert>
#include "linearSearch.h"
#include "binarySearch.h"
#include "binaryTreeSearch.h"
#include "hashTable.h"
#include "timer.h"
#include "testCases.h"

int SIZE = 20000;
int MAX = 1000000;

/*
void SieveOfErastosthenes(int N, std::vector<int> &data) {
    bool primes[N+1];
    std::memset(primes, true, sizeof(primes));

    for (int p = 2; p * p <= N; p++) {
        if (primes[p]) {
            for (int j = p * p; j <= N; j += p) {
                primes[j] = false;
            }
        }
    }

    for (int p = 2; p <= N; p++)
        if (primes[p])
            data.push_back(p);
}
 */

void hash_search(size_t N, size_t iteration, const std::string& filename) {
    size_t size = N;
    int samples = 50;

    std::vector<int> data;
    std::vector<double> measurement;
    std::ofstream myFile(filename);

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    timer t;
    for(; N <= iteration; N += size) {
        SieveOfErastosthenes(data);
        data.resize(N);
        data[data.size()-1];
        for(int i = 0; i < samples; i++) {
            hashTable hash(data);
            std::uniform_int_distribution<> target(0, (data.size()-1)); // define the range
            auto random = target(gen);
            t.start();
            hash.contains(data[random]);
            t.stop();
            assert(hash.contains(data[random]) == true);
            measurement.push_back(t.elapsedSec());
        }
        long double sum = std::accumulate(measurement.begin(), measurement.end(), 0.0);
        long double avg = sum / measurement.size();
        long double s = calcStdev(measurement, avg);
        auto stdDev = (s / sqrt(N));
        myFile << std::setprecision(9) << std::fixed << std::showpoint << N << "\t\t" << avg << "\t\t" << stdDev << "\t\t" << samples << std::endl;
        measurement.clear();
    }
}

void BST(size_t N, size_t iteration, const std::string& filename) {
    size_t size = N;
    int samples = 50;

    std::vector<int> data;
    std::vector<double> measurement;
    std::ofstream myFile(filename);

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    timer t;
    for(; N <= iteration; N += size) {
        SieveOfErastosthenes(data);
        data.resize(N);
        binarySearchTree bst(data);
        for(int i = 0; i < samples; i++) {
            std::uniform_int_distribution<> target(0, (data.size()-1)); // define the range
            auto random = target(gen);
            t.start();
            bst.contains(data[random]);
            t.stop();
            assert(bst.contains(data[random]) == true);
            measurement.push_back(t.elapsedSec());
        }

        long double sum = std::accumulate(measurement.begin(), measurement.end(), 0.0);
        long double avg = sum / measurement.size();
        long double s = calcStdev(measurement, avg);
        auto stdDev = (s / sqrt(N));
        myFile << std::setprecision(14) << std::fixed << std::showpoint << N << "\t\t" << avg << "\t\t" << stdDev << "\t\t" << samples << std::endl;
        measurement.clear();
    }
}


int main() {
    size_t N = SIZE;
    size_t iterations = MAX;
    std::string linear = "LinearSearch.txt";
    std::string binary = "BinarySearch.txt";
    std::string hashtable = "Hashtable.txt";
    std::string bst = "BST.txt";

    linearSearch LinearSearch;
    binarySearch BinarySearch;

    //binary_linear_Search(LinearSearch, N, iterations, linear);
    //binary_linear_Search(BinarySearch, N, iterations, binary);
    //BST(N, iterations, bst);
    hash_search(N, iterations, hashtable);

    /*
    //LinearSearch
    linearSearch LinearSearch;
    timer t;
    for(int size = SIZE; size <= 200000; size += SIZE) {
        data.resize(size);
        SieveOfErastosthenes(size, data);
        t.start();
        //LinearSearch(data.begin(), data.end(), 199961);
        assert(LinearSearch(data.begin(), data.end(), data[data.size()-2]) == true);
        t.stop();
        measurement.push_back(t.elapsedSec());
    }


    //BinarySearch
    binarySearch BinarySearch;
    if(BinarySearch(data.begin(), data.end(), 199961))
        std::cout<<"Found! BinarySearch\n";
    else
        std::cout<<"Not Found!\n";

    //BinarySearchTree
    binarySearchTree tree(data);
    if(tree.contains(199961))
        std::cout<<"Found! BinarySearchTree\n";
    else
        std::cout<<"Not found\n";

    //HashTabell
    hashTable hash(data);
    if(hash.contains(199961))
        std::cout<<"Found! HashTabell\n";
    else
        std::cout<<"Not found\n";
*/
    return 0;
}
