// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>

int main() {
    std::ifstream in_file;
    in_file.open("./romeoandjuliet.txt");
    std::ofstream out_file;
    out_file.open("./linenum.txt");
    std::string line;
    unsigned int line_number = 1;

    if (!in_file)
    {
        std::cerr << "Error opening in_file" << std::endl;
        return 1;
    }
    else if (!out_file)
    {
        std::cerr << "Error opening out_file" << std::endl;
        return 1;
    }
    std::cout << "in_file and out_file open" << std::endl;
    while (!in_file.eof())
    {
        std::getline(in_file, line);
        if (line.size() == 0) // Get rid of this condition to have lines numbers before every line
            out_file << std::endl;
        else if (line_number < 10)
            out_file << "   " << std::to_string(line_number) << " " << line << std::endl;
        else if (line_number < 100)
            out_file << "  " << std::to_string(line_number) << " " << line << std::endl;
        else if (line_number < 1000)
            out_file << " " << std::to_string(line_number) << " " << line << std::endl;
        ++line_number;
    }
    in_file.close();
    out_file.close();

    return 0;
}

