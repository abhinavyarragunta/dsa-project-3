#include "parseMovies.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::unordered_map<std::string, std::vector<std::string>> parseMovies(const std::string& csvFilePath) {
    std::unordered_map<std::string, std::vector<std::string>> movieMap;
    std::ifstream file(csvFilePath);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << csvFilePath << std::endl;
        return movieMap;
    }

    std::string line;
    std::getline(file, line); // Skip header line

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string movie, genre;
        std::vector<std::string> genres;
        std::getline(ss, movie, ',');

        while (std::getline(ss, genre, ',')) {
            if (!genre.empty()) {
                genres.push_back(genre);
            }
        }

        if (!movie.empty()) {
            movieMap[movie] = genres;
        }
    }

    file.close();
    return movieMap;
}
