#include <iostream>
#include <stdio.h>
#include <string>
using  namespace std;

/*2.17.Создать квадратную матрицу размера MxM, где Mявляется целым числом из диапазона [2,5].
 * Конкретный размер матрицы задается пользователем.
 * Матрица должна содержать слова из 5ти букв английского алфавита, которые могут быть как случайными, так и вводиться пользователем.
 * Полученную мат-рицу обработать следующим образом. Каждое слово матрицы заменить на дру-гое слово, образованное из его букв, упорядоченных по алфавиту.
 * Также требу-ется подсчитать общее количество гласных и согласных букв в исходной мат-рице. Результаты работы вывести на экран*/






int main() {
    cout << "Создаем квадратную матрицу размера M*M, где M является числом из диапазона [2,5]\n";
    string matrix[5][5], t;
    int lines, column;
    char lin[2];
    fail:
    cout << "\tвведите кол-во строк и столбцов:  ";
    cin >> lin;
    if(lin[0] > 49 && lin[0] < 54 && lin[1] == '\0') {
        lines = lin[0] - 48;
        column = lin[0] - 48;
    }
    else {
        cout << "Вы ввели число не из заданного диапозона [2;5]\nПопробуйте еще раз!\n";
        //return 0;
        goto fail;
    }


    char temp;
    int VowelLetters = 0, ConsonantLetters = 0;
    char k[2];
    cout << "\nВыберите вариант действий:\n1. Заполнить матрицу самостоятельно.\n2. Заполнить матрицу случайными словами.\n";
    fail_2:
    cout << "Введите цифру выбранного вами варианта: ";
    cin >> k;
    if(k[0] > 48 && k[0] < 51 && k[1] == '\0'){
        k[0] = k[0] - 48;
    }
    else{
        cout << "Вы ввели номер несуществующего варианта!\nПопробуйте еще раз!\n";
        //return 0;
        goto fail_2;
    }


    if(k[0] == 1){

        cout << "\nЗаполните матрицу M 5-ти значными буквами английского алфавита!\n";
        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < column; j++) {
                fail_1:
                cout << "Введите элемент "<<i+1<< " строчки "<<j+1<< " столбца: ";
                cin >> matrix[i][j];
                if(matrix[i][j][5] == '\0'  && matrix[i][j][4] != '\0')
                    for (int x = 0; x < 5; x++) {
                        if((matrix[i][j][x] < 65 || matrix[i][j][x] > 122) && x < 5){
                            cout << "Вы ввели недопустимые символы!\nПопробуйте еще раз!\n";
                            //return 0;
                            goto fail_1;
                        }
                        for (int x = 0; x < 4; x++) {
                            for (int z = x+1; z < 5; z++)
                                if(matrix[i][j][x] > matrix[i][j][z]) {
                                    temp = matrix[i][j][x];
                                    matrix[i][j][x] = matrix[i][j][z];
                                    matrix[i][j][z] = temp;
                                }
                        }
                    }
                else{
                    cout << "Вы ввели не 5-ти буквенное слово!\nПопробуйте еще раз!\n";
                    //return 0;
                    goto fail_1;
                }
            }
        }

        cout << "\nОтсортированная матрица M: \n";
        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < column; j++) {
                cout << matrix[i][j]<<'\t';
            }
            cout << '\n';
        }



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
        cout<<"Общее количество согласных букв: " << ConsonantLetters<<'\n';
    }
    else{//рандом
        char m[lines][column][5];
        for (int i = 0; i < lines; i++)
            for (int j = 0; j < column; j++)
                for (int x = 0; x < 5; x++)
                    do{
                        m[i][j][x] = 65 + rand() % 58;
                    }while(m[i][j][x] > 90 && m[i][j][x] < 97);

        cout << "\nСлучайно сгенерированная матрица M: \n";
        for (int i = 0; i < lines; i++){
            for (int j = 0; j < column; j++){
                for (int x = 0; x < 5; x++)
                    cout << m[i][j][x];
                cout << '\t';
            }
            cout << '\n';
        }

        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < column; j++){
                for (int x = 0; x < 4; x++) {
                    for (int z = x+1; z < 5; z++) {
                        if(m[i][j][x] > m[i][j][z]) {
                            temp = m[i][j][x];
                            m[i][j][x] = m[i][j][z];
                            m[i][j][z] = temp;
                        }
                    }
                }
            }
        }
        cout << "\nОтсортированная матрица M: \n";
        for (int i = 0; i < lines; i++){
            for (int j = 0; j < column; j++){
                for (int x = 0; x < 5; x++)
                    cout << m[i][j][x];
                cout << '\t';
            }
            cout << '\n';
        }

        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < column; j++) {
                for (int z = 0; z < 5; z++) {
                    if ((m[i][j][z] == 'a') || (m[i][j][z] == 'e') || (m[i][j][z] == 'i') ||
                        (m[i][j][z] == 'o') || (m[i][j][z] == 'u')) {
                        VowelLetters++;
                    } else if ((m[i][j][z] == 'A') || (m[i][j][z] == 'E') || (m[i][j][z] == 'I') ||
                               (m[i][j][z] == 'O') || (m[i][j][z] == 'U')) {
                        VowelLetters++;
                    } else
                        ConsonantLetters++;
                }

            }
        }
        cout << "\nОбщее количесвтво гласных букв: " << VowelLetters << '\n';
        cout << "Общее количество согласных букв: " << ConsonantLetters << '\n';
    }
}

















