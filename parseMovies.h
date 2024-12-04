#pragma once

#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, std::vector<std::string>> parseMovies(const std::string& csvFilePath);
