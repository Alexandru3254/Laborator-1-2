#include <iostream>
#include <cstring>

class Discipline {
private:
    char* denumireDisciplina;
    char* numeProfesor;
    int numarOre;
    char* formaSustinere;

public:
    // Constructor implicit
    Discipline() : denumireDisciplina(nullptr), numeProfesor(nullptr), numarOre(0), formaSustinere(nullptr) {}

    
    Discipline(const char* denumire) : numarOre(0) {
        denumireDisciplina = strdup(denumire);
        numeProfesor = nullptr;
        formaSustinere = nullptr;
    }

    
    ~Discipline() {
        delete[] denumireDisciplina;
        delete[] numeProfesor;
        delete[] formaSustinere;
    }

    
    void setNumeProfesor(const char* nume) {
        delete[] numeProfesor;
        numeProfesor = strdup(nume);
    }

    
    void setNumarOre(int ore) {
        numarOre = ore;
    }

    
    void setFormaSustinere(const char* forma) {
        delete[] formaSustinere;
        formaSustinere = strdup(forma);
    }

    // Funcția de schimbare a denumirii disciplinei
    void setDenumire(const char* denumire) {
        delete[] denumireDisciplina;
        denumireDisciplina = strdup(denumire);
    }

    
    void afisareDisciplina() {
        std::cout << "Denumire Disciplina: " << denumireDisciplina << std::endl;
        std::cout << "Nume Profesor: " << (numeProfesor ? numeProfesor : "N/A") << std::endl;
        std::cout << "Numar de ore: " << numarOre << std::endl;
        std::cout << "Forma de sustinere: " << (formaSustinere ? formaSustinere : "N/A") << std::endl;
    }
};

int main() {
    Discipline disciplina1("Matematica");
    disciplina1.setNumeProfesor("Dorin");
    disciplina1.setNumarOre(5);
    disciplina1.setFormaSustinere("Examen");

    Discipline disciplina2("Fizica");
    disciplina2.setNumeProfesor("Ana");
    disciplina2.setNumarOre(4);
    disciplina2.setFormaSustinere("Colocviu");

    std::cout << "Disciplina 1:\n";
    disciplina1.afisareDisciplina();
    
    std::cout << "\nDisciplina 2:\n";
    disciplina2.afisareDisciplina();

    return 0;
}
