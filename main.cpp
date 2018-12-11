#include <iostream>
#include <stdio.h>
#include <string>
using  namespace std;

int main() {
    cout << "Создаем квадратную матрицу размера M*M, где M является числом из диапазона [2,5]\n";
    string matrix[5][5], t;
    int lines, column;
    cout << "\tвведите кол-во строк:  ";
    cin >> lines;
    cout << "\tвведите кол-во столбцов: ";
    cin >> column;

    cout << "\nЗаполните матрицу M 5ти значными буквами английского алфавита: \n";
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < column; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "\n Заполнение матрицы M: \n";
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < column; j++) {
            cout << matrix[i][j]<<'\t';
        }
        cout << '\n';

    }
    char temp;
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < column; j++){
            for (int x = 0; x < 4; x++) {
                for (int z = x+1; z < 5; z++) {
                    if(matrix[i][j][x] > matrix[i][j][z]) {
                        temp = matrix[i][j][x];
                        matrix[i][j][x] = matrix[i][j][z];
                        matrix[i][j][z] = temp;
                    }
                }
            }
        }
    }
    cout << "\n Перевернутая матрица M: \n";
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < column; j++) {
            cout << matrix[i][j]<<'\t';
        }
        cout << '\n';

    }


       int VowelLetters = 0, ConsonantLetters = 0;
       for (int i = 0; i < lines; i++) {
           for (int j = 0; j < column; j++) {
               for (int z = 0; z < 5; z++) {
                   if ((matrix[i][j][z] == 'a') || (matrix[i][j][z] == 'e') || (matrix[i][j][z] == 'i') ||
                       (matrix[i][j][z] == 'o') || (matrix[i][j][z] == 'u')) {
                       VowelLetters++;
                   } else if ((matrix[i][j][z] == 'A') || (matrix[i][j][z] == 'E') || (matrix[i][j][z] == 'I') ||
                                (matrix[i][j][z] == 'O') || (matrix[i][j][z] == 'U')) {
                      VowelLetters++;
                   } else
                       ConsonantLetters++;

               }

           }
       }
       cout <<"\nОбщее количесвтво гласных букв: " << VowelLetters<<'\n';
       cout<<"\nОбщее количество согласных букв: " << ConsonantLetters<<'\n';
}




