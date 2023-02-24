#include <iostream>
#include <string>
#include <vector>

#pragma once

class GradeBook {
    private:
        std::string file_name;
        std::vector<std::string> names;
        std::vector<int> scores;
        std::vector<std::string> types;
        std::vector<int> max_scores;

    public:

        // Constructor with all vectors
        GradeBook(std::string file_name, std::vector<std::string> names, std::vector<std::string> types, std::vector<int> scores, std::vector<int> max_scores);

        // Main getters
        double getIndividualGrade(std::string name);
        double getCategoryGrade(std::string type);
        double getCourseGrade(int option);


        // Helper methods
        double getIndividualNoPrint(std::string name);
        double getCategoryNoPrint(std::string type);
        int getAssignmentIndex(std::string name);

        //Modifiers
        void changeAssignmentName(std::string original_name, std::string new_name);
        void changeAssignmentType(std::string name, std::string new_type);
        void changeAssignmentGrade(std::string name, int new_score);
        void changeAssignmentMaxGrade(std::string name, int new_max);

        void addNewGrade(std::string new_name, std::string new_type, int new_score, int new_max);

        void saveChanges();
};


