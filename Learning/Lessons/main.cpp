#include<iostream>

using namespace std;

// global scope

// int marks[20][6]
// working with multidimensional array is difficult
// if there was a mechanism which you could use to encapsulate marks of each subject for each student seperately?

struct Student{  // TO emulate a real world or abtract entities, you encapsulate all of its characterstics data
// at one point
    int maths, science, geopgraphy, english, cpp;
    std::string name, sirname, blood_group;
};

int main(){
    // local scope variables
    Students std11[20];
    for(int i{}; i<20; i++){
        cout << "Enter maths mark: ";
        cin >> std11[i].maths;
        cout << "Enter science marks: ";
        cin >> std[11].science;
        cin >> std11[i].cpp; // structure doesn't have cpp data member
        cout << "Enter student name: ";
        cin >> std11[i].name;
    }
    
    int marks[20][6];  // [][0]-maths, [][1]-science
    for(int j{}; j<20; j++){
        cout << "Enter maths mark: ";
        cin >> marks[j][7]; // segmentation fault, core dumped
    }
    return 0;
}