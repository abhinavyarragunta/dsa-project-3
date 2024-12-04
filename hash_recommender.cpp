#include <iostream>
#include <vector>
#include <string>
#include "hash_map.h"
#include <algorithm>
#include <iterator>
#include <unordered_set>

using namespace std;

vector<string> hashRecommender(popPickTable& movieTable, const unordered_set<string>& sharedGenres)
{
    vector<string> recommendations;
    for(int i = 0; i < movieTable.size(); i++)
    {
        if(movieTable.occupied[i])
        {
            const vector<string>& movieGenres = movieTable.table[i].value;

            for(const string& genre : movieGenres)
            {
                if(sharedGenres.find(genre) != sharedGenres.end())
                {
                    recommendations.push_back(movieTable.table[i].key);
                    break;
                }
            }
        }
    }
    return recommendations;
}

int main() {
    // Create and populate the hash table
    popPickTable movieTable(10);
    movieTable.insert("Jaws", {"Horror", "Shark"});
    movieTable.insert("Wicked", {"Musical"});
    movieTable.insert("Se7en", {"Mystery", "Thriller"});
    movieTable.insert("Finding Nemo", {"Adventure", "Family"});
    movieTable.insert("Inception", {"Thriller", "Sci-Fi"});

    cout << "User 1: Enter your favorite genres (type 'q' to finish):" << endl;
    unordered_set<string> user1Genres;
    string genre;
    while (true) {
        cin >> genre;
        if (genre == "q") break;
        user1Genres.insert(genre);
    }

    cout << "User 2: Enter your favorite genres (type 'q' to finish):" << endl;
    unordered_set<string> user2Genres;
    while (true) {
        cin >> genre;
        if (genre == "q") break;
        user2Genres.insert(genre);
    }

    // Find shared genres between User 1 and User 2
    unordered_set<string> sharedGenres;
    for (const string& genre : user1Genres) {
        if (user2Genres.find(genre) != user2Genres.end()) {
            sharedGenres.insert(genre);
        }
    }

    if (sharedGenres.empty()) {
        cout << "No shared genres found. No recommendations available." << endl;
        return 0;
    }

    // Get movie recommendations
    vector<string> recommendations = hashRecommender(movieTable, sharedGenres);

    if (recommendations.empty()) {
        cout << "No movies found for shared genres." << endl;
    } else {
        cout << "Recommended movies based on shared genres:" << endl;
        for (const string& movie : recommendations) {
            cout << "- " << movie << endl;
        }
    }

    return 0;
}
