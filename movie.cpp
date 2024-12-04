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

<<<<<<< HEAD
    string getName() {return name;}
    vector<string> getGenre() {return genre;}
    double getRating() {return rating;}
    double getLength() {return length;}
    int getYear() {return year;}
    vector<string> getCast() {return cast;}
    vector<string>getTags() {return tags;}
=======
    void addGenre(string genre) {genres.push_back(genre);}
    void addActor(string actorName) {cast.push_back(actorName);}
    void addTag(string tag) {tags.push_back(tag);}
>>>>>>> 8a0d094fcf930f726ca24a4e7f93890a98bf7a74
};