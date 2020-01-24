// Section 20
// Challenge 4
// Identifying palindrome strings using a stack and queue
#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
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
    std::string temp {format_string(format_string(s))};
    std::stack<char> current_1;
    std::queue<char> current_2;

    for (size_t i = 0; i < temp.size(); ++i)
    {
        current_1.push(temp[i]);
        current_2.push(temp[i]);
    }

    while (current_1.size() > 0 && current_2.size() > 0)
    {
        if (current_1.top() == current_2.front())
        {
            current_1.pop();
            current_2.pop();
        }
        else if (current_1.top() != current_2.front())
            return false;
    }
    return true;
}

int main()
{
    std::vector<std::string> test_strings { "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}