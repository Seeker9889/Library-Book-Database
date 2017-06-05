#include "datarecord.h"

DataRecord::DataRecord() {

}

DataRecord::DataRecord(vector<string> newData) {
    setData(newData);
}

void DataRecord::setData(vector<string> newData) {
    myData=newData;
    myBook.setmyInfo(myData);
}

