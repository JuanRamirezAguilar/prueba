#include <iostream>

#ifdef _WIN32
#include <windows.h> 
#define CLEAR "cls"
#define ESWINDOWS true
#else
#define CLEAR "clear"
#define ESWINDOWS false
#endif

using namespace std;

void gotoxy(int y_pos, int x_pos);
void setBorder(int alt, int anch, int posXInicio, int posYInicio);
void mostrarCursor(bool);
void menu();

int main () {

    if (ESWINDOWS)
        SetConsoleOutputCP(CP_UTF8);

    system(CLEAR);
    setBorder(10, 30, 0, 0);
    mostrarCursor(false);
    cin.ignore();

    return 0;
}

void gotoxy(int y_pos, int x_pos) {
    printf("%c[%d;%df", 0x1B, y_pos, x_pos);
}

void setBorder(int alt, int anch, int posXInicio, int posYInicio) {
    for (int i = 0; i <= anch; i++) {
        gotoxy(posYInicio, posXInicio + i);
        printf("\xe2\x96\x80");
        gotoxy(posYInicio + alt, posXInicio + i);
        printf("\xe2\x96\x84");
    }

    for (int i = 0; i <= alt; i++) {
        gotoxy(posYInicio + i, posXInicio);
        printf("\xe2\x96\x88");
        gotoxy(posYInicio + i, posXInicio + anch);
        printf("\xe2\x96\x88");
    }
}

void mostrarCursor(bool opc) { 
    if (opc)
        cout << "\033[?25h"; 
    else
        cout << "\033[?25l";
}

void menu() {

}
