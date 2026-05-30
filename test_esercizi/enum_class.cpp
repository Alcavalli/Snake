// scrivere un programma che, tramite una enum class, salva una stagione (primavera) e tramite uno switch stampa

#include <iostream>

enum class Stagione
{
    Estate,
    Inverno,
    Primavera,
    Autunno
};

int main()
{
    Stagione corrente = Stagione::Primavera;

    std::cout << "Stagione selezionata: ";
    switch(corrente)
    {
        case Stagione::Estate:
            std::cout << "estate";
            break;
        case Stagione::Inverno:
            std::cout << "inverno";
            break;
        case Stagione::Primavera:
            std::cout << "primavera";
            break;
        case Stagione::Autunno:
            std::cout << "autunno";
            break;
        // il default non è necessario
    }

    return 0;
}