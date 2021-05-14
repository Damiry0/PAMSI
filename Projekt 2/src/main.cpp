#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>

struct movie
{
    int id;
    std::string title;
    int rating;
};


void LoadFromFile(std::string filename, movie arr[])
{
    std::fstream file(filename);
    int i=0;
    std::string temp;
    if(file.is_open())
    {
        while(!file.eof())
        {
            std::getline(file,temp,','); arr[i].id=std::stoi(temp);
            std::getline(file,temp,','); arr[i].title=temp;
            std::getline(file,temp,'\n'); arr[i].rating=std::stoi(temp);
            ++i;
        }
    }
    else{std::cout<<"File not found.";}
    file.close();
    
}


int main ()
{
    movie arr[1000000];
    LoadFromFile("../data/projekt2_dane.csv",arr);
    std::cout<<"dupa";
    for (size_t i = 0; i < 1000000; i=i+1000)
    {
        std::cout<<"dupa";
        std::cout<<"Id="<<arr->id<<" "<<"tile="<<arr->title<<" "<<"rating="<<arr->rating<<"\n";
    }
    


    return 0;
}