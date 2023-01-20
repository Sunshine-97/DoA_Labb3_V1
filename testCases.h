//
// Created by Caaaarl on 2022-08-22.
//

#ifndef DOA_LABB3_V1_TESTCASES_H
#define DOA_LABB3_V1_TESTCASES_H

const int MAXP = 100000000;
//bool primes[MAXP];

void SieveOfErastosthenes(std::vector<int> &data) {
    //std::memset(primes, true, sizeof(primes));
    std::vector<bool> primes(MAXP, true);

    for (int p = 2; p * p <= MAXP; p++) {
        if (primes[p]) {
            for (int j = p * p; j <= MAXP; j += p) {
                primes[j] = false;
            }
        }
    }

    for (int p = 2; p <= MAXP; p++)
        if (primes[p])
            data.push_back(p);

}

template<typename T>
long double calcStdev(const T& data,long double avg) {
    long double standardDev = 0.0;

    for(int i = 0; i < data.size(); i++) {
        standardDev += pow(data[i] - avg, 2);
    }

    return std::sqrt(standardDev * (1.0 / (data.size()-1)));
}

template<class Search>
void binary_linear_Search(Search search, size_t N, size_t iteration, const std::string& filename){
    size_t size = N;
    int samples = 100;
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
        for(int i = 0; i < samples; i++) {
            std::uniform_int_distribution<> target(0, data.size()); // define the range
            auto random = target(gen);
            t.start();
            if(search(data.begin(), data.end(), data[random]))
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

/*
template<class Search>
void hash_BST_Search(Search search, size_t N, size_t iteration, const std::string& filename){
    size_t size = N;
    int samples = 100;
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
        search(data);
        for(int i = 0; i < samples; i++) {
            std::uniform_int_distribution<> target(0, data.size()); // define the range
            auto random = target(gen);
            t.start();
            if(search.contains(data[random]))
            {
                count++;
                t.stop();
            } else {
                t.stop();
                std::cerr<<"Not found! " << filename << "\n";
            }
            measurement.push_back(t.elapsedSec());
        }
        long double sum = std::accumulate(measurement.begin(), measurement.end(), 0.0);
        long double avg = sum / measurement.size();
        long double s = calcStdev(measurement, avg);
        auto stdev = (s / sqrt(N));
        myFile << std::setprecision(12) << std::fixed << std::showpoint << N << "\t\t" << avg << "\t\t" << stdev << "\t\t" << samples << std::endl;
        measurement.clear();
    }
}
*/

#endif //DOA_LABB3_V1_TESTCASES_H
