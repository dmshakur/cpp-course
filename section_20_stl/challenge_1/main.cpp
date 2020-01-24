// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>

std::string format_string(const std::string& s)
{
    std::string temp = s;

    for (size_t i = 0; i < temp.size(); ++i) // Formats String
    {
        if (temp[i] <= 122 && temp[i] >= 97)
            temp[i] -= 32;
        if (temp[i] < 65 || temp[i] > 90)
            temp.erase(temp.begin() + i);
    }

    return temp;
}

bool is_palindrome(const std::string& s)
{
    std::string temp = format_string(format_string(s));
    std::deque<char> sequence;

    for (char character : temp)
        sequence.push_back(character);

    while(sequence.size() != 0)
    {
        if (sequence.front() == sequence.back())
        {
            sequence.pop_front();
            if (sequence.size() > 0)
                sequence.pop_back();
        }
        else if (sequence.front() != sequence.back())
            return false;
    }
    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;

    for(const auto& s : test_strings)
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;

    std::cout << std::endl;

    // std::cout << std::endl << is_palindrome(test_strings[test_strings.size() - 1]) << std::endl;

    return 0;
}