
#include <iostream>
#include "gradebook.h"

grade_book();
       
grade_book(std::vector<int> score_obtainted,std::vector<std::string> type, std::vector<std::string> max_score);
       
double getIndividualGrade(std::string assignment_name);
double getCategoryGrade(std::string assignment_type);
double getCourseGrade(int option);

double getWeightFromType(std::string assignment_type);
double getOnlyCategoryTotal(std::string assignment_type);
int getAssignmentIndex(std::string assignment_name);
      
void changeAssignmentName(std::string p_assignment_name, string p_new_name);
void changeAssignmentType(std::string p_assignment_name, string p_new_type);
void changeAssignmentGrade(std::string p_assignment_name, int p_new_score);
void changeAssignmentMaxGrade(std::string p_assignment_name, int p_new_max_score);
    
        
void addNewGrade(std::string p_new_name, std::string p_new_type, int p_new_score, int p_new_max_score);
    
   
void saveChanges();
