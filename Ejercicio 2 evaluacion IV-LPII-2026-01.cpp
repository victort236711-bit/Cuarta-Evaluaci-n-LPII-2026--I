/*

2) Realice un programa que muestre en pantalla un rectángulo SIN RELLENO
(SOLO LOS BORDES), y que dentro del mismo aparezca el año de su
nacimiento tambien graficado con gotoxy.



*/


#include <iostream> 
#include <windows.h>  
#include <conio.h>

using namespace std;


void gotoxy(int x, int y) {  
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y = y;  
    SetConsoleCursorPosition(hcon, dwPos);  
}  
 

void Num2(int x, int y, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == n-1 || i == 0 || i == n/2 || (j == n-1 && i <= n/2) || (j == 0 && i >= n/2)) {
                gotoxy(x + j, y + i);
                cout << "*";
            }
        }
    }
}
 

void Num0(int x, int y, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == n-1 || i == 0 || j == n-1 || j == 0) {
                gotoxy(x + j, y + i);
                cout << "*";
            }
        }
    }
}
 

void Num6(int x, int y, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == n-1 || i == 0 || j == 0 || i == n/2 || (j == n-1 && i >= n/2)) {
                gotoxy(x + j, y + i);
                cout << "*";
            }
        }
    }
}


void rectangulo(int ancho, int alto) {

    for(int x = 0; x < ancho; x++) {
        gotoxy(x, 0);
		cout << "*"; 
        gotoxy(x, alto - 1);
		cout << "*";
    }
    
    
    	for(int y = 1; y < alto - 1; y++) {
    	gotoxy(0, y);
		cout << "*";
        gotoxy(ancho - 1, y);
		cout << "*";
    }
}
 
int main() {  



 
        
        system("cls"); 
        
        
        Num2(7, 5, 5);
        Num0(13, 5, 5);
        Num0(20, 5, 5);
        Num6(27, 5, 5);
        
       
        gotoxy(7, 15);
        cout << "FECHA DE NACIMIENTO: 2006";
        
        gotoxy(13, 17);
        cout << "VICTOR TOVAR";
        
        
        rectangulo(40, 15);
        
        gotoxy(0, 18);
    cout << "Presione cualquier tecla para salir...";
    getch(); 
    
  
    gotoxy(0, 20);
    cout << "Programa finalizado Hasta luego" << endl;
    
     

        

    
    return 0;   
}
