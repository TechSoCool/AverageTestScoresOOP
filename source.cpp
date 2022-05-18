/* programmer Name: Sterling Gerard
   Date: 2/2/2022
   Problem Statement: Create two text file (input file) Student’s name (5 students)
                      and student's grade (6 grades for each student).
                      write a program (usig Functions) to read these input files in
   two arrays (string and integer).
*/

#include <iostream>      // Preprocessor directive for cout object
#include <string>        // Preprocessor directive for reading string of characters
#include <fstream>       // Preprocessor directive for file
#include <iomanip>       // Preprocessor directive to manage format of output 
using namespace std;
// Global variables 
ifstream inname, ingrade;
int const row = 5;      // number of rows
int const col = 5;      // number of colomn 
//========================= Definition of Read function ===================
void read_data(string stName[row], double stGrade[row][col])
{
    inname.open("Names.txt");
    ingrade.open("Grades.txt");
    int r;       //loop control variable
    int c;       //loop control variable for colomn
     //loop to read all 5 or as mane name and grade you have in your files
    for (r = 0; r < row; r++)
    {
        getline(inname, stName[r]);    //Reads name and stores them in array of studentsName  array
        for (c = 0; c < col; c++)
            ingrade >> stGrade[r][c];         //Reads grades and stores them in array of studentsgrade array
    }
}
//========================= Definition of display function ================
void display_data(string stName[row], double stGrade[row][col], double stsum[row], double stave[row])
{
    int r;       //loop control variable
    int c;       //loop control variable for colomn
     //loop to read all 5 or as mane name and grade you have in your files
    cout << fixed << showpoint << setprecision(2);
    for (r = 0; r < row; r++)
    {
        cout << left << setw(17) << stName[r];          //Reads name and stores them in array of studentsName  array
        for (c = 0; c < col; c++)
            cout << right << setw(7) << stGrade[r][c];
        cout << right << setw(8) << "  The sum is: " << stsum[r] << right << setw(8) << "   The average is: " << stave[r] << endl;   //Reads grades and stores them in array of studentsgrade array
    }
}
//============================ Sum Function ===============================
void sum(double stGrade[row][col], double stsum[row])
{
    int r, c;

    for (r = 0; r < row; r++)
    {
        for (c = 0; c < col; c++)
        {
            stsum[r] = stsum[r] + stGrade[r][c];
        }
    }
}
//============================ Sum Function ===============================
void average(double stsum[row], double stave[row])
{
    int r;

    for (r = 0; r < row; r++)
        stave[r] = stsum[r] / static_cast<double>(col);
}


//==========================  Main program ================================

int main()
{
    double grade[row][col] = { {0.0}, {0.0} };    //Declarion of arguments
    string name[row] = {};
    double st_s[row] = { 0.0 };
    double st_a[row] = { 0.0 };
    

    read_data(name, grade);       //calling read function , passing proper arguments
    sum(grade, st_s);             //calling function sum
    average(st_s, st_a);          //calling  function average 
    
    display_data(name, grade, st_s, st_a);

    inname.close();
    ingrade.close();

    system("pause");
    return 0;
}
