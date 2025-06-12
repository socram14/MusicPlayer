#include <iostream>//Libreria estandar
#include <stdlib.h>//Libreria estandar
#include <locale.h>//Libreria para poder poner la ñ
#include <cstdlib>//Librerias para limpiar pantalla
#include <cstring>//Libreria para estilizar
#include "window.hpp" //Archivo con todo lo relacionado a el dibujo de cajas
#include "validaciones.hpp"//Archivo de las validaciones de entradas de datos
#include "lista_Circular.hpp" //Archivo donde se encuentra la clase con sus respectivos metodos
using namespace std;//Libreria estandar

//Variables
string opc_aux ,aux_submenu;
int opc, num_registros, submenu;

//Objetos
int main(){
    CircularList lista_reproduccion;
    blind_cursor();
    window_setting();
    system("cls");
    presentacion();
    system("cls");
    titular();
    print_window();
    print_aristas();
    print_partTwo();
    titular();
    ShowCursor(false);
    num_registros = 0;
    //update_table(&num_registros,lista_reproduccion);
    lista_reproduccion.print_one(&num_registros);
    do{
        gotoxy(97,33);cout<<"Selecciona una opcion: ";
        cin >> opc_aux;
        while(!esNumero(&opc_aux)){
            gotoxy(97,34);cout<< "Ingresa una opcion valida";
            gotoxy(97,33);cout<<"Selecciona una opcion:              ";
            gotoxy(97,35);cin >> opc_aux;
            gotoxy(97,35);cout<<"                                       "<<char(186)<< "         ";
        }
        opc = stoi(opc_aux);
        switch(opc){
            case 1:{
                string name, artista, album, genero, duracion;
                gotoxy(97,33);cout<<"---Registro de una cancion---";
                gotoxy(97,34);cout<<"Ingresa el nombre de la cancion: ";
                gotoxy(97,35);cin >> name;
                while(!esDigito(&name)){
                    clean_window();
                    gotoxy(97,34);cout<< "Ingresa una opcion valida";
                    gotoxy(97,33);cout<<"Recuerda no ingresar espacios";
                    gotoxy(97,35);cin >> name;
                }
                clean_window();
                gotoxy(97,33);cout<<"---Registro de una cancion---";
                gotoxy(97,34);cout<<"Ingresa el nombre del artista: ";
                gotoxy(97,35);cin >> artista;
                while(!esDigito(&artista)){
                    clean_window();
                    gotoxy(97,34);cout<< "Ingresa una opcion valida";
                    gotoxy(97,33);cout<<"Recuerda no ingresar espacios";
                    gotoxy(97,35);cin >> artista;
                }
                clean_window();
                gotoxy(97,33);cout<<"---Registro de una cancion---";
                gotoxy(97,34);cout<<"Ingresa el nombre del album: ";
                gotoxy(97,35);cin >> album;
                while(!esDigito(&album)){
                    clean_window();
                    gotoxy(97,34);cout<< "Ingresa una opcion valida";
                    gotoxy(97,33);cout<<"Recuerda no ingresar espacios";
                    gotoxy(97,35);cin >> album;
                }
                clean_window();
                gotoxy(97,33);cout<<"---Registro de una cancion---";
                gotoxy(97,34);cout<<"Ingresa a que genero pertenece: ";
                gotoxy(97,35);cin >> genero;
                while(!esDigito(&genero)){
                    clean_window();
                    gotoxy(97,34);cout<< "Ingresa una opcion valida";
                    gotoxy(97,33);cout<<"Recuerda no ingresar espacios";
                    gotoxy(97,35);cin >> genero;
                }
                clean_window();
                gotoxy(97,33);cout<<"---Registro de una cancion---";
                gotoxy(97,34);cout<<"Ingresa la duracion de la cancion";
                gotoxy(97,35);cout<<"(Ejemplo: \"03:46\"): ";
                gotoxy(97,36);cin >> duracion;
                while(!esTiempo(duracion)){
                    clean_window();
                    gotoxy(97,34);cout<< "Ingresa una opcion valida";
                    gotoxy(97,33);cout<<"Recuerda el formato\"03:46\": ";
                    gotoxy(97,35);cin >> duracion;
                }
                save_song(num_registros, name, artista, genero, album, duracion);
                clean_window();
                lista_reproduccion.remove();
                clear_songs();
                num_registros = 0;
                lista_reproduccion.print_one(&num_registros);
            }
            break;
            case 2:{
                clean_window();
                if(lista_reproduccion.empty() == true){
                    gotoxy(97,33);cout<<"---La lista esta vacia---";
                    Sleep(2000);
                    clean_window();
                }
                else{
                    gotoxy(97,33);cout<<"---Buscar por---";
                    gotoxy(97,34);cout<<"Ingresa una opcion: ";
                    gotoxy(97,35);cin >> aux_submenu;
                    while(!esNumero(&aux_submenu)){
                        gotoxy(97,34);cout<< "Ingresa una opcion valida";
                        gotoxy(97,33);cout<<"Selecciona una opcion:              ";
                        gotoxy(97,35);cin >> aux_submenu;
                        gotoxy(97,35);cout<<"                                       "<<char(186)<< "         ";
                    }
                    submenu = stoi(aux_submenu);
                    switch(submenu){
                        case 1:{
                            lista_reproduccion.searchbyId();
                            clean_window();
                            Sleep(3000);
                            clear_progressbar();
                        }
                        break;
                        case 2:{
                            lista_reproduccion.searchbySong();
                            clean_window();
                            Sleep(3000);
                            clear_progressbar();
                        }
                        break;
                        case 3:{
                            lista_reproduccion.searchbyArtist();
                            clean_window();
                            Sleep(3000);
                            clear_progressbar();
                        }
                        break;
                    }
                }
            }
            break;
            case 3:{
                clean_window();
                if(lista_reproduccion.empty() == true){
                    gotoxy(97,33);cout<<"---La lista esta vacia---";
                    Sleep(2000);
                    clean_window();
                }
                else{
                    clean_window();
                    gotoxy(97,33);cout<<"---Ordenar por---";
                    gotoxy(97,34);cout<<"Elije el metodo por el cual";
                    gotoxy(97,35);cout<<"quieres ordenar: ";cin >> aux_submenu;
                    while(!esNumero(&aux_submenu)){
                        gotoxy(97,34);cout<< "Ingresa una opcion valida";
                        gotoxy(97,33);cout<<"Selecciona una opcion:              ";
                        gotoxy(97,35);cin >> aux_submenu;
                        gotoxy(97,35);cout<<"                                       "<<char(186)<< "         ";
                    }
                    submenu = stoi(aux_submenu);
                    switch(submenu){
                        case 1:{
                            lista_reproduccion.sortbySong();
                            num_registros = 0;
                            clean_window();
                            clear_songs();
                            lista_reproduccion.print_two(&num_registros);
                            gotoxy(97,33);cout<<"---Lista Ordenada---";
                            Sleep(2000);
                            clean_window();
                        }
                        break;
                        case 2:{
                            lista_reproduccion.sortbyArtist();
                            num_registros = 0;
                            clean_window();
                            clear_songs();
                            lista_reproduccion.print_two(&num_registros);
                            gotoxy(97,33);cout<<"---Lista Ordenada---";
                            Sleep(2000);
                            clean_window();
                        }
                        break;
                        case 3:{
                            lista_reproduccion.sort();
                            num_registros = 0;
                            clean_window();
                            clear_songs();
                            lista_reproduccion.print_two(&num_registros);
                            gotoxy(97,33);cout<<"---Lista Ordenada---";
                            Sleep(2000);
                            clean_window();
                        }
                        break;
                        case 4:{
                            lista_reproduccion.sortReverse();
                            num_registros = 0;
                            clean_window();
                            clear_songs();
                            lista_reproduccion.print_two(&num_registros);
                            gotoxy(97,33);cout<<"---Lista Ordenada---";
                            Sleep(2000);
                            clean_window();
                        }
                        break;
                    }
                    clean_window();
                }
            }
            break;
            case 4:{
                clean_window();
                if(lista_reproduccion.empty() == true){
                    gotoxy(97,33);cout<<"---La lista esta vacia---";
                    Sleep(2000);
                    clean_window();
                }
                else{
                    lista_reproduccion.reverse();
                    clear_songs();
                    clean_window();
                    num_registros = 0;
                    lista_reproduccion.print_two(&num_registros);
                }
            }
            break;
            case 5:{
                string nombre_actualizar,name, artista, album, genero, duracion;
                gotoxy(97,33);cout<<"---Edicion de un registro---";
                gotoxy(97,34);cout<<"---Registro a editar---";
                gotoxy(97,35);cout<<"Ingresa el nombre de la cancion ";
                gotoxy(97,36);cout<<"a cambiar: ";cin >> nombre_actualizar;
                clean_window();
                gotoxy(97,33);cout<<"---Edicion de un registro---";
                gotoxy(97,34);cout<<"---Nuevos datos---";
                gotoxy(97,35);cout<<"Ingresa el nuevo nombre de la cancion: ";
                gotoxy(97,36);cin >> name;
                clean_window();
                gotoxy(97,33);cout<<"---Edicion de un registro---";
                gotoxy(97,34);cout<<"---Nuevos datos---";
                gotoxy(97,35);cout<<"Ingresa el nombre del artista: ";
                gotoxy(97,36);cin >> artista;
                clean_window();
                gotoxy(97,33);cout<<"---Edicion de un registro---";
                gotoxy(97,34);cout<<"---Nuevos datos---";
                gotoxy(97,35);cout<<"Ingresa el nombre del album: ";
                gotoxy(97,36);cin >> album;
                clean_window();
                gotoxy(97,33);cout<<"---Edicion de un registro---";
                gotoxy(97,34);cout<<"---Nuevos datos---";
                gotoxy(97,35);cout<<"Ingresa a que genero pertenece: ";
                gotoxy(97,36);cin >> genero;
                clean_window();
                gotoxy(97,33);cout<<"---Edicion de un registro---";
                gotoxy(97,34);cout<<"---Nuevos datos---";
                gotoxy(97,35);cout<<"Ingresa la duracion de la cancion";
                gotoxy(97,36);cout<<"(Ejemplo: \"03:46\"): ";
                gotoxy(97,37);cin >> duracion;
                while(!esTiempo(duracion)){
                    clean_window();
                    gotoxy(97,34);cout<< "Ingresa una opcion valida";
                    gotoxy(97,33);cout<<"Recuerda el formato\"03:46\": ";
                    gotoxy(97,35);cin >> duracion;
                }
                edit_song(nombre_actualizar,name,artista,album,genero,duracion);
                clear_songs();
                clean_window();
                lista_reproduccion.remove();
                num_registros = 0;
                lista_reproduccion.print_one(&num_registros);
            }
            break;
            case 6:{
                clean_window();
                if(lista_reproduccion.empty() == true){
                    gotoxy(97,33);cout<<"---La lista esta vacia---";
                    Sleep(2000);
                    clean_window();
                }
                else{
                    string eliminar;
                    gotoxy(97,33);cout<<"---Eliminar un registro---";
                    gotoxy(97,34);cout<<"Ingresa el nombre de la cancion ";
                    gotoxy(97,35);cout<<"a eliminar: ";cin >> eliminar;
                    clear_songs();
                    delete_song(eliminar);
                    clean_window();
                    lista_reproduccion.remove();
                    num_registros = 0;
                    lista_reproduccion.print_one(&num_registros);
                }
            }
            break;
            case 7:{
                clean_window();
                if(lista_reproduccion.empty() == true){
                    gotoxy(97,33);cout<<"---La lista ya esta vacia---";
                    Sleep(2000);
                    clean_window();
                }
                else{
                    lista_reproduccion.remove();
                    clear_songs();
                    clean_window();
                }
            }
            break;
            case 8:{
                clean_window();
                if(lista_reproduccion.empty() == true){
                    gotoxy(97,33);cout<<"---La lista ya esta vacia---";
                    Sleep(2000);
                    clean_window();
                }
                else{
                    bool exit_program = false;
                    int arrow_key;
                    do {
                        num_registros = 0;
                        lista_reproduccion.print_list(&num_registros);
                        clean_window();
                        gotoxy(97,33);cout<<"---Reproducir cancion---";
                        gotoxy(97,34);cout << "Usa las flechas para moverte";
                        gotoxy(97,35);cout << "Enter para reproducir";
                        arrow_key = getch();
                        switch (arrow_key) {
                            case 72: // Flecha arriba
                                lista_reproduccion.moveTo(1);
                                clear_songs();
                                num_registros = 0;
                                lista_reproduccion.print_list(&num_registros);
                                break;
                            case 80: // Flecha abajo
                                lista_reproduccion.moveTo(2);
                                clear_songs();
                                num_registros = 0;
                                lista_reproduccion.print_list(&num_registros);
                                break;
                            case 13: // Enter
                                exit_program = true;
                                break;
                        }
                    } while (!exit_program);
                    clean_window();
                    lista_reproduccion.play_Song();
                }            
            }
            break;
            case 9:{
                clean_window();
                gotoxy(97,33);cout<<"---Detener Cancion---";
                gotoxy(97,34);cout << "Esta opcion se hanilitara";
                gotoxy(97,35);cout << "cuando estes reproduciendo";
                gotoxy(97,36);cout << "musica";
                Sleep(2000);
                clean_window();
            }
            break;
            case 10:{
                clean_window();
                gotoxy(97,33);cout<<"---Cerrando Reproductor---";
                gotoxy(96,34);cout<<"[                          ]";
                double tiempo_transcurrido = 0, avance = 0, duracion =15;
                int longitud = 26; // longitud total de la barra de progreso 
                while (avance != 100){
                    avance = (tiempo_transcurrido / duracion) * 100;
                    int longitud_actual = avance / 100 * longitud;
                    gotoxy(97,34);cout << string(longitud_actual, char('*'));
                    tiempo_transcurrido++;
                    Sleep(100);
                }
                Sleep(2000);
            }
            break;
            default:{
                gotoxy(97,33);cout<<"---Opcion fuera del menu---";
                gotoxy(97,34);cout<<"Por favor ingresa una que se";
                gotoxy(97,35);cout<<"encuentre en el menu";
                Sleep(3000);
                clean_window();
            }
            break;
        }
    }while(opc != 10);
    return 0;
}