#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int Number_Of_Students;
int Number_Of_Homework;

struct Student_Data {
    string student_name;
    string student_surname;
    vector<int> Homework;
    int exam_grade;
};

void Input(Student_Data& Sdata){
    string str_placeholder;

    cout << "Enter the students name: ";
    cin >> str_placeholder;

    Sdata.student_name = str_placeholder;

    cout << " Enter the students surname: ";
    cin >> str_placeholder;

    Sdata.student_surname = str_placeholder;

    cout << "How many homewotk assigments did the students have: ";
    cin >> str_placeholder;

    Number_Of_Homework = stoi(str_placeholder);

    for (int j = 0; j < Number_Of_Homework; j++){
        cout << "[" << j + 1 << "] Enter the homewotks grade: ";
        cin >> str_placeholder;
        Sdata.Homework.push_back(stoi(str_placeholder));
    }

    cout << "Enter the exam grade: ";
    cin >> str_placeholder;

    Sdata.exam_grade = stoi(str_placeholder);
}

double Avreginator(const vector<int>& Sdata){
    double HW_average = 0;

    for (int i = 0; i < Sdata.size(); i++){
        HW_average = HW_average + Sdata[i];
    }

    HW_average = HW_average / Sdata.size();

    return HW_average;
}

double avg_grade(const Student_Data& Sdata){
    double average = Avreginator(Sdata.Homework);
    average = 0.4 * average + 0.6 * Sdata.exam_grade;

    return average;
}

double Medianator(const vector<int>& Sdata){
    double HW_average;
    vector<int> sortedVector = Sdata;
    sort(sortedVector.begin(), sortedVector.end());

    if (sortedVector.size() % 2 == 0){
        HW_average = (sortedVector[sortedVector.size() / 2 - 1] + sortedVector[sortedVector.size() / 2]) / 2.0;

        return HW_average;
    }else{
        HW_average = sortedVector[sortedVector.size() / 2];

        return HW_average;
    }
}

double median_grade(const Student_Data& Sdata){
    double average = Medianator(Sdata.Homework);
    average = 0.4 * average + 0.6 * Sdata.exam_grade;

    return average;
}

void print_data(const vector<Student_Data>& Sdata, string mode){

    if (mode == "avg"){
        cout << "Name       |Surname       |Average Grade" << endl;
        cout << "........................................" << endl;

        for (const auto& Sdata : Sdata){
            cout << left<<setw(15) << Sdata.student_name << setw(15) << Sdata.student_surname << setw(15)<<fixed<<setprecision(2) << avg_grade(Sdata) << endl;
        }
    }else{
        cout << "Name       |Surname       |Average Grade" << endl;
        cout << "........................................" << endl;

        for (const auto& Sdata : Sdata){
            cout << left<<setw(15) << Sdata.student_name << setw(15) << Sdata.student_surname << setw(15)<<fixed<<setprecision(2) << median_grade(Sdata) << endl;
        }
    }
}

int main(){
    vector<Student_Data> Sdata;

    string str_placeholder;

    cout << "Do you know the number of students in your class and how many homework assigments they have had (y/n): ";
    cin >> str_placeholder;

    if (str_placeholder == "y"){
        cout << "How many students are in your class: ";
        cin >> str_placeholder;

        Number_Of_Students = stoi(str_placeholder);
        vector<Student_Data> Sdata(Number_Of_Students);

        for (int i = 0; i < Number_Of_Students; i++){
            Input(Sdata[i]);
        }    

        cout << "Do you want the average grades or the median? Type (avg) for the average grade or (med) for the median: ";
        cin >> str_placeholder;

       print_data(Sdata, str_placeholder);

        return 0;
    }else{
        do {
            Student_Data Stud_data;
            Input(Stud_data);
            Sdata.push_back(Stud_data);

            cout << "Do you want input another student(y/n): ";
            cin >> str_placeholder;
        }while (str_placeholder == "y");

        cout << "Do you want the average grades or the median? Type (avg) for the average grade or (med) for the median: ";
        cin >> str_placeholder;

        print_data(Sdata, str_placeholder);

        return 0;
    }
}