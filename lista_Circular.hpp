#include <iostream>
//#include "window.hpp"
using namespace std;


class Node{
    public:
        int id;
        string cancion;
        string artista;
        string genero;
        string album;
        string duracion;
        Node *next;
        Node *back;
};

class CircularList{
    private:
        Node *ptrHead;
    public:
        CircularList();
        void insert_First(int,string,string,string,string,string);
        void insert_Last(int,string,string,string,string,string);
        bool empty();
        void print_one(int*);
        void print_two(int*);
        void print_list(int*);
        void sort();
        void sortReverse();
        void sortbySong();
        void sortbyArtist();
        void searchbyId();
        void searchbySong();
        void searchbyArtist();
        void reverse();
        void moveTo(int);
        void play_Song();
        //No los he usado
        
        void buscar_por_nombre(string);
        void modificar(int);
        void remove();
};

CircularList::CircularList(){
    ptrHead = NULL;
}

void CircularList::insert_First(int id,string cancion, string artista, string genero, string album, string duracion){
    Node *new_node = new Node();
    new_node->id = id;
    new_node->cancion = cancion;
    new_node->artista = artista;
    new_node->genero = genero;
    new_node->album = album;
    new_node->duracion = duracion;

    if (ptrHead == NULL){
        new_node->next = new_node;
        new_node->back = new_node;
        ptrHead = new_node;
    }
    else{
        Node *last_node = ptrHead->back;
        new_node->next = ptrHead;
        new_node->back = last_node;
        ptrHead->back = new_node;
        last_node->next = new_node;
        ptrHead = new_node;
    }
}

void CircularList::insert_Last(int id,string cancion, string artista, string genero, string album, string duracion){
    Node *new_node = new Node();
    new_node->id = id;
    new_node->cancion = cancion;
    new_node->artista = artista;
    new_node->genero = genero;
    new_node->album = album;
    new_node->duracion = duracion;
    if (ptrHead == NULL){
        new_node->next = new_node;
        new_node->back = new_node;
        ptrHead = new_node;
    }
    else{
        Node *last_node = ptrHead->back;
        new_node->next = ptrHead;
        new_node->back = last_node;
        ptrHead->back = new_node;
        last_node->next = new_node;
    }
}

bool CircularList::empty(){
    if(ptrHead == NULL)
        return true;
    else
        return false;
}

void CircularList::print_one(int *pos){
    string nombre_buscar, id_actual, nombre_actual, nombre_artista, genero_actual, album_actual , duracion_actual;
    ifstream archivo("C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/file.txt");
    int id_tmp = 0;
    while (archivo >> id_actual >> nombre_actual >> nombre_artista >> genero_actual >> album_actual >> duracion_actual){
        id_tmp = (*pos) + 1;
        gotoxy(7,8 + (*pos));cout << id_tmp << endl;
        gotoxy(17,8 + (*pos));cout << nombre_actual << endl;
        gotoxy(54,8 + (*pos));cout << nombre_artista << endl;
        gotoxy(81,8 + (*pos));cout << duracion_actual << endl;
        insert_Last(id_tmp,nombre_actual,nombre_artista,genero_actual,album_actual,duracion_actual);
        (*pos)++;
    }
    archivo.close();
}

void CircularList::print_two(int *pos){
        Node *temp = ptrHead;
        do{
            gotoxy(7,8 + (*pos));cout << temp->id << endl;
            gotoxy(17,8 + (*pos));cout << temp->cancion << endl;
            gotoxy(54,8 + (*pos));cout << temp->artista << endl;
            gotoxy(81,8 + (*pos));cout << temp->duracion << endl;
            (*pos)++;
            temp = temp->next;
        } while (temp != ptrHead);
}

