#include "Node.h"
#include "Lista.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int idcfg;
bool primero=false;
bool cfgant = false;
bool reproduciendo=false;

void mostrarMenu(Node* actual,Lista& lista);
void menu_2(Lista& registros,Node* actual,Lista& lista);
void cargarTxt(Lista& lista,Lista& registros);
void pausar(Lista& lista);
void registrar(Node* clonar,Lista& registros);
void guardarCfg(Lista& lista);
void cargarCfg(Lista& lista,Lista& registros);
void limpiaryagregaractual(Lista& registros, Node* actual);
void menu_3(Lista& registros,Node* actual,Lista& lista);

int main(){
    Lista lista;
    Lista registros;
    Lista regis;
    cargarTxt(lista,registros);
    cargarCfg(lista,registros);
    Node* actual;
    string opcion;
    do
    {
        actual=lista.getActual();
        mostrarMenu(actual,lista);
        cin >> opcion;
        if (opcion == "w") pausar(lista);
        else if (opcion == "q"){
            lista.anterior();
            reproduciendo=true;
            actual=lista.getActual();
            if(idcfg != actual->id){
                registrar(actual,registros);
            } else {
                lista.siguiente();
                actual=lista.getActual();
            }
        }
        else if (opcion == "e"){
            lista.siguiente();
            reproduciendo=true;
            cfgant = true;
            actual=lista.getActual();
            if(actual == nullptr){
                idcfg = -1;
            }
            registrar(actual,registros);
        }
        else if (opcion == "s") lista.alternarAleatorio();
        else if (opcion == "r") lista.repeticion();
        else if (opcion == "a") {
            string option2;
            do{
                menu_2(registros,actual,lista);
                cin >> option2;
                for (char &c : option2) {
                    c = toupper(c);
                }
                if (option2.length() > 1 && option2[0] == 'S'){
                    bool esNumero = true;
                    string numero;
                    for(size_t i = 1;i <option2.length();i++){
                        if (!isdigit(option2[i])) {
                            esNumero = false;
                            break;
                        }
                        numero += option2;
                    }
                    if (esNumero) {
                        for(int i = 0; i< stoi(numero);i++){
                            lista.siguiente();
                            reproduciendo=true;
                            cfgant = true;
                            actual=lista.getActual();
                            if(actual == nullptr){
                                idcfg = -1;
                            }
                            registrar(actual,registros);
                        }
                    } else {
                        cout << "Error: Ingrese un número después de S" << endl;
                    }
                }
            } while (option2 != "V");
        }
        else if (opcion == "l") {
            string option3;
            do{
                menu_3(registros,actual,lista);
                cin >> option3;
                for (char &c : option3) {
                    c = toupper(c);
                }
                if (option3.length() > 1 && option3[0] == 'R'){
                    bool esNumero = true;
                    string numero;
                    for(size_t i = 1;i <option3.length();i++){
                        if (!isdigit(option3[i])) {
                            esNumero = false;
                            break;
                        }
                        numero += option3;
                    }
                    if (esNumero) {
                        lista.buscar(stoi(numero));
                        reproduciendo=true;
                        actual=lista.getActual();
                        registrar(actual,registros);
                    } else {
                        cout << "Error: Ingrese un número después de R" << endl;
                    }
                }
                
                if (option3.length() > 1 && option3[0] == 'A'){
                    bool esNumero = true;
                    string numero;
                    for(size_t i = 1;i <option3.length();i++){
                        if (!isdigit(option3[i])) {
                            esNumero = false;
                            break;
                        }
                        numero += option3;
                    }
                    if (esNumero) {
                        lista.eliminar(stoi(numero));
                        registros.eliminar(stoi(numero));
                    } else {
                        cout << "Error: Ingrese un número después de D" << endl;
                    }
                }
                
                if (option3.length() == 0 && option3[0] == 'N'){
                    int idnew = lista.ultimaSong();
                    
                    string nombre, artista, album,ruta,id,year,duracion;
                    cout<<"Nombre de la cancion: "<<endl;
                    cin >> nombre;
                    cout<<"Artista: "<<endl;
                    cin >> artista;
                    cout<<"Album: "<<endl;
                    cin >> album;
                    cout<<"Año: "<<endl;
                    cin >> year;
                    cout<<"Duracion (en segundos): "<<endl;
                    cin >> duracion;
                    cout<<"Ruta de la cancion: "<<endl;
                    cin >> ruta;
                    Node* nuevo=new Node(idnew,nombre,artista,album,stoi(year),stoi(duracion),ruta);
                    lista.agregar(nuevo);
                }
                if (option3.length() > 1 && option3[0] == 'D'){
                    bool esNumero = true;
                    string numero;
                    for(size_t i = 1;i <option3.length();i++){
                        if (!isdigit(option3[i])) {
                            esNumero = false;
                            break;
                        }
                        numero += option3;
                    }
                    if (esNumero) {
                        lista.eliminar(stoi(numero));
                        registros.eliminar(stoi(numero));
                    } else {
                        cout << "Error: Ingrese un número después de D" << endl;
                    }
                }
                
            } while (option3 != "V");
            
            
        }
        else if (opcion == "x") break;
        else {
            cout << "opcion invalida" << endl;
        }
    } while (opcion != "x");
    guardarCfg(lista);
    cout << "apagando..." << endl;
    return 0;
}
void menu_3(Lista& registros,Node* actual,Lista& lista){
    string alas;
    string repe;
    if(lista.getAleatorio() == true){
        alas = "S";
    } else{
        alas = "";
    }
    if(lista.getRepeticion() == 0){
        repe = "";
    } else if(lista.getRepeticion() == 1){
        repe = "R1";
    } else{
        repe = "RA";
    }
    system("clear");
    if (cfgant != false&& actual != nullptr){
        cout << "Actual"<<"("<< alas <<"-"<<repe<<")"<<":" << actual->nombre<<" - " <<actual->album<< endl;
    } else{
        cout << "Actual"<<"("<< alas <<"-"<<repe<<")"<<":"<< endl;
    }
    cout<<""<<endl;
    cout<<"Lista de reproducción actual:"<<endl;
    lista.mostrar();
    cout<<""<<endl;
    cout<<"Opciones:"<<endl;
    cout<<"R<num> - Reproducir canción seleccionada"<<endl;
    cout<<"A<num> - Agregar canción seleccionada al final de la lista de reproducción actual"<<endl;
    cout<<"N – Agregar canción al registro de canciones"<<endl;
    cout<<"D<num> – Eliminar canción seleccionada"<<endl;
    cout<<"V – Volver al menú principal"<<endl;
}
void menu_2(Lista& registros,Node* actual,Lista& lista){
    string alas;
    string repe;
    if(lista.getAleatorio() == true){
        alas = "S";
    } else{
        alas = "";
    }
    if(lista.getRepeticion() == 0){
        repe = "";
    } else if(lista.getRepeticion() == 1){
        repe = "R1";
    } else{
        repe = "RA";
    }
    system("clear");
    if (cfgant != false&& actual != nullptr){
        cout << "Actual"<<"("<< alas <<"-"<<repe<<")"<<":" << actual->nombre<<" - " <<actual->album<< endl;
    } else{
        cout << "Actual"<<"("<< alas <<"-"<<repe<<")"<<":"<< endl;
    }
    cout<<""<<endl;
    cout<<"Lista de reproducción actual:"<<endl;
    
    if(lista.mostrar2(registros) == 0){
        cout<<""<<endl;
        cout<<"Opciones:"<<endl;
        cout<<"V – Volver al menú principal"<<endl;
    } else{
        cout<<""<<endl;
        cout<<"Opciones:"<<endl;
        cout<<"S<num> - Saltar a la canción seleccionada"<<endl;
        cout<<"V – Volver al menú principal"<<endl;
    }
}
void mostrarMenu(Node* actual, Lista& lista){
    string alas;
    string repe;
    if(lista.getAleatorio() == true){
        alas = "S";
    } else{
        alas = "";
    }
    if(lista.getRepeticion() == 0){
        repe = "";
    } else if(lista.getRepeticion() == 1){
        repe = "R1";
    } else{
        repe = "RA";
    }
    system("clear");
    if (reproduciendo){
        cout << "Reproduciendo"<<"("<< alas <<"-"<<repe<<")"<<":" << actual->nombre<< endl;
        cout << "Artista: "   << actual->artista<<endl;
        cout << "Album: "  << actual->album<<"   ["<<actual->year<<"]"<<endl;
    }
    else{
        cout<<"Reproducción Detenida"<<endl;
    }
    cout<<""<<endl;
    cout << "Opciones" << endl;
    cout << "W - Repoducir/Pausar" << endl;
    cout << "Q - Pista Anterior" << endl;
    cout << "E - Pista Siguiente" << endl;
    cout << "S - Activar/Desactivar modo aleatorio" << endl;
    cout << "R - Reproduccion (Desactivado/Repetir una/repetir todas)" << endl;
    cout << "A - Ver lista de reproduccion actual" << endl;
    cout << "L - Listado de canciones" << endl;
    cout << "X - Salir" << endl;
    cout << "Ingrese Opcion: " <<endl;
}

