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
    long double square_sum = 0.0;

    for(int i = 0; i < data.size(); i++) {
        square_sum += pow(data[i] - avg, 2);
    }

    return std::sqrt(square_sum * (1.0 / (data.size() - 1)));
}

template<class Search>
void binary_linear_Search(Search search, size_t N, size_t iteration, const std::string& filename){
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
        for(int i = 0; i < samples; i++) {
            std::uniform_int_distribution<> target(0, (data.size()-1)); // define the range
            auto random = target(gen);
            auto value = data[random];
            t.start();
            search(data.begin(), data.end(), value);
            t.stop();
            measurement.push_back(t.elapsedSec());
        }
        long double sum = std::accumulate(measurement.begin(), measurement.end(), 0.0);
        long double avg = sum / measurement.size();
        long double s = calcStdev(measurement, avg);
        auto avgTime = sqrt(N) * avg;
        myFile << std::setprecision(9) << std::fixed << std::showpoint << N << "\t\t" << avgTime << "\t\t" << s << "\t\t" << samples << std::endl;
        measurement.clear();
    }
}

#endif //DOA_LABB3_V1_TESTCASES_H
