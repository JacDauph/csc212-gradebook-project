#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>


int main(int argc, char*argv[]) {
    std::string file_name = argv[1];

    std::ifstream inFile(file_name);

    std::string line;

    std::vector<std::string> assignment_name;
    std::vector<std::string> assignment_type;
    std::vector<int> obtained_grade;
    std::vector<int> max_score;

    while(std::getline(inFile,line)){
        std::stringstream ss(line);
        int grade, score;
        std::string name, type;

        ss << line;
        ss >> name >> type >> grade >> score;

        assignment_name.push_back(name);
        assignment_type.push_back(type);
        obtained_grade.push_back(grade);
        max_score.push_back(score);


    }
    
    return 0;
}
