#include <iostream>//Libreria estandar
#include <stdlib.h>//Libreria estandar
#include <locale.h>//Libreria para poder poner la ñ
#include <cstdlib>//Librerias para limpiar pantalla
#include <cstring>//Libreria para estilizar
#include <ctime>//Libreria para el tiempo
#include <windows.h>  //Libreria para usar gotoxy
#include <sstream>//Libreria para strings
#include <iomanip>
#include <conio.h>
#include "archivos.hpp"
//#include "lista_Circular.hpp"
using namespace std;//Libreria estandar

void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}

void clean_window(){
    for(int y = 0; y < 9; y++){
        gotoxy(97,33 + y);cout<<string(39, ' ')<<char(186)<<string(10, ' ');
    }
}

void blind_cursor(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    //volver a mostrar el cursor
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void window_setting(){
    system("mode con: cols=145 lines=44");
    system("title Reproductor de Musica");
    system("color 02");
    // Cambiar color del texto 
    /*
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    */
}

void print_window(){
    gotoxy(5,1);cout<<char(201)<<string(130, char(205))<<char(187);
    for(int x = 0; x < 40; x++){
        gotoxy(5, 2 + x);cout<<char(186);
        gotoxy(136, 2 + x);cout<<char(186);
    }
    gotoxy(5, 42);cout<<char(200)<<string(130, char(205))<<char(188);
    gotoxy(5,5);cout<<char(204)<<string(130,char(205))<<char(185);
    //gotoxy(65,3);cout<<"REPRODUCTOR DE MUSICA";
    gotoxy(6,6);cout<<" Indice ";
    gotoxy(16,6);cout<<" Nombre de la cancion    ";
    gotoxy(53,6);cout<<" Artista ";
    gotoxy(80,6);cout<<" Duracion ";

    for(int y = 0; y < 36; y++){
        gotoxy(95,6 + y);cout<<char(186);
    }
    for(int y = 0; y < 27; y++){
        gotoxy(15,6 + y);cout<<char(186);
        gotoxy(52,6 + y);cout<<char(186);
        gotoxy(79,6 + y);cout<<char(186);
        gotoxy(100,6 + y);cout<<char(186);
    }
    gotoxy(5,32);cout<<string(131,char(205));
    gotoxy(97,6);cout<<"1"; 
    gotoxy(101,6);cout<<" Registrar nueva cancion"; 
    gotoxy(96,7);cout<<string(40,char(205));
    gotoxy(97,8);cout<<"2"; 
    gotoxy(101,8);cout<<" Buscar por:"; 
    gotoxy(101,9);cout<<"    1-Id"; 
    gotoxy(101,10);cout<<"    2-Nombre Cancion"; 
    gotoxy(101,11);cout<<"    3-Nombre Artista"; 
    gotoxy(96,12);cout<<string(40,char(205));
    gotoxy(97,13);cout<<"3"; 
    gotoxy(101,13);cout<<" Ordenar por:"; 
    gotoxy(101,14);cout<<"    1-Nombre cancion"; 
    gotoxy(101,15);cout<<"    2-Nombre Artista"; 
    gotoxy(101,16);cout<<"    3-Ascendente"; 
    gotoxy(101,17);cout<<"    4-Descendente"; 
    gotoxy(96,18);cout<<string(40,char(205));
    gotoxy(97,19);cout<<"4"; 
    gotoxy(101,19);cout<<" Invertir Lista"; 
    gotoxy(96,20);cout<<string(40,char(205));
    gotoxy(97,21);cout<<"5"; 
    gotoxy(101,21);cout<<" Editar Registro"; 
    gotoxy(96,22);cout<<string(40,char(205));
    gotoxy(97,21);cout<<"5"; 
    gotoxy(101,21);cout<<" Editar Registro"; 
    gotoxy(96,22);cout<<string(40,char(205));
    gotoxy(97,23);cout<<"6"; 
    gotoxy(101,23);cout<<" Remover Registro"; 
    gotoxy(96,24);cout<<string(40,char(205));
    gotoxy(97,25);cout<<"7"; 
    gotoxy(101,25);cout<<" Vaciar Lista"; 
    gotoxy(96,26);cout<<string(40,char(205));
    gotoxy(97,27);cout<<"8"; 
    gotoxy(101,27);cout<<" Reproducir cancion"; 
    gotoxy(96,28);cout<<string(40,char(205));
    gotoxy(97,29);cout<<"9"; 
    gotoxy(101,29);cout<<" Detener Cancion"; 
    gotoxy(96,30);cout<<string(40,char(205));
    gotoxy(97,31);cout<<"10"; 
    gotoxy(101,31);cout<<" Salir"; 
}

void print_aristas(){
    gotoxy(52,5);cout<<char(203);
    gotoxy(95,5);cout<<char(203);
    gotoxy(100,5);cout<<char(203);
    gotoxy(15,5);cout<<char(203);
    gotoxy(79,5);cout<<char(203);

    gotoxy(95,7);cout<<char(204);
    gotoxy(100,7);cout<<char(206);
    gotoxy(95,12);cout<<char(204);
    gotoxy(100,12);cout<<char(206);
    gotoxy(95,18);cout<<char(204);
    gotoxy(100,18);cout<<char(206);
    gotoxy(95,20);cout<<char(204);
    gotoxy(100,20);cout<<char(206);
    gotoxy(95,22);cout<<char(204);
    gotoxy(100,22);cout<<char(206);
    gotoxy(95,24);cout<<char(204);
    gotoxy(100,24);cout<<char(206);
    gotoxy(95,26);cout<<char(204);
    gotoxy(100,26);cout<<char(206);
    gotoxy(95,28);cout<<char(204);
    gotoxy(100,28);cout<<char(206);
    gotoxy(95,30);cout<<char(204);
    gotoxy(100,30);cout<<char(206);
//Este cambia
    gotoxy(95,32);cout<<char(204);
    gotoxy(100,32);cout<<char(202);
    //Impresion de Aristas
    gotoxy(95,42);cout<<char(202);

    gotoxy(136,7);cout<<char(185);
    gotoxy(136,12);cout<<char(185);
    gotoxy(136,18);cout<<char(185);
    gotoxy(136,20);cout<<char(185);
    gotoxy(136,22);cout<<char(185);
    gotoxy(136,24);cout<<char(185);
    gotoxy(136,26);cout<<char(185);
    gotoxy(136,28);cout<<char(185);
    gotoxy(136,30);cout<<char(185);
    gotoxy(136,32);cout<<char(185);

    gotoxy(5,32);cout<<char(204);
    gotoxy(15,32);cout<<char(202);
    gotoxy(52,32);cout<<char(202);
    gotoxy(79,32);cout<<char(202);
    gotoxy(95,32);cout<<char(206);
}

void print_partTwo(){
    //Impresion de lineas
    gotoxy(5,36);cout<<char(204);
    gotoxy(6,36);cout<<string(89,char(205));
    gotoxy(95,36);cout<<char(185);
    gotoxy(5,38);cout<<char(204);
    gotoxy(6,38);cout<<string(89,char(205));
    gotoxy(95,38);cout<<char(185);
    gotoxy(5,40);cout<<char(204);
    gotoxy(6,40);cout<<string(89,char(205));
    gotoxy(95,40);cout<<char(185);

    //Impresion del texto
    gotoxy(7,37);cout<<"Indice: ";
    gotoxy(7,39);cout<<"Nombre de la cancion: ";
    gotoxy(57,39);cout<<"Album: ";
    gotoxy(7,41);cout<<"Artista: ";
    gotoxy(57,41);cout<<"Genero: ";
    gotoxy(5,7);cout<<char(204)<<string(9, char(205))<<char(206)<<string(36, char(205))<<char(206)<<string(26, char(205))<<char(206)<<string(15, char(205))<<char(206);
    //Progress bar
    gotoxy(7,33);cout<<char(201)<<string(60, char(205))<<char(187);
    gotoxy(7,34);cout<<char(186); gotoxy(68,34);cout<<char(186);  gotoxy(70,34);cout << "Porcentaje: " << 0.00 << "%";
    gotoxy(7,35);cout<<char(200)<<string(60, char(205))<<char(188);
}

void titular() {
    gotoxy(40,2);cout<<char(203)<<char(205)<<char(187)<<char(218)<<char(196)<<char(191)<<char(218)<<char(196)<<char(191)<<char(194)<<char(196)<<char(191)<<char(218)<<char(196)<<char(191)<<char(218)<<char(194)<<char(191)<<char(194)<<char(' ')<<char(194)<<char(218)<<char(196)<<char(191)<<char(218)<<char(194)<<char(191)<<char(218)<<char(196)<<char(191)<<char(194)<<char(196)<<char(191)<<"  "<<char(218)<<char(194)<<char(191)<<char(218)<<char(196)<<char(191)<<"  "<<char(201)<<char(203)<<char(187)<<char(194)<<char(' ')<<char(194)<<char(218)<<char(196)<<char(191)<<char(218)<<char(194)<<char(191)<<char(218)<<char(196)<<char(191)<<char(218)<<char(196)<<char(191);
    gotoxy(40,3);cout<<char(204)<<char(203)<<char(188)<<char(195)<<char(180)<<" "<<char(195)<<char(196)<<char(217)<<char(195)<<char(194)<<char(217)<<char(179)<<char(' ')<<char(179)<<char(' ')<<char(179)<<char(179)<<char(179)<<char(' ')<<char(179)<<char(179)<<char(' ')<<char(' ')<<char(' ')<<char(179)<<char(' ')<<char(179)<<char(' ')<<char(179)<<char(195)<<char(194)<<char(217)<<"  "<<char(' ')<<char(179)<<char(179)<<char(195)<<char(180)<<char(' ')<<"  "<<char(186)<<char(186)<<char(186)<<char(179)<<char(' ')<<char(179)<<char(192)<<char(196)<<char(191)<<char(' ')<<char(179)<<char(' ')<<char(179)<<char(' ')<<char(' ')<<char(195)<<char(196)<<char(180);
    gotoxy(40,4);cout<<char(202)<<""<<char(200)<<char(205)<<char(192)<<char(196)<<char(217)<<char(193)<<"  "<<char(193)<<char(192)<<char(196)<<char(192)<<char(196)<<char(217)<<char(196)<<char(193)<<char(217)<<char(192)<<char(196)<<char(217)<<char(192)<<char(196)<<char(217)<<char(' ')<<char(193)<<char(' ')<<char(192)<<char(196)<<char(217)<<char(193)<<char(192)<<char(196)<<"  "<<char(196)<<char(193)<<char(217)<<char(192)<<char(196)<<char(217)<<"  "<<char(202)<<char(' ')<<char(202)<<char(192)<<char(196)<<char(217)<<char(192)<<char(196)<<char(217)<<char(192)<<char(193)<<char(217)<<char(192)<<char(196)<<char(217)<<char(193)<<char(' ')<<char(193);
}

void restaurarConfiguracionConsola() {
    SetConsoleOutputCP(437);
}


void save_song(int index, string cancion, string artist, string genero, string album, string duracion){
    index++;
    Song temp;
    File f;
    temp.setId(index); temp.setNombre(cancion); temp.setArtista(artist); temp.setGenero(genero); temp.setAlbum(album); temp.setDuracion(duracion);
    f.WriteToFile(temp);
}

void edit_song(string nombre_buscar, string nuevo_nombre, string nuevo_artista, string nuevo_album, string nuevo_genero, string nueva_duracion){
    string ad_actual,nombre_archivo, artista_archivo, album_archivo, genero_archivo, duracion_archivo;
    ifstream archivo_entrada("C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/file.txt");
    ofstream archivo_salida("C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/tmp.txt");
    string id;
    bool encontrado = false;
    while (archivo_entrada >> id >> nombre_archivo >> artista_archivo >> album_archivo >> genero_archivo >> duracion_archivo){
        if (nombre_archivo == nombre_buscar){
            archivo_salida << id << " " << nuevo_nombre << " " << nuevo_artista << " " << nuevo_album << " " << nuevo_genero << " " << nueva_duracion <<  endl;
            encontrado = true;
        }else {
            archivo_salida << id << " " << nombre_archivo << " " << artista_archivo << " " << album_archivo << " " << genero_archivo << " " << duracion_archivo <<  endl;
        }
    }
    
    archivo_entrada.close();
    archivo_salida.close();
    
    if (encontrado) {
        // Elimina el archivo original
        remove("C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/file.txt");
        // Renombra el archivo temporal como el archivo original
        rename("C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/tmp.txt", "C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/file.txt");
        clean_window();
        gotoxy(97,33);cout << "La cancion ha sido actualizada." << endl;
        Sleep(2000);
    } else {
        clean_window();
        gotoxy(97,33);cout << "La cancion no se ha encontrado" << endl;
        Sleep(2000);
    }
}

void delete_song(string nombre_borrar){
    string id_actual, nombre_actual, artista_actual, genero_actual, album_actual, duracion_actual;
    ifstream archivo_entrada("C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/file.txt");
    ofstream archivo_salida("C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/tmp.txt");
    
    bool encontrado = false;
    while (archivo_entrada >> id_actual >> nombre_actual >> artista_actual >> genero_actual >> album_actual >> duracion_actual){
        if (nombre_actual == nombre_borrar){
            encontrado = true;
            continue;
        }
        archivo_salida << id_actual << " " << nombre_actual << " " << artista_actual << " " << genero_actual << " " << album_actual << " " << duracion_actual << endl;
    }
    
    archivo_entrada.close();
    archivo_salida.close();
    
    if (encontrado) {
        // Elimina el archivo original
        remove("C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/file.txt");
        // Renombra el archivo temporal al nombre original
        rename("C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/tmp.txt", "C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/file.txt");
        clean_window();
        gotoxy(97,33);cout << "Registro eliminado exitosamente." << endl;
        Sleep(2000);
    } else {
        clean_window();
        gotoxy(97,33);cout << "La cancion no se ha encontrado" << endl;
    }
}

void clear_songs(){
    for(int posiciones = 0; posiciones < 24; posiciones++){
        gotoxy(5,8 + posiciones);cout<<char(186)<<"         "<<char(186)<<"                                    "<<char(186)<<"                          "<<char(186)<<"             ";
    }
}

double stot(string tiempo){
    istringstream ss(tiempo);
    int minutos, segundos;
    char separador;
    ss >> minutos >> separador >> segundos;
    double duracion = minutos * 60 + segundos;
    return duracion;
}

void clear_progressbar(){
    gotoxy(8,34);cout << string(60, char(' '));
    gotoxy(1,8);cout<<"   ";
    gotoxy(70, 34); cout << "Porcentaje: 0.00% " << endl;
    gotoxy(15,37);cout<<"                    ";
    gotoxy(29,39);cout<<"                ";
    gotoxy(64,39);cout<<"                ";
    gotoxy(16,41);cout<<"                ";
    gotoxy(65,41);cout<<"                ";
}

/*
void progressbar(double duracion){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    double tiempo_transcurrido = 0, avance = 0;
    int longitud = 60; // longitud total de la barra de progreso
    while (avance != 100){
        avance = (tiempo_transcurrido / duracion) * 100;
        gotoxy(70, 34); cout << "Porcentaje: " << fixed << setprecision(2) << avance << "%" << endl;
        int longitud_actual = avance / 100 * longitud;
        gotoxy(8,34);cout << string(longitud_actual, char(219));
        tiempo_transcurrido++;
        Sleep(1000);
    }
    clear_progressbar();
    //volver a mostrar el cursor
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}
*/
void progressbar(double duracion) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    double tiempo_transcurrido = 0, avance = 0;
    gotoxy(97,33);cout<<"Presiona:";
    gotoxy(97,34);cout << "9 - Para detener la cancion";
    int longitud = 60; // longitud total de la barra de progreso
    while (avance != 100) {
        avance = (tiempo_transcurrido / duracion) * 100;
        gotoxy(70, 34);
        cout << "Porcentaje: " << fixed << setprecision(2) << avance << "%" << endl;
        int longitud_actual = avance / 100 * longitud;
        gotoxy(8, 34);
        cout << string(longitud_actual, char(219));
        tiempo_transcurrido++;
        // Verificar si se ha presionado una tecla
        if (_kbhit()) {
            int tecla = getch();
            // Realizar la acción correspondiente
            if (tecla == 57) {
                PlaySound(0,0,0);
                clear_progressbar();
                clean_window();
                break;
            }
        }

        Sleep(1000);
    }
    clear_progressbar();
    // volver a mostrar el cursor
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void presentacion(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    gotoxy(5,1);cout<<char(201)<<string(130, char(205))<<char(187);
    for(int x = 0; x < 40; x++){
        gotoxy(5, 2 + x);cout<<char(186);
        gotoxy(136, 2 + x);cout<<char(186);
    }
    gotoxy(5, 42);cout<<char(200)<<string(130, char(205))<<char(188);
    //gotoxy(5,5);cout<<char(204)<<string(130,char(205))<<char(185);
    gotoxy(15,10);cout << "    ____                            __           __                    __        __  ___           _           \n";
    gotoxy(15,11);cout << "   / __ \\___  ____  _________  ____/ /_  _______/ /_____  _____   ____/ /__     /  |/  /_  _______(_)________ _\n";
    gotoxy(15,12);cout << "  / /_/ / _ \\/ __ \\/ ___/ __ \\/ __  / / / / ___/ __/ __ \\/ ___/  / __  / _ \\   / /|_/ / / / / ___/ / ___/ __ `/\n";
    gotoxy(15,13);cout << " / _, _/  __/ /_/ / /  / /_/ / /_/ / /_/ / /__/ /_/ /_/ / /     / /_/ /  __/  / /  / / /_/ (__  ) / /__/ /_/ /\n";
    gotoxy(15,14);cout << "/_/ |_|\\___/  ___/_/   \\____/\\__,_/\\__,_/\\___/\\__/\\____/_/      \\__,_/\\___/  /_/  /_/\\__,_/____/_/\\___/\\__,_/\n"; 
    gotoxy(15,15);cout << "           /_/                                                                                                  ";
    gotoxy(65,17);cout<<"Cargando";
    gotoxy(54,18);cout<<"[                              ]";
    double tiempo_transcurrido = 0, avance = 0, duracion = 20;
    int longitud = 30; // longitud total de la barra de progreso
    while (avance != 100){
        avance = (tiempo_transcurrido / duracion) * 100;
        int longitud_actual = avance / 100 * longitud;
        gotoxy(55,18);cout << string(longitud_actual, char('*'));
        tiempo_transcurrido++;
        Sleep(100);
    }
    Sleep(2000);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}