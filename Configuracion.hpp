#ifndef CONFIGURACION_HPP
#define CONFIGURACION_HPP
#include <string>
#include <map>
#include <vector>
#include <functional>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

struct Cancion {
    std::string id;
    stdd::string nombre_song;
    std::string nombre_artista;
    std::string nombre_album;
    int years;
    int duracion_seg;
    std::string ubicacion_archivo;
    std::string toString() const {
        return id+"|"+nombre_song+"|"+nombre_artista+"|"+nombre_album+"|"+
        std::to_string(years)+"|"+std::to_string(duracion_seg)+"|"+ubicacion_archivo;
    }

    static Cancion fromString(const std::string& data){
        Cancion c;
        std::stringstream ss(data);
        std::getline(ss,c.id,'|');
        std::getline(ss,c.nombre_song,'|');
        std::getline(ss,c.nombre_artista,'|');
        std::getline(ss,c.nombre_album,'|');
        std::string years_str;
        std::getline(ss,years_str,'|');
        c.years = std::stroi(years_str);
        std::string duracion_seg;
        std::getline(ss,duracion_seg,'|');
        c.years = std::stroi(duracion_seg);
        std::getline(ss,c.ubicacion_archivo);
        return c;
    }
    void mostrar() const{
        std::cout<<nombre_song<<" - "<<nombre_album<<std::endl;
    }
}

class Cofiguracion {
    private:
        std::map<std::string, std::string> datos;
        std::string nombreArchivoCFG;
        std::string nombreArchivoTXT;
        std::string trim(const std::string& str);

    public:
        Configuracion(const std::string& ArchivoCFG, const std::string& ArchivoTXT);
        // metodos para el CFG
        bool cargarCFG();
        bool guardarCFG();

        std::string getString(const std::string& clave, const std::string& defaultValue = "");
        int getInt(const std::string& clave,int defaultValue = 0);
        bool getBool(const std::string& clave,bool defaultValue = false);
        void set(const std::string& clave,const std;;string& valor);
        void set(const std::string& clave,int valor);        
        void set(const std::string& clave,bool valor);





    //metodos TXT
    bool cargarTXT();
    bool guardarTXT();

    void agregarCancion(const Cancion& cancion);
    bool eliminarCacion(const std::string& id);
    Cancion* buscarCancion(const std::string& id);
    std::vector<Cancion> obtenerTodasLasCanciones();
    int getTotalCanciones();
    void mostrarTodasLasCanciones();
    
    
}
#endif