#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

class Song{
private:
    int id;
    string nombre;
    string artista;
    string genero;
    string album;
    string duracion;

public:
    void setId(int);
    int getId();
    void setNombre(string);
    string getNombre();
    void setArtista(string);
    string getArtista();
    void setGenero(string);
    string getGenero();
    void setAlbum(string);
    string getAlbum();
    void setDuracion(string);
    string getDuracion();
    void searchbyName();
};

void Song::setId(int id){
    this->id = id;
}

int Song::getId(){
    return this->id;
}

void Song::setNombre(string nombre){
    this->nombre = nombre;
}

string Song::getNombre(){
    return this->nombre;
}

void Song::setArtista(string artista){
    this->artista = artista;
}

string Song::getArtista(){
    return this->artista;
}

void Song::setGenero(string genero){
    this->genero = genero;
}

string Song::getGenero(){
    return this->genero;
}

void Song::setAlbum(string album){
    this->album = album;
}

string Song::getAlbum(){
    return this->album;
}

void Song::setDuracion(string duracion){
    this->duracion = duracion;
}

string Song::getDuracion(){
    return this->duracion;
}

void Song::searchbyName(){
    //Busca segun el nombre de la rola
    string nombre_buscar, id_actual, nombre_actual, nombre_artista, genero_actual, album_actual , duracion_actual;
    cout << "Ingresa el nombre a buscar: ";
    cin >> nombre_buscar;
    ifstream archivo("C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/file.txt");
    while (archivo >> id_actual >> nombre_actual >> nombre_artista >> genero_actual >> album_actual >> duracion_actual){
        if (nombre_actual == nombre_buscar){
            cout << "ID: " << id_actual << endl;
            cout << "Nombre cancion: " << nombre_actual << endl;
            cout << "Nombre artista: " << nombre_artista << endl;
            cout << "Genero: " << genero_actual << endl;
            cout << "Album: " << album_actual << endl;
            cout << "Duracion: " << duracion_actual << endl;
            archivo.close();
            return;
        }
    }
    archivo.close();
    cout << "El nombre " << nombre_buscar << " no fue encontrado en el archivo." << endl;
}


class File{
    private:
    public:
        void WriteToFile(Song);
        void ReadToFile();
        void edit(int);
};

void File::WriteToFile(Song ct){
    fstream file;
    file.open("C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/file.txt", ios::app);
    file << ct.getId() << " " << ct.getNombre() << " " << ct.getArtista() << " " << ct.getGenero() << " " << ct.getAlbum() << " " << ct.getDuracion() <<endl;
    file.close();
}

void File::ReadToFile(){
    fstream file;
    char data[200];
    file.open("C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/file.txt", ios::in);
    file >> data; // read line
    while (!file.eof()){
        cout << data << endl; // show data
        file >> data;         // read file
    }
    file.close(); // close file
}

void File::edit(int index){
    string nombre_buscar, id_actual, nombre_archivo, telefono_archivo, direccion_archivo;
    cout << "Ingresa el nombre a buscar: ";
    cin >> nombre_buscar;
    cout<<"------Nuevos datos------"<<endl;
    cout << "Ingresa el nuevo nombre: ";
    string nombre_nuevo;
    cin >> nombre_nuevo;
    cout << "Ingresa la direccion: ";
    string direccion_nueva;
    cin >> direccion_nueva;
    cout << "Ingresa el telefono: ";
    string telefono_nuevo;
    cin >> telefono_nuevo;
    
    ifstream archivo_entrada("C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/file.txt");
    ofstream archivo_salida("C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/tmp.txt");
    
    bool encontrado = false;
    int id_nuevo = 0;
    while (archivo_entrada >> id_actual >> nombre_archivo >> direccion_archivo >> telefono_archivo){
        if (nombre_archivo == nombre_buscar){
            archivo_salida << index << " " << nombre_nuevo << " " << direccion_nueva << " " << telefono_nuevo << endl;
            encontrado = true;
        } else {
            id_nuevo++;
            archivo_salida << id_nuevo << " " << nombre_archivo << " " << direccion_archivo << " " << telefono_archivo << endl;
        }
    }
    
    archivo_entrada.close();
    archivo_salida.close();
    
    if (encontrado) {
        // Elimina el archivo original
        remove("C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/file.txt");
        // Renombra el archivo temporal como el archivo original
        rename("C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/tmp.txt", "C:/Users/marco/Documents/Programacion/Estructura de Datos/Proyecto_Reproductor/file.txt");
        cout << "El contacto ha sido actualizado." << endl;
    } else {
        cout << "El nombre " << nombre_buscar << " no fue encontrado en el archivo." << endl;
    }
}
