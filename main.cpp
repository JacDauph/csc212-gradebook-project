#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>


int main(int argc, char*argv[]) {
    std::string file_name = argv[1];

    std::ifstream inFile(file_name);

    std::string line;

    std::vector<std::string> assignment_name;
    std::vector<std::string> assignment_type;
    std::vector<int> obtained_grade;
    std::vector<int> max_score;

    while(std::getline(inFile,line)){
        //std::cout << line << std::endl; working
        std::stringstream ss(line);
        int grade, score;
        std::string name, type;

        ss << line;
        ss >> name >> type >> grade >> score;

        assignment_name.push_back(name);
        assignment_type.push_back(type);
        obtained_grade.push_back(grade);
        max_score.push_back(score);


    }
    
    grade_book = new GradeBook(file_name, names, types, scores, max_scores);

    int choice;

    do{
        std::cout << "Please insert a number, based on the options below:" << std::endl;
        std::cout << "1 - Get individual grade" << "\n"
                "2 - Get category grade" << "\n"
                "3 - Get course grade" << "\n"
                "4 - Modify assignment name" << "\n"
                "5 - Modify type name in file" << "\n"
                "6 - Modify assignment grade in file" << "\n"
                "7 - Modify assigment max grade in file" << "\n"
                "8 - Add a new grade to file" << "\n"
                "9 - Save changes to file" << "\n"
                "0 - Exit Program" << std::endl;
        std::cout << std::endl;
        std::cin >> choice;
        std::cout << std::endl;

        std::string name, type, original_name, new_name, new_type, decision, decision2;
        int option, new_score, new_max;

        switch(choice){


            case 1:

                std::cout << "Please enter the name of the assignmemt (case sensitive)" << std::endl;
                std::cout << std::endl;
                std::cin >> name;
                std::cout << std::endl;
                std::cout << "--------------------------------------------------------" << std::endl;
                grade_book->getIndividualGrade(name);

                break;
            case 2:

                std::cout << "Please enter the category (case sensitive) \n Enter one of: lab, assignment, project, exam" << std::endl;
                std::cout << std::endl;
                std::cin >> type;
                std::cout << std::endl;
                std::cout << "--------------------------------------------------------" << std::endl;
                grade_book->getCategoryGrade(type);

                break;
            case 3:

                std::cout << "Please select from the available options (type in number of option you want)." << std::endl;
                std::cout << "1 - All grades within their respective categories and a course overall" << "\n"
                                <<"\n"<<
                            "2 - Only category totals and course overall" << "\n"
                               << "\n" <<
                            "3 - Only the course overall" << std::endl;

                std::cout << std::endl;

                std::cin >> option;

                std::cout << std::endl;
                std::cout << "--------------------------------------------------------" << std::endl;
                grade_book->getCourseGrade(option);

                break;
            case 4:

                std::cout << "Please enter the original assignment name and the new assignment name separated by a single white space (case sensitive)" << std::endl;
                std::cout << std::endl;
                std::cin >> original_name >> new_name;
                std::cout << std::endl;

                grade_book->changeAssignmentName(original_name,new_name);

                break;
            case 5:

                std::cout << "Please enter the name of the assignment and the new type name separated by a single white space (case sensitive)" << std::endl;
                std::cout << std::endl;
                std::cin >> name >> new_type;
                std::cout << std::endl;

                grade_book->changeAssignmentType(name,new_type);

                break;
            case 6:

                std::cout << "Please enter the name of the assignment and the new grade separated by a single white space (case sensitive)" << std::endl;
                std::cout << std::endl;
                std::cin >> name >> new_score;
                std::cout << std::endl;

                grade_book->changeAssignmentGrade(name,new_score);
            break;
            case 7:

                std::cout << "Please enter the name of the assignment and the new max score separated by a single white space (case sensitive)" << std::endl;
                std::cout << std::endl;
                std::cin >> name >> new_max;
                std::cout << std::endl;

                grade_book->changeAssignmentMaxGrade(name,new_max);
            break;
            case 8:

                std::cout << "Please enter the new information in this order separated by single white spaces (NO COMMAS):" << std::endl;
                std::cout << "assignment_name, category, score, max_score" << std::endl;
                std::cout << std::endl;
                std::cin >> new_name >> new_type >> new_score >> new_max;
                std::cout << std::endl;

                grade_book->addNewGrade(new_name, new_type, new_score, new_max);
                break;
            case 9:

                std::cout << "Would you like to save the changes made to the file? (y/n)" << std::endl;
                std::cout << std::endl;
                std::cin >> decision;
                std::cout << std::endl;

                if(decision == "y"){
                    std::cout << "WARNING: Committing these changes will effectively overwrite your file" << "\n"
                                << "\n" <<
                                "Are you sure you want to save the changes (y/n)" << std::endl;
                    std::cout << std::endl;
                    std::cin >> decision2;
                    std::cout << std::endl;
                    if(decision2 == "y"){
                        grade_book->saveChanges();
                    }else{
                        std::cout << "Exiting saved changes..." << std::endl;
                    }
                }else if (decision == "n"){
                    std::cout << "Exiting saved changes..." << std::endl;
                }else{
                    std::cout << "Error: Invalid option" << std::endl;
                }

            break;
            case 0:
                break;
            default:
                std::cout << "Not a valid option, Please try again." << std::endl;
                std::cout << std::endl;
                std::cout << "--------------------------------------------------------" << std::endl;
                break;


        }


    }while(choice != 0);


    delete grade_book;
    
    return 0;
}
