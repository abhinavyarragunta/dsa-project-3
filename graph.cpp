#include <iostream>
#include <movie.cpp>
#include <unordered_map>
#include <vector>
using namespace std;

struct UserNode {
private:
    string username;
public:
    UserNode(string u = "User") {username = u;}
};

struct GenreNode {
private:
    string genre;
public:
    GenreNode(string g = "No Genre") {genre = g;}
};


class MoviesGraph {
private:
    unordered_map<UserNode, vector<GenreNode>> UserToGenreAdjList;
    unordered_map<GenreNode, vector<Movie>> GenreToMovieAdjList;
public:
    MoviesGraph(UserNode rootUser) {
        UserToGenreAdjList[rootUser] = {}
    }

    void addUser(string username) {
        UserNode newUser = new UserNode(username);
        UserToGenreAdjList[newUser] = {};
    }

    void addGenreToUser(UserNode user, GenreNode genre) {
        UserToGenreAdjList[user].push_back(genre);
    }

    void addMovieToGenre(GenreNode newGenre, Movie newMovie) {
        if (GenreToMovieAdjList.find(newGenre) == GenreToMovieAdjList.end())
            GenreToMovieAdjList[newGenre] = {newMovie};
        else GenreToMovieAdjList[newGenre].push_back(newMovie);
    }
};
