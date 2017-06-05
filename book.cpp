#include "book.h"
#include "internalvariables.h"
#include <string>
#include <vector>

Book::Book()
{
    initmyInfo();
}

Book::Book(vector<string> newData) {
    initmyInfo();
    int i=0;
    for (auto const& key : myInfo) {
        //Set each value of myInfo to the correct newData
        //If newData does not have a certain value, set that myInfo value to an empty string
        if (newData.size()>i) {
            myInfo[key.first]=newData.at(i);
        } else
            myInfo[key.first]="";
    }
}

void Book::initmyInfo() {
    for (auto const& name:INTERNALinfo) {
        myInfo[name]="";
    }
}

void Book::setmyInfo(vector<string> newData) {
    int i=0;
    for (auto const& key : myInfo) {
        if (newData.size()>i) {
            myInfo[key.first]=newData.at(i);
            i++;
        }
    }
}

void Book::setmyInfo(string whichKey, string data) {
    //If whichKey is not an existing key...
    if (myInfo.find(whichKey) == myInfo.end()) {
        //do nothing
    } else { //Set data to the given key
        myInfo[whichKey]=data;
    }
}

vector<string> Book::getDataVector() const {
    vector<string> toReturn;
    for (auto const& key: myInfo) {
        toReturn.push_back(myInfo.at(key.first));
    }
    return toReturn;
}
