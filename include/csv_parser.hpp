#ifndef CSV_PARSER_HPP
#define CSV_PARSER_HPP

#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct CSVParser {
    vector<vector<string>> data;

    void parse(const string& filename) {
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            vector<string> row;
            size_t pos = 0;
            while ((pos = line.find(',')) != string::npos) {
                row.push_back(line.substr(0, pos));
                line.erase(0, pos + 1);
            }
            // last line after the last comma
            row.push_back(line);
            data.push_back(row);
        }
    }
};

#endif // CSV_PARSER_HPP