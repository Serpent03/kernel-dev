#include <stdio.h>
#include <stdlib.h>

int** init_2darray(int w, int h) {
  int** m = (int**)calloc(w, sizeof(int*));
  for (int i = 0; i < w; i++) {
    m[i] = (int*)calloc(h, sizeof(int));
    for (int j = 0; j < h; j++) {
      m[i][j] = (i * 3) + j;
    }
  }
  return m;
}

void print_2darray(int** mat, int w, int h) {
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
}


int main() {
  int** mat = init_2darray(3, 4);
  print_2darray(mat, 3, 4);
}


