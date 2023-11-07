#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<float>> data;
    int rows;
    int cols;
    mutable int errorCode; // Folosim 'mutable' pentru a permite modificarea în funcțiile const

public:
    // Constructor fără parametri (constructorul implicit)
    Matrix() : rows(0), cols(0), errorCode(0) {}

    // Constructor pentru matrice pătrată
    Matrix(int size) : rows(size), cols(size), errorCode(0) {
        if (size <= 0) {
            errorCode = 1; // Cod de eroare pentru dimensiune incorectă
            return;
        }
        data = std::vector<std::vector<float>>(size, std::vector<float>(size, 0.0));
    }

    // Constructor pentru matrice dreptunghiulară
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols), errorCode(0) {
        if (numRows <= 0 || numCols <= 0) {
            errorCode = 1; // Cod de eroare pentru dimensiuni incorecte
            return;
        }
        data = std::vector<std::vector<float>>(numRows, std::vector<float>(numCols, 0.0));
    }

    // Funcție membru de acces pentru a returna valoarea elementului (i, j)
    float getElement(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            errorCode = 2; // Cod de eroare pentru acces incorect
            return 0.0;
        }
        return data[i][j];
    }

    // Funcție de setare a valorii elementului (i, j)
    void setElement(int i, int j, float value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            data[i][j] = value;
        } else {
            errorCode = 2; // Cod de eroare pentru acces incorect
        }
    }

    // Funcție de adunare a două matrice
    Matrix add(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            errorCode = 3; // Cod de eroare pentru dimensiuni incompatibile
            return Matrix();
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    // Funcție de scădere a două matrice
    Matrix subtract(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            errorCode = 3; // Cod de eroare pentru dimensiuni incompatibile
            return Matrix();
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return result;
    }

    // Funcție de înmulțire a matricei cu alta matrice
    Matrix multiply(const Matrix& other) const {
        if (cols != other.rows) {
            errorCode = 3; // Cod de eroare pentru dimensiuni incompatibile
            return Matrix();
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                float sum = 0.0;
                for (int k = 0; k < cols; k++) {
                    sum += data[i][k] * other.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }

        return result;
    }

    // Funcție pentru a obține codul de eroare
    int getErrorCode() const {
        return errorCode;
    }

    // Funcție pentru a obține numărul de rânduri
    int getRows() const {
        return rows;
    }

    // Funcție pentru a obține numărul de coloane
    int getCols() const {
        return cols;
    }
};

int main() {
   
    Matrix mat1(2, 2); // Matrice 2x2
    Matrix mat2(2, 2); // Matrice 2x2

    
    mat1.setElement(0, 0, 1.0);
    mat1.setElement(0, 1, 2.0);
    mat1.setElement(1, 0, 3.0);
    mat1.setElement(1, 1, 4.0);

   
    mat2.setElement(0, 0, 5.0);
    mat2.setElement(0, 1, 6.0);
    mat2.setElement(1, 0, 7.0);
    mat2.setElement(1, 1, 8.0);

    /
    Matrix result = mat1.add(mat2);

    for (int i = 0; i < result.getRows(); i++) {
        for (int j = 0; j < result.getCols(); j++) {
            std::cout << result.getElement(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}