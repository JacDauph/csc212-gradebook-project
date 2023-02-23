
#include <iostream>
#include "gradebook.h"

grade_Book::grade_Book(){}

grade_Book::grade_Book(std::vector<int> score_obtainted,std::vector<std::string> type, std::vector<std::string> max_score){}
       
double grade_Book::getIndividualGrade(std::string assignment_name){
    //creates an idex of the passed in assignment name
    int idx;
    idx = getAssignmentIndex(assignment_name);


    //goes to the score_obtained vector to obtain and return the score of that assignment
    //score as an percentage
    //double score = ( (score_obtainted[idx] / max_score[idx]) * 100);
    double score = score_obtainted[idx];

    //print results
    //std::cout << score << std::endl; //printed
    return score;

}

double grade_Book::getCategoryGrade(std::string assignment_type){
    double scoreTotal, maxTotal;
    scoreTotal = 0;
    maxTotal = 0;
    //goes through the scores, if the index of the type equals the passed in assignment type->
    //it will add that score of the assignment to the scoreTotal, and the max score of the assignment to maxTotal
    for(int i = 0; i < score_obtainted.size(); i++){
        if(type[i] == assignment_type){
            scoreTotal += score_obtainted[i];
            maxTotal += max_score[i];
        }
    }

    double catGrade = scoreTotal / maxTotal;

    //print results
    //std::cout << catGrade << std::endl;
    return catGrade;
}

//all grades within their respective categories and a course overall
//only category totals and course overall
//only the course overall
double grade_Book::getCourseGrade(){
    double courseScore, courseTotal;
    courseScore = 0;
    courseTotal = 0;

    double courseGrade = 0;

    for(int i = 0; i < score_obtainted.size(); i++){
        courseScore += score_obtainted[i];
        courseTotal += max_score[i];
    }

    courseGrade = ((courseScore / courseTotal) * 100);
    return courseGrade;
}

double grade_Book::getWeightFromType(std::string assignment_type){return 0.0;}
double grade_Book::getOnlyCategoryTotal(std::string assignment_type){return 0.0;}
int grade_Book::getAssignmentIndex(std::string assignment_name){return 0;}
      
void grade_Book::changeAssignmentName(std::string p_assignment_name, std::string p_new_name){
    int idx;
    idx = getAssignmentIndex(p_assignment_name);
    assignment_names[idx] = p_new_name;
}
void grade_Book::changeAssignmentType(std::string p_assignment_name, std::string p_new_type){

}


void grade_Book::changeAssignmentGrade(std::string p_assignment_name, int p_new_score){}
void grade_Book::changeAssignmentMaxGrade(std::string p_assignment_name, int p_new_max_score){}


void grade_Book::addNewGrade(std::string p_new_name, std::string p_new_type, int p_new_score, int p_new_max_score){}
    
   
void grade_Book::saveChanges(){}
