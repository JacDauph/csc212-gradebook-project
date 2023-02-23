
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


double GradeBook::getIndividualNoPrint(std::string name){
    // Gets the index of the specified assignment name
    int idx = getAssignmentIndex(name);
    double output;

    // If the name is in the this->names list, else run an error message and return
    if(idx != -1){

        // Set the output to the score you got over the max score possible
        // The 1.0 numbers are for escaping integer division and the *100 makes it so the result is not a decimal
        output = (this->scores[idx]*1.0) / (this->max_scores[idx]*1.0)*100;
    }else{

        // Case for if the option entered was invalid
        std::cout << "Error: Assignment name not in gradebook" << std::endl;
        return 0;
    }

    return output;
}
double GradeBook::getCategoryNoPrint(std::string type){
    double output;

    // If the type is in the this->types list, else run an error message and return
    if (std::find(this->types.begin(), this->types.end(), type) != this->types.end()){
        // Counter is used for averaging the grade for the course
        int counter = 0;

        // For the number of types in this->types, check if the user specified type matches
        // If so, run getIndividualGrade with the name in that index and add one to the counter
        for(int i = 0; i < this->types.size(); i++){
            if(this->types[i] == type){
                output += getIndividualNoPrint(this->names[i]);
                counter++;
            }
        }

        // Divide the output by the counter, averaging the category grade
        output /= counter;

    }else{

        // Case for if the option entered was invalid
        std::cout << "Error: Type not in gradebook" << std::endl;
        return 0;
    }

    return output;
}
int GradeBook::getAssignmentIndex(std::string name){

    // For every name in this->names, check to see if it matches the user specified name
    // If it does, return the index, else return -1
    for(int i = 0; i < this->names.size(); i++){
        if(names[i] == name){
            return i;
        }
    }

    return -1; // Assignment name is not in list
}

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
