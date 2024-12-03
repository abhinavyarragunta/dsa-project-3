#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Movie {
private:
    string name;
    vector<string> genre;
    double rating;
    double length;
    int year;
    vector<string> cast;
    vector<string> tags;

public:
    Movie(string n, string g, double r = 0, double l = 0, int y = 0000) {
        name = n;
        genre.push_back(g);
        year = y;
        rating = r < 0 ? 0 : r;
        length = l < 0 ? 0 : l;
    }

    string getName() {return name;}
    vector<string> getGenre() {return genre;}
    double getRating() {return rating;}
    double getLength() {return length;}
    int getYear() {return year;}
    vector<string> getCast() {return cast;}
    vector<string>getTags() {return tags;}


};