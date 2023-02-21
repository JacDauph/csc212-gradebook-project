#include <iostream>
#include <string>
#include <vector>
class grade_Book {
    private:
        std::string file_name;
        std::vector<int> score_obtainted;
        std::vector<std::string> type;
        std::vector<std::string> max_score; 

    public:
        //default constructor/constructor with vector as data
        grade_book();
        //contructor with all vectors
        grade_book(std::vector<int> score_obtainted,std::vector<std::string> type, std::vector<std::string> max_score);
        //Getter methods
        double getIndividualGrade(string assignment_name);
        double getCategoryGrade(string assignment_type);
        double getCourseGrade(int option);
        //helper methods
        void changeAssignmentName(std::string p_assignment_name, string p_new_name);
        void changeAssignmentType(std::string p_assignment_name, string p_new_type);
        void changeAssignmentGrade(std::string p_assignment_name, int p_new_score);
        void changeAssignmentMaxGrade(std::string p_assignment_name, int p_new_max_score);
    
        //method for changing file
        void addNewGrade(string p_new_name, string p_new_type, int p_new_score, int p_new_max_score);
    
        //saves the changes made to file
        void saveChanges();

        



};

