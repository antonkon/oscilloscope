#include "main.h"


//void Draw(GtkWidget *widget, GtkWidget *data){


//	int i,
//
//	/* Коордитаты точек справа и слева от нач. коорд. */
//	xl = WIDTH_AREA/2-1,
//	yl = HEIGHT_AREA/2,
//	xr = WIDTH_AREA/2,
//	yr = HEIGHT_AREA/2;
//
//	/* Масштаб в единице 3/4 высоты */
//	int baza = (HEIGHT_AREA/2) * 3/4;
//	float w = 2*M_PI/baza;
//
//	yr -= func(0)*baza;
//	gdk_draw_point(data->window,
//					widget->style->black_gc,
//					xr, yr);
//	xr++;
//	for(i=0; i < WIDTH_AREA/2; i++){
//		yr -= func(w*i)*baza;
//		yl -= func(w*(-i))*baza;
//		gdk_draw_point(data->window,
//					widget->style->black_gc,
//					xr, yr);
//		gdk_draw_point(data->window,
//					widget->style->black_gc,
//					xl, yl);
//		xr++; xl--;
//		yl = HEIGHT_AREA/2;
//		yr = HEIGHT_AREA/2;
//	}
//}
//
//void eventbutStart(GtkWidget *widget, GdkEventConfigure *event, GtkWidget *data){
//	g_print("111\n");
//
//    initDraw(data);
//}
//
//gboolean eventDraw(GtkWidget *widget, GdkEventConfigure *event, gpointer data){
////	g_print("222\n");
//
//    WIDTH_AREA = event->width;
//    HEIGHT_AREA = event->height;
//
//    static gint f = 0;
//
//
//
//
//    if (f <= 2) {
//        f++;
//        return(TRUE);
//    }
//
//    Draw(widget,data);
//
//	return(TRUE);
//}

int main( int   argc, char *argv[] )
{
    if (InitGui(&argc, argv) != 0) {
        g_print("Ошибка в InitGui !");
        return 1;
    }

    return 0;
}
