#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    vector<string> grades(n);
    vector<int> credits(n);

    double totalGradePoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter Grade (A, B, C, D, F): ";
        cin >> grades[i];

        cout << "Enter Credit Hours: ";
        cin >> credits[i];

        double gradePoint;

        if (grades[i] == "A")
            gradePoint = 4.0;
        else if (grades[i] == "B")
            gradePoint = 3.0;
        else if (grades[i] == "C")
            gradePoint = 2.0;
        else if (grades[i] == "D")
            gradePoint = 1.0;
        else
            gradePoint = 0.0;

        totalGradePoints += gradePoint * credits[i];
        totalCredits += credits[i];
    }

    double cgpa = totalGradePoints / totalCredits;

    cout << "\n----- Result -----\n";
    for (int i = 0; i < n; i++) {
        cout << "Course " << i + 1 << ": Grade " << grades[i]
             << ", Credits " << credits[i] << endl;
    }

    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "CGPA: " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}