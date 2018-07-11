#include <stdio.h>
#include <math.h>
using namespace std;

int min(int x, int y)
{
  return (x < y) ? x : y;
}
int jumpSearch(int *arr, int valueToSearch, int  arrSize)
{
  if (valueToSearch < arr[0] || valueToSearch > arr[arrSize - 1]) {
    printf("value not present in the array");
    return -1;
  }

  int range = sqrt(arrSize);
  int step = range;
  while (arr[min(step, arrSize-1)] <= valueToSearch)
  {
    if (step > arrSize) {
      return -1;
    }
    step += step;
  }


  int index = step - 2*range;

  while (index <= (step - range)) {
    if (arr[index] == valueToSearch) {
      return index;
    }
    index++;
  }
  return -1;
}
int main()
{
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,
                 34, 55, 89, 144, 233, 377, 610 };
    int valueToSearch = 55;
    int arrSize  = sizeof(arr) / sizeof(arr[0]);

    // Find the index of valueToSearch  using Jump Search
    int index = jumpSearch(arr, valueToSearch, arrSize);
 
    // Print the index where valueToSearch  is located
    printf("\nNumber %d  is at index %d", valueToSearch, index);
    return 0;
}
