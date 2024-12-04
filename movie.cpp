#include <string>
using namespace std;

class Movie {
private:
    string name;
    string genre;
    string description;

public:
    Movie(string n, string g, string d) {
        name = n;
        genre = g;
        description = d;
    }

    bool operator==(const Movie& other) const {return (this->name == other.name);}
    bool operator<(const Movie& other) const {return (this->name < other.name);}

    string getName() {return name;}
    string getGenre() {return genre;}
    string getDescription() {return description;}

};