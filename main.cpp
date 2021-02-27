#include <iostream>
#include "Persona.h"
using namespace UndavPersona;
using std::cout, std::endl;

void PruebaPersona();

int main()
{
    PruebaPersona();

}

void PruebaPersona()
{
    cout << "CREANDO PERSONAS" << endl;
    auto persona1 = CrearPersona("Nombre1", "Apellido1");
    MostrarInfo(persona1);
    auto persona2 = CrearPersona("Nombre2", "Apellido2");
    MostrarInfo(persona2);
    cout<<endl;
    cout << "PROBANDO GETTERS" << endl;
    cout << "GetID: " << ObtenerId(persona1) << endl;
    cout << "GetNombre: " << ObtenerNombre(persona1) << endl;
    cout << "GetApellido: " << ObtenerApellido(persona1) << endl;
    cout << "GetCantidadAmigos: " << ObtenerCantidadAmigos(persona1) << endl;
    cout << endl;
    cout << "CAMBIANDO NOMBRE Y APELLIDO" << endl;
    CambiarNombre(persona1, "NuevoNombre1");
    CambiarApellido(persona1, "NuevoApellido1");
    MostrarInfo(persona1);
    cout << endl;
    cout << "AGREGANDO AMIGO" << endl;
    AgregarAmigo(persona1, persona2);
    MostrarInfo(persona1);
    cout << endl;
    cout << "MOSTRANDO INFO DEL AMIGO" << endl;
    MostrarInfo(persona2);
    cout << endl;
    cout << "SON AMIGOS? " << endl;
    (SonAmigos(persona1, persona2)) ? cout << "Si" : cout << "No";
    cout << endl << endl;
    cout << "SON LA MISMA PERSONA? (persona1 y persona1)" << endl;
    (SonIguales(persona1, persona1)) ? cout << "Si" : cout << "No";
    cout << endl;
    cout << "SON LA MISMA PERSONA? (persona1 y persona2)" << endl;
    (SonIguales(persona1, persona2)) ? cout << "Si" : cout << "No";
    cout << endl << endl;
    cout << "SERIALIZADO EXPRESIVO" << endl;
    cout << Serializar(persona1, Expresivo) << endl;
    cout << "SERIALIZADO CSV" << endl;
    cout << Serializar(persona1, CSV) << endl;

    Destruir(persona1);
    Destruir(persona2);
}
