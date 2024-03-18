#include "headers.h"
#include "main.h"

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
        cout << "Ivsekite, kuri faila norit nuskaityti. [1] kursiokai.txt, [2] Studentai1000.txt, [3] Studentai10000.txt," << endl;
        cout << "[4] Studentai100000.txt, [5] Studentai 1000000.txt, [6] Studentai10000000.txt: ";
        int a;
        cin >> a;

        string filename;

        if (a == 1){
            filename = "kursiokai.txt";
        }
        else if (a == 2){
            filename = "Studentai1000.txt";
        }
        else if (a == 3){
            filename = "Studentai10000.txt";
        }
        else if (a == 4){
            filename = "Studentai100000.txt";
        }
        else if (a == 5){
            filename = "Studentai1000000.txt";
        }
        else if (a == 6){
            filename = "Studentai10000000.txt";
        }
        
        fileInput(filename);
    }

    
}