#include <stdio.h>
#define ARRAY_SIZE 13

int binary_search(int array[], int num, int key)
{
  int middle, low, high;
  low = 0;
  high = num - 1;

  while (low <= high)
  {
    middle = (low + high) / 2;
    if (array[middle] == key)
      return middle;
    else if (array[middle] < key)
      low = middle + 1;
    else
      high = middle - 1;
  }

  return -1;
}

void print_array(int array[], int num)
{
  int i;
  for (i = 0; i < num; i++)
    printf("%d ", array[i]);
  printf("\n");
}

int main()
{
  int index, key;
  int array[ARRAY_SIZE] = {
      50, 80, 150, 210, 250, 280, 330,
      470, 510, 530, 800, 900, 990};

  key = 800;
  print_array(array, ARRAY_SIZE);
  index = binary_search(array, ARRAY_SIZE, key);
  if (index != -1)
    printf("Found %d (Index:%d)\n", key, index);
  else
    printf("Not found: %d\n", key);

  return 0;
}
