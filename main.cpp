#include <stdio.h>
typedef struct {
    int x;
    int y;
} Pos;

typedef struct {
    Pos start;
    Pos end;
} Rectangle;

Rectangle CreateRectangle(int x1, int y1, int x2, int y2){
    Rectangle n;
    n.start.x = x1;
    n.start.y = y1;
    n.end.x   = x2;
    n.end.y   = y2;
    return n;
}

int calcArea(Rectangle rect){
    int largura = rect.end.x - rect.start.x;
    int altura  = rect.end.y - rect.start.y;
    if (largura < 0 || altura < 0) return 0;
    return largura * altura;
}

Rectangle RetangleIntersection(Rectangle rect1,Rectangle rect2){



    return CreateRectangle(0, 0, 0, 0);
}

int main(){
     // TESTE 1: Interseção parcial (esperado: start=(5,5), end=(10,10), area=25)
    Rectangle a1 = CreateRectangle(0, 0, 10, 10);
    Rectangle b1 = CreateRectangle(5, 5, 15, 15);

    return 0;
}