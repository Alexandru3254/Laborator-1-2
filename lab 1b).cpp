#include <iostream>


struct Vector {
    long* data;
    int numar_elemente;

   
    Vector() : data(nullptr), numar_elemente(0) {
    }

    
    void initializare(int dimensiune) {
        data = new long[dimensiune];
        numar_elemente = dimensiune;
        for (int i = 0; i < dimensiune; i++) {
            data[i] = 0;
        }
    }

   
    void eliminare() {
        if (data != nullptr) {
            delete[] data;
            data = nullptr;
            numar_elemente = 0;
        }
    }


    void set_dimensiune(int dimensiune) {
        eliminare();
        initializare(dimensiune);
    }

    
    long& operator[](int index) {
        if (index >= 0 && index < numar_elemente) {
            return data[index];
        }
        throw std::out_of_range("Index invalid");
    }


    long suma_elementelor_pare() {
        long suma = 0;
        for (int i = 0; i < numar_elemente; i++) {
            if (data[i] % 2 == 0) {
                suma += data[i];
            }
        }
        return suma;
    }
};

int main() {
    Vector vector;
    int dimensiune;

    std::cout << "Introduceți dimensiunea vectorului: ";
    std::cin >> dimensiune;

    vector.initializare(dimensiune);

    std::cout << "Introduceți elementele vectorului:\n";
    for (int i = 0; i < dimensiune; i++) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> vector[i];
    }


    long maxim = vector[0];
    int pozitie_maxim = 0;
    for (int i = 1; i < dimensiune; i++) {
        if (vector[i] > maxim) {
            maxim = vector[i];
            pozitie_maxim = i;
        }
    }

    std::cout << "Elementul maximal este " << maxim << " la poziția " << pozitie_maxim << std::endl;

    std::cout << "Suma elementelor pare ale vectorului: " << vector.suma_elementelor_pare() << std::endl;

    vector.eliminare();

    return 0;
}
