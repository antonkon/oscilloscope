//
// Created by radio on 27.05.17.
//

#ifndef ANALYS_RECHI_MAIN_H
#define ANALYS_RECHI_MAIN_H

#include <gtk/gtk.h>

static gint WIDTH_AREA = 760;
static gint HEIGHT_AREA = 240;

/* Коды ошибок */
/* Код ошибки состоид из 4 цифр. Первые две цифры
 * обозначают модуль в котором ошибка, вторые две сама ошибка.
 */

/* Ошибка инициализации GTK */
#define ERROR_INIT_GTK 0101


/* Создание графического интерфейсаы */
/* Находится в handlers.c */
int InitGui(int argc, char *argv[]);

/* Завершае приложение по закрытию окна */
/* Находится в handlers.c */
gint eventDestroy(GtkWidget *widget, GdkEvent *event, gpointer data);

/* Обработчик: вызывается при изменении размеров окна */
/* Находится в handlers.c */
gint EResize(GtkWidget *widget, GdkEventConfigure *event, gpointer data);

/* Обработчик кнопки "Старт" */
/* Находится в handlers.c */
gint EButStart(GtkWidget *widget, GdkEvent *event, gpointer data);

/* Обработчик кнопки "Стоп" */
/* Находится в handlers.c */
gint EButStop(GtkWidget *widget, GdkEvent *event, gpointer data);

/* Считывает данные с микрофона и возвращает*/
/* Находится в audio.c */
short* AudioData();

#endif //ANALYS_RECHI_MAIN_H
