#include <iostream>
#include <vector>
#include <string>
#include "hash_map.h"
#include <algorithm>
#include <iterator>
#include <unordered_set>

using namespace std;

vector<string> getAllGenres(popPickTable& movieTable)
{
    unordered_set<string> uniqueGenres;
    for(int i = 0; i < movieTable.size(); i++)
    {
        if(movieTable.occupied[i])
        {
            for(const string& genre: movieTable.table[i].value)
            {
                uniqueGenres.insert(genre);
            }
        }
    }
    return vector<string>(uniqueGenres.begin(), uniqueGenres.end());
}

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

   vector<unordered_set<string>> allUserGenres;
   while(true)
   {
        cout << "Enter genres for a new user (type 'q' to finish user, 'done' to stop adding users):" << endl;
        unordered_set<string> userGenres;
        string genre;
        while(true)
        {
            cin >> genre;
            if(genre == "q") break;
            if(genre == "done") break;
            userGenres.insert(genre);
        }
        if(genre == "done") break;
        allUserGenres.push_back(userGenres);
   }

    if(allUserGenres.empty())
    {
        cout << "No user preferences entered." << endl;
        //Maybe print out entire list here
        return 0;
    }

    unordered_set<string> sharedGenres = allUserGenres[0];
    for(int i = 1; i < allUserGenres.size(); i++)
    {
        unordered_set<string> tempSharedGenres;
        for(const string& genre : sharedGenres)
        {
            if(allUserGenres[i].find(genre) != allUserGenres[i].end())
            {
                tempSharedGenres.insert(genre);
            }
        }
        sharedGenres = tempSharedGenres;
        if(sharedGenres.empty()) break;
        
    }

    if(sharedGenres.empty())
    {
        cout << "No shared genres found among all users. No recommendations. :(" << endl;
    }
    else
    {
        vector<string> recommendations = hashRecommender(movieTable, sharedGenres);

        if(recommendations.empty())
        {
            cout << "No movies found for shared genres." << endl;
        }
        else
        {
            cout << "Recommendeded movies based on shared genres:" << endl;
            for(const string& movie : recommendations)
            {
                cout << "- " << movie << endl;
            }
        }
    }

    return 0;
}
