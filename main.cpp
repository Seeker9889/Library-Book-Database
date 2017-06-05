/*
 * Sam George
 * Library Book Database
 *
 * Notes:
 *  -Datarecord exists so the database can store things other than just books. For now there is only books, but Datarecord provides an interface which could easily allow for other media's data to be stored
 *  -Map is used to hold Book info to allow easy access to specific values. A vector could have been used, but this would have required keeping track of magic numbers to know which element a desired
 *      value is at. While the keys to the map also contain a magic number of sorts, e.g. "2" in 2-Author, the "Author" part of the string provides some in-code explanation of the value
 *  -All const internal variables are defined in internalvariables.h and identifiers are designated with INTERNAL...
 *
 * */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
