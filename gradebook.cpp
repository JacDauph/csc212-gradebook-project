
#include <iostream>
#include <fstream>
#include "gradebook.h"

grade_Book::grade_Book(){}

grade_Book::grade_Book(std::vector<std::string> assignment_name_list, std::vector<std::string> type, std::vector<int> score_obtained, std::vector<int> max_score){}
       
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


double grade_Book::getWeightFromType(std::string assignment_type){ 
       if (assignment_type == "lab"){
            return 0.2;

        }
        else if(assignment_type == "homework"){
            return 0.2;
        }
        else if(assignment_type == "Review Project"){
            return 0.15;
        }
        else if(assignment_type == "Final Project"){
            return 0.35;
        }
        else if(assignment_type == "Final Exam"){
            return 0.1;
        }
        else{
            std::cout << "Type not available" << "\n";
             return 0.0;
        }
      }

double grade_Book::getOnlyCategoryTotal(std::string assignment_type){
       
    std::vector <int> temp_indexes;
    for(int i = 0; i< this->type.size(); i++){
        if(this->type[i] == assignment_type ){
            temp_indexes.push_back(i);
        }
    }
    double add_nums;
    for(int j =0; j< temp_indexes.size(); j++){
        add_nums+= this->score_obtained[temp_indexes[j]];

    }
    add_nums = add_nums/ temp_indexes.size();
    double weight = getWeightFromType(assignment_type);
    double cat_total =  add_nums*weight;
    return cat_total;
}

int grade_Book::getAssignmentIndex(std::string assignment_name){
    
    for(int i = 0; i < this->assignment_name_list.size(); i ++){
        if(assignment_name_list[i] == assignment_name){
            
            return i;
        }

    }
    std::cout<< "Not Found" << "\n";
    return -1;
}
      

// Modifiers
void GradeBook::changeAssignmentName(std::string original_name, std::string new_name){
    // Retrieves the index of the name provided by the user
    int index = getAssignmentIndex(original_name);

    // Sets that element at the index retrieved above to the new name inserted by the user
    this->names.at(index) = new_name;
}
void GradeBook::changeAssignmentType(std::string name, std::string new_type){
    // Retrieves the index of the name provided by the user
    int index = getAssignmentIndex(name);

    // Sets that element at the index retrieved above to the new type inserted by the user
    this->types.at(index) = new_type;
}
void GradeBook::changeAssignmentGrade(std::string name, int new_score){

    // Retrieves the index of the name provided by the user
    int index = getAssignmentIndex(name);

    // Sets that element at the index retrieved above to the new score inserted by the user
    this->scores.at(index) = new_score;
}

void GradeBook::changeAssignmentMaxGrade(std::string name, int new_max){

    // Retrieves the index of the name provided by the user
    int index = getAssignmentIndex(name);

    // Sets that element at the index retrieved above to the new score inserted by the user
    this->max_scores.at(index) = new_max;
}

void GradeBook::addNewGrade(std::string new_name, std::string new_type, int new_score, int new_max){
    // Pushes the inserted (by user) information into the respected vectors
    this->names.push_back(new_name);
    this->types.push_back(new_type);
    this->scores.push_back(new_score);
    this->max_scores.push_back(new_max);
}

void GradeBook::saveChanges(){
    std::ofstream updatedFile(this->file_name);

    for(int i = 0; i < this->types.size(); i++){
        // This line will append a new line to the file, the line contains the new appended grade that was added
        // in the addNewGrade method
        updatedFile << this->names.at(i) << ' ' << this->types.at(i) << ' ' << this->scores.at(i) << ' ' << this->max_scores.at(i) << std::endl;
    }

    updatedFile.close();
}