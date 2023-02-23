
#include <iostream>
#include "gradebook.h"

grade_Book::grade_Book(){}

grade_Book::grade_Book(std::vector<int> score_obtainted,std::vector<std::string> type, std::vector<std::string> max_score){}
       
double grade_Book::getIndividualGrade(std::string assignment_name){return 0.0;}
double grade_Book::getCategoryGrade(std::string assignment_type){return 0.0;}
double grade_Book::getCourseGrade(int option){return 0.0;}


double grade_Book::getWeightFromType(std::string assignment_type){return 0.0;}
double grade_Book::getOnlyCategoryTotal(std::string assignment_type){return 0.0;}
int grade_Book::getAssignmentIndex(std::string assignment_name){
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
      
void grade_Book::changeAssignmentName(std::string p_assignment_name, std::string p_new_name){}
void grade_Book::changeAssignmentType(std::string p_assignment_name, std::string p_new_type){}
void grade_Book::changeAssignmentGrade(std::string p_assignment_name, int p_new_score){}
void grade_Book::changeAssignmentMaxGrade(std::string p_assignment_name, int p_new_max_score){}


void grade_Book::addNewGrade(std::string p_new_name, std::string p_new_type, int p_new_score, int p_new_max_score){}

   
void grade_Book::saveChanges(){}
