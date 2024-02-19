#include <iostream>
#include <string>
#include <random>

using namespace std;

const int needed_int = 10000;

int Number_Of_Students;
int Number_Of_Homework;
string status;
string gen_s;

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

    do {
        cout << "Should we generate the students grades(y/n): ";
        cin >> gen_s;

        if (gen_s != "y" && gen_s != "n"){
            cout << "Invalid input. Type y for yes or n for no: " << endl;
        }
    }while (gen_s != "y" && gen_s != "n");

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
    Sdata = new Student_Data[Number_Of_Students];

    string str_placeholder;
    int random_grade;

    for (int i = 0; i < Number_Of_Students; i++){
        cout << "Enter the students name: ";
        cin >> str_placeholder;

        Sdata[i].student_name = str_placeholder;

        cout << "Enter the students surname: ";
        cin >> str_placeholder;

        Sdata[i].student_surname = str_placeholder;

        if (gen_s == "y"){
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dis(1, 10);

            for (int j = 0; j < Number_Of_Homework; j++){
                random_grade = dis(gen);
                Sdata[i].HW[j] = random_grade;
            }

            random_grade = dis(gen);
            Sdata[i].exam_grade = random_grade;

        }else{
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
}

void inputB(){
    string str_placeholder;
    string end;
    int i = 2;
    int k = 0;
    int j = 0;
    int stud_count = 1;
    int exam_g;
    int random_grade;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 10);

    string* ph_array = new string[i];
    int* int_placeholder_array = new int[j + 1];
    string str_placeholder_array[2];

    cout << "[" << stud_count << "] Enter the students name: ";
    cin >> str_placeholder;
    str_placeholder_array[0] = str_placeholder;

    cout << "[" << stud_count << "] Enter the students surname: ";
    cin >> str_placeholder;
    str_placeholder_array[1] = str_placeholder;

    stud_count++;

    if (gen_s == "y"){
        Number_Of_Homework = dis(gen);

        int_placeholder_array = new int[Number_Of_Homework];

        for (int a = 0; a < Number_Of_Homework; a++){
            int_placeholder_array[a] = dis(gen);
        }

        exam_g = dis(gen);
    }else{
        cout << "When you have entered all the grades type (end) in the input field." << endl;

        do {
            cout << "[" << j + 1 << "] Enter the students grade: ";
            cin >> end;

            if (end == "end"){
                break;
            }

            int_placeholder_array[j] = stoi(end);

            j++;
        }while (true);

        cout << "Enter the students exam grade: ";
        cin >> exam_g;

        Number_Of_Homework = j;
    }

    cout << "To stop entering in student information type (end) in the input field." << endl;
    while (true) {
        cout << "[" << stud_count << "] Enter the students name: ";
        cin >> str_placeholder;
        k++;

        if (str_placeholder == "end"){
            break;
        }

        cout << "[" << stud_count << "] Enter the students surname: ";
        cin >> end;
        k++;

        if (i == k) {

            string* new_ph_array = new string[i + 2];

            for (int o = 0; o < i; o++) {
                new_ph_array[o] = ph_array[o];
            }

            delete[] ph_array;

            ph_array = new_ph_array;
        }

        ph_array[i] = str_placeholder;
        ph_array[i + 1] = end;
        i = i + 2;
        stud_count++;
        cout << "..........." << endl;
    }

    Number_Of_Students = stud_count - 1;

    Sdata = new Student_Data[Number_Of_Students];

    Sdata[0].student_name = str_placeholder_array[0];
    Sdata[0].student_surname = str_placeholder_array[1];

    int line = 2;
    for (int u = 1; u < Number_Of_Students; u++){
        Sdata[u].student_name = ph_array[line];
        line++;
        Sdata[u].student_surname = ph_array[line];
        line++;
    }

    for (int z = 0; z < Number_Of_Homework; z++){
        Sdata[0].HW[z] = int_placeholder_array[z];
    }

    Sdata[0].exam_grade = exam_g;

    if (gen_s == "y"){
        for (int m = 1; m < Number_Of_Students; m++){
            for (int c = 0; c < Number_Of_Homework; c++){
                Sdata[m].HW[c] = dis(gen);
            }
            Sdata[m].exam_grade = dis(gen);
        }
    }else{
        for (int m = 1; m < Number_Of_Students; m++){
            cout << "Enter the [" << m + 1 << "] HW grades" << endl;

            for (int c = 0; c < Number_Of_Homework; c++){
                cout << "Grade: ";
                cin >> Sdata[m].HW[c];
            }

            cout << "Enter the [" << m + 1 << "] exam grade : ";
            cin >> Sdata[m].exam_grade;
        }
    }
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