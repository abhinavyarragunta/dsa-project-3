#include <iostream>
#include <string>

using namespace std;

class Movie {
private:
    string name;
    string genre;
    double rating;
    double length;

public:
    Movie(string n, string g, double r = 0, double l = 0) {
        name = n;
        genre = g;
        rating = r < 0 ? 0 : r;
        length = l < 0 ? 0 : l;
    }

    string getName() {return name;}
    string getGenre() {return genre;}
    double getRating() {return rating;}
    double getLength() {return length;}

};