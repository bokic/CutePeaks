#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "peaksview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public Q_SLOTS:
    void setFilename(const QString& filename);


private:
    PeaksView * mView;
    QSlider * mYSlider;
    QSlider * mXSlider;

};

#endif // MAINWINDOW_H
