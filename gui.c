//
// Created by radio on 27.05.17.
//

#include "main.h"

int InitGui(int argc, char *argv[]) {
    GtkWidget *win;
    GtkWidget *vbox;

    GtkWidget *fixed;
    GtkWidget *butStart;
    GtkWidget *butStop;
    GtkWidget *draw_area;

    if (!gtk_init_check(&argc, &argv)) {
        g_print("Ошибка инициализации GTK !");
        return ERROR_INIT_GTK;
    }
/*---------*/
    win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//    gtk_window_set_decorated(GTK_WINDOW(win),FALSE);
    gtk_window_set_default_size(GTK_WINDOW(win), 800, 340);
    gtk_signal_connect(GTK_OBJECT(win),
                       "destroy",
                       GTK_SIGNAL_FUNC(eventDestroy),
                       NULL);
    /* Рамка в 20 пикс */
    gtk_container_set_border_width(GTK_CONTAINER(win),20);
/*---------*/
    vbox = gtk_vbox_new(FALSE,10);
    gtk_container_add(GTK_CONTAINER(win),vbox);

/*---------*/
    draw_area = gtk_drawing_area_new();
    gtk_widget_set_usize(draw_area, WIDTH_AREA, HEIGHT_AREA);
    gtk_signal_connect(GTK_OBJECT(draw_area),
                       "event",
                       GTK_SIGNAL_FUNC(EResize),
                       draw_area);
    gtk_box_pack_start(GTK_BOX(vbox),draw_area,TRUE,TRUE,0);
/*---------*/
    fixed = gtk_fixed_new();
    gtk_box_pack_end(GTK_BOX(vbox),fixed,FALSE,FALSE,0);
/*---------*/
    butStart = gtk_button_new_with_label("Старт");
    gtk_widget_set_size_request(butStart, 150, 50);
    gtk_signal_connect(GTK_OBJECT(butStart),
                       "clicked",
                       GTK_SIGNAL_FUNC(EButStart),
                       draw_area);
    gtk_fixed_put(GTK_FIXED(fixed), butStart, 0, 0);
/*---------*/
    butStop = gtk_button_new_with_label("Стоп");
    gtk_widget_set_size_request(butStop, 150, 50);
    gtk_signal_connect(GTK_OBJECT(butStop),
                       "clicked",
                       GTK_SIGNAL_FUNC(EButStop),
                       draw_area);
    gtk_fixed_put(GTK_FIXED(fixed), butStop, 200, 0);

    /* сигнал таймера */
    gtk_timeout_add(100, EButStart, draw_area);

    gtk_widget_show_all(win);
    gtk_main ();

    return 0;
}