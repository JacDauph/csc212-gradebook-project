
#include <iostream>
#include <fstream>
#include "gradebook.h"

grade_Book::grade_Book(){}
       
grade_Book::grade_Book(std::vector<int> score_obtainted,std::vector<std::string> type, std::vector<int> max_score){}
       
double grade_Book::getIndividualGrade(std::string assignment_name){}
double grade_Book::getCategoryGrade(std::string assignment_type){}
double grade_Book::getCourseGrade(int option){}

double grade_Book::getWeightFromType(std::string assignment_type){}
double grade_Book::getOnlyCategoryTotal(std::string assignment_type){}
int grade_Book::getAssignmentIndex(std::string assignment_name){}

/*
This method will change the original assignment name to a user specified assignment name
*/
void grade_Book::changeAssignmentName(std::string p_assignment_name, std::string p_new_name){

    int index = getAssignmentIndex(p_assignment_name);
    this->assignment_name_list.at(index) = p_new_name;

}

/*
This method will change the original assignment type to a user specified type
*/
void grade_Book::changeAssignmentType(std::string p_assignment_name, std::string p_new_type){

    int index = getAssignmentIndex(p_assignment_name);
    this->type.at(index) = p_new_type;

}

/*
This method will change the original assignment score to a user specified score
*/
void grade_Book::changeAssignmentGrade(std::string p_assignment_name, int p_new_score){

    int index = getAssignmentIndex(p_assignment_name);
    this->score_obtained.at(index) = p_new_score;

}

/*
This method will change the original assignment max score to a user specified max score
*/
void grade_Book::changeAssignmentMaxGrade(std::string p_assignment_name, int p_new_max_score){

    int index = getAssignmentIndex(p_assignment_name);
    this->max_score.at(index) = p_new_max_score;

}

/*
This method will append new information based on user input for each member vector
*/
void grade_Book::addNewGrade(std::string p_new_name, std::string p_new_type, int p_new_score, int p_new_max_score){

    this->assignment_name_list.push_back(p_new_name);
    this->type.push_back(p_new_type);
    this->score_obtained.push_back(p_new_score);
    this->max_score.push_back(p_new_max_score);

}

/*
This method creates a file of the same name as the input file and writes the new updated information if applicable
*/
void grade_Book::saveChanges(){

    std::ofstream updatedFile(this->file_name);

    for(int i = 0; i < this->type.size(); i++){
        updatedFile << this->assignment_name_list.at(i) << ' ' << this->type.at(i) << ' ' << this->score_obtained.at(i) << ' ' << this->max_score.at(i) << std::endl;
    }

    updatedFile.close();

}
