#include "visualMemory.h"


int main() {

    ///Assert
    assert(al_init());
    assert(al_init_primitives_addon());
    assert(al_init_image_addon());
    al_init_font_addon();
    assert(al_install_mouse());
    assert(al_install_keyboard());
    srand(time(NULL));
    assert(al_init_ttf_addon());

    /// Bitmap
    ALLEGRO_BITMAP *icon;
    icon = al_create_bitmap(0,0);
    icon = al_load_bitmap("img/iconDisplay1.png");
    //al_draw_scaled_bitmap(icon,0,0,1024,1024,0,0,32,32,0);

    /// Display
    ALLEGRO_DISPLAY *display;
    display=al_create_display(WIDTH,HEIGHT);
    al_set_window_title(display,"Visual Memory");
    al_set_window_position(display,0,0);
    //al_set_display_icon(display,icon);

    /// Fonts
    ALLEGRO_FONT *font = NULL;
    font = al_load_font("../fonts/RobotoMono-Regular.ttf",40,ALLEGRO_ALIGN_CENTER);

    /// Timer
    ALLEGRO_TIMER *timer;
    timer = al_create_timer(1.0/60);
    al_start_timer(timer);

    /// Queue
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_EVENT event;
    queue = al_create_event_queue();
    al_register_event_source(queue,al_get_mouse_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue,al_get_keyboard_event_source());


    /// Declaration
    int end=0;
    int temps = 0;
    bool victory = 1;
    int score = 0;
    ELEMENT elements[NB_ELEMENTS][NB_ELEMENTS]={0};

    /// Initialisation
    initElements(elements);
    al_clear_to_color(DARK_GREY);

    /// Boucle
    while (!end) {
        al_wait_for_event(queue,&event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE :
                end=1;
                break;
            case ALLEGRO_EVENT_KEY_DOWN :
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE :
                        end=1;
                        break;
                }
                break;
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN :

                checkGoodSquare(elements,event);

                break;
            case ALLEGRO_EVENT_TIMER :
                //al_clear_to_color(DARK_GREY);
                drawGrid(elements);
                al_flip_display();
                al_draw_textf(font,LIGHT_GREY,700,600,ALLEGRO_ALIGN_CENTER,"%d",score);

                if (victory == 1) {
                    //al_clear_to_color(DARK_GREY);
                    initElements(elements);
                    randomElements(elements,NB_ACTIF);
                    activationElementsVisible(elements);
                    drawGrid(elements);
                    al_flip_display();
                    al_rest(3.0);
                    hideElements(elements);
                    victory = 0;
                }
                if (!victory) {
                    victory = checkVictory(elements,&score);
                }



                temps++;
                break;
        }
    }




    /// Destroy
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    al_destroy_display(display);
    al_destroy_font(font);

    return 0;
}
