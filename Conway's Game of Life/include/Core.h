#pragma once


constexpr unsigned int SCREEN_WIDTH = 960;
constexpr unsigned int SCREEN_HEIGHT = 540;

constexpr unsigned int CELL_WIDTH = 15;
constexpr unsigned int NUM_OF_CELL_ROWS = SCREEN_HEIGHT / CELL_WIDTH;
constexpr unsigned int NUM_OF_CELL_COLS = SCREEN_WIDTH / CELL_WIDTH;
constexpr unsigned int NUM_OF_CELLS = NUM_OF_CELL_ROWS * NUM_OF_CELL_COLS;
