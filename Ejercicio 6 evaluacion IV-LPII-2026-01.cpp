#include <iostream>
#include <string>
#include <cctype>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

bool validarNombre(string nombre) {
    if (nombre.length() > 8) {
        return false;
    }
    for (char c : nombre) {
        if (!isalpha(c)) return false; 
    }
    return true;
}

const int LETRAS[26][5][5] = {
    { {0,1,1,1,0}, {1,0,0,0,1}, {1,1,1,1,1}, {1,0,0,0,1}, {1,0,0,0,1} }, // A
    { {1,1,1,1,0}, {1,0,0,0,1}, {1,1,1,1,0}, {1,0,0,0,1}, {1,1,1,1,0} }, // B
    { {0,1,1,1,1}, {1,0,0,0,0}, {1,0,0,0,0}, {1,0,0,0,0}, {0,1,1,1,1} }, // C
    { {1,1,1,1,0}, {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {1,1,1,1,0} }, // D
    { {1,1,1,1,1}, {1,0,0,0,0}, {1,1,1,1,0}, {1,0,0,0,0}, {1,1,1,1,1} }, // E
    { {1,1,1,1,1}, {1,0,0,0,0}, {1,1,1,1,0}, {1,0,0,0,0}, {1,0,0,0,0} }, // F
    { {0,1,1,1,1}, {1,0,0,0,0}, {1,0,1,1,1}, {1,0,0,0,1}, {0,1,1,1,1} }, // G
    { {1,0,0,0,1}, {1,0,0,0,1}, {1,1,1,1,1}, {1,0,0,0,1}, {1,0,0,0,1} }, // H
    { {1,1,1,1,1}, {0,0,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0}, {1,1,1,1,1} }, // I
    { {0,0,1,1,1}, {0,0,0,1,0}, {0,0,0,1,0}, {1,0,0,1,0}, {0,1,1,0,0} }, // J
    { {1,0,0,0,1}, {1,0,0,1,0}, {1,1,1,0,0}, {1,0,0,1,0}, {1,0,0,0,1} }, // K
    { {1,0,0,0,0}, {1,0,0,0,0}, {1,0,0,0,0}, {1,0,0,0,0}, {1,1,1,1,1} }, // L
    { {1,0,0,0,1}, {1,1,0,1,1}, {1,0,1,0,1}, {1,0,0,0,1}, {1,0,0,0,1} }, // M
    { {1,0,0,0,1}, {1,1,0,0,1}, {1,0,1,0,1}, {1,0,0,1,1}, {1,0,0,0,1} }, // N
    { {0,1,1,1,0}, {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {0,1,1,1,0} }, // O
    { {1,1,1,1,0}, {1,0,0,0,1}, {1,1,1,1,0}, {1,0,0,0,0}, {1,0,0,0,0} }, // P
    { {0,1,1,1,0}, {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,1,1}, {0,1,1,1,1} }, // Q
    { {1,1,1,1,0}, {1,0,0,0,1}, {1,1,1,1,0}, {1,0,0,1,0}, {1,0,0,0,1} }, // R
    { {0,1,1,1,1}, {1,0,0,0,0}, {0,1,1,1,0}, {0,0,0,0,1}, {1,1,1,1,0} }, // S
    { {1,1,1,1,1}, {0,0,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0} }, // T
    { {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {0,1,1,1,0} }, // U
    { {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {0,1,0,1,0}, {0,0,1,0,0} }, // V
    { {1,0,0,0,1}, {1,0,0,0,1}, {1,0,1,0,1}, {1,1,0,1,1}, {1,0,0,0,1} }, // W
    { {1,0,0,0,1}, {0,1,0,1,0}, {0,0,1,0,0}, {0,1,0,1,0}, {1,0,0,0,1} }, // X
    { {1,0,0,0,1}, {0,1,0,1,0}, {0,0,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0} }, // Y
    { {1,1,1,1,1}, {0,0,0,1,0}, {0,0,1,0,0}, {0,1,0,0,0}, {1,1,1,1,1} }  // Z
};

void dibujarLetra(char letra, int x, int y) {
    letra = toupper(letra);
    if (letra < 'A' || letra > 'Z') return;
    
    int indice = letra - 'A';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (LETRAS[indice][i][j] == 1) {
                gotoxy(x + j, y + i);
                cout << "*";
            }
        }
    }
}

int main() {
    char opcion;
    
    do {
        string nombre;
        
        do {
            system("cls");
            cout << "=== GRAFICADOR DE NOMBRES ===" << endl;
            cout << "Ingrese un nombre (Max 8 caracteres, sin caracteres especiales): ";
            cin >> nombre;
        } while (!validarNombre(nombre));
        
        system("cls");
        
        int anchoConsola = 80;
        int altoConsola = 25;
        
        int anchoTotalNombre = (nombre.length() * 5) + (nombre.length() - 1);
        
        int inicioX = (anchoConsola - anchoTotalNombre) / 2;
        int inicioY = (altoConsola - 5) / 2;
        
        for (size_t i = 0; i < nombre.length(); i++) {
            dibujarLetra(nombre[i], inicioX + (i * 6), inicioY);
        }
        
        gotoxy(0, 21);
        cout << "=================================================" << endl;
        cout << "desea procesar otro nombre? (S/N): ";
        cin >> opcion;
        opcion = toupper(opcion);
        
    } while (opcion == 'S' || opcion == 's');
    
    return 0;
}