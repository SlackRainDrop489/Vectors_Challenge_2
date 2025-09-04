#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

bool randVisable = true;


void AddGrade(vector<double>& grades) {
    cout << "Input a grade: ";
    if (double input; !(cin >> input)) {
        cout << "Invalid input." << endl;
        cin.clear();
    } else {
        grades.push_back(input);
        cout << input << " added." << endl;
    }
}

void DisplayGrades(const vector<double> &grades) {
    if (grades.empty()) {
        cout << "There are no grades." << endl;
        return;
    }
    for (const double grade : grades) {
        cout << grade << " ";
    }
    cout << endl;
}

void CalcAverageGrade(const vector<double> &grades) {
    if (grades.empty()) {
        cout << "There are no grades." << endl;
        return;
    }
    double total = 0;
    for (double grade : grades) {
        total += grade;
    }
    double average = total / grades.size();
    cout << "The average grade is: " << average << endl;
}

void FindHighandLow(const vector<double> &grades) {
    if (grades.empty()) {
        cout << "There are no grades." << endl;
        return;
    }
    double highest = grades[0];
    double lowest = grades[0];
    for (int i = 1; i < grades.size(); i++) {
        if (grades[i] > highest) {
            highest = grades[i];
        }
        if (grades[i] < lowest) {
            lowest = grades[i];
        }
    }
    cout << "Highest: " << highest << " Lowest: " << lowest << endl;
}

void GradesAboveThreshold(const vector<double> &grades) {
    if (grades.empty()) {
        cout << "There are no grades." << endl;
        return;
    }
    cout << "Input a threshold: ";
    if (double threshold; !(cin >> threshold)) {
        cout << "Invalid input." << endl;
        cin.clear();
    } else {
        cout << endl << "Grades Above: " << threshold << endl;
        for (int i = 1; i < grades.size(); i++) {
            if (grades[i] > threshold) {
                cout << grades[i] << " ";
            }
        }
        cout << endl;
    }
}



void Menu() {
    cout << "1. Add a Grade" << endl;
    cout << "2. Display All Grades" << endl;
    cout << "3. Calculate Average Grade" << endl;
    cout << "4. Find Highest and Lowest Grade" << endl;
    cout << "5. Count Grades Above Threshold" << endl;
    cout << "6. Quit" << endl;
    if (randVisable) {
        cout << "7. Random Grade Nums" << endl;
    }
}


int main() {
    srand(time(0));
    vector<double> grades;
    int choice;
    do {
        Menu();
        if (!(cin >> choice)) {
            cout << "Invalid input." << endl;
            cin.clear();
        } else {
            switch (choice) {
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
                    if (randVisable) {
                        for (int i = 0; i < 10; i++) {
                            grades.push_back((rand() % 100) + 1);
                        }
                    } else {
                        cout << "Invalid Choice." << endl;
                    }
                    break;
                default:
                    cout << "Invalid Choice." << endl;
                    break;
            }
        }
        cout << "---------------------------" << endl;
    } while (choice != 6);

    return 0;
}