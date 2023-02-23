#include <iostream>
#include <string>
#include <vector>

#pragma once

class grade_Book {
    private:
        std::string file_name;
        std::vector<std::string> assignment_name_list;
        std::vector<int> score_obtainted;
        std::vector<std::string> type;
        std::vector<int> max_score;

    public:
        //default constructor/constructor with vector as data
        grade_Book();
        //contructor with all vectors
        grade_Book(std::vector<std::string> assignment_name_list, std::vector<std::string> type, std::vector<int> score_obtained, std::vector<int> max_score);

        //Getter methods
        double getIndividualGrade(std::string assignment_name);
        double getCategoryGrade(std::string assignment_type);
        double getCourseGrade();
        //helper methods
        double getWeightFromType(std::string assignment_type);
        double getOnlyCategoryTotal(std::string assignment_type);
        int getAssignmentIndex(std::string assignment_name);

        //Modifiers
        void changeAssignmentName(std::string original_name, std::string new_name);
        void changeAssignmentType(std::string name, std::string new_type);
        void changeAssignmentGrade(std::string name, int new_score);
        void changeAssignmentMaxGrade(std::string name, int new_max);

        void addNewGrade(std::string new_name, std::string new_type, int new_score, int new_max);

        void saveChanges();
};


