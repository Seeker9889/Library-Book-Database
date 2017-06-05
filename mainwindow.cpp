#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "book.h"
#include "datarecord.h"
#include "internalvariables.h"
#include <QLineEdit>
#include <vector>
#include <iostream>
#include <fstream>

int currentRecord;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    display={ui->leTitle, ui->leAuthor};

    //Test Processes
    readDataSet();
    currentRecord=0;
    displayRecord(currentRecord);
    //vector<string> testData;
    /*testData.push_back("SCIENCE!");
    testData.push_back("Gordan Freeman");
    testData.push_back("More info");
    testData.push_back("Even more info");
    DataRecord dr=DataRecord(testData);
    DataSet.push_back(dr);
    writeDataSet();*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::writeDataSet() {
    fstream fs;
    fs.open(INTERNALfilelocation, fstream::out | fstream::trunc);

    if (!fs.is_open()) {
        return false;
    }

    for (auto const& dr : DataSet) {
        for (auto const& data : dr.getData()) {
            fs << data << "\n";
        }
        fs << INTERNALendOfRecordMsg << "\n";
    }

    fs.close();

    return true;
}

bool MainWindow::readDataSet() {
    fstream fs;
    fs.open(INTERNALfilelocation, fstream::in);

    if (!fs.is_open()) {
        return false;
    }

    string currentLine="";
    string extraInfo="";
    bool endedWithEndOfRecord=false;
    vector<string> currentDataRecord;
    //Read data into DataSet, making required DataRecords as it goes
    //while getline(fs, currentLine)
    //if line is not INTERNALendOfRecordMsg, read that line into as a piece of data into a Book in a DataRecord
    //if the Book info is filled and there are still more lines before INTERNALendOfRecordMsg, the rest of the data goes into 999-Other in the Book
    while (getline (fs, currentLine)) {
        endedWithEndOfRecord=false;
        if (currentLine != INTERNALendOfRecordMsg && currentDataRecord.size()<INTERNALinfo.size()) {
            currentDataRecord.push_back(currentLine);
        } else if (currentLine != INTERNALendOfRecordMsg) {
            extraInfo=currentDataRecord.at(currentDataRecord.size()-1);
            extraInfo+="\n"+currentLine;
            currentDataRecord.pop_back();
            currentDataRecord.push_back(extraInfo);
        } else {
            extraInfo="";
            DataSet.push_back(currentDataRecord);
            currentDataRecord.clear();
            endedWithEndOfRecord=true;
        }
    }
    if (!endedWithEndOfRecord) {
        DataSet.push_back(currentDataRecord);
        currentDataRecord.clear();
    }

    return true;
}

void MainWindow::displayRecord(int whichRec) {
    clearDisplay();
    //For the given record, individiually grab the string of each piece of data (title, author, etc.) and display them to the given line edits
    if (DataSet.size()>whichRec) {
        for (int m=0; m<2/*Commented out until ui has more line edits m<DataSet.at(whichRec).getData().size()*/; m++) {
            display.at(m)->setText(QString::fromStdString(DataSet.at(whichRec).getData(INTERNALinfo.at(m))));
        }
    }
}

void MainWindow::clearDisplay() {
    for (auto const& le : display) {
        le->setText("");
    }
}

void MainWindow::on_bExit_clicked() {
    qApp->exit();
}


//Navigation Button Slots
void MainWindow::on_bNext_clicked() {
    if (currentRecord+1<DataSet.size()) {
        displayRecord(++currentRecord);
    }
}

void MainWindow::on_bPrevious_clicked() {
    if (currentRecord-1>=0) {
        displayRecord(--currentRecord);
    }
}

void MainWindow::on_bLast_clicked() {
    currentRecord=DataSet.size()-1;
    displayRecord(currentRecord);
}

void MainWindow::on_bFirst_clicked() {
    currentRecord=0;
    displayRecord(currentRecord);
}
