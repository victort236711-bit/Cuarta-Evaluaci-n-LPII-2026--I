/* 7) Realice un programa que permita al usuario ingresar un número entre 1 
y 9999, y este se muestre graficado en pantalla. Use la función gotoxy 
para construir los dígitos. */
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

const int DIGITOS[10][5][5] = {
    { {1,1,1,1,1}, {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {1,1,1,1,1} }, 
    { {0,0,1,0,0}, {0,1,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0}, {1,1,1,1,1} }, 
    { {1,1,1,1,1}, {0,0,0,0,1}, {1,1,1,1,1}, {1,0,0,0,0}, {1,1,1,1,1} }, 
    { {1,1,1,1,1}, {0,0,0,0,1}, {1,1,1,1,1}, {0,0,0,0,1}, {1,1,1,1,1} }, 
    { {1,0,0,0,1}, {1,0,0,0,1}, {1,1,1,1,1}, {0,0,0,0,1}, {0,0,0,0,1} }, 
    { {1,1,1,1,1}, {1,0,0,0,0}, {1,1,1,1,1}, {0,0,0,0,1}, {1,1,1,1,1} }, 
    { {1,1,1,1,1}, {1,0,0,0,0}, {1,1,1,1,1}, {1,0,0,0,1}, {1,1,1,1,1} }, 
    { {1,1,1,1,1}, {0,0,0,0,1}, {0,0,0,1,0}, {0,0,1,0,0}, {0,1,0,0,0} }, 
    { {1,1,1,1,1}, {1,0,0,0,1}, {1,1,1,1,1}, {1,0,0,0,1}, {1,1,1,1,1} }, 
    { {1,1,1,1,1}, {1,0,0,0,1}, {1,1,1,1,1}, {0,0,0,0,1}, {1,1,1,1,1} } 
};

void dibujarDigito(int num, int x, int y) {
    if (num < 0 || num > 9) return;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (DIGITOS[num][i][j] == 1) {
                gotoxy(x + j, y + i);
                cout << "#";
            }
        }
    }
}

int main() {
    char opcion;
    
    do {
        int numero;
        
        do {
            system("cls");
            cout << "=== GRAFICADOR DE NUMEROS ===" << endl;
            cout << "Ingrese un numero entre 1 y 9999: ";
            cin >> numero;
        } while (numero < 1 || numero > 9999);
        
        system("cls");
        
        string numStr = to_string(numero);
        int posX = 10;
        int posY = 5;
        
        for (size_t i = 0; i < numStr.length(); i++) {
            int digito = numStr[i] - '0';
            dibujarDigito(digito, posX + (i * 6), posY);
        }
        
        gotoxy(0, 12);
        cout << "=================================================" << endl;
        cout << "desea ingresar otro numero? (S/N): ";
        cin >> opcion;
        opcion = toupper(opcion);
        
    } while (opcion == 'S' || opcion == 's');
    
    return 0;
}
