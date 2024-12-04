#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    string name;
    double rating;
    double length;
    int year;
    vector<string> genres;
    vector<string> cast;
    vector<string> tags;

public:
    Movie(string n, double r = 0, double l = 0, int y = 0000) {
        name = n;
        rating = r < 0 ? 0 : r;
        length = l < 0 ? 0 : l;
        year = y;
    }

    void addGenre(string genre) {genres.push_back(genre);}
    void addActor(string actorName) {cast.push_back(actorName);}
    void addTag(string tag) {tags.push_back(tag);}
};