#include <stdio.h>
#include <search.h>
#define ARRAY_SIZE 13

void print_array(int array[], int num)
{
  int i;
  for (i = 0; i < num; i++)
    printf("%d ", array[i]);
  printf("\n");
}

int compare_int(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

int main()
{
  int key;
  int array[ARRAY_SIZE] = {
      50, 80, 150, 210, 250, 280, 330,
      470, 510, 530, 800, 900, 990};

  key = 800;
  print_array(array, ARRAY_SIZE);
  size_t nmemb = ARRAY_SIZE + 1; // 見つからなかったときのデータ格納のため
  int *result;
  result = lsearch(&key, array, &nmemb, sizeof(int), compare_int);
  if (result != NULL)
  {
    int index = result - array; // 見つかったアドレスから配列の先頭アドレスを引く
    printf("Found %d (Index:%d)\n", key, index);
  }
  else
    printf("Not found: %d\n", key);

  return 0;
}