void pausar(Lista& lista){
    Node* actual=lista.getActual();
    if(actual == nullptr) return;
    if(reproduciendo){
        cout<<"pausando "<<actual->nombre<<endl;
        reproduciendo=false;
    }
    else{
        cout<<"reanudando "<<actual->nombre<<endl;
        reproduciendo=true;
    }
}

void cargarTxt(Lista& lista,Lista& registros){
    ifstream archivo("music_source.txt");
    if(!archivo.is_open()){
        cout<<"error al abrir el archivo"<<endl;
        return;
    }
    
    string linea;
    
    while(getline(archivo,linea)){
        if(linea.empty()) continue;
        
        stringstream ss(linea);
        string id, nombre, artista, album, year, duracion, ruta;
        
        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, artista, ',');
        getline(ss, album, ',');
        getline(ss, year, ',');
        getline(ss, duracion, ',');
        getline(ss, ruta);
        Node* nuevo=new Node(stoi(id),nombre,artista,album,stoi(year),stoi(duracion),ruta);
        lista.agregar(nuevo);
        if(primero==false) {
            Node* temp=new Node(stoi(id),nombre,artista,album,stoi(year),stoi(duracion),ruta);
            registros.agregar(temp);
            primero=true;
        }
    }
    archivo.close();
}
void cargarCfg(Lista& lista,Lista& registros){
	ifstream archivo("status.cfg");
	if(!archivo.is_open()){
	    cfgant = false;
	    if(lista.getStart() != nullptr){
	        lista.Cfg(lista.getStart());
	    }
		return;
	}
	string linea;
    string id;
    string pausandoStr;
    string aleatorioStr;
    string repetirStr;
	getline(archivo, linea);
    id = linea.substr(linea.find('=') + 1);
    idcfg = stoi(id);
    getline(archivo, linea);
    pausandoStr = linea.substr(linea.find('=') + 1);
    reproduciendo = (pausandoStr == "true"||pausandoStr == "false");
    
    getline(archivo, linea);
    aleatorioStr = linea.substr(linea.find('=') + 1);
    bool aleatorios;
    if (aleatorioStr == "true") {
        aleatorios = true;
    } else if (aleatorioStr == "false") {
        aleatorios = false;
    } else {
        aleatorios = false;
    }
    lista.Cfgala(aleatorios);
    
    getline(archivo, linea);
    repetirStr = linea.substr(linea.find('=') + 1);
    lista.Cfgrep(stoi(repetirStr));
    
    archivo.close();
    if (!id.empty()) {
        int id1 = std::stoi(id);
        Node* temp = lista.buscar(id1);
        if (temp != nullptr) {
            lista.Cfg(temp);
            cfgant = true;
            limpiaryagregaractual(registros,temp);
        } else {
            cfgant = false;
        }
    } else {
        if (lista.getStart() != nullptr) {
            lista.Cfg(lista.getStart());
        }
        cfgant = false;
    }
}
void registrar(Node* clonar,Lista& registros){
    if(clonar == nullptr)return;
    Node* clon=new Node(
        clonar->id,
        clonar->nombre,
        clonar->artista,
        clonar->album,
        clonar->year,
        clonar->duracion,
        clonar->ruta
        );
    registros.agregar(clon);
}

void guardarCfg(Lista& lista){
    if(lista.getActual()==nullptr)return;
    
    ofstream archivo("status.cfg");
    archivo<<"id="<<lista.getActual()->id<<endl;
    archivo<<"reproduciendo="<<(reproduciendo ? "true" : "false")<<endl;
    archivo<<"modo aleatorio="<<(lista.getAleatorio() ? "true" : "false")<<endl;
    archivo<<"repeticion="<<lista.getRepeticion()<<endl;
    archivo.close();
}

void limpiaryagregaractual(Lista& registros, Node* actual){
	if(actual == nullptr) return;
	registros.limpiar();
	
	Node* clon = new Node(
        clon->id,
        clon->nombre,
        clon->artista,
        clon->album,
        clon->year,
        clon->duracion,
        clon->ruta
    );
    registros.agregar(clon);
}