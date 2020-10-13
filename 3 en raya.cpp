/*# El-Juego-del-tres-en-raya
Trabajo final*/
#include <iostream>#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

char a = '1', b = '2', c = '3', d = '4', e = '5', f = '6', g = '7', h = '8', i = '9', turn = ' ', ganador, user, maq;
int pos = 0;

void chturn(char& x) {// Esta funcion hace el cambio de turno entre jugadores
    if (x == 'X')
        x = 'O';
    else
        x = 'X';

}

/*
void symandTurn(char& us, char& ma, char& tur){
  char temp;

  cout << "Con que simbolo desea jugar, X or O? ";
  cin >> us;

  while (tur == ' ') {
    if (us == 'x' || us == 'X') {// Diferencia entre mayusculas y minusculas
        us = 'X';
        ma = 'O';
    }
    else if (us == 'o' || us == 'O') { // Diferencia entre mayusculas y minusculas
        us = 'O';
        ma = 'X';
    }
    else {
        cout << "No ingreso un simbolo correcto, intentelo otra vez.";
        cin >> us;
    }
  }

  cout << "Desea ir primero? (Digite 1 para ir primero y 2 para ir segundo)";
  cin >> temp;

  while (temp != '0'){

    if (temp == '1'){
      tur = us;
      temp = '0';
    }
    else if (temp == '2'){
      tur = ma;
      temp = '0';
    }
    else{
      cout << "Escoja un valor adecuado. POR FAVOR: ";
      cin >> temp;
    }
  }

}
*/

void BlockOrWin(char& cas, int& posi) {
    if (a == cas && b == cas && c == '3') {
        posi = 3;
    }
    else if (a == cas && c == cas && b == '2') {
        posi = 2;
    }
    else if (b == cas && c == cas && a == '1') {
        posi = 1;
    }//end primera fila
    else if (d == cas && e == cas && f == '6') {
        posi = 6;
    }
    else if (e == cas && f == cas && d == '4') {
        posi = 4;
    }//end segunda fila
    else if (g == cas && h == cas && i == '9') {
        posi = 9;
    }
    else if (h == cas && i == cas && g == '7') {
        posi = 7;
    }
    else if (g == cas && i == cas && h == '8') {
        posi = 8;
    }//end tererca fila

    else if (a == cas && d == cas && g == '7') {
        posi = 7;
    }
    else if (d == cas && g == cas && a == '1') {
        posi = 1;
    }
    else if (a == cas && g == cas && d == '4') {
        posi = 4;
    }//end primera col

    else if (e == cas && h == cas && b == '2') {
        posi = 2;
    }
    else if (b == cas && e == cas && h == '8') {
        posi = 8;
    }//end segunda col

    else if (c == cas && f == cas && i == '9') {
        posi = 9;
    }
    else if (f == cas && i == cas && c == '3') {
        posi = 3;
    }
    else if (c == cas && i == cas && f == '6') {
        posi = 6;
    }//end tercera col


    else if (e == cas && a == cas && i == '9') {
        posi = 9;
    }
    else if (e == cas && i == cas && a == '1') {
        posi = 1;
    }//diag 1 a 9

    else if (c == cas && e == cas && g == '7') {
        posi = 7;
    }
    else if (e == cas && g == cas && c == '3') {
        posi = 3;
    }//diag 3 a 7

}


void ltactic(char& cas, int& posi) {
    if (((b == cas || c == cas) && (d == cas || g == cas)) && a == '1') {
        posi = 1;
    }
    else if (((a == cas || d == cas) && (h == cas || i == cas)) && g == '7') {
        posi = 7;
    }
    else if (((g == cas || h == cas) && (c == cas || f == cas)) && i == '9') {
        posi = 9;
    }
    else if (((a == cas || b == cas) && (f == cas || i == cas)) && c == '3') {
        posi = 3;
    }

}

void foo(char& x, char& y) {//Esta funcion detecta si el casillero seleccionado esta ocupado
    if (x != 'X' && x != 'O') {
        x = y;
        chturn(y);
    }
    else
        cout << "Esta casilla ya esta ocupada intentelo otra vez!" << endl;

}

void win(char x, char y) {

    if (x == y) {
        cout << "Felicitaciones, gano el jugador." << endl;
    }
    else {
        cout << "Perdedor! Gano la maquina." << endl;
    }
}

void tableReset(){
    a = '1', b = '2', c = '3', d = '4', e = '5', f = '6', g = '7', h = '8', i = '9';
}

bool winCompr(char x, char y, char z){
    if (x == y && x == z){
        ganador = x;
    }
    return (x == y && x == z);
}

