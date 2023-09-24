#include <iostream>
/*1) int* ptr = (int*)malloc(sizeof(int)) - int* ptr = new int
2) int* ptrArr = (int*)malloc(sizeof(int) * N) - int* ptrArr = new int[N]
3) free(ptr) - delete ptr
4) free(ptrArr) - delete[] ptrArr

да, нужно освобождать динамическую память
нет, нельзя, ибо невозможно предугадать, как поведёт себя программа
нельзя освободить невыделенную программу, если она не была выделена
*/
int main() {
    
    int n;
    std::cout << "enter amount of string of Fibonacci's triangle : "; /*не понимаю почему нормально не получается расшифровать латиницу*/
    std::cin >> n;

    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[i + 1];
    }

    arr[0][0] = 1;
    for (int i = 1; i < n; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
        for (int j = 1; j < i; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}