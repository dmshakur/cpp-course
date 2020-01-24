#include <iostream>
#include <iomanip>
#include <fstream>

int main()
{
    std::ifstream responses;
    responses.open("./responses.txt");

    if (!responses)
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string answer_key {}, name {}, response {};
    unsigned int score;

    responses >> answer_key;
    while (responses >> name >> response)
    {
        for (size_t i {}; i < response.length(); ++i)
        {
            if (answer_key.at(i) == response.at(i))
                score++;
        }
        
        std::cout << name <<  " : " << score << "/5" << std::endl;
        score = 0;
    }

    responses.close();
    
    return 0;
}