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
        grade_Book(std::vector<std::string> assignment_name_list, std::vector<std::string> type, std::vector<int> score_obtained, std::vector<int> max_score)

        //Getter methods
        double getIndividualGrade(std::string assignment_name);
        double getCategoryGrade(std::string assignment_type);
        double getCourseGrade();
        //helper methods
        double getWeightFromType(std::string assignment_type);
        double getOnlyCategoryTotal(std::string assignment_type);
        int getAssignmentIndex(std::string assignment_name);
        //modifiers
        void changeAssignmentName(std::string p_assignment_name, std::string p_new_name);
        void changeAssignmentType(std::string p_assignment_name, std::string p_new_type);
        void changeAssignmentGrade(std::string p_assignment_name, int p_new_score);
        void changeAssignmentMaxGrade(std::string p_assignment_name, int p_new_max_score);
    
        //method for changing file
        void addNewGrade(std::string p_new_name, std::string p_new_type, int p_new_score, int p_new_max_score);
    
        //saves the changes made to file
        void saveChanges();

        



};


