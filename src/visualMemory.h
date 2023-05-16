
#ifndef VISUALMEMORY_VISUALMEMORY_H
#define VISUALMEMORY_VISUALMEMORY_H

/// Include
#include <stdio.h>
#include <assert.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <time.h>

/// Dimensions
#define WIDTH 1600
#define HEIGHT 900
#define SQUARE 75
#define RAYON 20
#define SPACING 8

/// Color
#define DARK_GREY al_map_rgb(38, 42, 51)
#define GREEN al_map_rgb(67, 255, 175)
#define LIGHT_GREY al_map_rgb(82, 103, 119)

/// Number
#define NB_ELEMENTS 3
#define NB_ACTIF 3

///Structure
typedef struct {
    int x,y;
    int actif;
    int visible;
}ELEMENT;

/// Function
void drawGrid(ELEMENT rect[NB_ELEMENTS][NB_ELEMENTS]);
void initElements(ELEMENT ele[NB_ELEMENTS][NB_ELEMENTS]);
void randomElements(ELEMENT elements[NB_ELEMENTS][NB_ELEMENTS],int number);
void activationElementsVisible(ELEMENT elements[NB_ELEMENTS][NB_ELEMENTS]);
void hideElements(ELEMENT elements[NB_ELEMENTS][NB_ELEMENTS]);
bool checkVictory(ELEMENT elements[NB_ELEMENTS][NB_ELEMENTS],int *score);
void checkGoodSquare(ELEMENT elements[NB_ELEMENTS][NB_ELEMENTS],ALLEGRO_EVENT event);

#endif //VISUALMEMORY_VISUALMEMORY_H
