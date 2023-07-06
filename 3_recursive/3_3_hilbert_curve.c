#include <stdio.h>

#define IMG_SIZE 512

int image[IMG_SIZE][IMG_SIZE];
int x0, y0;
int color = 255;
int recursive = 4;

void draw_line(int direction, int length){
    for (int i = 0; i < length; i++){
        switch (direction){
            case 0: y0++; break; // down 
            case 2: x0++; break; // right
            case 4: y0--; break; // up 
            case 6: x0--; break; // left
        }
        if (x0 >= 0 && x0 < IMG_SIZE && y0 >= 0 && y0 < IMG_SIZE){
            image[y0][x0] = color; 
        }
    }
}

void A(int i, int u);
void B(int i, int u);
void C(int i, int u);
void D(int i, int u);

void A(int i, int u){
    if (i>0){
        D(i-1, u);
        draw_line(6, u);
        A(i-1, u);
        draw_line(0, u);
        A(i-1, u);
        draw_line(2, u);
        B(i-1, u);
    }
}

void B(int i, int u){
    if (i>0){
        C(i-1, u);
        draw_line(4, u);
        B(i-1, u);
        draw_line(2, u);
        B(i-1, u);
        draw_line(0, u);
        A(i-1, u);
    }
}

void C(int i, int u){
    if (i>0){
        B(i-1, u);
        draw_line(2, u);
        C(i-1, u);
        draw_line(4, u);
        C(i-1, u);
        draw_line(6, u);
        D(i-1, u);
    }
}

void D(int i, int u){
    if (i>0){
        A(i-1, u);
        draw_line(0, u);
        D(i-1, u);
        draw_line(6, u);
        D(i-1, u);
        draw_line(4, u);
        C(i-1, u);
    }
}

void hilbert(int n){
    int u = IMG_SIZE / (recursive + 1);
    int i = 0;
    x0 = u/2;
    y0 = u/2;
    do {
        i++;
        u = u / 2;
        x0 = x0 + (u / 2);
        y0 = y0 + (u / 2);
        A(i, u);
        color -= (color / recursive);
    } while (i != n);
}

void write_ppm(const char* filename){
    FILE* fp = fopen(filename, "wb");
    fprintf(fp, "P5\n%d %d\n255\n", IMG_SIZE, IMG_SIZE);
    for (int y = 0; y < IMG_SIZE; y++){
        for (int x = 0; x < IMG_SIZE; x++){
            fputc(image[y][x], fp);
        }
    }
    fclose(fp);
}

int main(){
    hilbert(recursive);
    write_ppm("hilbert.ppm");
    return 0;
}

