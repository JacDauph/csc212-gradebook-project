# Runtime Instructions:
```mermaid
flowchart TB
    subgraph Start
    start(Please insert a number, based on the options below:)-->a1(1 - Get individual grade)
    start(Please insert a number, based on the options below:)--> a2(2 - Get category grade)
    start(Please insert a number, based on the options below:)--> a3(3 - Get course grade)
    
    start(Please insert a number, based on the options below:)--> a4(4 - Modify assignment name)
    
    start(Please insert a number, based on the options below:)--> a5(5 - Modify type name in file)
    
    start(Please insert a number, based on the options below:)--> a7(7 - Modify assigment max grade in file)
    
    start(Please insert a number, based on the options below:)--> a8(8 - Add a new grade to file)
    
    
    start(Please insert a number, based on the options below:)--> a9(9 - Save changes to file)
    
    
    end
   
  
    
    a1(1 - Get individual grade) ---> individual(Please enter the name of the assignmemt)
    
    a2(2 - Get category grade) --> cat(Please enter the category.)
    
    a3 --> course(Please select from the available options)
    
    
    course --> all(1 - All grades within their respective categories and a course overall)
    
    course --> cat_course(2 - Only category totals and course overall)

    course --> course_only(3 - Only the course overall)

    
    




```

Once the program has run, it will ask "Please insert a number, based on the options below:", in which 10 different options are given.

### The inputs of each option are case sensitive to the dataset for a .txt file

<br>

### Entering a 1, will allow the user to get a specific grade of any assignment, lab, project, or final exam.

* However, entering an input not within the text file will result in a message that says:

--------------------------------------------------------
*Error: Assignment name not in gradebook*

<br>

### Entering a 2, will allow the user to search for a category grade.
In which it will output all of the assignments in that category, their grades, and the category grade.


--------------------------------------------------------
Name of Assignment: 

Grade: 


<br>

#### Entering a 3, will give an output to the course grade, which includes 3 different options.

*The first option is all the grades in the respective categories, the category grades, and the course overall grade.


*The second option will output all the category grades and the course overall grade.


*The third option will output only the course overall grade


<br>

### Options 4 to 8 are changes done directly to the file, but will not be saved unless option 9 for saving changes is inputted by the user

<br>

#### Entering a 4, will the user to change the name of an assignment name

*This is done by entering the original assignment name first and a whitespace between the new desired name to replace the original name.

<br>

#### Entering a 5, will the user to change the name of a specific assignment to a different category type


*This is done by entering the assignment name first and a whitespace between the new category to place the assignment in.

<br>



#### Entering a 6, will the user to change the grade of a specific assignment


*This is done by entering the assignment name first and a whitespace between the grade to give the assignment

<br>

#### Entering a 7, will the user to change the max score grade of a specific assignment


*This is done by entering the assignment name first and a whitespace between the max score grade to give the assignment

<br>

#### Entering a 8, allows the user to add an entire new assignment with a category, grade obtained, and a max grade.


*This is done by entering the new assignment name, category, grade obtained, and max grade.

*ALL WITH WHITE SPACE BETWEEN AND NO COMMAS IN BETWEEN*

<br>

#### Entering a 9 will save all changes desired from inputs to the original file

<br>

### Entering a 0 will completely exit out the program, leaving any progress not saved from input 9 to be gone.
