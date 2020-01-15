#include <iostream>
#include <fstream>

int main()
{
    std::ifstream in_file;
    in_file.open("../poem.txt");
    if (!in_file)
    {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    

    in_file.close();
    return 0;
}