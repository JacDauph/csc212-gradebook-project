# Project Summary

This summary is written for the [Review Project for CSC212](https://csc-dsa.github.io/sp23/projects/gradebook.html).

This code was written by Alex Chow, Jacob Dauphinais, Peter Majdalani, and Kevin Lattuada.

## Premise

When compiled (following the compilation instructions) and run (following the runtime instructions), this code will take in a formatted text file (see test files or instructions) and allow you to view grades of any assignment within the test file, the grade of a specific type or section of assignment (such as labs, assignments, exams, etc.) and the cumulative grade of the course.

The program also allows further modification of the text file, allowing for the addition of new assignments to the file, as well as complete modification of the name, type, score, and max score of the assignment specified.


## Brief Code Explanation

### Classes

`GradeBook` - This is the only class in the project, which contains the methods detailed below. It has members `file_name`, `names`, `types`, `scores`, and `max_scores` which are the name of the input file, a vector of all assignment names, a vector of all assignment types, a vector of all scores obtained, and a vector of all max scores for the assignments, respectively.

### Methods 

#### GradeBook

`getIndividualGrade` - Given a specified assignment name, print out the name and grade of that assignment. This also returns the individual assignment's grade.

`getCategoryGrade` - Given a specified assignment type/category, print out all assignments in that category, their grades, and the cumulative grade for the category. This also returns the category grade.

`getCourseGrade` - Print out the following given a number input:
- (INPUT 1) Print out all assignments, their grades, and type/category grades (the same as `getCategoryGrade`) for each category, as well as the cumulative grade for all assignments.
- (INPUT 2) Print out all type/category grades and the cumulative grade for all assignments.
- (INPUT 3) Print out the cumulative grade for all assignments.

`getIndividualNoPrint` - Returns the individual assignment's grade. Does not print anything.

`getCategoryNoPrint` - Returns the type/category grade. Does not print anything.

`getAssignmentIndex` - Returns the index of a specified assignment name. If the name does not exist, return -1.

`changeAssignmentName` - Changes the name of a specified assignment.

`changeAssignmentType` - Changes the type of a specified assignment.

`changeAssignmentGrade` - Changes the score of a specified assignment (NOTE: This does not changed the calculated grade to what is specified, only the "score out of" portion).

`changeAssignmentMaxGrade` - Changes the max score of an assignment (NOTE: This does not changed the calculated grade to what is specified).

`addNewGrade` - Adds a newly formatted grade to the file.

`saveChanges` - Saves all changes made within the program to the inputted file.
