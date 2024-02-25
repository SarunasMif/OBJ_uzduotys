#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <random>
#include <sstream>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int Number_Of_Students;
int Number_Of_Homework;
string gen_s;
string input_mode;
string sort_type;

struct Student_Data {
    string student_name;
    string student_surname;
    vector<int> Homework;
    int exam_grade;
};

bool isDigit(const string& str_placeholder){
    for (char c : str_placeholder){
        if (!isdigit(c)){
            return false;
        }
    }

    return true;
}

void Input(Student_Data& Sdata){
    string str_placeholder;

    cout << "Enter the students name: ";
    cin >> str_placeholder;

    Sdata.student_name = str_placeholder;

    cout << " Enter the students surname: ";
    cin >> str_placeholder;

    Sdata.student_surname = str_placeholder;

    if (gen_s == "y"){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(1, 10);

        Number_Of_Homework = dis(gen);

        for (int i = 0; i < Number_Of_Homework; i++){
            Sdata.Homework.push_back(dis(gen));
        }

        Sdata.exam_grade = dis(gen);
    }else{
        cout << "How many homework assigments did the students have: ";
        cin >> str_placeholder;

        Number_Of_Homework = stoi(str_placeholder);

        for (int j = 0; j < Number_Of_Homework; j++){
            cout << "[" << j + 1 << "] Enter the homework grade: ";
            cin >> str_placeholder;
            Sdata.Homework.push_back(stoi(str_placeholder));
        }

        cout << "Enter the exam grade: ";
        cin >> str_placeholder;

        Sdata.exam_grade = stoi(str_placeholder);
    }
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
    vector<Student_Data> sorted = Sdata;

    if (mode == "avg"){
        cout << "Name       |Surname       |Average Grade" << endl;
        cout << "----------------------------------------" << endl;

        //vector<Student_Data> sorted = Sdata;

            sort(sorted.begin(), sorted.end(), [](const Student_Data& a, const Student_Data& b) {
                return avg_grade(a) < avg_grade(b);
            });

        for (const auto& Sdata : sorted){
            cout << left << setw(17) << Sdata.student_name << setw(15) << Sdata.student_surname << setw(15)<<fixed<<setprecision(2) << avg_grade(Sdata) << endl;
        }
    }
    if (mode == "med"){
        cout << "Name       |Surname       |Average Grade" << endl;
        cout << "----------------------------------------" << endl;

        vector<Student_Data> sorted = Sdata;

            sort(sorted.begin(), sorted.end(), [](const Student_Data& a, const Student_Data& b) {
                return median_grade(a) < median_grade(b);
            });

        for (const auto& Sdata : sorted){
            cout << left<<setw(15) << Sdata.student_name << setw(15) << Sdata.student_surname << setw(15)<<fixed<<setprecision(2) << median_grade(Sdata) << endl;
        }
    }
}

int manualInput(){
    vector<Student_Data> Sdata;

    string str_placeholder;

    cout << "Do you know the number of students in your class and how many homework assigments they have had (y/n): ";
    cin >> str_placeholder;

    cout << "Should we generate the grades for you?(y/n): ";
    cin >> gen_s;

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

void fileInput(){
    vector<Student_Data> Sdata;
    string str_placeholder;

    ifstream Read("kursiokai.txt");

    getline(Read, str_placeholder);

    auto start = high_resolution_clock::now();

    while (getline(Read, str_placeholder)) {
        Student_Data Adata;

        istringstream get(str_placeholder);
        get >> Adata.student_name >> Adata.student_surname;
        int grade;

        while (get >> grade) {
            Adata.Homework.push_back(grade);
        }

        Adata.exam_grade = Adata.Homework.back();
        Adata.Homework.pop_back();

        Sdata.push_back(Adata);
    }

    Read.close();

    cout << "Do you want the median or the average grade, type (avg) for average, type (med) for median: ";
    cin >> str_placeholder;

    print_data(Sdata, str_placeholder);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    double microseconds = duration.count();
    double seconds = microseconds / 1000000;

    cout << "Program took " << fixed << setprecision(6) << seconds << " to complete.";
}

int main(){
    cout << "Do you want to input student information by hand or input it from a file?" << endl;
    
    do {
        cout << "Input (manual) to input info by hand or type (file) to input it from a file: ";
        cin >> input_mode;

        
    }while (input_mode != "manual" && input_mode != "file");

    if (input_mode == "manual"){
        manualInput();
    }else{
        fileInput();
    }
}