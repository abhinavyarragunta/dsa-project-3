#include <iostream>
#include "parseMovies.h"

int main() {
    // Replace "movies.csv" with the path to your CSV file
    std::string csvFilePath = "../movies.csv";
    std::unordered_map<std::string, std::vector<std::string>> movieMap = parseMovies(csvFilePath);

    // Example: Display the parsed data
    for (const auto& [movie, genres] : movieMap) {
        std::cout << "Movie: " << movie << "\nGenres: ";
        for (const std::string& genre : genres) {
            std::cout << genre << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
