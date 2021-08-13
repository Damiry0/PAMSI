#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

#include "Sort.h"


enum class CSVState {
    UnquotedField,
    QuotedField,
    QuotedQuote
};

std::vector<std::string> readCSVRow(const std::string& row);
std::vector<std::vector<std::string>> readCSV(std::istream& in);
void ParseCSV(const std::string& csvSource, std::vector<std::vector<std::string> >& lines);

void bucketSort(int arr[], int arrSize) {
    
    int maximum_value = 0;
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > maximum_value) {
            maximum_value = arr[i];
        }
    }
    auto bucket_vector = std::vector<unsigned >(static_cast<unsigned int>(maximum_value + 1));
    for (int i = 0; i < arrSize; ++i) {
        bucket_vector[arr[i]]++;
    }
    int count = 0;
    for (int i = 0; i < bucket_vector.capacity(); ++i) {
        for (int j = 0; j < bucket_vector[i]; ++j) {
            arr[count] = i;
            count++;
        }
    }
}




int main()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

	
    std::string sourceFilePath = "C:\\Users\\damir\\Documents\\GitHub\\PAMSI\\Projekt 2\\data\\projekt2_dane.csv";
    std::fstream filename(sourceFilePath);
	
    auto vec=readCSV(filename);
    long ArraySize[]{ 10000,100000,500000,962900 };

    
	//MergeSort
    int** arrayOfMergeArrays = new int* [4];
    for (int i = 0; i < 4; i++)
    {
        arrayOfMergeArrays[i] = new int[ArraySize[i]];
    }
    
    for (int j = 0; j < 4; j++)
    {
        std::cout << "Started sorting \n";
        long count = 0;
        for (int i = 0; i < ArraySize[j]; i++)
        {
            if (vec[i][2].empty()) vec[i][2] = "5";
            arrayOfMergeArrays[j][i] = stoi(vec[i][2]);
            count = count + arrayOfMergeArrays[j][i];
        }
        auto t1 = high_resolution_clock::now();
        quickSort(arrayOfMergeArrays[j], 0, ArraySize[j] - 1);
        auto t2 = high_resolution_clock::now();
        auto ms_double = t2 - t1;
        std::cout << "MergeSort time for " << ArraySize[j] << ":" << ms_double.count() << "ms \n";
        std::cout << "Mediana " << arrayOfMergeArrays[j][ArraySize[j] / 2] << "\n";
        std::cout << "Srednia wartość" << (double)count / (double)ArraySize[j] << "\n";
        delete[] arrayOfMergeArrays[j];
    }
    std::cout << "\n";

	//QuickSort
    int** arrayOfArrays = new int* [4];
    for (int i = 0; i < 4; i++)
    {
        arrayOfArrays[i] = new int[ArraySize[i]];
        long count = 0;
    }
    for (int j = 0; j < 4; j++)
    {
        std::cout << "Started sorting \n";
        long count = 0;
        for (int i = 0; i < ArraySize[j]; i++)
        {
            if (vec[i][2].empty()) vec[i][2] = "5";
            arrayOfArrays[j][i] = stoi(vec[i][2]);
            count = count + arrayOfArrays[j][i];
        }
        auto t1 = high_resolution_clock::now();
        quickSort(arrayOfArrays[j], 0, ArraySize[j] - 1);
        auto t2 = high_resolution_clock::now();
        auto ms_double = t2 - t1;
        std::cout << "QuickSort time for " << ArraySize[j] << ":" << ms_double.count() << "ms \n";
        std::cout << "Mediana:" << arrayOfArrays[j][ ArraySize[j]/2]<<"\n";
        std::cout << "Srednia wartosc:" << (double)count / (double) ArraySize[j] << "\n";
        delete[] arrayOfArrays[j];
    }
    std::cout << "\n";
	
	//BucketSort
    int** arrayOfArraysBucket = new int* [4];
    for (int i = 0; i < 4; i++)
    {
        arrayOfArraysBucket[i] = new int[ArraySize[i]];
    }

    for (int j = 0; j < 4; j++)
    {
        long count = 0;
        std::cout << "Started sorting \n";
        for (int i = 0; i < ArraySize[j]; i++)
        {
            if (vec[i][2].empty()) vec[i][2] = "5";
            arrayOfArraysBucket[j][i] = stoi(vec[i][2]);
            count = count + arrayOfArraysBucket[j][i];
        }
        auto t1 = high_resolution_clock::now();
        bucketSort(arrayOfArraysBucket[j], ArraySize[j]);
        auto t2 = high_resolution_clock::now();
        auto ms_double = t2 - t1;
        std::cout << "BucketSort time for " << ArraySize[j] << ":" << ms_double.count() << "ms \n";
        std::cout << "Mediana:" << arrayOfArraysBucket[j][ArraySize[j] / 2] << "\n";
        std::cout << "Srednia wartosc:" << (double)count / (double)ArraySize[j] << "\n";
        delete[] arrayOfArraysBucket[j];
    }
	
	//IntroSort
    int** arrayOfArraysIntro = new int* [4];
    for (int i = 0; i < 4; i++)
    {
        arrayOfArraysIntro[i] = new int[ArraySize[i]];
    }

    for (int j = 0; j < 4; j++)
    {
        long count = 0;
        std::cout << "Started sorting \n";
        for (int i = 0; i < ArraySize[j]; i++)
        {
            if (vec[i][2].empty()) vec[i][2] = "5";
            arrayOfArraysIntro[j][i] = stoi(vec[i][2]);
            count = count + arrayOfArraysIntro[j][i];
        }
        auto t1 = high_resolution_clock::now();
        introSort(arrayOfArraysIntro[j],arrayOfArraysIntro[j], arrayOfArraysIntro[j]+(ArraySize[j]) - 1  );
        auto t2 = high_resolution_clock::now();
        auto ms_double = t2 - t1;
        std::cout << "IntroSort time for " << ArraySize[j] << ":" << ms_double.count() << "ms \n";
        std::cout << "Mediana:" << arrayOfArraysIntro[j][ArraySize[j] / 2] << "\n";
        std::cout << "Srednia wartosc:" << (double)count / (double)ArraySize[j] << "\n";
        delete[] arrayOfArraysIntro[j];
    }
    //licbza pustych 47.389

}



std::vector<std::string> readCSVRow(const std::string& row) {
    CSVState state = CSVState::UnquotedField;
    std::vector<std::string> fields{ "" };
    size_t i = 0;
    for (char c : row) {
        switch (state) {
        case CSVState::UnquotedField:
            switch (c) {
            case ',':
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
            case ',':
                fields.push_back(""); i++;
                state = CSVState::UnquotedField;
                break;
            case '"':
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