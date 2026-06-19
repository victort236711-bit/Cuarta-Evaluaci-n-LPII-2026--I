/*

1) Realice un programa que grafique en pantalla un pequeño laberinto con
mínimo 2 obstáculos, diseñe un pequeño “personaje”, que bien puede ser
una letra o una forma de su elección. Su personaje debe moverse dentro
del laberinto y si choca con los bordes debe informar en pantalla al
usuario que perdió. Incluya una “meta”, que al ser alcanzada (Al final
del laberinto), muestre en pantalla al usuario que ganó y posteriormente
resetee el laberinto.

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

void ocultarCursor() {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hcon, &cci);
}


void dibujarMapa(int ancho, int alto, int obs1X, int obs1Y, int obs2X, int obs2Y, int metaX, int metaY) {
    system("cls");
    
   
    for(int x = 0; x < ancho; x++) {
        gotoxy(x, 0); cout << "*";    
        gotoxy(x, alto - 1); cout << "*";
    }
    for(int y = 0; y < alto; y++) {
        gotoxy(0, y); cout << "*";
        gotoxy(ancho - 1, y); cout << "*";
    }
    
    
    gotoxy(obs1X, obs1Y); cout << "***";
    gotoxy(obs2X, obs2Y); cout << "****";
    gotoxy(metaX, metaY); cout << "X";
    
    

    gotoxy(0, alto + 1);
    cout << "-------------Teclado para moverse------------" << endl;
    cout<<"---W Arriba-- "<<"---S Abajo---";
	cout<<"---A Izquierda--"<<"---D derecha--"<<endl<<endl;

}

int main() {
    ocultarCursor();
    
    int ancho = 40;
    int alto = 15;

    int x = 3;
    int y = 3;
    
    
    int xAnt = x;
    int yAnt = y;

    int metaX = 35; int metaY = 12;
    int obs1X = 15; int obs1Y = 5;
    int obs2X = 25; int obs2Y = 9;

    char tecla;
    bool ejecutando = true; 
    bool redibujarEscenario = true;

    do {
       
        if (redibujarEscenario) {
            dibujarMapa(ancho, alto, obs1X, obs1Y, obs2X, obs2Y, metaX, metaY);
            redibujarEscenario = false;
        }
        
       
        gotoxy(xAnt, yAnt); cout << " ";
      
      
        gotoxy(x, y); cout << "O";
        
       
        xAnt = x;
        yAnt = y;

        tecla = _getch();

        switch(tecla) {
            case 'w':
			 case 'W': y--; break;
            case 's': 
			case 'S': y++; break;
            case 'a': 
			case 'A': x--; break;
            case 'd': 
			case 'D': x++; break;
        }

        bool chocoObs1 = (y == obs1Y && x >= obs1X && x < obs1X + 3);
        bool chocoObs2 = (y == obs2Y && x >= obs2X && x < obs2X + 4);

        if (x <= 0 || x >= ancho - 1 || y <= 0 || y >= alto - 1 || chocoObs1 || chocoObs2) {
            
            char respuesta = ' ';
            system("cls"); 
   
            while (respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N') {
                gotoxy(0, 2);
                cout << "Perdiste chocaste con el limite u obstaculo" << endl;
                cout << "Deseas continuar con el juego? (s/n): ";
                respuesta = _getch();
            }

            if (respuesta == 'n' || respuesta == 'N') {
                ejecutando = false; 
            } else {
                x = 3; 
                y = 3; 
                xAnt = 3;
                yAnt = 3;
                redibujarEscenario = true; 
            }
        }
        
        else if (x == metaX && y == metaY) {
            gotoxy(0, alto + 3);
            cout << "---GANASTE EL JUEGO SIGUE ASI BRO--- "<<endl<<endl;
            system("pause");
            x = 3; y = 3; 
            xAnt = 3; yAnt = 3;
            redibujarEscenario = true;
        }

    } while(ejecutando);

    system("cls");
    cout << "----Gracias por jugar bro--- " << endl;
    return 0;
}
