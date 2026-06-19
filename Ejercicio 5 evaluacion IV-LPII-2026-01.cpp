/*

5) Realice un programa que permita al usuario:
1. Convertir $ a Bs
2. Convertir Bs a euros
3. Calcular cuánto tiempo necesitaría ahorrar para lograr una meta
monetaria ingresada por teclado, partiendo de un salario mensual
base ingresado por teclado y gastos mensuales fijos ingresados por
teclado.
4. Calcular cuánto tardaría en alcanzar un peso deseado, partiendo de
un peso actual ingresado por teclado y una medida de kg que es
capaz de comprometerse a perder por mes. 




*/

#include <iostream>

using namespace std;

int main() {
    char opc;

    do {
       
        double dolares = 0;
        double bolivares = 0;
        double euro = 0;
        double salario = 0;
        double gastos = 0;
        double meta = 0;
        double ahorro_mensual = 0;
        double meses_ahorro = 0;
        double tasaDolar = 0;
        double tasaEuro = 0;
        double peso_actual = 0;
        double peso_deseado = 0;
        double kg_por_mes = 0;
        double meses_peso = 0;
        
     
        cout << "\n---- Convertir de dolares a bolivares ----" << endl;
        cout << "Ingresar la tasa del dolar: ";
        cin >> tasaDolar;
        cout << "Ingresar la cantidad de dolares: ";
        cin >> dolares;
        
        bolivares = dolares * tasaDolar;
       
        cout << fixed; 
        cout.precision(2);
        cout << "Es equivalente a: " << bolivares << " Bolivares." << endl << endl;
        
        
        cout << "---- Convertir de bolivares a Euros ----" << endl;
        cout << "Ingrese la tasa de euros (Bs por Euro): ";
        cin >> tasaEuro;
        cout << "Ingresar la cantidad de bolivares: ";
        cin >> bolivares;
        
        if (tasaEuro > 0) {
            euro = bolivares / tasaEuro;
            cout << "Es equivalente a: " << euro << " Euros" << endl << endl;
        } else {
            cout << "La tasa no puede ser cero." << endl << endl;
        }
        
   
        cout << "--------- Calcular tiempo de ahorro ------------" << endl;
        cout << "Ingrese su salario mensual: ";
        cin >> salario;
        cout << "Ingrese sus gastos mensuales: ";
        cin >> gastos;
        cout << "Ingrese su meta de dinero: ";
        cin >> meta;
        
        ahorro_mensual = salario - gastos;
        
        if (ahorro_mensual > 0) {
            meses_ahorro = meta / ahorro_mensual;
            cout << "Puede tardar un tiempo estimado de: " << meses_ahorro << " meses." << endl << endl;
        } else {
            cout << "Alerta: Sus gastos son mayores o iguales a su salario. ¡No puede ahorrar!" << endl << endl;
        }
       
        cout << "--------- Tiempo para perder su peso ------------" << endl;
        cout << "Ingrese su peso actual (kg): ";
        cin >> peso_actual;
        cout << "Ingrese su peso deseado (kg): ";
        cin >> peso_deseado;
        cout << "Ingrese cuantos kg perdera por mes: ";
        cin >> kg_por_mes;
        
        if (peso_actual > peso_deseado && kg_por_mes > 0) {
            meses_peso = (peso_actual - peso_deseado) / kg_por_mes;
            cout << "Tardara aproximadamente " << meses_peso << " meses en alcanzar su meta." << endl << endl;
        } else if (peso_actual <= peso_deseado) {
            cout << "¡Ya estas en tu peso ideal o por debajo de el!" << endl << endl;
        } else {
            cout << "La cantidad de kg por mes debe ser mayor a 0." << endl << endl;
        }
        
        cout << "---------------------------------------" << endl;
        cout << " desea repetir el programa? (s/n): ";
        cin >> opc;
        
    } while (opc == 's' || opc == 'S');

    return 0;
}
