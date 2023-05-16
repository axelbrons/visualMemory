#include "visualMemory.h"

void initElements(ELEMENT ele[NB_ELEMENTS][NB_ELEMENTS]) {
    int k=0;
    int l=0;
    for (int i = 0 ; i < NB_ELEMENTS ; i++) {
        for (int j = 0 ; j < NB_ELEMENTS; j++) {
            ele[i][j].actif=0;
            ele[i][j].visible=0;
            ele[i][j].x=670+j*SQUARE+k*SPACING;
            ele[i][j].y=290+i*SQUARE+l*SPACING;
            printf("%d,%d , x : %d et y : %d\n",i,j,ele[i][j].x,ele[i][j].y);
            k++;
            if (j == 2) {
                k=0;
                l++;
            }
        }
    }
}


void drawGrid(ELEMENT rect[NB_ELEMENTS][NB_ELEMENTS]) {
    al_clear_to_color(DARK_GREY);
    for (int i = 0; i < NB_ELEMENTS; i++) {
        for (int j = 0; j < NB_ELEMENTS; j++) {
            if (rect[i][j].visible == 1) {
                al_draw_filled_rounded_rectangle(rect[i][j].x,rect[i][j].y,rect[i][j].x+SQUARE,rect[i][j].y+SQUARE,RAYON,RAYON,GREEN);
            }
            else {
                al_draw_filled_rounded_rectangle(rect[i][j].x,rect[i][j].y,rect[i][j].x+SQUARE,rect[i][j].y+SQUARE,RAYON,RAYON,LIGHT_GREY);
            }
        }
    }
}

void randomElements(ELEMENT elements[NB_ELEMENTS][NB_ELEMENTS],int number){
    int num1 = 0;
    int num2 = 0;
    for (int i = 0 ; i < number ; i++) {
        num1 = rand()%3;
        num2 = rand()%3;
        if (elements[num1][num2].visible==0) {
            elements[num1][num2].visible=1;
        }else {
            i--;
        }
    }
}

void activationElementsVisible(ELEMENT elements[NB_ELEMENTS][NB_ELEMENTS]) {
    for (int i = 0 ; i < NB_ELEMENTS ; i++) {
        for (int j = 0 ; j < NB_ELEMENTS ; j++) {
            if (elements[i][j].visible==1) {
                elements[i][j].actif=1;
            }
            else {
                elements[i][j].actif=0;
            }
        }
    }
}

void hideElements(ELEMENT elements[NB_ELEMENTS][NB_ELEMENTS]) {
    for (int i = 0 ; i < NB_ELEMENTS ; i++) {
        for (int j = 0 ; j < NB_ELEMENTS ; j++) {
            elements[i][j].visible=0;
        }
    }
}

bool checkVictory(ELEMENT elements[NB_ELEMENTS][NB_ELEMENTS],int *score) {
    int cpt = 0;
    for (int i = 0 ; i < NB_ELEMENTS ; i++) {
        for (int j = 0 ; j < NB_ELEMENTS ; j++) {
            if (elements[i][j].visible==elements[i][j].actif) {
                cpt++;
            }
        }
    }
    if (cpt == 9){
        *score=*score+1;
        return true;
    }
    else {
        return false;
    }
}

void checkGoodSquare(ELEMENT elements[NB_ELEMENTS][NB_ELEMENTS], ALLEGRO_EVENT event) {

    for (int i = 0 ; i < NB_ELEMENTS ; i++) {
        for (int j = 0; j < NB_ELEMENTS; j++) {
            if (event.mouse.x > elements[i][j].x && event.mouse.x < elements[i][j].x+SQUARE && event.mouse.y > elements[i][j].y && event.mouse.y < elements[i][j].y+SQUARE && elements[i][j].actif == 1) {
                elements[i][j].visible=1;
            }
        }
    }

}