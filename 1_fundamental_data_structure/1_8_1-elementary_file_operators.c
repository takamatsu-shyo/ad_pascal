#include <stdlib.h>
#include <stdio.h>

#define MaxLength 4096

typedef struct {
    int len;
    char a[MaxLength];
} File;

typedef struct {
    File* f;
    int pos;
    int eof;
} Rider;

File* New(char* name){
    File* f = malloc(sizeof(File));
    f->len = 0;
    return f;
}

File* Old(char* name){
    File *f = malloc(sizeof(File));
    return f;
}

void Close(File *f){
    free(f);
}

void Set(Rider* r, File* f, int pos){
    r->f = f;
    r->eof = 0;
    if (pos >= 0){
        if (pos <= f->len){
            r->pos = pos;
        } else {
            r->pos = f->len;
        }
    } else {
        r->pos = 0;
    }
}

void Write(Rider* r, char ch){
    //printf("r->pos %d ", r->pos);
    //printf("r->f->len %d ", r->f->len);

    if ((r->pos <= r->f->len) && (r->pos < MaxLength)){
        //printf("%c ", ch);
        r->f->a[r->pos] = ch;
        if (r->pos == r->f->len){
            r->f->len++;
            //printf("new r->f->len %d ", r->f->len);
        }
        r->pos++;
    } else {
        r->eof = 1;
        printf("EOF ");
    }

    //printf("\n");
}

char Read(Rider* r){
    if (r->pos < r->f->len){
        char ch = r->f->a[r->pos];
        r->pos++;
        return ch;
    } else {
        r->eof = 1;
        return '\0';
    }
}

int main(){
    File* file = New("testFile");
    Rider rider;
    Set(&rider, file, 0);

    char ch = 'a';
    for (int i = 0; i < 50; i++){
        Write(&rider, ch + i);
    }

    Set(&rider, file, 0);

    for (int i = 0; i < 50; i++){
        printf("%c ", Read(&rider));
    }
    printf("\n");

    Close(file);

    return 0;
}
