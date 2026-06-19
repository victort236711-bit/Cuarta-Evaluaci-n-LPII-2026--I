/*

4) Escriba, compile y ejecute un programa que permita al usuario elegir
entre tres figuras que se muestren en pantalla: Un cuadrado, un triángulo
y un rectángulo.


*/



        

    
#include <iostream>
#include <windows.h> 
#include<conio.h>

using namespace std;


void gotoxy(int x, int y) {  
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y = y;  
    SetConsoleCursorPosition(hcon, dwPos); 
}



void cuadrado(int lado) {
    for(int y = 0; y < lado; y++) {
        for(int x = 0; x < lado; x++) {
            
            if(y == 0 || y == lado - 1 || x == 0 || x == lado - 1) {
                gotoxy(x, y);
                cout << "*";
            }
        }
    }
}

void rectangulo(int ancho, int alto) {
    for(int y = 0; y < alto; y++) {
        for(int x = 0; x < ancho; x++) {
            
            if(y == 0 || y == alto - 1 || x == 0 || x == ancho - 1) {
                gotoxy(x, y);
                cout << "*";
            }
        }
    }
}

void triangulo(int altura) {
    for(int y = 0; y < altura; y++) {
        for(int x = 0; x <= y; x++) {
           
            if(x == 0 || y == altura - 1 || x == y) {
                gotoxy(x, y);
                cout << "*";
            }
        }
    }
}


int main() {   
    int opcion;
    char continuar;

   do {
        system("cls"); 
        
        cout << "1. Dibujar Cuadrado" << endl;
        cout << "2. Dibujar Triangulo " << endl;
        cout << "3. Dibujar Rectangulo " << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        system("cls"); 

        switch(opcion) {
            case 1:
                cuadrado(15);
                break;
            case 2:
                triangulo(12); 
                break;
            case 3:
                rectangulo(40, 14);
                break;
            case 4:
                gotoxy(0, 0);
                cout << "Eso fue todo" << endl;
                return 0; 
            default:
                gotoxy(0, 0);
                cout << "Opcion no valida." << endl;
        }

        gotoxy(0, 16); 
        cout << "¿Desea elegir otra figura? (S/N): ";
        cin >> continuar;


    } while(continuar == 's' || continuar == 'S');

  
    system("cls");
    gotoxy(0, 0);
    cout << "Eso fue todo sobre el programa de figuras " << endl;

    return 0;
}
