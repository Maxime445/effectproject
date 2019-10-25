#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "effect.h"
#include "audio.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void reloadEffectChainUI();

private:
    Ui::MainWindow *ui;

    Audio* audio;

    void populateSelectEffects();
    QList<QString> effectList;
    int newEffectType;

    void createEffect();
private slots:
    void effectsSelectIndexChanged(int index);
};
#endif // MAINWINDOW_H
