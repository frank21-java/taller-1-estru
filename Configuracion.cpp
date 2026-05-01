#include "Configuracion.hpp"
#include <set>
Configuracion::Configuracion(const std::string& archivoCFG,const std::string& archivoTXT)
    : nombreArchivoCFG(archivoCFG),nombreArchivoTXT(archivoTXT){}
// metodos para el CFG
std::string Configuracion::trim(const std::string& str){
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");
    if(first == std::string::npos || last == std::string::npos) return "";
    return str.substr(first,(last-first+1));
}
bool Configuracion::cargarCFG(){
    std::ifstream archivo(nombreArchivoCFG);
    if (!archivo.is_open()){
        return false;
    }
    datos.clear();
    std::string linea;
    while (getline(archivo,linea)){
        if(linea.empty()||linea[0]=='#') continue;
        size_t pos = linea.find('=');
        if(pos != std::string::npos){
            std::string clave = trim(linea.substr(0,pos));
            std::string valor = trim(linea.substr(pos+1));
            datos[clave] = valor;
        }
    }
    archivo.close();
    return true;
}
bool Configuracion::guardarCFG(){
    std::ofstream archivo(nombreArchivoCFG);
    if(!archivo.is_open()) return false;
    for(const auto& par:datos){
        archivo << par.first <<"="<<par.second<<std::endl;
    }
    archivo.close();
    return true;
}
std::string Configuracion::getString(const std::string& clave, const std::string& defaultValue){
    if (datos.find(clave) != datos.end()){
        return datos[clave];
    }
    return defaultValue;
}
int Configuracion::getInt(const std::string& clave,int defaultValue){
    if(datos.find(clave)!=datos.end()){
        try{
            return std::stoi(datos[clave]);
        } catch (...){
            return defaultValue;
        }
    }
    return defaultValue;
}
bool Configuracion::getBool(const std::string& clave,bool defaultValue){
    if(datos.find(clave)!=datos.end()){
        std::string valor = datos[clave];
        std::transform(valor.begin(),valor.end(),valor.begin(),::tolower);
        return(valor == "true"||valor == "1"||valor == "yes");
    }
    return defaultValue;
}
void Configuracion::set(const std::string& clave,const std::string& valor){
    datos[clave]=valor;
}
void Configuracion::set(const std::string& clave,int valor){
    datos[clave]=std::to_string(valor);
}
void Configuracion::set(const std::string& clave,bool valor){
    datos[clave]=valor ? "true" : "false";
}





//metodos TXT
bool Configuracion::cargarTXT(){
    std::ifstream archivo(nombreArchivoTXT);
    if(!archivo.is_open()) return false;
    std::string linea;
    bool Linea1 = true;
    while (getline(archivo,linea)){
        if(Linea1){
            Linea1 = false;
            continue;
        }
        if(linea.empty()) continue;
        try{
            Cancion cancion = Cancion::fromString(linea);
            datos["cancion_"+cancion.id] = cancion.toString();
        } catch (const std::exception& e){
            std::cerr <<"Error al procesar linea: "<< linea<<std::endl;
        }
    }
    archivo.close();
    return true;
}
bool Configuracion::guardarTXT(){
    std::ofstream archivo(nombreArchivoTXT);
    if(!archivo.is_open()) return false;
    std::vector<Cancion> canciones = obtenerTodasLasCanciones();
    for(const auto& cancion:canciones){
        archivo<<cancion.toString()<<std::endl;
    }
    archivo.close();
    return true;
}
void Configuracion::agregarCancion(const Cancion& cancion){
    std::string key = "cancion_"+cancion.id;
    set(key,cancion.toString());
}
bool Configuracion::eliminarCacion(const std::string& id){
    std::string key = "cancion_"+id;
    if(datos.find(key) == datos.end()){
        return false;
    }
    datos.erase(key);
    return true;
}
Cancion* Configuracion::buscarCancion(const std::string& id){
    std::string key = "cancion_"+id;
    if(datos.find(key)!=datos.end()){
        static Cancion cancion;
        cancion = Cancion::fromString(datos[key]);
        return&cancion;
    }
    return nullptr;
}
std::vector<Cancion> Configuracion::obtenerTodasLasCanciones(){
    std::vector<Cancion> canciones;
    for(const auto& par: datos){
        if(par.first.find("cancion_") == 0){
            canciones.push_back(Cancion::fromString(par.second));
        }
    }
    return canciones;
}
int Configuracion::getTotalCanciones(){
    int total = 0;
    for(const auto& par : datos){
        if(par.first.find("cancion_") == 0){
            total++;
        }
    }
    return total;
}
void Configuracion::mostrarTodasLasCanciones(){
    std::vector<Cancion> canciones = obtenerTodasLasCanciones();
    int a = 1;
    if(canciones.empty()){
        return;
    } else{
        for(const auto& cancion: canciones){
            cancion.mostrar(a);
            a +=1;
        }
    }
}
void Configuracion::setUltimaCancion(const std::string& id){
    set("ultima_cancion", id);
    guardarCFG();
}
std::string Configuracion::getUltimaCancionID(){
    return getString("ultima_cancion_id","");
}
Cancion* Configuracion::getUltimaCancion(){
    std:: string id = getUltimaCancionID();
    if(!id.empty()){
        return buscarCancion(id);
    }
    return nullptr;
}
bool Configuracion::hayUltimaCancion(){
    std::string id = getUltimaCancionID();
    return !id.empty();
}
bool Configuracion::sincronizar(){
    return guardarCFG()&&guardarTXT();
}
void Configuracion::mostrarUltimaCancionReproducida(){
    Cancion* ultima = getUltimaCancion();
    if(!hayUltimaCancion()){
        std::cout<<"Reproducciendo ( ): "<<std::endl;
        std::cout<<"Artista: "<<std::endl;
        std::cout<<"Album: "<<std::endl;
        return;
    }
    if(ultima){
        std::cout<<"Reproducciendo ("<< ultima->nombre_song << "): "<< std::endl;
        std::cout<<"Artista: "<<ultima->nombre_artista<<std::endl;
        std::cout<<"Album: "<<ultima->nombre_album<<" ["<<ultima->years<<"]"<<std::endl;
    }
}