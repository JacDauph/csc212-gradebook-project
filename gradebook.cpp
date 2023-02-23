
#include <iostream>
#include <fstream>
#include "gradebook.h"

grade_Book::grade_Book(){}

grade_Book::grade_Book(std::vector<std::string> assignment_name_list, std::vector<std::string> type, std::vector<int> score_obtained, std::vector<int> max_score){}
       
double GradeBook::getIndividualGrade(std::string name){
    // Gets the index of the specified assignment name
    int idx = getAssignmentIndex(name);
    double output;

    // If the name is in the this->names list, else run an error message and return
    if(idx != -1){

        // Set the output to the score you got over the max score possible
        // The 1.0 numbers are for escaping integer division and the *100 makes it so the result is not a decimal
        output = (this->scores[idx]*1.0) / (this->max_scores[idx]*1.0)*100;
        std::cout << "Name of Assignment: " << this->names[idx] << std::endl << "Grade: " << output << std::endl << std::endl;
    }else{
        // Case for if the option entered was invalid
        std::cout << "Error: Assignment name not in gradebook" << std::endl;
        return 0;
    }

    std::cout << "--------------------------------------------------------" << std::endl;

    // Returns grade out of 100
    return output;
}

double GradeBook::getCategoryGrade(std::string type){
    double output;

    // If the type is in the this->types list, else run an error message and return
    if (std::find(this->types.begin(), this->types.end(), type) != this->types.end()){
        // Counter is used for averaging the grade for the course
        int counter = 0;

        // For the number of types in this->types, check if the user specified type matches
        // If so, run getIndividualGrade with the name in that index and add one to the counter
        for(int i = 0; i < this->types.size(); i++){
            if(this->types[i] == type){
                output += getIndividualGrade(this->names[i]);
                counter++;
            }
        }

        // Divide the output by the counter, averaging the category grade
        output /= counter;

        std::cout << std::endl << "Category Name: " << type << std::endl << "Category Grade: " << output << std::endl << std::endl;

    }else{
        // Case for if the option entered was invalid
        std::cout << "Error: Type not in gradebook" << std::endl;
        return 0;
    }

    std::cout << "--------------------------------------------------------" << std::endl;

    // Returns category grade out of 100
    return output;
}

//all grades within their respective categories and a course overall
//only category totals and course overall
//only the course overall
double GradeBook::getCourseGrade(int option){
    double output, assign, proj, lab, exam;

    switch(option){
        case 1: // All grades within their respective categories and a course overall

            // Runs getCategoryGrade for all categories (this in turn prints out all grades)
            // This also adds the method outputs to the output variable after multiplying it by the weight, which is from the course website
            // This weighted grading method is standard:      Weighted Grade = w1 * g1 + w2 * g2 + ... + w_n * g_n
            // The hardcoded weights (in the form of the decimal numbers) are taken from the course website
            output += this->getCategoryGrade("lab") * .2;
            output += this->getCategoryGrade("assignment") * .2;
            output += this->getCategoryGrade("project") * .5;
            output += this->getCategoryGrade("exam") * .1;
            std::cout << std::endl << "Course Grade: " << output << std::endl << std::endl;
            break;

        case 2: // Only category totals and course overall

            // Assigns values for easier reading, utilizing getCategoryNoPrint so that no other grades are printed
            assign = this->getCategoryNoPrint("assignment");
            proj = this->getCategoryNoPrint("project");
            lab = this->getCategoryNoPrint("lab");
            exam = this->getCategoryNoPrint("exam");

            // Prints all of the category grades in order, as the above code does not print anything (this is so that these functions can be unique with their printing)
            std::cout << std::endl << "Category Name: lab" << std::endl << "Category Grade: " << lab << std::endl << std::endl;
            std::cout << std::endl << "Category Name: assignment" << std::endl << "Category Grade: " << assign << std::endl << std::endl;
            std::cout << std::endl << "Category Name: project" << std::endl << "Category Grade: " << proj << std::endl << std::endl;
            std::cout << std::endl << "Category Name: exam" << std::endl << "Category Grade: " << exam << std::endl << std::endl;

            // This also adds the method outputs to the output variable after multiplying it by the weight, which is from the course website
            // This weighted grading method is standard:      Weighted Grade = w1 * g1 + w2 * g2 + ... + w_n * g_n
            // The hardcoded weights (in the form of the decimal numbers) are taken from the course website
            output += lab * .2;
            output += assign * .2;
            output += proj * .5;
            output += exam * .1;
            std::cout << std::endl << "Course Grade: " << output << std::endl << std::endl;
            break;

        case 3: // Only the course overall

            // Runs the getCategoryNoPrint function for each type "lab" "assignment" "project" "exam"
            // This also adds the method outputs to the output variable after multiplying it by the weight, which is from the course website
            // This weighted grading method is standard:      Weighted Grade = w1 * g1 + w2 * g2 + ... + w_n * g_n
            // The hardcoded weights (in the form of the decimal numbers) are taken from the course website
            output += this->getCategoryNoPrint("lab") * .2;
            output += this->getCategoryNoPrint("assignment") * .2;
            output += this->getCategoryNoPrint("project") * .5;
            output += this->getCategoryNoPrint("exam") * .1;
            std::cout << std::endl << "Course Grade: " << output << std::endl << std::endl;
            break;

        default:

            // Default case for if the option entered was invalid
            std::cout << "Error: Invalid option" << std::endl << std::endl;
            return 0;
            break;
    }

    std::cout << "--------------------------------------------------------" << std::endl;

    return output;
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
