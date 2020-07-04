#ifndef KMERS_HPP
#define KMERS_HPP

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Kmers
{
private:
    string sequence;
    int k;
    unordered_map<string, int> map;

public:
    Kmers(int k, string sequence);
    ~Kmers();
    void frequentWords();
    pair<vector<string>, int> maxMap();
};

/**
 * Kmer constructor.
 * 
 * @param k the length of the pattern
 */
Kmers::Kmers(int k, string sequence)
{
    this->k = k;
    this->sequence = sequence;
}

/**
 * Destructor.
 */
Kmers::~Kmers() {}

/**
 * Completes the map with the frequencies of each kmer.
 */
void Kmers::frequentWords()
{
    // Make sure k is smaller than sequence's length
    string kmer = "";
    for (int i = 0; i < this->k; i++)
    {
        kmer += this->sequence[i];
    }
    this->map.insert({kmer, 1});

    for (int i = k; i < this->sequence.length(); i++)
    {
        kmer = kmer.substr(1, kmer.length()) + this->sequence[i];
        if (this->map.find(kmer) == this->map.end())
        {
            this->map.insert({kmer, 1});
        }
        else
        {
            this->map[kmer] = this->map[kmer] + 1;
        }
    }
}

/**
 * Get the most frequent kmer.
 * TODO: What if the frequencies are the same.
 * 
 * @return the most frequent pattern along with its frequency
 */
pair<vector<string>, int> Kmers::maxMap()
{
    vector<string> patterns;
    int frequency = INT_MIN;
    for (auto pairs : this->map)
    {
        if (pairs.second > frequency)
        {
            patterns.clear();
            patterns.push_back(pairs.first);
            frequency = pairs.second;
        }
        else if (pairs.second == frequency)
        {
            patterns.push_back(pairs.first);
        }
    }
    pair<vector<string>, int> result(patterns, frequency);
    return result;
}
#endif