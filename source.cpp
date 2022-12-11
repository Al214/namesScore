#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>

int alphabetValue(char);

int main()
{
    std::ifstream file("p022_names.txt");
    std::vector<std::string> names;
    if(file)
    {
        //Extracting words from file into vector
        std::string name;
        while(!file.eof())
        {
            std::getline(file, name, ',');
            names.push_back(name);
        }
        file.close();

        //Sorting and then computing values
        std::sort(names.begin(), names.end());
        int index = 1;
        unsigned long long sum = 0;
        for(auto word: names)
        {
            int nameValue = 0;
            for(int letter = 0; letter < word.size(); letter++)
            {
                nameValue += alphabetValue(word.at(letter));
            }
            nameValue *= index;
            sum += nameValue;
            index++;
        }
        std::cout << "The sum is " << sum << std::endl;
    }
    else
        std::cout << "File not found.\n";
    return 0;
}

int alphabetValue(char ch)
{
    if(std::isupper(ch))
        return ch - 'A' + 1;
    else
        return 0;
}