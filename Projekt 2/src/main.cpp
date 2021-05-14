#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>

typedef struct movie
{
    int id;
    std::string title;
    int rating;
    movie() :id(0),rating(0){}
}movie;


void LoadFromFile(std::string filename, movie arr[])
{
    std::fstream file(filename);
    auto i = 0;
    std::string temp;
    if (file.is_open())
    {
        while (!file.eof())
        {
            std::getline(file, temp, ','); arr[i].id =(int) std::stof(temp);
            std::getline(file, temp, ','); arr[i].title = temp;
            std::getline(file, temp, '\n'); arr[i].rating = (int)std::stof(temp);
            ++i;
        }
    }
    else { std::cout << "File not found."; }
    file.close();
}


enum class CSVState {
    UnquotedField,
    QuotedField,
    QuotedQuote
};

std::vector<std::string> readCSVRow(const std::string& row) {
    CSVState state = CSVState::UnquotedField;
    std::vector<std::string> fields{ "" };
    size_t i = 0; // index of the current field
    for (char c : row) {
        switch (state) {
        case CSVState::UnquotedField:
            switch (c) {
            case ',': // end of field
                fields.push_back(""); i++;
                break;
            case '"': state = CSVState::QuotedField;
                break;
            default:  fields[i].push_back(c);
                break;
            }
            break;
        case CSVState::QuotedField:
            switch (c) {
            case '"': state = CSVState::QuotedQuote;
                break;
            default:  fields[i].push_back(c);
                break;
            }
            break;
        case CSVState::QuotedQuote:
            switch (c) {
            case ',': // , after closing quote
                fields.push_back(""); i++;
                state = CSVState::UnquotedField;
                break;
            case '"': // "" -> "
                fields[i].push_back('"');
                state = CSVState::QuotedField;
                break;
            default:  // end of quote
                state = CSVState::UnquotedField;
                break;
            }
            break;
        }
    }
    return fields;
}

/// Read CSV file, Excel dialect. Accept "quoted fields ""with quotes"""
std::vector<std::vector<std::string>> readCSV(std::istream& in) {
    std::vector<std::vector<std::string>> table;
    std::string row;
    while (!in.eof()) {
        std::getline(in, row);
        if (in.bad() || in.fail()) {
            break;
        }
        auto fields = readCSVRow(row);
        table.push_back(fields);
    }
    return table;
}



int main()
{
    std::cout << "dupa";
    long const count = 100;
    auto* arr = new movie[count];
    LoadFromFile("C:\\Users\\damir\\Documents\\GitHub\\PAMSI\\Projekt 2\\data\\projekt2_dane.csv", arr);
    std::cout << "dupa";
    for (size_t i = 0; i <= count; i = i++)
    {
        std::cout << "dupa";
        std::cout << "Id=" << arr[i].id << " " << "tile=" << arr[i].title << " " << "rating=" << arr[i].rating << "\n";
    }
    delete[] arr;
    return 0;
}