#pragma once

enum class StatoGioco
{
    InCorso,
    GameOver
};

enum class Direzione
{
    Su = 0,
    Giu = 3,            // senza accento per evitare possibili errori
    Destra = 1,
    Sinistra = 2
};