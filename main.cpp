/*
Quinn Alvine
9/4/2025
This code is to deal with grades. It adds grades to an array, displays them, calculates the average, finds the highest and the lowest,
and it finds all of the grades that are over the threshold.
Vectors_Challenge_2
*/


#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

bool randVisable = true; // This allows you to have the option to add in some random grades
int amountofRand = 10; // This will set the amount of random grades


void AddGrade(vector<double>& grades) { // This will add grades to the vector of grades
    cout << "Input a grade: ";
    if (double input; !(cin >> input)) { // This will check to make sure that the input is a int
        cout << "Invalid input." << endl;
        cin.clear();
    } else {
        if (input > 100 || input < 1) { // This will make sure that the input is between 1 and 100
            cout << "Please input a value that is in between 1 and 100" << endl;
        } else {
            grades.push_back(input); // This will add in the grade into the vector of grades
            cout << input << " added." << endl;
        }
    }
}

void DisplayGrades(const vector<double> &grades) { // This will display all of the grades that are in the vector
    if (grades.empty()) { // This will look to see if the vector of grades is empty and if it is it will print out the there are no grades and then it will return the functions
        cout << "There are no grades." << endl;
        return;
    }
    for (const double grade : grades) { // If there are grades this will go through all of the grades in the vector and print them out
        cout << grade << " ";
    }
    cout << endl;
}

void CalcAverageGrade(const vector<double> &grades) { // This will calculate the average of all of the grades
    if (grades.empty()) { // This will check to make sure that there are grades in the vector and if there are non it will print out that there are no grades and then it will return the function
        cout << "There are no grades." << endl;
        return;
    }
    double total = 0; // This is the variable for all of the grades added together
    for (double grade : grades) { // This will go through the vecotr and add them all to the total variable
        total += grade;
    }
    double average = total / grades.size(); // This will then calculate the average and then the next line will print it to the console
    cout << "The average grade is: " << average << endl;
}

void FindHighandLow(const vector<double> &grades) { // This will find the highest grade and the lowest grade
    if (grades.empty()) { // This will make sure that there are grades in the vector before running
        cout << "There are no grades." << endl;
        return;
    }
    double highest = grades[0]; // This will set the default value to the first value in the vector
    double lowest = grades[0]; // This will set the default value to the first value in the vector
    for (int i = 1; i < grades.size(); i++) { // This will go through all of the values in the vector
        if (grades[i] > highest) { // This will see if the value in the vector is greater than the previous one and if it is it will change the highest variable to that number
            highest = grades[i];
        }
        if (grades[i] < lowest) { // This will see if the value in the vector is less than the previous one and if it is it will change the lowest variable to that number
            lowest = grades[i];
        }
    }
    cout << "Highest: " << highest << " Lowest: " << lowest << endl; // This will then print out the highest and then the lowest variable
}

void GradesAboveThreshold(const vector<double> &grades) { // This will find all of the grades that are greater than the threshold
    if (grades.empty()) { // This will check to make sure that there are some grades inside of the vector before running
        cout << "There are no grades." << endl;
        return;
    }
    cout << "Input a threshold: ";
    if (double threshold; !(cin >> threshold)) { // This will check to make sure that the threshold that you input is a int before running
        cout << "Invalid input." << endl;
        cin.clear();
    } else {
        if (threshold >= 100 || threshold < 1) { // This will then check to make sure that the value that you input is a number that will acctually give you a result
            cout << "Please input a value that is less than 100 and greater than 1." << endl;
            return;
        }
        int total = 0; // This is the variable that will have the total amount of grades above the threshold
        for (int i = 1; i < grades.size(); i++) { // This will go through all of the grades
            if (grades[i] > threshold) { // This will check to see if the grade is bigger than the threshold and if it is it will add one to the total
                total += 1;
            }
        }
        cout << endl << "Total grades above the threshold are: " << total << endl; // This will then print out how many grades are above the threshold
    }
}



void Menu() { // This will print out the menu
    cout << "1. Add a Grade" << endl;
    cout << "2. Display All Grades" << endl;
    cout << "3. Calculate Average Grade" << endl;
    cout << "4. Find Highest and Lowest Grade" << endl;
    cout << "5. Count Grades Above Threshold" << endl;
    cout << "6. Quit" << endl;
    if (randVisable) { // This will look to see if you have enabled the random numbers
        cout << "7. Random Grade Nums" << endl;
    }
}


int main() { // This is the main function
    srand(time(0)); // This will set the random number seed based on the time
    vector<double> grades; // This is the vector of grades
    int choice; // This is the choice variable
    do { // This is the do-while
        Menu(); // This will print out the menu
        if (!(cin >> choice)) { // This will make sure that you input a int
            cout << "Invalid input." << endl;
            cin.clear();
        } else {
            switch (choice) { // This will then fire whatever function it needs to fire
                case 1:
                    AddGrade(grades);
                    break;
                case 2:
                    DisplayGrades(grades);
                    break;
                case 3:
                    CalcAverageGrade(grades);
                    break;
                case 4:
                    FindHighandLow(grades);
                    break;
                case 5:
                    GradesAboveThreshold(grades);
                    break;
                case 6:
                    cout << "Quit" << endl;
                    break;
                case 7:
                    if (randVisable) { // This will look to see if randomnumbers is active and if it is it will allow you to use this function to add in random grades
                        for (int i = 0; i < amountofRand; i++) {
                            grades.push_back((rand() % 100) + 1);
                        }
                    } else {
                        cout << "Invalid Choice." << endl; // If random numbers is not enabled then it will just act as if it is not a valid input
                    }
                    break;
                default:
                    cout << "Invalid Choice." << endl; // This will print out that you input something that was not one of the choices
                    break;
            }
        }
        cout << "---------------------------" << endl; // This is just to seperate the lines to make readability better
    } while (choice != 6); // This will run as long as choice does not equal 6

    return 0;
}