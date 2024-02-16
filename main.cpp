#include <iostream>
#include <string>

using namespace std;

const int needed_int = 10000;

int Number_Of_Students;
int Number_Of_Homework;
string status;

struct Student_Data{
    string student_name;
    string student_surname;
    int exam_grade;
    int *HW = new int[Number_Of_Homework];
};

Student_Data *Sdata;

void input_chooser(){
    string str_placeholder;

    do {
        cout << "Do you know how many students do you have in your class and how many homework assigments have they had(y/n): ";
        cin >> str_placeholder;

        if (str_placeholder != "y" && str_placeholder != "n"){
            cout << "Invalid input. Type y for yes or n for no: " << endl;
        }
    }while (str_placeholder != "y" && str_placeholder != "n");

    if (str_placeholder == "y"){
        cout << "How many students are in your class: ";
        cin >> str_placeholder;

        Number_Of_Students = stoi(str_placeholder);

        cout << "How many homework assigments did they have?: ";
        cin >> str_placeholder;

        Number_Of_Homework = stoi(str_placeholder);

        status = "y";
    }else{
        status = "n";
    }
}

void inputA(){
    //Known numbers
    Sdata = new Student_Data[Number_Of_Students];

    string str_placeholder;

    for (int i = 0; i < Number_Of_Students; i++){
        cout << "Enter the students name: ";
        cin >> str_placeholder;

        Sdata[i].student_name = str_placeholder;

        cout << "Enter the students surname: ";
        cin >> str_placeholder;

        Sdata[i].student_surname = str_placeholder;

        for (int j = 0; j < Number_Of_Homework; j ++){
            cout << "[" << j + 1 << "] Enter the homework grade: ";
            cin >> str_placeholder;

            Sdata[i].HW[j] = stoi(str_placeholder);
        }

        cout << "Enter the students exam grade: ";
        cin >> str_placeholder;

        Sdata[i].exam_grade = stoi(str_placeholder);
    }
}

void inputB(){
    //Unknown numbers
    //Store first inputs info into a separate array than from it you can get how many HW people had
    string str_placeholder;
    string end;
    int i = 0;
    int j = 0;

    Sdata = new Student_Data[i + 1];

    cout << "To end the inputs type (end) int the terminal at any point." << endl;

    do {
        cout << "[" << i + 1 << "] Enter the students name: ";
        cin >> str_placeholder;

        if (str_placeholder == "end"){
            break;
        }

        Sdata[i].student_name = str_placeholder;

        cout << "Enter the students surname: ";
        cin >> str_placeholder;

        cout << "To end the homework grade inputs type (99) in the terminal at any point." << endl;
        do {
            cout << "[" << j + 1 << "] Enter the students grade: ";
            cin >> end;

            Sdata[i].HW[j] = stoi(end);

            j++;
        }while (end != "99");

        Number_Of_Homework = j;

        j = 0;

        cout << "Enter the students exam grade: ";
        cin >> str_placeholder;

        Sdata[i].exam_grade = stoi(str_placeholder);

        i++;

        Number_Of_Students = i;

        Sdata = new Student_Data[i + 1];
    }while (str_placeholder != "end");
}

double avg_grade(int i){
    double place_holder;
    double exam;

    for (int j = 0; j < Number_Of_Homework; j++){
        place_holder = place_holder + Sdata[i].HW[j];
    }

    place_holder = place_holder / 3;
    place_holder = place_holder * 0.4;
    exam = Sdata[i].exam_grade;
    exam = exam * 0.6;
    place_holder = place_holder + exam;
    place_holder = (int)(place_holder * 100 + 0.5);

    return (double)place_holder / 100;
}

double median_grade(int i){
    int num_of_grades = Number_Of_Homework + 1;
    double num1 = 0;
    double num2 = 0;

    double list_of_grades[num_of_grades];
    double median = 0;

    for (int o = 0; o < num_of_grades - 1; o++){
        list_of_grades[o] = Sdata[i].HW[o];
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
        median = (int)(median * 100 + 0.5);

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
};

void print_data(string mode){
    if (mode == "avg"){
        cout << "Name       |Surname      |Average Grade" << endl;
        cout << "......................................." << endl;

        for (int i = 0; i < Number_Of_Students; i++){
            cout << Sdata[i].student_name << "       |" << Sdata[i].student_surname << "       |";
            cout << avg_grade(i) << endl;;
        }
    }else{
        cout << "Name       |Surname      |Median Grade" << endl;
        cout << "......................................." << endl;

        for (int i = 0; i < Number_Of_Students; i++){
            cout << Sdata[i].student_name << "       |" << Sdata[i].student_surname << "       |";
            cout << median_grade(i) << endl;
        }

    }
}

int main() {
    string str_placeholder;

    input_chooser();

    if (status == "y"){
        inputA();
    }else{
        inputB();
    }

    cout << "Do you want the average grades or the median? Type (avg) for the average grade or (med) for the median: ";
    cin >> str_placeholder;

   print_data(str_placeholder);

   delete[] Sdata; 

    return 0;
}