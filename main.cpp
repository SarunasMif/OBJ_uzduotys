#include "includes.h"
#include "headers.h"

void splitstudents(const vector<Student_Data>& S_Data, string mode){
    auto start = high_resolution_clock::now();
    string a = "kietiakiai.txt";
    string b = "nuskriaustukai.txt";

    vector<Student_Data> kietiakiai;
    vector<Student_Data> nuskriaustukai;

    for (const auto& adata : S_Data){
        if (avg_grade(adata) < 5){
            nuskriaustukai.push_back(adata);
        }else{
            kietiakiai.push_back(adata);
        }
    }

    auto stop = high_resolution_clock::now();
    chrono::duration<double> diff = stop - start;
    cout << "Rusiavimas baigtas! Rusiavimas uztruko " << diff.count() << " sekundes." << endl;

    print_data(kietiakiai, mode, a);
    print_data(nuskriaustukai, mode, b);

}

bool isDigit(const string& str_placeholder, int check){
    for (char c : str_placeholder){
        if (!isdigit(c)){
            return false;
        }
    }

    if (check == 1){
        if (stoi(str_placeholder) < 1 || stoi(str_placeholder) > 10){
            return false;
        }
    }

    if (check == 2){
        if (stoi(str_placeholder) < 1 || stoi(str_placeholder) > 4){
            return false;
        }
    }

    if (check == 3){
        if (stoi(str_placeholder) < 1 || stoi(str_placeholder) > 2){
            return false;
        }
    }

    return true;
}// Tikrina ar string yra sudarytas tiks is skaiciu

bool isString(const string& str_placeholder){
    for (char c : str_placeholder){
        if (!isalpha(c)){
            return false;
        }
    }

    return true;
}// Tikrina ar string yra sudarytas tiks is raidziu

void Input(Student_Data& Sdata){
    string str_placeholder;

    do {
        cout << "Iveskite studento varda: ";
        cin >> str_placeholder;

        if (!isString(str_placeholder)) {
            cout << "Error: vardas turi buti sudarytas tik is raidziu." << endl;
        }
    }while (!isString(str_placeholder));

    Sdata.student_name = str_placeholder;

    do {
        cout << "Iveskite studento pavarde: ";
        cin >> str_placeholder;

        if (!isString) {
            cout << "Error: pavarde turi buti sudaryta tik is raidziu." << endl;
        }
    }while (!isString(str_placeholder));

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
        // Sugeneruojami atsitiktinei pazmiai
    }else{
        do {
            cout << "Kiek namu darbu turejo studentai: ";
            cin >> str_placeholder;

            if (!isDigit(str_placeholder, 0)){
                cout << "Error! Turi buti skaicius. " << endl;
            }
        }while (!isDigit(str_placeholder, 0));

        Number_Of_Homework = stoi(str_placeholder);

        for (int j = 0; j < Number_Of_Homework; j++){
           
            do {
                cout << "[" << j + 1 << "] Iveskite pazymi: ";
                cin >> str_placeholder;

                if (!isDigit(str_placeholder, 1)){
                    cout << "Error! Pazimys turi buti naturalusis skaicius nuo 1 iki 10." << endl;
                }
            }while (!isDigit(str_placeholder, 1));

            Sdata.Homework.push_back(stoi(str_placeholder));
        }

        do {
            cout << "Iveskite egzamino pazymi: ";
            cin >> str_placeholder;

            if (!isDigit(str_placeholder, 1)){
                cout << "Error! Pazimys turi buti naturalusis skaicius nuo 1 iki 10." << endl;
            }
        }while (!isDigit(str_placeholder, 1));

        Sdata.exam_grade = stoi(str_placeholder);
    }// Jei vartotojas zino kiek turejo namu darbu
}

double Avreginator(const vector<int>& Sdata){
    double HW_average = 0;

    for (int i = 0; i < Sdata.size(); i++){
        HW_average = HW_average + Sdata[i];
    }

    HW_average = HW_average / Sdata.size();

    return HW_average;
}// Vidurkio skaiciavimas 

double avg_grade(const Student_Data& Sdata){
    double average = Avreginator(Sdata.Homework);
    average = 0.4 * average + 0.6 * Sdata.exam_grade;

    return average;
}// Vidurkio skaiciavimas

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
}// Medianos skaiciavimas

