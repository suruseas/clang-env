#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define HEIGHT 20
#define WIDTH 40
#define MAX_GENERATION 100
#define THRESHOLD 7
#define WAIT_MS 100

void init(int array[HEIGHT][WIDTH])
{
  srand((unsigned)time(NULL));

  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      int num = (int)((double)rand());
      array[i][j] = (num % 10) > THRESHOLD ? 1 : 0;
    }
  }
}

void print(int array[HEIGHT][WIDTH])
{
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
      printf("%c ", array[i][j] == 1 ? '*' : '.');
    printf("\n");
  }
  printf("\n");
}

void battle(int base[HEIGHT][WIDTH], int result[HEIGHT][WIDTH])
{
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      int suvivors = 0;
      // 左上
      if (i - 1 >= 0 && j - 1 >= 0 && base[i - 1][j - 1] == 1)
        suvivors++;
      // 上
      if (i - 1 >= 0 && base[i - 1][j] == 1)
        suvivors++;
      // 右上
      if (i - 1 >= 0 && j + 1 < WIDTH && base[i - 1][j + 1] == 1)
        suvivors++;
      // 左
      if (j - 1 >= 0 && base[i][j - 1] == 1)
        suvivors++;
      // 右
      if (j + 1 < WIDTH && base[i][j + 1] == 1)
        suvivors++;
      // 左下
      if (i + 1 < HEIGHT && j - 1 >= 0 && base[i + 1][j - 1] == 1)
        suvivors++;
      // 下
      if (i + 1 < HEIGHT && base[i + 1][j] == 1)
        suvivors++;
      // 右下
      if (i + 1 < HEIGHT && j + 1 < WIDTH && base[i + 1][j + 1] == 1)
        suvivors++;

      // 生死判定
      bool is_alive = false;
      if (base[i][j] == 1)
      {
        if (suvivors == 2 || suvivors == 3)
          is_alive = true;
      }
      else
      {
        if (suvivors == 3)
          is_alive = true;
      }

      result[i][j] = is_alive ? 1 : 0;
    }
  }
}

void copy(int base[HEIGHT][WIDTH], int result[HEIGHT][WIDTH])
{
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
      result[i][j] = base[i][j];
  }
}

int main()
{

  int array[HEIGHT][WIDTH];
  init(array);

  for (int generation = 0; generation < MAX_GENERATION; generation++)
  {
    printf("Generation: %d\n", generation);
    if (generation > 0)
    {
      int new_array[HEIGHT][WIDTH];
      battle(array, new_array);
      copy(new_array, array);
    }

    print(array);
    usleep(WAIT_MS * 1000);

    if (generation != MAX_GENERATION - 1)
      // 移動する
      printf("\033[%dA", HEIGHT + 2);
  }

  return 0;
}
