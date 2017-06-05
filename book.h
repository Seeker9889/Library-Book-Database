#ifndef BOOK_H
#define BOOK_H

using namespace std;
#include <string>
#include <vector>
#include <map>

class Book
{
private:
    map <string, string> myInfo;
    //Set keys for myInfo; change to add/remove stored information
    void initmyInfo();
public:
    //Constructors
    Book();
    Book(vector<string> newData);

    //Set value functions
    void setmyInfo(vector<string> newData);
    void setmyInfo(string which, string data);

    //Accessor functions
    map<string, string> getInfo() const {return myInfo;}
    string getInfo(string key) const {return myInfo.at(key);}
    //Should never be needed since Datarecord holds the vector
    vector<string> getDataVector() const;
};

#endif // BOOK_H