double median_grade(const Student_Data& Sdata){
    double average = Medianator(Sdata.Homework);
    average = 0.4 * average + 0.6 * Sdata.exam_grade;

    return average;
}// Medianos skaiciavimas

void print_data(const vector<Student_Data>& Sdata, string mode, string filename){
    vector<Student_Data> sorted = Sdata;
    string setting;
    
    do {
        cout << "Jei norite isvesti i terminala iveskite 1. Jei norite isvesti i faila iveskite 2: ";
        cin >> setting;

        if (!isDigit(setting, 3)){
            cout << "Error! Turi buti sveikasis skaicius nuo 1 iki 2.";
        }

    }while(!isDigit(setting, 3));



    if (setting == "1"){
        if (mode == "3"){
            cout << left << setw(17) << "Vardas " << setw(15) << "Pavarde " << setw(15) << "Galutinis(Vid.) " << setw(15) << "Galutinis(Med.)" << endl;
            cout << "---------------------------------------------------------------" << endl;

            sort(sorted.begin(), sorted.end(), [](const Student_Data& a, const Student_Data& b) {
                return avg_grade(a) < avg_grade(b);
            });

            for (const auto& Sdata : sorted){
                //cout << left << setw(17) << Sdata.student_name << setw(15) << Sdata.student_surname << setw(16) << fixed << setprecision(2) << avg_grade(Sdata) << setw(15) << fixed << setprecision(2) << median_grade(Sdata) << endl;
            }
        }// Rusiuoja pagal vidurkius

        else if (mode == "4"){
            cout << left << setw(17) << "Vardas " << setw(15) << "Pavarde " << setw(15) << "Galutinis(Vid.) " << setw(15) << "Galutinis(Med.)" << endl;
            cout << "---------------------------------------------------------------" << endl;

            sort(sorted.begin(), sorted.end(), [](const Student_Data& a, const Student_Data& b) {
                return median_grade(a) < median_grade(b);
            });

            for (const auto& Sdata : sorted){
                //cout << left << setw(17) << Sdata.student_name << setw(15) << Sdata.student_surname << setw(16) << fixed << setprecision(2) << avg_grade(Sdata) << setw(15) << fixed << setprecision(2) << median_grade(Sdata) << endl;
            }
        }// Rusiuoja pagal pazymiu mediana

        else if (mode == "1"){
            cout << "Vardas       Pavarde       Galutinis(Vid.) Galutinis(Med.)" << endl;
            cout << "----------------------------------------------------" << endl;

            sort(sorted.begin(), sorted.end(), [](const Student_Data& a, const Student_Data& b) {
                return stoi(a.student_name.substr(6)) < stoi(b.student_name.substr(6));
            });

            for (const auto& Sdata : sorted){
                //cout << left << setw(17) << Sdata.student_name << setw(15) << Sdata.student_surname << setw(16) << fixed << setprecision(2) << avg_grade(Sdata) << setw(15) << fixed << setprecision(2) << median_grade(Sdata) << endl;
            }

        }// Rusiuoja pagal vardus

        else if (mode == "2"){
            cout << left << setw(17) << "Vardas " << setw(15) << "Pavarde " << setw(15) << "Galutinis(Vid.) " << setw(15) << "Galutinis(Med.)" << endl;
            cout << "---------------------------------------------------------------" << endl;

            sort(sorted.begin(), sorted.end(), [](const Student_Data& a, const Student_Data& b) {
                return stoi(a.student_name.substr(6)) < stoi(b.student_name.substr(6));
            });

            for (const auto& Sdata : sorted){
                //cout << left << setw(17) << Sdata.student_name << setw(15) << Sdata.student_surname << setw(16) << fixed << setprecision(2) << avg_grade(Sdata) << setw(15) << fixed << setprecision(2) << median_grade(Sdata) << endl;
            }
        }// Rusiuoja pagal pavardes
    }else{

        if (mode == "1"){
            sort(sorted.begin(), sorted.end(), [](const Student_Data& a, const Student_Data& b) {
                return stoi(a.student_name.substr(6)) < stoi(b.student_name.substr(6));
            });

            ofstream write(filename);

            write << left << setw(17) << "Vardas " << setw(15) << "Pavarde " << setw(15) << "Galutinis(Vid.) " << setw(15) << "Galutinis(Med.)" << endl;
            write << "---------------------------------------------------------------" << endl;

            for (const auto& Sdata : sorted){
                stringstream Adata;
                Adata << left << setw(17) << Sdata.student_name << setw(15) << Sdata.student_surname << setw(16) << fixed << setprecision(2) << avg_grade(Sdata) << setw(15) << fixed << setprecision(2) << median_grade(Sdata) << endl;
                write << Adata.str() << endl;
            }
        }//Isveda pagal varda

        else if (mode == "2"){
            sort(sorted.begin(), sorted.end(), [](const Student_Data& a, const Student_Data& b) {
                return stoi(a.student_name.substr(6)) < stoi(b.student_name.substr(6));
            });

            ofstream write(filename);

            write << left << setw(17) << "Vardas " << setw(15) << "Pavarde " << setw(15) << "Galutinis(Vid.) " << setw(15) << "Galutinis(Med.)" << endl;
            write << "---------------------------------------------------------------" << endl;

            for (const auto& Sdata : sorted){
                stringstream Adata;
                Adata << left << setw(17) << Sdata.student_name << setw(15) << Sdata.student_surname << setw(16) << fixed << setprecision(2) << avg_grade(Sdata) << setw(15) << fixed << setprecision(2) << median_grade(Sdata) << endl;
                write << Adata.str() << endl;
            }

            write.close();

        }//Isveda pagal pavarde

        else if (mode == "3"){
            sort(sorted.begin(), sorted.end(), [](const Student_Data& a, const Student_Data& b) {
                return avg_grade(a) < avg_grade(b);
            });

            ofstream write(filename);

            write << left << setw(17) << "Vardas " << setw(15) << "Pavarde " << setw(15) << "Galutinis(Vid.) " << setw(15) << "Galutinis(Med.)" << endl;
            write << "---------------------------------------------------------------" << endl;

            for (const auto& Sdata : sorted){
                stringstream Adata;
                Adata << left << setw(17) << Sdata.student_name << setw(15) << Sdata.student_surname << setw(16) << fixed << setprecision(2) << avg_grade(Sdata) << setw(15) << fixed << setprecision(2) << median_grade(Sdata) << endl;
                write << Adata.str() << endl;
            }

            write.close();

        }//Isveda pagal vidurki

        else if (mode == "4"){
            sort(sorted.begin(), sorted.end(), [](const Student_Data& a, const Student_Data& b) {
                return stoi(a.student_name.substr(6)) < stoi(b.student_name.substr(6));
            });

            ofstream write(filename);

            write << left << setw(17) << "Vardas " << setw(15) << "Pavarde " << setw(15) << "Galutinis(Vid.) " << setw(15) << "Galutinis(Med.)" << endl;
            write << "---------------------------------------------------------------" << endl;

            for (const auto& Sdata : sorted){
                stringstream Adata;
                Adata << left << setw(17) << Sdata.student_name << setw(15) << Sdata.student_surname << setw(16) << fixed << setprecision(2) << avg_grade(Sdata) << setw(15) << fixed << setprecision(2) << median_grade(Sdata) << endl;
                write << Adata.str() << endl;
            }

            write.close();
        }
    }



}

