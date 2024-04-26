#include <iostream>
#include <math.h>

using namespace std;

float soma(float a, float b) {
    return a + b;
}

float sub(float a, float b) {
    return a - b;
}

float mult(float a, float b) {
    return a * b;
}

float divid(float a, float b) {
    return a / b;
}

float potencia(float a, float b) {
    return pow(a, b);
}

float raiz(float a, float b) {
    float exp = 1 / b;
    return pow(a, exp);
}

float percent(float a) {
    return a / 100;
}

float pri_num(char voip[50]) {
    int meio;
    // Descobri onde está o operador e onde termina a jogada
    for (int i = 0; i < 50; i++) {
        if (voip[i] == '+' || voip[i] == '-' || voip[i] == '*' || voip[i] == '/' || voip[i] == '^' || voip[i] == '%' || voip[i] == '#') {
            meio = i;
        }
    }

    // Transformar char em float e somar
    int total = 0; int gamb;
    for (int i = 1; i <= meio; i++) {
        int dez = i - 1;
        int a = voip[meio - i] - '0';
        a *= pow(10, dez);
        total += a;
        gamb = dez;
    }

    int less = 0;
    for (int i = 1; i <= gamb; i++) {
        int a = pow(2, i);
        less += gamb / a;
    }
    return total + less;
}

float seg_num(char voip[50]) {
    int meio; int final;
    // Descobri onde está o operador e onde termina a jogada
    for (int i = 0; i < 50; i++) {
        if (voip[i] == '+' || voip[i] == '-' || voip[i] == '*' || voip[i] == '/' || voip[i] == '^' || voip[i] == '%' || voip[i] == '#') {
            meio = i;
        }
        else if(voip[i] == '='){
            final = i;
        }
    }

    // Transformar char em float e somar
    int total = 0; int gamb;
    for (int i = meio+1; i < final; i++) {
        int a = voip [i] - '0';
        int dez = (final-i-1);
        a = a * pow (10,dez);
        total += a;
        gamb = dez;
    }

    int less = 0;
    for (int i = 1; i <= gamb; i++) {
        int a = pow(2, i);
        less += gamb / a;
    }
    return total + less;
}

char operador (char voip [50]){

    int meio;
    for (int i = 0; i < 50; i++) {
        if (voip[i] == '+' || voip[i] == '-' || voip[i] == '*' || voip[i] == '/' || voip[i] == '^' || voip[i] == '%' || voip[i] == '#') {
            meio = i;
        }
    }

    return voip [meio];
}

float resultado(char voip [50]) {
    
    int a = pri_num(voip);
    int b = seg_num(voip);
    char op = operador(voip);
    float resultado = 0.0;

    cout << a;
    cout << b;
    cout << op;

    if (op == '+') {
        float resultado = soma(a, b);
    } else if (op == '-') {
        float resultado = sub(a, b);
    } else if (op == '*') {
        float resultado = mult(a, b);
    } else if (op == '/') {
        float resultado = divid(a, b);
    } else if (op == '^') {
        float resultado = potencia(a, b);
    } else if (op == '%') {
        float resultado = percent(a);
    } else {
        cout << "Operador não reconhecido.";
    }

return resultado;
}

int main() {
    char expressao[50];

    cout << "Bem-vindo à calculadora virtual" << endl;
    cout << "-------------------------------------" << endl;
    cout << "|  C  A  L  C  U  L  A  D  O  R  A  |" << endl;
    cout << "-------------------------------------" << endl;

    cout << "Digite a expressão que deseja realizar: ";
    cin >> expressao;

    cout << "Resultado: " << resultado(expressao) << endl;

    return 0;
}



/*float sec_num (char voip[50]){


int meio ; int final;
 
for (int i = 0; i < 50; i++){

if (voip[i] == '+' || voip[i] == '-' || voip[i] == '*' || voip[i] == '/' || voip[i] == '^' || voip[i] == '%' || voip[i] == '#'){

meio = i;

}

else if (voip [i] == '='){

final = i;

}

}

cout << meio << " " << final ;

}*/


