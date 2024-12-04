#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "movie.cpp"
using namespace std;

class MoviesGraph {
private:
    unordered_map<string, vector<string>> UserToGenreAdjList;
    unordered_map<string, vector<Movie>> GenreToMovieAdjList;

public:
    MoviesGraph(string rootUser) {
        UserToGenreAdjList[rootUser] = vector<string>();
    }

    void addUser(string username) {
        if (UserToGenreAdjList.find(username) == UserToGenreAdjList.end())
            UserToGenreAdjList[username] = vector<string>();
        else cout << "User " << username << " already exists." << endl;
    }

    void addGenreToUser(string user, string genre) {
        if (UserToGenreAdjList.find(user) != UserToGenreAdjList.end())
            UserToGenreAdjList[user].push_back(genre);
        else cout << "User " << user << " does not exist." << endl;
    }

    void addMovieToGenre(string genre, Movie newMovie) {
        GenreToMovieAdjList[genre].push_back(newMovie);
    }
};
