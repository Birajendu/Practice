#include <stdio.h>

int binarySearchRecursive(int arr[], int start, int end, int valueToSearch)
{
  if (valueToSearch > arr[end] || valueToSearch < arr[start]) {
    return -1;
  }
  int mid = (start + end)/2;
  if ( valueToSearch == arr[mid] ) {
    return mid;
  }

  if ( valueToSearch > arr[mid]) {
    return binarySearchRecursive(arr, mid+1, end, valueToSearch);
  } else if ( valueToSearch < arr[mid]) {
    return binarySearchRecursive(arr, start, mid-1, valueToSearch);
  }
  return -1;
}
int binarySearch(int arr[], int size, int valueToSearch)
{
  int start = 0;
  int end = size -1;
  while (start < end) {

    int mid =(start + end)/2;
    if (arr[mid] == valueToSearch) {
      return mid;
    }

    if (arr[mid] > valueToSearch) {
      end = mid - 1;
    }

    if  (arr[mid] < valueToSearch) {
      start = mid + 1;
    }
  }
  return -1;
}

int main(void)    
{
  int arr[] = {5,6,7,8,9,10,11,12,13};
//  int result = binarySearch(arr, sizeof(arr)/ sizeof(arr[0]), 20);
  int start = 0;
  int end = (sizeof(arr)/ sizeof(arr[0])) -1;
  int result = binarySearchRecursive(arr, start, end , 10);
  if ( -1 == result) {
    printf("Not found \n");
  } else {
    printf("Found in :%d\n", result);
  }
  return 0;
}
