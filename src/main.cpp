#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "priority_queue.cpp"



std::vector<std::string> split(const std::string & s, char c)
{
    std::vector<std::string> splitted;
    std::string word;
    for(char ch : s)
    {
        if((ch == c) && (!word.empty()))
        {
            splitted.push_back(word);
            word.clear();
        }
        else
            word += ch;
    }
    if(!word.empty())
        splitted.push_back(word);

    return splitted;
}



std::vector<std::string> SplitTxtIntoWords(std::string filename)
{
    std::ifstream in_s(filename);
    std::vector <std::vector<std::string>> content;
    std::vector <std::string> vec;
    if(in_s)
    {
        std::string line;
        
        while(getline(in_s, line))
        {
            for(const std::string & str : split(line, ' '))
                vec.push_back(str);
            content.push_back(vec);
            vec.clear();
        }

        in_s.close();
    }
    else
        std::cout << "Could not open: " + filename << std::endl;

    vector<string>str_vec;
    for(const std::vector<std::string> & str_vec : content)
    {
        for(unsigned int i = 0; i < str_vec.size(); ++i)
            std::cout << str_vec[i] <<std::endl;
        std::cout << std::endl;
    }
    return str_vec;
}



int main() {
   PriorityQueue<string> queue;
   queue.enqueue("Ala ",1);
   queue.enqueue("kota",7);
   queue.enqueue("ma",5);
   queue.enqueue("a kot ma ale",45);
   std::vector<string>beka= SplitTxtIntoWords("../data/bitwa.txt");
   for (int i = 0; i < beka.size(); i++)
   {
       std::cout<<beka[i]<<endl;
   }
   







   queue.Print();



  


}
