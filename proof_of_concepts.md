# Overview of Project
1. Program
    - successful compilation of data for each member, respectively
    - required viewable outputs as documented
    - files
    - main.cpp
    - gradebook.cpp
    - gradebook.h
2. Documentation
    - README.md
    - summary
    - planning
    - compilation instructions
    - runtime instructions
    - sample input/output screenshots with brief explanations of the images used
3. Walkthrough
    - recorded walkthrough
4. Datasets
    - mock data for each member


# Proof of Planning

## What we need
Suggestions by Jacob Dauphinais:
- Write a program to successfully evaluate individual deliverables from CSC 212 to provide an accurate output of semester course grades. Viewable outputs should include:
  - individual: returns an individual deliverable name and grade
  - category: returns all grades from the category and category total
  - course: ability to return each of the following:
    - all grades within their respective categories and a course overall
    - only category totals and course overall
    - only the course overall
 - clear, conscientious comments embedded within the your code
 - successfully compiles accurate output
 - use read input to take in grades from an external file
 - use write output to write any changes back to your input file

Suggestions by Alex Chow:
- Use vectors or class inheritance for storing category grades(labs and assignments).
- Set a default grade (0 value)  or default “N/A” for grades not existing?
- Tokenize our txt files, separating the text and the grade values (First line will likely just be the names)
- Calculate the current grade with a formula of some sort (Just use size of vector for category grades)
- Use the index or count of our category grades to differentiate each specific lab/assignment
- Allow user to add or remove a grade to a category and save it to the file
- Allow the user to grab a specific lab or assignment grade.



# Pseudocode (for class)
![image](https://user-images.githubusercontent.com/90423821/221441695-b89c1f7e-0c93-4bed-bb21-310a6cf5dd02.png)

## Responsibilities of Each Member

Peter Majdalani:
- Begin coding main (get the vectors filled with the needed data)
- Implement addNewGrade
- Implement changeAssignmentName()

Alex Chow:
- Class methods(helpers and some modifiers)
- Implement changeAssignment Grade, change Assignment Max Grade
- getAssignmentIndex, getWeightFromType getOnlyCategoryTotal

Kevin Lattuada:
- Modifiers:  changeAssignmentName, changeAssignmentType
- Outputs:  getIndivual, getCategory, get CourseGrade
- Create mock datasets

Jacob Dauphinais:
- Add comments to all methods in the gradebook.cpp file concerning the function
- Create constructors
- Begin creating the change and saveChanges methods



