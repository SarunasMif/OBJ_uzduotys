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
    double avg_HW_grade = 0;

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

double medianGrade(int i)
{
    int num_of_grades = Number_Of_Homework + 1;
    double num1 = 0;
    double num2 = 0;
    double list_of_grades[num_of_grades];
    double median = 0;

    for (int o = 0; o < num_of_grades - 1; o++){
        list_of_grades[o] = Sdata[i].HW_grades[o];
    }
    list_of_grades[num_of_grades - 1] = Sdata[i].exam_grade;

    if (num_of_grades % 2 == 0){
        for (int j = 0; j < num_of_grades / 2; j++){
            num1 = list_of_grades[j];
        }
        for (int k = 0; k < num_of_grades / 2 + 1; k++){
            num2 = list_of_grades[k];
        }

        median = num1 + num2;
        median = median / 2;
        median = (int)(median * 100 + .5);

        return (double)median / 100;
    }else{
        num1 = num_of_grades - 1;
        num1 = num1 / 2;
        num1 = num1 + 1;

        for (int l = 0; l < num1; l++){
            median = list_of_grades[l];
        }

        return median;
    }
}

void print_Data()
{
    string str_placeholder;

    cout << "Do you want to get the median grade instead of the final average? " << endl;

    do {
        cin.clear();
        cout << "Type y if yes and n if no (y/n): ";
        cin >> str_placeholder;

    }while (str_placeholder != "y" && str_placeholder != "n");

    if (str_placeholder == "n"){
        cout << "Name       |Surname       |Final Grade" << endl;
        cout << "...................................." << endl;

        for (int i = 0; i < Number_Of_Students; i++){
            cout << Sdata[i].name << "       |" << Sdata[i].surname << "       |";

            cout << averageGrade(i) << endl;;
        }
    }else{
        cout << "Name       |Surname       |Median Grade" << endl;
        cout << "...................................." << endl;

        for (int i = 0; i < Number_Of_Students; i++){
            cout << Sdata[i].name << "       |" << Sdata[i].surname << "       |";

            cout << medianGrade(i) << endl;;
        }
    }
    
}

int main()
{
    collect_Data();
    print_Data();

    return 0;
}