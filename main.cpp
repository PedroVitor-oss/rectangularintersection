#include <stdio.h>
#include <algorithm>
#include <vector>

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

    //ponit start
    // max x entre os pontos de start
    // max y entre os pontos de start
    int sx = std::max(rect1.start.x,rect2.start.x);
    int sy = std::max(rect1.start.y,rect2.start.y);

    // point end 
    int ex = std::min(rect1.end.x,rect2.end.x);
    int ey = std::min(rect1.end.y,rect2.end.y);

    return CreateRectangle(sx, sy, ex, ey);
}
 
Rectangle IntersectAll(Rectangle rectangles[], const int n_rectangle){

    Rectangle result = rectangles[0];

    for( int i = 1; i < n_rectangle; i++ ){
        Rectangle other = rectangles[i];
        result = RetangleIntersection(result,other);
        // mostart cada interceção 
        printf("intercecao %d: other rectangle start(%d,%d) end(%d,%d)\n",i,other.start.x,other.start.y,other.end.x,other.end.y);
        printf("RESULT : Intersecao resultante -> start=(%d,%d), end=(%d,%d), area=%d\n\n",result.start.x,result.start.y,result.end.x,result.end.y,calcArea(result));

    }
    return result;
}


int main(){
     // TESTE 1: Interseção parcial (esperado: start=(5,5), end=(10,10), area=25)
    // Rectangle a1 = CreateRectangle(0, 0, 10, 10);
    // Rectangle b1 = CreateRectangle(5, 5, 15, 15);

    // Rectangle result = RetangleIntersection(a1,b1);
    // printf("TESTE 1: Intersecao parcial (esperado: start=(5,5), end=(10,10), area=25)\n");
    // printf("RESULT : Intersecao resultante -> start=(%d,%d), end=(%d,%d), area=%d",result.start.x,result.start.y,result.end.x,result.end.y,calcArea(result));

    // agora com array
     // ============================
    // TESTE 1: 3 retângulos com interseção comum
    // A: (0,0)-(10,10)
    // B: (2,2)-(12,12)
    // C: (4,4)-(8,8)
    // Esperado: start=(4,4), end=(8,8), area=16
    // ============================
    Rectangle t1[] = {
        CreateRectangle(0, 0, 10, 10),
        CreateRectangle(2, 2, 12, 12),
        CreateRectangle(4, 4,  8,  8)
    };
    Rectangle r1 = IntersectAll(t1, 3);
    printf("Esperado: start=(4,4), end=(8,8), area=16\n");
    printf("T1: start=(%d,%d) end=(%d,%d) area=%d\n",
           r1.start.x, r1.start.y, r1.end.x, r1.end.y, calcArea(r1));
    return 0;
}