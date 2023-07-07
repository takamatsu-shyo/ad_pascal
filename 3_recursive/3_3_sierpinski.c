#include <stdio.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define PI 3.1415926535

typedef struct {
    unsigned char r, g, b;
} Pixel;

Pixel image[HEIGHT][WIDTH];

typedef struct {
    double x, y;
} Point;

Point position = {WIDTH / 2, HEIGHT / 2};

void draw_line(int dir, int len){
    int angle = dir * 45;
    double rad = angle * PI / 180.0;

    double dx = cos(rad);
    double dy = sin(rad);

    for (int i = 0; i < len; i++){
        position.x += dx;
        position.y += dy;

        double x = position.x;
        double y = position.y;
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT){
            int draw_x = (int)x;
            int draw_y = (int)y;
            image[draw_y][draw_x].r = 255;
            image[draw_y][draw_x].g = 255;
            image[draw_y][draw_x].b = 255;
        }
    }
}

void draw_set(int x, int y){
    position.x = x;
    position.y = y;
}

void draw_clear() {
    for (int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){
            image[y][x].r = 0;
            image[y][x].g = 0;
            image[y][x].b = 0;
        }
    }
}

void write_ppm(const char *filename){
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){
            Pixel p = image[y][x];
            fprintf(fp, "%c%c%c", p.r, p.g, p.b);
        }
    }
    fclose(fp);
}

void A(int k);
void B(int k);
void C(int k);
void D(int k);
int h;

void A(int k){
    if (k>0){
        A(k-1);
        draw_line(7, h);
        B(k-1);
        draw_line(0, 2*h);
        D(k-1);
        draw_line(1, h);
        A(k-1);
    }
}

void B(int k){
    if (k>0){
        B(k-1);
        draw_line(5, h);
        C(k-1);
        draw_line(6, 2*h);
        A(k-1);
        draw_line(7, h);
        B(k-1);
    }
}

void C(int k){
    if (k>0){
        C(k-1);
        draw_line(3, h);
        D(k-1);
        draw_line(4, 2*h);
        B(k-1);
        draw_line(5, h);
        C(k-1);
    }
}

void D(int k){
    if (k>0){
        D(k-1);
        draw_line(1, h);
        A(k-1);
        draw_line(2, 2*h);
        C(k-1);
        draw_line(3, h);
        D(k-1);
    }
}

void sierpsinski(int n){
    int i = 3;
    int square_size = WIDTH;
    h = square_size / 8;
    int x0 = WIDTH / 2 - 270;
    int y0 = HEIGHT / 2 + 150;

    draw_clear();

    do {
        ++i;
        x0 = x0 + h;
        y0 = y0 + h;
        h = h / 8;
 
        draw_set(x0, y0);

        A(i); draw_line(7, h);
        B(i); draw_line(5, h);
        C(i); draw_line(3, h);
        D(i); draw_line(1, h);
    } while (i != n);
}

int main(){
    sierpsinski(4);

    write_ppm("sierpsinski.ppm");
}