void CircularList::print_list(int *pos){ 
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    SetConsoleTextAttribute(hConsole,1);
    //system("color 0F");//A:VERDE CLARO 5: PURPURA
    Node *temp = ptrHead;
    gotoxy(7,8 + (*pos));cout << temp->id << endl;
    gotoxy(17,8 + (*pos));cout << temp->cancion << endl;
    gotoxy(54,8 + (*pos));cout << temp->artista << endl;
    gotoxy(81,8 + (*pos));cout << temp->duracion << endl;
    (*pos)++;
    temp = temp->next;
    gotoxy(1,8);cout<<">>>";
    SetConsoleTextAttribute(hConsole,2);
    do{
        gotoxy(7,8 + (*pos));cout << temp->id << endl;
        gotoxy(17,8 + (*pos));cout << temp->cancion << endl;
        gotoxy(54,8 + (*pos));cout << temp->artista << endl;
        gotoxy(81,8 + (*pos));cout << temp->duracion << endl;
        (*pos)++;
        temp = temp->next;
    } while (temp != ptrHead);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void CircularList::moveTo(int opc){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    if (!empty()){
        Node *temp = ptrHead;
        if (opc == 1){
            temp = temp->next;
            ptrHead = temp;
        }
        else if (opc == 2){
            temp = temp->back;
            ptrHead = temp;
        }
    }
    //volver a mostrar el cursor
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}


void CircularList::remove(){
    
    if (!empty()) {
        Node* current = ptrHead;
        Node* nextNode = nullptr;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != ptrHead);
        ptrHead = nullptr;
    }
}

