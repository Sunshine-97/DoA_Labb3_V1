#include <iostream>
#include <cstring>
#include <vector>
#include <random>
#include <fstream>
#include <iomanip>
#include "linearSearch.h"
#include "binarySearch.h"
#include "binarySearchTree.h"
#include "hashTable.h"
#include "timer.h"
#include "testCases.h"

int SIZE = 100000;
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
    int count = 0;

    std::vector<int> primes;
    std::vector<double> measurement;
    std::ofstream myFile(filename);

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    timer t;
    SieveOfErastosthenes(primes);
    for(; N <= iteration; N += size) {
        std::vector<int> data = primes;
        data.resize(N);
        hashTable hash(data);
        for(int i = 0; i < samples; i++) {
            std::uniform_int_distribution<> target(0, (data.size())); // define the range
            auto random = target(gen);
            t.start();
for(int repeat = 0; repeat < 10000; repeat ++)
            if(hash.contains(data[random]))
            {
                count++;
                t.stop();
                //std::cout<<"Found!\n";
            } else {
                std::cerr<<"Not found! " << filename << "\n";
            }
            measurement.push_back(t.elapsedSec()/ 10000);
        }
        long double sum = std::accumulate(measurement.begin(), measurement.end(), 0.0);
        long double avg = sum / measurement.size();
        long double s = calcStdev(measurement, avg);
        auto stdev = (s / std::sqrt(N));
        myFile << std::setprecision(12) << std::fixed << std::showpoint << N << "\t\t" << avg << "\t\t" << stdev << "\t\t" << samples << std::endl;
        measurement.clear();
    }
}

void BST(size_t N, size_t iteration, const std::string& filename) {
    size_t size = N;
    int samples = 50;
    int count = 0;

    std::vector<int> primes;
    std::vector<double> measurement;
    std::ofstream myFile(filename);

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    timer t;
    SieveOfErastosthenes(primes);
    for(; N <= iteration; N += size) {
        std::vector<int> data = primes;
        data.resize(N);
        binarySearchTree bst(data);
        for(int i = 0; i < samples; i++) {
            std::uniform_int_distribution<> target(0, (data.size())); // define the range
            auto random = target(gen);
            t.start();
            if(bst.contains(data[random]))
            {
                count++;
                t.stop();
                //std::cout<<"Found!\n";
            } else {
                std::cerr<<"Not found! " << filename << "\n";
            }
            measurement.push_back(t.elapsedSec());
        }
        long double sum = std::accumulate(measurement.begin(), measurement.end(), 0.0);
        long double avg = sum / measurement.size();
        long double s = calcStdev(measurement, avg);
        auto stdev = (s / std::sqrt(N));
        myFile << std::setprecision(12) << std::fixed << std::showpoint << N << "\t\t" << avg << "\t\t" << stdev << "\t\t" << samples << std::endl;
        measurement.clear();
    }
}


int main() {
    size_t N = SIZE;
    size_t iterations = MAX;
    std::string hashtable = "Hashtable.txt";
    std::string bst = "BST.txt";

    linearSearch LinearSearch;
    binarySearch BinarySearch;

    binary_linear_Search(LinearSearch, N/10, iterations/10, "LinearSearch.txt");
    binary_linear_Search(BinarySearch, N/10, iterations/10, "BinarySearch.txt");
    BST(N/100, iterations/100, bst);
    hash_search(N/100, iterations/100, hashtable);

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
