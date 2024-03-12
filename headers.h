#ifndef HEADERS_H
#define HEADERS_H

int Number_Of_Students;
int Number_Of_Homework;
string gen_s;
string input_mode;

struct Student_Data {
    std::string student_name;
    string student_surname;
    vector<int> Homework;
    int exam_grade;
};

bool isDigit(const string& str_placeholder, int check);
bool isString(const string& str_placeholder);
void Input(Student_Data& Sdata);
double Avreginator(const vector<int>& Sdata);
double avg_grade(const Student_Data& Sdata);
double Medianator(const vector<int>& Sdata);
double median_grade(const Student_Data& Sdata);
void print_data(const vector<Student_Data>& Sdata, string mode, string filename);
int manualInput();
int fileInput();

#endif