//Este es el bueno
void CircularList::sort() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    if (!empty()) {
        Node *current = ptrHead;
        while (current->next != ptrHead) {
            Node *minNode = current;
            Node *temp = current->next;
            while (temp != ptrHead) {
                if (temp->id < minNode->id) {
                    minNode = temp;
                }
                temp = temp->next;
            }
            if (current != minNode) {
                std::swap(current->id, minNode->id);
                std::swap(current->cancion, minNode->cancion);
                std::swap(current->artista, minNode->artista);
                std::swap(current->genero, minNode->genero);
                std::swap(current->album, minNode->album);
                std::swap(current->duracion, minNode->duracion);
            }
            current = current->next;
        }
    }
        //volver a mostrar el cursor
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void CircularList::sortReverse() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    if (!empty()) {
        Node *current = ptrHead;
        while (current->next != ptrHead) {
            Node *minNode = current;
            Node *temp = current->next;
            while (temp != ptrHead) {
                if (temp->id > minNode->id) {
                    minNode = temp;
                }
                temp = temp->next;
            }
            if (current != minNode) {
                std::swap(current->id, minNode->id);
                std::swap(current->cancion, minNode->cancion);
                std::swap(current->artista, minNode->artista);
                std::swap(current->genero, minNode->genero);
                std::swap(current->album, minNode->album);
                std::swap(current->duracion, minNode->duracion);
            }
            current = current->next;
        }
    }
        //volver a mostrar el cursor
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void CircularList::sortbySong(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    if (!empty()) {
        Node *current = ptrHead;
        while (current->next != ptrHead) {
            Node *minNode = current;
            Node *temp = current->next;
            while (temp != ptrHead) {
                if (temp->cancion < minNode->cancion) {
                    minNode = temp;
                }
                temp = temp->next;
            }
            if (current != minNode) {
                std::swap(current->id, minNode->id);
                std::swap(current->cancion, minNode->cancion);
                std::swap(current->artista, minNode->artista);
                std::swap(current->genero, minNode->genero);
                std::swap(current->album, minNode->album);
                std::swap(current->duracion, minNode->duracion);
            }
            current = current->next;
        }
    }
        //volver a mostrar el cursor
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void CircularList::sortbyArtist(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    if (!empty()) {
        Node *current = ptrHead;
        while (current->next != ptrHead) {
            Node *minNode = current;
            Node *temp = current->next;
            while (temp != ptrHead) {
                if (temp->artista < minNode->artista) {
                    minNode = temp;
                }
                temp = temp->next;
            }
            if (current != minNode) {
                std::swap(current->id, minNode->id);
                std::swap(current->cancion, minNode->cancion);
                std::swap(current->artista, minNode->artista);
                std::swap(current->genero, minNode->genero);
                std::swap(current->album, minNode->album);
                std::swap(current->duracion, minNode->duracion);
            }
            current = current->next;
        }
    }
        //volver a mostrar el cursor
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}


void CircularList::searchbyId(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    string id_buscar;
    gotoxy(97,33);cout<<"---Buscar por Id---";
    gotoxy(97,35);cout << "                         ";
    gotoxy(97,34);cout << "Ingresa el id a buscar: ";cin >> id_buscar;
    while(!esNumero(&id_buscar)){
            gotoxy(97,34);cout<< "Ingresa una opcion valida";
            gotoxy(97,33);cout<<"Selecciona una opcion:              ";
            gotoxy(97,35);cin >> id_buscar;
            gotoxy(97,35);cout<<"                                       "<<char(186)<< "         ";
    }
    Node *temp = ptrHead; bool ban = false;
    do{
        if(temp->id == stoi(id_buscar)){
            gotoxy(15,37);cout<<temp->id;
            gotoxy(29,39);cout<<temp->cancion;
            gotoxy(64,39);cout<<temp->album;
            gotoxy(16,41);cout<<temp->artista;
            gotoxy(65,41);cout<<temp->genero;
            ban = true;
            break;
        }
        temp = temp->next;
    } while(temp != ptrHead);
    if(ban == false){
        clean_window();
        gotoxy(97,33);cout<<"No se ha encontrado el registro";
        Sleep(2000);
    }
    //volver a mostrar el cursor
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void CircularList::searchbyArtist(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    string artista;
    gotoxy(97,33);cout<<"---Buscar por Artista---";
    gotoxy(97,35);cout << "                         ";
    gotoxy(97,34);cout << "Ingresa el artista a buscar: ";
    gotoxy(97,35);cin >> artista;
    Node *temp = ptrHead; bool ban = false;
    do{
        if(temp->artista == artista){
            gotoxy(15,37);cout<<temp->id;
            gotoxy(29,39);cout<<temp->cancion;
            gotoxy(64,39);cout<<temp->album;
            gotoxy(16,41);cout<<temp->artista;
            gotoxy(65,41);cout<<temp->genero;
            ban = true;
            break;
        }
        temp = temp->next;
    } while(temp != ptrHead);
    if(ban == false){
        clean_window();
        gotoxy(97,33);cout<<"No se ha encontrado el registro";
        Sleep(2000);
    }
    //volver a mostrar el cursor
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void CircularList::searchbySong(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    string song;
    gotoxy(97,33);cout<<"---Buscar por Cancion---";
    gotoxy(97,35);cout << "                         ";
    gotoxy(97,34);cout << "Ingresa la cancion a buscar: ";
    gotoxy(97,35);cin >> song;
    Node *temp = ptrHead; bool ban = false;
    do{
        if(temp->cancion == song){
            gotoxy(15,37);cout<<temp->id;
            gotoxy(29,39);cout<<temp->cancion;
            gotoxy(64,39);cout<<temp->album;
            gotoxy(16,41);cout<<temp->artista;
            gotoxy(65,41);cout<<temp->genero;
            ban = true;
            break;
        }
        temp = temp->next;
    } while(temp != ptrHead);
    if(ban == false){
        clean_window();
        gotoxy(97,33);cout<<"No se ha encontrado el registro";
        Sleep(2000);
    }
    //volver a mostrar el cursor
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void CircularList::reverse(){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    if(!empty()){
        Node* current = ptrHead;
        do {
            Node* temp = current->next;
            current->next = current->back;
            current->back = temp;
            current = current->back;
        } while (current != ptrHead);
        ptrHead = ptrHead->next;
    }
        //volver a mostrar el cursor
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void CircularList::play_Song(){
    Node *temp = ptrHead;
    string sonido = temp->cancion;
    string son = sonido + ".wav";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    
    //volver a mostrar el cursor
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    ifstream archivo(son.c_str());
    if(archivo.good()){
        PlaySound(TEXT(son.c_str()), NULL, SND_ASYNC);
        gotoxy(15,37);cout<<temp->id;
        gotoxy(29,39);cout<<temp->cancion;
        gotoxy(64,39);cout<<temp->album;
        gotoxy(16,41);cout<<temp->artista;
        gotoxy(65,41);cout<<temp->genero;
        progressbar(stot(temp->duracion));
        clean_window();
    }
    else{
        gotoxy(97,33);cout<<"---Archivo no encontrado---";
        gotoxy(97,34);cout<<"Por favor asegurate de que";
        gotoxy(97,35);cout<<"se encuentre en la carpeta";
        Sleep(3000);
        gotoxy(1,8);cout<<"   ";
        clean_window();
    }
}

