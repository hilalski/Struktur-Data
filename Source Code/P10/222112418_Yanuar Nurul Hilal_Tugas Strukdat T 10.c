// heaps in c
#include <stdio.h>
#include <stdlib.h>

#define CLEAR system("cls")
#define MAX 100

// return parent index
int parent(int i)
{
   return (i) / 2;
}

// return left child index
int left(int i)
{
   return (2 * i);
}

// return right child index
int right(int i)
{
   return (2 * i + 1);
}

// swap elements
void swap(int *p, int *q)
{
   int temp = *p;
   *p = *q;
   *q = temp;
}

/**
 * function to heapify the tree
 *
 * @param a heap array
 * @param heapsize size of heap
 * @param data data to be inserted
 */
void insert(int a[], int heapsize, int data)
{
   int i;
   if (heapsize == MAX)
   {
      printf("Heap telah penuh");
      return;
   }

   heapsize++;
   i = heapsize - 1;
   a[i] = data;

   while (i != 0 && a[parent(i)] < a[i])
   {
      swap(&a[i], &a[parent(i)]);
      i = parent(i);
   }
}

/**
 * function to delete element from heap
 *
 * @param a heap array
 * @param heapsize size of heap
 * @return int return deleted element
*/
int delete (int a[], int heapsize)
{
   int max = a[0];
   a[0] = a[heapsize - 1];
   heapsize--;
   int i = 0;

   while (i < heapsize)
   {
      if (a[i] < a[left(i)] && a[left(i)] > a[right(i)])
      {
         swap(&a[i], &a[left(i)]);
         i = left(i);
      }
      else if (a[i] < a[right(i)] && a[right(i)] > a[left(i)])
      {
         swap(&a[i], &a[right(i)]);
         i = right(i);
      }
      else
      {
         break;
      }
   }

   return max;
}

/**
 * function to display heap
 *
 * @param a heap array
 * @param heapsize size of heap
 */
void display(int a[], int heapsize)
{
   int i;

   if (heapsize == 0)
   {
      printf("Heap kosong");
      return;
   }

   for (i = 0; i < heapsize; i++)
   {
      printf("%d ", a[i]);
   }

   printf("\n");
}

int main()
{
   int heapsize = 0;
   int temp[MAX];
   int choice, data;

   while (choice != 4)
   {
      CLEAR;
       printf("\n       [HEAP OPERATIONS]");
      printf("\n =====================================");
      printf("\n 1. Insert item pada Heap");
      printf("\n 2. Delete item dari Heap");
      printf("\n 3. Display semua elemen pada Heap");
      printf("\n 4. Keluar");
      printf("\n =====================================");
      printf("\n Masukkan pilihan : ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         printf(" Input data : ");
         scanf("%d", &data);
         insert(temp, heapsize, data);
         heapsize++;
         break;
      case 2:
         if (heapsize == 0)
         {
            printf(" Heap kosong!");
            break;
         }

         printf(" Data yang dihapus : %d", delete (temp, heapsize));
         heapsize--;
         break;
      case 3:
         if (heapsize == 0)
         {
            printf(" Heap kosong!");
            break;
         }

         printf(" Heap : ");
         display(temp, heapsize);
         break;
      case 4:
         exit(0);
         break;
      default:
         printf(" Pilihan tidak valid!");
      }

      printf("\nTekan untuk melanjutkan...");
      getch();
   }
   return 0;
}