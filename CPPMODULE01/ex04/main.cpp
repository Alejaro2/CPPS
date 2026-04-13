#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{

    if (argc != 4)
    {
        std::cerr << "Error: Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: Search string (s1) cannot be empty." << std::endl;
        return (1);
    }


    std::ifstream infile(filename.c_str());

    if (!infile.is_open())
    {
        std::cerr << "Error: Cannot open input file: " << filename << std::endl;
        return (1);
    }

    std::string content;
    std::getline(infile, content, '\0');
    infile.close();

    size_t pos = 0;
    while (true)
    {
        pos = content.find(s1, pos);
        if (pos == std::string::npos)
            break;

        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }

    std::string out_filename = filename + ".replace";
    std::ofstream outfile(out_filename.c_str());

    if (!outfile.is_open())
    {
        std::cerr << "Error: Cannot create output file." << std::endl;
        return (1);
    }

    outfile << content;
    outfile.close();

    return (0);
}