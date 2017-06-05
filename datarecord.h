#ifndef DATARECORD_H
#define DATARECORD_H

#include "book.h"
#include <vector>

class DataRecord
{
private:
    int recordID;
    vector<string> myData;
    Book myBook;
public:
    //Constructors
    DataRecord();
    DataRecord(vector<string> newData);

    //Set value functions
    void setData(vector<string> newData);

    //Accessor functions
    int getrecordID() {return recordID;}
    Book getBook() {return myBook;}
    string getData(string key) const {return myBook.getInfo(key);}
    vector<string> getData() const {return myData;}
};

#endif // DATARECORD_H
