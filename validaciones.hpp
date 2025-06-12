#include <iostream>//Libreria estandar
#include <stdlib.h>//Libreria estandar
#include <conio.h>//Libreria estandar
#include <locale.h>//Libreria para poder poner la ñ
#include <cstdlib>//Librerias para limpiar pantalla
#include <cstring>//Libreria para estilizar
#include <math.h>//Libreria de matematicas
#include <cmath>//Libreria de matematicas
#include <string>//Libreria de los strings
#include <sstream>//Libreria para strings
#include <regex>//Para las expresiones regulares
using namespace std;//Libreria estandar

//Validacion de cadenas
bool esDigito(const string *texto){
    for (char c : *texto) {
        if (!isalpha(c)) { // Verificar si el carácter no es una letra
            return false;
        }
    }
    return true;
}

//Funciones de validacion de datos ingresados
bool esNumero(const string* cadena) {
    if ((*cadena).length() > 10) {
        return false;
    }
    for(char c : *cadena) {
        if (!isdigit(c) || isspace(c)) {
            return false;
        }
    }
    return true;
}

bool esTiempo(const string& texto) {
    // Comprobar que el texto tenga el formato MM:SS
    regex patron("^([0-5][0-9]):([0-5][0-9])$");
    return regex_match(texto, patron);
}

bool isNumber(const string* input){
    if((*input).length() > 10){
        cout<<"El numero ingresado es muy grande, ingresa uno mas corto"<<endl;
        return false;
    }
    istringstream ss(*input);
    double* value = (double*)malloc(sizeof(double));
    if (ss >> *value) {
        char c;
        double* pointCount = (double*)malloc(sizeof(double));
        double* decimalCount = (double*)malloc(sizeof(double));
        *pointCount = 0;
        *decimalCount = 0;
        while (ss >> c) {
            if (c == '.') {
                (*pointCount)++;
                if ((*pointCount) > 1) {
                    cout<<"Hay mas de un punto, por favor solo ingresa uno"<<endl;
                    return false; // hay más de un punto en la cadena, lo que significa que no es un número válido
                }
            }
            else if (c == ',') {
                cout<<"Recuera hacer uso del punto, no de la ','"<<endl;
                return false; // la cadena contiene una coma, lo que significa que no es un número válido
            }
            else if (isdigit(c)) {
                (*decimalCount)++;
                if ((*pointCount) >= 1) {
                    if ((*decimalCount) > 0) {
                        cout<<"Lo que ingresaste no es un numero valido"<<endl;
                        return false; // hay más de una cifra después del punto, lo que significa que no es un número válido
                    }
                }
            }
            else {
                cout<<"Lo que ingresaste no es un numero, por favor ingresa uno"<<endl;
                return false; // hay caracteres después del número y no son un punto ni una cifra, lo que significa que no es un número válido
            }
        }
        return true;
    }
    cout<<"Lo que ingresaste no es un numero valido"<<endl;
    return false; // no se pudo leer un número válido
}

bool isNumberPos(const string* input){
    if((*input).length() > 9){
        cout<<"El numero ingresado es muy grande, ingresa uno mas corto"<<endl;
        return false;
    }
    for(char c: *input){
        if(c == '-'){
            cout<<"Numero ingresado no valido , por favor ingresa un numero positivo"<<endl;
            return false;
        }
    }
    istringstream ss(*input);
    double* value = (double*)malloc(sizeof(double));
    if (ss >> *value) {
        char c;
        double* pointCount = (double*)malloc(sizeof(double));
        double* decimalCount = (double*)malloc(sizeof(double));
        *pointCount = 0;
        *decimalCount = 0;
        while (ss >> c) {
            if (c == '.') {
                (*pointCount)++;
                if ((*pointCount) > 1) {
                    cout<<"Hay mas de un punto, por favor solo ingresa uno"<<endl;
                    return false; // hay más de un punto en la cadena, lo que significa que no es un número válido
                }
            }
            else if (c == ',') {
                cout<<"Recuera hacer uso del punto, no de la 'n'"<<endl;
                return false; // la cadena contiene una coma, lo que significa que no es un número válido
            }
            else if (isdigit(c)) {
                (*decimalCount)++;
                if ((*pointCount) >= 1) {
                    if ((*decimalCount) > 0) {
                        cout<<"Lo que ingresaste no es un numero valido"<<endl;
                        return false; // hay más de una cifra después del punto, lo que significa que no es un número válido
                    }
                }
            }
            else {
                cout<<"Lo que ingresaste no es un numero, por favor ingresa uno"<<endl;
                return false; // hay caracteres después del número y no son un punto ni una cifra, lo que significa que no es un número válido
            }
        }
        return true;
    }
    cout<<"Lo que ingresaste no es un numero valido"<<endl;
    return false; // no se pudo leer un número válido
}


bool esBinario(string* binario) {
    int* auxf = (int*)malloc(sizeof(int));
    int* digit = (int*)malloc(sizeof(int));
    if ((*binario).length() > 10) {
        cout << "El numero ingresado es demasiado grande, por favor intenta con uno mas corto" << endl;
        return false;
    }
    for (char c : *binario) {
        if (!isdigit(c)) {
            return false;
        }
    }
    *auxf = stoi(*binario);
    *digit = (*auxf) % 10;
    if (*digit != 0 && *digit != 1) {
        return false;
    }
    return true;
}

bool esOctal(int* numero) {
    while ((*numero) != 0) {
        int digito = (*numero) % 10;
        if (digito < 0 || digito > 7) {
            return false;
        }
        (*numero) /= 10;
    }
    return true;
}

bool esHexadecimal(string* numero) {
    if ((*numero).length() > 10) {
        cout << "El numero ingresado es demasiado grande, por favor ingresa uno mas corto" << endl;
        return false;
    }
    for (char c : *numero) {
        if (!isxdigit(c) || (isalpha(c) && !isupper(c))) {
            return false;
        }
    }
    return true;
}