#include <iostream>

using namespace std;

const int Number_Of_Students = 3;

struct Student_Data{
    string name;
    string surname;
    int HW_grades[3];
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

void collect_Data() 
{
    string str_placeholder;
    
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
    }

}

void print_Data()
{
    for (int i = 0; i < Number_Of_Students; i++){
        cout << "[" << i << "] " << Sdata[i].name << " " << Sdata[i].surname << endl;
    }
}

int main()
{
    collect_Data();
    print_Data();

    return 0;
}