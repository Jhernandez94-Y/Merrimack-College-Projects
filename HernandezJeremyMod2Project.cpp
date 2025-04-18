#include <iostream>
#include <vector>
using namespace std;

class squareMatrix {
private:
    int order; 
    double** matrix;

public:
    squareMatrix(int n) {
        // creates matrix with each element equaling 0
        order = n; 
        // for rows
        matrix = new double*[order];
        for (int i = 0; i < order; ++i) {
            // for columns
            matrix[i] = new double[order]; 
            for (int j = 0; j < order; ++j) {
                matrix[i][j] = 0; 
            }
        }
    }

    // Method to get an element at a specific position
    double getElement(int row, int col) {
        if (row >= 0 && row < order && col >= 0 && col < order) {
            return matrix[row][col];
        } else {
            // return 0 if input invalid
            cout << "Invalid input!" << endl;
            return 0;
        }
    }

    // Method to set an element at a specific position
    void setElement(int row, int col, double value) {
        if (row >= 0 && row < order && col >= 0 && col < order) {
            matrix[row][col] = value;
        } else {
            cout << "Invalid input!" << endl;
        }
    }

    // Method to get the diagonal elements
    vector<double> getDiagonal() {
        // created vector to hold diagonal elements
        vector<double> diagonal;
        for (int i = 0; i < order; ++i) {
            // push_back used to add more memory in vector if no more space
            diagonal.push_back(matrix[i][i]);
        }
        return diagonal;
    }
};

int main() {
    // Create a square matrix of size 3
    squareMatrix mat(3);
    
    // Set elements in the matrix
    mat.setElement(0, 0, 21.0);
    mat.setElement(0, 1, 82.0);
    mat.setElement(0, 2, 97.0);
    mat.setElement(1, 0, 22.0);
    mat.setElement(1, 1, 59.0);
    mat.setElement(1, 2, 14.0);
    mat.setElement(2, 0, 43.0);
    mat.setElement(2, 1, 23.0);
    mat.setElement(2, 2, 50.0);
    
    cout << "Element at (1, 1): " << mat.getElement(1, 1) << endl; 
    cout << "Element at (0, 2): " << mat.getElement(0, 2) << endl; 
    
    // Get and print the diagonal elements
    vector<double> diagonal = mat.getDiagonal();
    cout << "Diagonal elements: ";
    for (double val : diagonal) {
        cout << val << " "; 
    }
    return 0;
}