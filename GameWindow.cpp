#include "GameWindow.h"

\
GameWindow::GameWindow(int Xwindow, int Ywindow)
{
    _xCentre = Xwindow / 2;
    _yCentre = Ywindow / 2;
    _Xwindow = Xwindow;
    _Ywindow = Ywindow;
}

int GameWindow::getXCentre()
{
    return _xCentre;
}

int GameWindow::getYCentre()
{
    return _yCentre;
}

int GameWindow::getXWindow()
{
    return _Xwindow;
}

int GameWindow::getYWindow()
{
    return _Ywindow;
}
