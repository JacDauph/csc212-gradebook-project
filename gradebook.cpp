
#include <iostream>
#include "gradebook.h"

grade_book();
       
grade_book(std::vector<int> score_obtainted,std::vector<std::string> type, std::vector<std::string> max_score);
       
double getIndividualGrade(std::string assignment_name);
double getCategoryGrade(std::string assignment_type);
double getCourseGrade(int option);

double getWeightFromType(std::string assignment_type);
double getOnlyCategoryTotal(std::string assignment_type);
int getAssignmentIndex(std::string assignment_name){
    bool check;
    for(int i = 0; i < this->assignment_name_list.size(); i ++){
        if(assignment_name_list[i] == assignment_name){
            check = true;
            return i;
        }

    }
    std::cout<< "Not Found" << "\n";
    return false;
}
      
void changeAssignmentName(std::string p_assignment_name, string p_new_name);
void changeAssignmentType(std::string p_assignment_name, string p_new_type);
void changeAssignmentGrade(std::string p_assignment_name, int p_new_score){
    int index = getAssignmentIndex(p_assignment_name);
    this-> score_obtained.at(index) = p_new_score;

}
void changeAssignmentMaxGrade(std::string p_assignment_name, int p_new_max_score);
    
        
void addNewGrade(std::string p_new_name, std::string p_new_type, int p_new_score, int p_new_max_score);
    
   
void saveChanges();
