#include <iostream>
#include <string>

using namespace std;

const int Number_Of_Students = 3;
const int Number_Of_Homework = 3;

struct Student_Data{
    string name;
    string surname;
    int HW_grades[Number_Of_Homework];
    int exam_grade;
};

Student_Data Sdata[Number_Of_Students]; 

bool isString(const string& str_placeholder){
    for (char c : str_placeholder) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

bool isInt(const string& str_placeholder){
    for (char c : str_placeholder){
        if (!isdigit(c)){
            return false;
        }

        int grade = stoi(str_placeholder);

        if (grade > 10 || grade < 0){
            return false;
        }
    }

    return true;
}

void collect_Data() 
{
    string str_placeholder;
    char placeholder;
    int int_placeholder;
    
    for (int i = 0; i < Number_Of_Students; i++){
        do {
            cout << "Enter the students name: ";
            cin >> str_placeholder;

            if (!isString(str_placeholder)){
                cout << "Invalid!. Students name can not contain any numbers." << endl;
            } 
        }while (!isString(str_placeholder));

        Sdata[i].name = str_placeholder;

        do {
            cout << "Enter the students surname: ";
            cin >> str_placeholder;

            if (!isString(str_placeholder)){
                cout << "Invalid!. Students surname can not contain any numbers." << endl;
            }
        }while (!isString(str_placeholder));

        Sdata[i].surname = str_placeholder;

        for (int j = 0; j < Number_Of_Homework; j++){
            do {
                cout << "[" << j + 1 << "] Enter the students homework grade: ";
                cin >> str_placeholder;

                if (!isInt(str_placeholder)){
                    cout << "Invalid!. Students grade can only be a number and in decimal form from 0 to 10." << endl;
                }
            }while (!isInt(str_placeholder));

            int_placeholder = stoi(str_placeholder);

            Sdata[i].HW_grades[j] = int_placeholder;
        }

        do {
            cout << "Enter the students exam grade: ";
            cin >> str_placeholder;

            if (!isInt(str_placeholder)){
                cout << "Invalid!. Students exam grade can only be a number and in decimal form from 0 to 10" << endl;
            }
        }while (!isInt(str_placeholder));

        int int_placeholder = stoi(str_placeholder);

        Sdata[i].exam_grade = int_placeholder;
    }

}

double averageGrade(int i)
{
    double final_grade = 0;
    double exam_grade = Sdata[i].exam_grade;
    double avg_HW_grade =0;

    for (int j = 0; j < Number_Of_Homework; j++){
        avg_HW_grade = avg_HW_grade + Sdata[i].HW_grades[j];
    }

    avg_HW_grade = avg_HW_grade / 3;
    final_grade = avg_HW_grade * 0.4;
    exam_grade = exam_grade * 0.6;
    final_grade = final_grade + exam_grade;
    final_grade = (int)(final_grade * 100 + .5);
    return (double)final_grade / 100;
}


void print_Data()
{
    double average;

    cout << "Name       |Surname       |Final Grade" << endl;
    cout << "...................................." << endl;

    for (int i = 0; i < Number_Of_Students; i++){
        cout << Sdata[i].name << "       |" << Sdata[i].surname << "       |";

        cout << averageGrade(i) << endl;;
    }
    
}

int main()
{
    collect_Data();
    print_Data();

    return 0;
}