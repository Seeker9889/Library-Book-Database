#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <vector>
#include <datarecord.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool writeDataSet();
    bool readDataSet();
    void displayRecord(int whichRec);
    void clearDisplay();

    //All DataRecords that have been opened
    vector<DataRecord> DataSet;
    //Line edits which display data record information
    //Update as necessary to refer to each line edit display on the form
    vector<QLineEdit*> display;

private slots:
    void on_bExit_clicked();

    void on_bNext_clicked();

    void on_bPrevious_clicked();

    void on_bLast_clicked();

    void on_bFirst_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
