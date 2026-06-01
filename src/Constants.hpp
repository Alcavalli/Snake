#pragma once

namespace Constants
{
    // Griglia di gioco
    constexpr int COLS = 17;
    constexpr int ROWS = 15;

    // Grandezza finestra
    constexpr int WINDOW_WIDTH  = 680;
    constexpr int WINDOW_HEIGHT = 600;

    // Cella
    constexpr int CELL_SIZE = WINDOW_WIDTH / COLS;      // ogni cella quadrata sarà 40x40 px

    // Tempo per i frame
    constexpr int MOVE_INTERVAL_MS = 200;
    constexpr int LAMPEGGIO_MS = 500;
    
    // Direzioni accodate
    constexpr int MAX_INPUT_QUEUE = 2;
}