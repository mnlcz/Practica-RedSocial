//
// Created by MnLCz on 25/2/2021.
//

#include "Persona.h"
#include <iostream>
#include <vector>
using std::cout,std::endl, std::vector, std::to_string;

int g_idGenerados = 0;
struct UndavPersona::Persona
{
    unsigned int id = 0; // id inicial es 0, aumenta de a 1.
    string nombre;
    string apellido;
    vector<Persona*> amigos;
};

UndavPersona::Persona *UndavPersona::CrearPersona(string nombre, string apellido)
{
    auto nuevaPersona = new UndavPersona::Persona;
    nuevaPersona->nombre = nombre;
    nuevaPersona->apellido = apellido;
    GenerarID(nuevaPersona);

    return nuevaPersona;
}

void UndavPersona::GenerarID(UndavPersona::Persona *persona)
{
    persona->id += g_idGenerados;
    g_idGenerados++;
}

void UndavPersona::MostrarInfo(const UndavPersona::Persona *persona)
{
    cout << "ID: " << persona->id << endl;
    cout << "NOMBRE: " << persona->nombre << endl;
    cout << "APELLIDO: " << persona->apellido << endl;
    cout << "CANTIDAD DE AMIGOS: " << persona->amigos.size() << endl;
    if(!persona->amigos.empty())
        MostrarIDsAmigos(persona);
}

unsigned int UndavPersona::ObtenerId(const UndavPersona::Persona *persona)
{
    return persona->id;
}

string UndavPersona::ObtenerNombre(const UndavPersona::Persona *persona)
{
    return persona->nombre;
}

string UndavPersona::ObtenerApellido(const UndavPersona::Persona *persona)
{
    return persona->apellido;
}

int UndavPersona::ObtenerCantidadAmigos(UndavPersona::Persona *persona)
{
    return persona->amigos.size();
}

void UndavPersona::CambiarNombre(UndavPersona::Persona *persona, string nombre)
{
    persona->nombre = nombre;
}

void UndavPersona::CambiarApellido(UndavPersona::Persona *persona, string apellido)
{
    persona->apellido = apellido;
}

void UndavPersona::AgregarAmigo(UndavPersona::Persona *persona, UndavPersona::Persona *amigo)
{
    if (!SonAmigos(persona, amigo) && !SonIguales(persona, amigo))
    {
        persona->amigos.push_back(amigo);
        amigo->amigos.push_back(persona);
    }
}

void UndavPersona::MostrarIDsAmigos(const UndavPersona::Persona *persona)
{
    cout << "IDs amigos: [";
    for(auto amigo : persona->amigos)
    {
        cout << " " << amigo->id << " ";
    }
    cout << "]" << endl;
}

bool UndavPersona::SonIguales(const UndavPersona::Persona *persona1, const UndavPersona::Persona *persona2)
{
    return persona1->id == persona2->id;
}

bool UndavPersona::SonAmigos(const UndavPersona::Persona *persona, UndavPersona::Persona *otraPersona)
{
    for(auto amigo : persona->amigos)
    {
        if(amigo->id == otraPersona->id)
            return true;
    }
    return false;
}

void UndavPersona::Destruir(UndavPersona::Persona *persona)
{
    delete persona;
}

string UndavPersona::Serializar(const UndavPersona::Persona *persona, TipoFormato formato)
{
    string serializado;
    switch (formato)
    {
        case Expresivo:
            serializado = FormatoExpresivo(persona);
            break;
        case CSV:
            serializado = FormatoCSV(persona);
    }
    return serializado;
}

string UndavPersona::FormatoExpresivo(const UndavPersona::Persona *persona)
{
    string s_ID = to_string(persona->id);
    string n_Amigos = to_string(persona->amigos.size()) + " amigos";
    string serializado = "[" + s_ID + "] " + persona->nombre + " " + persona->apellido + " " + "tiene " + n_Amigos;
    return serializado;
}

string UndavPersona::FormatoCSV(const UndavPersona::Persona *persona)
{
    string s_ID = to_string(persona->id);
    string n_Amigos = to_string(persona->amigos.size());
    string serializado = s_ID + "," + persona->nombre + "," + persona->apellido + "," + n_Amigos;
    return serializado;
}


