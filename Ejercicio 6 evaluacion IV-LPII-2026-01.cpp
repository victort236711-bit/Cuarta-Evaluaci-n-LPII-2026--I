/* 6) Realice un programa que permita al usuario graficar el nombre de su 
preferencia en pantalla. Es decir, que ingrese un nombre por consola y, a 
partir de esa entrada, se grafique en pantalla usando la función gotoxy, 
el nombre solicitado, centrado y con un tamaño mínimo de N=5. El nombre 
como máximo puede tener 8 caracteres. Valide que no se incluyan 
caracteres especiales. */

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
    { {0,1,1,1,0}, {1,0,0,0,1}, {1,1,1,1,1}, {1,0,0,0,1}, {1,0,0,0,1} }, 
    { {1,1,1,1,0}, {1,0,0,0,1}, {1,1,1,1,0}, {1,0,0,0,1}, {1,1,1,1,0} }, 
    { {0,1,1,1,1}, {1,0,0,0,0}, {1,0,0,0,0}, {1,0,0,0,0}, {0,1,1,1,1} }, 
    { {1,1,1,1,0}, {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {1,1,1,1,0} }, 
    { {1,1,1,1,1}, {1,0,0,0,0}, {1,1,1,1,0}, {1,0,0,0,0}, {1,1,1,1,1} }, 
    { {1,1,1,1,1}, {1,0,0,0,0}, {1,1,1,1,0}, {1,0,0,0,0}, {1,0,0,0,0} }, 
    { {0,1,1,1,1}, {1,0,0,0,0}, {1,0,1,1,1}, {1,0,0,0,1}, {0,1,1,1,1} }, 
    { {1,0,0,0,1}, {1,0,0,0,1}, {1,1,1,1,1}, {1,0,0,0,1}, {1,0,0,0,1} }, 
    { {1,1,1,1,1}, {0,0,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0}, {1,1,1,1,1} }, 
    { {0,0,1,1,1}, {0,0,0,1,0}, {0,0,0,1,0}, {1,0,0,1,0}, {0,1,1,0,0} }, 
    { {1,0,0,0,1}, {1,0,0,1,0}, {1,1,1,0,0}, {1,0,0,1,0}, {1,0,0,0,1} }, 
    { {1,0,0,0,0}, {1,0,0,0,0}, {1,0,0,0,0}, {1,0,0,0,0}, {1,1,1,1,1} }, 
    { {1,0,0,0,1}, {1,1,0,1,1}, {1,0,1,0,1}, {1,0,0,0,1}, {1,0,0,0,1} }, 
    { {1,0,0,0,1}, {1,1,0,0,1}, {1,0,1,0,1}, {1,0,0,1,1}, {1,0,0,0,1} }, 
    { {0,1,1,1,0}, {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {0,1,1,1,0} }, 
    { {1,1,1,1,0}, {1,0,0,0,1}, {1,1,1,1,0}, {1,0,0,0,0}, {1,0,0,0,0} }, 
    { {0,1,1,1,0}, {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,1,1}, {0,1,1,1,1} }, 
    { {1,1,1,1,0}, {1,0,0,0,1}, {1,1,1,1,0}, {1,0,0,1,0}, {1,0,0,0,1} }, 
    { {0,1,1,1,1}, {1,0,0,0,0}, {0,1,1,1,0}, {0,0,0,0,1}, {1,1,1,1,0} }, 
    { {1,1,1,1,1}, {0,0,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0} }, 
    { {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {0,1,1,1,0} }, 
    { {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {0,1,0,1,0}, {0,0,1,0,0} }, 
    { {1,0,0,0,1}, {1,0,0,0,1}, {1,0,1,0,1}, {1,1,0,1,1}, {1,0,0,0,1} }, 
    { {1,0,0,0,1}, {0,1,0,1,0}, {0,0,1,0,0}, {0,1,0,1,0}, {1,0,0,0,1} }, 
    { {1,0,0,0,1}, {0,1,0,1,0}, {0,0,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0} }, 
    { {1,1,1,1,1}, {0,0,0,1,0}, {0,0,1,0,0}, {0,1,0,0,0}, {1,1,1,1,1} }  
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
        
    } while (opcion == 'S');
    
    return 0;
}
