#include "Kmers.hpp"

#include <fstream>

using namespace std;

int main()
{
    // Large file
    ifstream filein("vibrio_choleare.txt");
    // Small file
    // ifstream filein("vibrio_choleare_mini.txt");

    string sequence = "";
    getline(filein, sequence);

    Kmers kmers3 = Kmers(3, sequence);
    Kmers kmers4 = Kmers(4, sequence);
    Kmers kmers5 = Kmers(5, sequence);
    Kmers kmers6 = Kmers(6, sequence);
    Kmers kmers7 = Kmers(7, sequence);
    Kmers kmers8 = Kmers(8, sequence);
    Kmers kmers9 = Kmers(9, sequence);

    vector<Kmers> list = {kmers3, kmers4, kmers5, kmers6, kmers7, kmers8, kmers9};
    vector<pair<vector<string>, int>> result;
    for (auto kmer : list)
    {
        kmer.frequentWords();
        result.push_back(kmer.maxMap());
    }

    for (auto pairs : result)
    {
        cout << "Kmer: ";
        for (auto list : pairs.first)
        {
            cout << list << " ";
        }
        cout << "| "
             << " frequency : " << pairs.second << endl;
    }
}