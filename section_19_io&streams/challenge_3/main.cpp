// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include <sstream>

int main() 
{
    std::ifstream in_file;
    in_file.open("./romeoandjuliet.txt");

    if (in_file)
    {
        std::string input, line;
        int word_count = 0;
        
        std::cout << "Enter the substring to search for: ";    
        std::cin >> input;

        while (!in_file.eof())
        {
            std::getline(in_file, line);
            for (size_t i = 0; i < line.size(); ++i)
                if (line.substr(i, input.size()) == input)
                    ++word_count;
        }

        std::cout << 0 << " words were searched...\nThe substring " << input << " was found " << word_count << " times\n";
    }
    else
    {
        std::cerr << "File did not open" << std::endl;
        return 1;
    }

    in_file.close();
    return 0;
}
