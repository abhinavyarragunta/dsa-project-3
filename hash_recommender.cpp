#include <iostream>
#include <vector>
#include <string>
#include "hash_map.h"
#include <algorithm>
#include <iterator>

using namespace std;

vector<string> hashRecommender(popPickTable& movieTable, const string& title)
{
    //if title exists within hashtable
        //then search for its genres
        //then find movie with similar genres as the ones in title
        // return a vector of movies that have similar genres

    vector<string> recommendations;
    string foundTitle = movieTable.searchTitle(title);
    if(foundTitle == "Not Found")
    {
        cout << "Movie not found!" << '\n';
        return recommendations;
    }

    vector<string> genres = movieTable.searchGenres(title);
    if(genres.empty())
    {
        cout << "No genres found for " << title << '\n';
        return recommendations;
    }

    for(int i = 0; i < movieTable.size(); i++)
    {
        if(movieTable.occupied[i])
        {
            vector<string> currentGenres = movieTable.table[i].value;

            for(const string& genre : genres)
            {
                if(std::find(currentGenres.begin(), currentGenres.end(), genre) != currentGenres.end())
                {
                    recommendations.push_back(movieTable.table[i].key);
                    break;
                }
            }
        }
    }

    return recommendations;
}