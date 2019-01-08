#pragma once

#define SHOW_FRAME_RATE 1


constexpr unsigned int SCREEN_WIDTH = 1280;
constexpr unsigned int SCREEN_HEIGHT = 720;

constexpr unsigned int CELL_WIDTH = 10;
constexpr unsigned int NUM_OF_CELL_ROWS = SCREEN_HEIGHT / CELL_WIDTH;
constexpr unsigned int NUM_OF_CELL_COLS = SCREEN_WIDTH / CELL_WIDTH;
constexpr unsigned int NUM_OF_CELLS = NUM_OF_CELL_ROWS * NUM_OF_CELL_COLS;
