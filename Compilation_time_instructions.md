# **Compliation Time Instructions:**
### The .txt file is the dataset/gradebook used, where grades can be any .txt file name with the similar dataset content.

## With CLion
1. Open CLion
2. Create a new project with C++11
3. Add the main.cpp, gradebook.cpp, gradebook.h, and desired text files to your project.
## Make sure the .txt file is within cmake-build-debug and within the file of testing in there. The main.cpp should replace the old main and the new files should be added in the same area as the main.cpp

4. Under CMakeList.txt make sure the add_executeable is *"add_executable(gradebook main.cpp gradebook.cpp gradebook.h)"*
5. If the program is going to be ran automattically, over in "Open 'Edit/Debug configurations' dialog" click edit configurations
6. Inside Program Arguments add in the name of your text file. For example: (grades.txt)
7. Click the run program button.

## If not using CLion
1. Open up your IDE
2. Create a new Project
3. Add all the files to your program
4.  Inside the terminal enter: *g++ main.cpp gradebook.cpp -o prog* 
5.  After : *./prog grades.txt*
6.  Or: *g++ main.cpp gradebook.cpp -o prog && ./prog grades.txt*

1. * Or: *g++ -std=c++11 main.cpp gradebook.cpp -o prog*
2. *./prog grades.txt*

### "grades" can be substituted with the name of the file for testing.





