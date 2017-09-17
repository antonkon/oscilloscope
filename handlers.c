//
// Created by radio on 27.05.17.
//

#include "main.h"

short *aud_data = NULL;
gboolean status = TRUE;

gint eventDestroy(GtkWidget *widget, GdkEvent *event, gpointer data){
    g_print("123\n");
    gtk_main_quit();
    return(0);
}

void WindowFon(GtkWidget *data) {
    static GdkColormap *colormap = NULL;
    static GdkGC *gcFon1 = NULL;                /* фон */
    static GdkGC *gcFon2 = NULL;                /* пунктир */
    GdkColor color;

    /* цвет фона: d4d0c8 */
    /* цвет пунктира: 808080 */
    if (colormap == NULL){
        colormap = gdk_colormap_get_system();
        gcFon1 = gdk_gc_new(data->window);
        gcFon2 = gdk_gc_new(data->window);

        gdk_color_parse("#d4d0c8",&color);
        gdk_color_alloc(colormap,&color);
        gdk_gc_set_foreground(gcFon1,&color);

        gdk_color_parse("#808080",&color);
        gdk_color_alloc(colormap,&color);
        gdk_gc_set_foreground(gcFon2,&color);
    }
    /* Заливка фона */
    gdk_draw_rectangle(data->window,
                       gcFon1,
                       TRUE,
                       0, 0, WIDTH_AREA, HEIGHT_AREA);
    /* рамка */
    gdk_draw_rectangle(data->window,
                       data->style->black_gc,
                       FALSE,
                       0, 0, WIDTH_AREA-1, HEIGHT_AREA-1);

    /* центральная линия */
    gdk_draw_line(data->window,
                  data->style->black_gc,
                  0, HEIGHT_AREA/2, WIDTH_AREA-1, HEIGHT_AREA/2);

}

gint WindowContent(GtkWidget *data) {
    int i,j,x=0,x_last=0;
    float y,y_last=0.0;
    float baza = (HEIGHT_AREA/2) * 3/4;

//    for(i=-5; i<200; i++) {
//        gdk_draw_point(data->window,
//                       data->style->black_gc,
//                       i, i);
//    }
    if (aud_data != NULL) {

            for (i = 20; i < 1000; i++) {
                y = HEIGHT_AREA/2;
                y += -(aud_data[i] / 32768.0) * baza;
                x++;
                gdk_draw_line(data->window,
                              data->style->black_gc,
                              x_last, y_last,
                              x, y);
                y_last = y;
                x_last = x;
            }

    }

    return 0;
}

gint EResize(GtkWidget *widget, GdkEventConfigure *event, gpointer data) {
    WIDTH_AREA = event->width;
    HEIGHT_AREA = event->height;

    WindowFon(data);
    WindowContent(data);

    return 0;
}

gint EButStart(GtkWidget *widget, GdkEvent *event, gpointer data) {
    aud_data= AudioData();
    WindowFon(data);
    WindowContent(data);

    return status;
}

gint EButStop(GtkWidget *widget, GdkEvent *event, gpointer data) {

    if(status == FALSE) {
        status = TRUE;
        gtk_timeout_add(100, EButStart, data);
    } else status = FALSE;

    return 0;
}