int manualInput(){
    vector<Student_Data> Sdata;

    string str_placeholder;

    do {
        cout << "Ar zinote kiek studentu yra jusu klaseje? (y/n): ";
        cin >> str_placeholder;
    }while (str_placeholder != "y" && str_placeholder != "n");

    do {
        cout << "Ar norite, kad pazymiai butu sugeneruoti? (y/n): ";
        cin >> gen_s;
    }while (gen_s != "y" && gen_s != "n");

    if (str_placeholder == "y"){
        cout << "Kiek studentu yra jusu klaseje: ";
        cin >> str_placeholder;

        Number_Of_Students = stoi(str_placeholder);
        vector<Student_Data> Sdata(Number_Of_Students);

        for (int i = 0; i < Number_Of_Students; i++){
            Input(Sdata[i]);
        }    

        do {
            cout << "Ar norite, kad rusiuotu pagal vardus (1), pavardes (2), vidurki (3), pazymiu mediana (4)? : ";
            cin >> str_placeholder;

            if (!isDigit(str_placeholder, 2)){
                cout << "Error, turi buti skaicius nuo 1 iki 4." << endl;
            }
        }while (!isDigit(str_placeholder, 2));

       print_data(Sdata, str_placeholder, "xd.txt");

        return 0;
    }else{
        do {
            Student_Data Stud_data;
            Input(Stud_data);
            Sdata.push_back(Stud_data);

            cout << "Ar norite ivesti dar viena studenta(y/n): ";
            cin >> str_placeholder;
        }while (str_placeholder == "y");

        do {
            cout << "Ar norite, kad rusiuotu pagal vardus (1), pavardes (2), vidurki (3), pazymiu mediana (4)? : ";
            cin >> str_placeholder;

            if (!isDigit(str_placeholder, 2)){
                cout << "Error, turi buti skaicius nuo 1 iki 4." << endl;
            }
        }while (!isDigit(str_placeholder, 2));

        print_data(Sdata, str_placeholder, "xd");

        return 0;
    }
}// Rankinis studentu duomenu ivedimas

