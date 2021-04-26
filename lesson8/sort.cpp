// ыщке.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

void bubble(int* num, int n)
{
  for (int i = n - 1; i > 0; i--)
    {
    for (int j = 0; j < i; j++)
      if (num[j] > num[j + 1])
      {
        int temp = num[j];
        num[j] = num[j + 1];
        num[j + 1] = temp;
      }
    }
}

void shaker(int* num, int n)
{
      bool swap = true;
      int i = 0;
      int j = n - 1;
      while(i < j && swap) 
      {
         swap = false;
         for(int k = i; k < j; k++) 
         {
            if(num[k] > num[k + 1]) 
            {
               int temp = num[k];
               num[k] = num[k + 1];
               num[k + 1] = temp;
               swap = true;
            }
         }
         j--;
         if(swap) 
         {
            swap = false;
            for(int k = j; k > i; k--) 
            {
               if(num[k] < num[k - 1]) 
               {
                  int temp = num[k];
                  num[k] = num[k - 1];
                  num[k - 1] = temp;
                  swap = true;
               }
            }
         }
         i++;
      }   
}

void insert(int* num, int n) 
{
    for (int i = 1, j; i < n; i++)
    {
        int temp = num[i]; 
        for (j = i - 1; j >= 0 && num[j] > temp; j--)
            num[j + 1] = num[j]; 
        num[j + 1] = temp;   
    }
}

void selection(int* num, int n) 
{
    for(int i = 0; i < n; ++i) 
    { 
        int pos = i; 
        int temp = num[i];
        for(int j = i + 1; j < n; j++)
        {
            if (num[j] < temp) 
           {
               pos = j; 
               temp = num[j]; 
           }
        }
        num[pos] = num[i]; 
        num[i] = temp;
    }
}
void merge(int* num, int left, int center, int right) {
	int* temp = new int[right + 1];
	int i,j;
	for (i = center+1; i > left; i--) 
		temp[i-1] = num[i-1];
	for (j = center; j < right; j++) 
		temp[right+center-j] = num[j+1];
	for (int k = left; k <= right; k++)
		if (temp[j] < temp[i]) 
			num[k] = temp[j--];
		else
			num[k] = temp[i++];
        delete [] temp;
}

void mergesort(int* num, int left, int right) {
	if (left<right) {
		int center = (left+right)/2;
		mergesort(num, left, center);
		mergesort(num, center+1, right);
		merge(num, left, center, right);
	}
}


void quick_sort(int* num, int start, int end) {
    if (start >= end)
        return;
    int mid = num[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (num[left] < mid && left < right)
            left++;
        while (num[right] >= mid && left < right)
            right--;
		int temp = num[left];
        num[left] = num[right];
		num[right] = temp;
    }
    if (num[left] >= num[end]){
		int temp = num[left];
        num[left] = num[end];
		num[end] = temp;}
    else
        left++;
    quick_sort(num, start, left - 1);
    quick_sort(num, left + 1, end);
}

void qsort(int* num, int len) {
    quick_sort(num, 0, len);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	int *A = new int[100];
	std::cout << "len > ";
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cout << i << " > ";
		std::cin >> A[i];
	}
	//bubble(A, n);
	//shaker(A, n);
	//insert(A, n);
	//selection(A, n);
	//mergesort(A,0, n);
	qsort(A, n);
	for (int i = 1; i <= n; i++) {
		std::cout << A[i] << " ";
	}
	return 0;
}

