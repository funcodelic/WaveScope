/*
*
*
*
*/
#include <QApplication>
#include <QWidget>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << "running WaveScope...\n";
    cout << "_cplusplus = " << __cplusplus << endl;


    QApplication app(argc, argv);
    QWidget w;
    w.setWindowTitle("WaveScope");
    w.resize(400, 300);
    w.setStyleSheet("background-color: #2b6cff;");
    w.show();
    return app.exec();

    return 0;
}