int fileInput(string filename){
    vector<Student_Data> Sdata;
    string str_placeholder;

    ifstream Read;
    try {
        Read.open(filename);

        if (!Read){
            throw "Failas nerastas.";
            return 1;
        }
    }
    catch (const char* error) {
        cerr << "Error: " << error << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }// Neveik dar kaip turetu neuzdaro programos

    getline(Read, str_placeholder);

    auto start = high_resolution_clock::now();

    while (getline(Read, str_placeholder)) {
        Student_Data Adata;

        istringstream get(str_placeholder);
        get >> Adata.student_name >> Adata.student_surname;
        int grade;

        while (get >> grade) {
            Adata.Homework.push_back(grade);
            Number_Of_Homework++;
        }

        Adata.exam_grade = Adata.Homework.back();
        Adata.Homework.pop_back();
        Number_Of_Homework--;

        Sdata.push_back(Adata);
    }// Nuskaitoma informacija is failo ir irasoma i vektoriu

    Read.close();

    do {
            cout << "Ar norite, kad rusiuotu pagal vardus (1), pavardes (2), vidurki (3), pazymiu mediana (4)? : ";
            cin >> str_placeholder;

            if (!isDigit(str_placeholder, 2)){
                cout << "Error, turi buti skaicius nuo 1 iki 4." << endl;
            }
        }while (!isDigit(str_placeholder, 2));

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    double microseconds = duration.count();
    double seconds = microseconds / 1000000;

    cout << "Failo nuskaitymas uztruko " << fixed << setprecision(6) << seconds << " sekundes.";

    splitstudents(Sdata, str_placeholder);

    return 0;
}// Studentu duomenu nuskaitymas is failo

int generateFile(){
    int s_num = 0;
    int hw_hum = 0;
    string filename;

    cout << "Kiek studentu generuoti norit: ";
    cin >> s_num;

    cout << "Kiek namu darbu buvo: ";
    cin >> hw_hum;
    Number_Of_Homework = hw_hum;

    auto start = high_resolution_clock::now();
    filename =  "Studentai" + to_string(s_num) + ".txt";
    ofstream write(filename);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 10);

    write << left << setw(15) << "Vardas" << setw(15) << "Pavarde";

    for (int i = 0; i < hw_hum; i++){
        write << "ND" + to_string(i + 1) << "\t";
    }
    write << "Egz." << endl;

    for (int i = 0; i < s_num; i++){
        stringstream s_data;
        s_data << left << setw(15) << "Vardas" + to_string(i + 1) << setw(15) << "Pavarde" + to_string(i + 1);

        for (int j = 0; j <= hw_hum; j++){
            s_data << setw(6) << dis(gen) << "\t";
        }

        write << s_data.str() << endl;
    }

    write.close();

    auto stop = high_resolution_clock::now();
    chrono::duration<double> diff = stop - start;
    cout << "Failas sukurtas! Failo kurimas uztruko " << diff.count() << " sekundes." << endl;

    fileInput(filename);

    return 0;
}

int main(){
    cout << "Ar norite ivesti studentu duomenis rankiniu budu ar nuskaityti is failo?" << endl;
    
    do {
        cout << "Iveskite 1, jei norite uzpildyti rankiniu budu, iveskite 2, jei norite nuskaityti nuo failo, jei noite generuoti faila iveskite 3: ";
        cin >> input_mode;

        
    }while (input_mode != "1" && input_mode != "2" && input_mode != "3");

    if (input_mode == "1"){
        manualInput();
    }
    else if (input_mode == "3"){
        generateFile();
    }else {
        string filename = "kursiokai.txt";
        fileInput(filename);
    }

    
}