void winSit(){

    if (winCompr(a, b, c) || winCompr(d, e, f) || winCompr(g, h, i) || winCompr(a, d, g) || winCompr(b, e, h) || winCompr(c, f, i) || winCompr(a, e ,i) || winCompr(g, e, c)){

        win(ganador, user);

        cout << "Si desea volver a jugar digite 0: ";
        cin >> pos;

        if (pos == 0){
            tableReset();
            turn = user; //Volver a escoger simbolo y turno
        }
        else {
            pos = -1;
        }
    }
}

bool check(char x) {
    bool temp = (x == 'X' || x == 'O');
    return temp;
}

int main() {
    srand((unsigned)time(0)); //Unsigned = sin signo

    cout << "Con que simbolo desea jugar, X or O? ";
    cin >> user;

    while (turn == ' ') {
        if (user == 'x' || user == 'X') {// Diferencia entre mayusculas y minusculas
            user = 'X';
            maq = 'O';
            turn = user;
        }
        else if (user == 'o' || user == 'O') { // Diferencia entre mayusculas y minusculas
            user = 'O';
            maq = 'X';
            turn = user;
        }
        else {
            cout << "No ingreso un simbolo correcto, intentelo otra vez.";
            cin >> user;
        }
    }

    cout << "Usted es: " << user << endl;
    cout << "La maquina sera: " << maq << endl << endl;

    cout << "   " << a << "\t|   " << b << "\t|   " << c << endl;
    cout << "-------------------------\n";
    cout << "   " << d << "\t|   " << e << "\t|   " << f << endl;
    cout << "-------------------------\n";
    cout << "   " << g << "\t|   " << h << "\t|   " << i << endl << endl;

    while (pos != -1) {

        int aux = 10;

        if (turn == user) {
            cout << "Turno del usuario: " << endl;
            cout << "Ingrese una posicion (del 1 al 9): ";
            cin >> pos;
            cout << endl;
        }
        else if (turn == maq){
            cout << "Turno de la maquina: " << endl;
            if (e == '5') {
                pos = 5;
            }
            else {
                while (aux != pos) {
                    int random = (rand() % 9) + 1, temp = aux;

                    if (aux == temp) {
                        BlockOrWin(maq, aux);
                    }
                    if (aux == temp) {
                        BlockOrWin(user, aux);
                    }
                    if (aux == temp) {
                        ltactic(user, aux);
                    }
                    if (aux == temp) {
                        ltactic(maq, aux);
                    }

                    while (aux == temp) {
                        if (random == 5) {
                            aux = 7;
                        }
                        else if (random % 2 == 1) {
                            aux = random;
                        }
                        if (a == '1' || c == '3' || g == '7' || i == '9'){
                          if (random == 2 || random == 4) {
                              aux = random - 1;
                          }
                          else if (random == 6 || random == 8) {
                              aux = random + 1;
                          }
                        }
                        else if (random % 2 == 0){
                          aux = random;
                        }
                    }



                    if (aux != a && aux != b && aux != c && aux != d && aux != e && aux != f && aux != g && aux != h && aux != i)
                        pos = aux;
                }
            }

        }

        switch (pos) {

        case 1:
            foo(a, turn);
            break;
        case 2:
            foo(b, turn);
            break;
        case 3:
            foo(c, turn);
            break;
        case 4:
            foo(d, turn);
            break;
        case 5:
            foo(e, turn);
            break;
        case 6:
            foo(f, turn);
            break;
        case 7:
            foo(g, turn);
            break;
        case 8:
            foo(h, turn);
            break;
        case 9:
            foo(i, turn);
            break;
        default:
            cout << "DEBE ESCOGER UN VALOR ENTRE 1 y 9." << endl;
            cin >> pos;
        }

        cout << "   " << a << "\t|   " << b << "\t|   " << c << endl;
        cout << "-------------------------\n";
        cout << "   " << d << "\t|   " << e << "\t|   " << f << endl;
        cout << "-------------------------\n";
        cout << "   " << g << "\t|   " << h << "\t|   " << i << endl << endl;

        winSit();

        if (check(a) && check(b) && check(c) && check(d) && check(e) && check(f) && check(g) && check(h) && check(i)) {
            cout << "EMPATE. Todos los casilleros estan llenos. Si desea volver a comenzar digite 0: ";
            cin >> pos;
            if (pos == 0) {
                tableReset();
                turn = user;
                //symandTurn(user, maq, turn);
            }
            else {
                pos = -1;
            }


        }
    }

    //system("CLS");
    return 0;
}
