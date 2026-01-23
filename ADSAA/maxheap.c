#include <stdio.h>
#define MAX 50

void swap(int *, int *);
void maxHeapifyUp(int);
void maxHeapifyDown(int);
void insertMaxHeap(int);
void deleteMaxHeap();
void displayMaxHeap();

int maxHeap[MAX];
int maxSize = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertMaxHeap(int value)
{
    if (maxSize == MAX)
    {
        printf("Heap is full!\n");
        return;
    }
    maxHeap[maxSize] = value;
    maxHeapifyUp(maxSize);
    maxSize++;
}

void maxHeapifyUp(int i)
{
    while (i > 0 && maxHeap[(i - 1) / 2] < maxHeap[i])
    {
        swap(&maxHeap[i], &maxHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteMaxHeap()
{
    if (maxSize == 0)
    {
        printf("Max heap is empty\n");
        return;
    }

    printf("Deleted element: %d\n", maxHeap[0]);
    maxHeap[0] = maxHeap[--maxSize];
    maxHeapifyDown(0);
}

void maxHeapifyDown(int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < maxSize && maxHeap[left] > maxHeap[largest])
        largest = left;

    if (right < maxSize && maxHeap[right] > maxHeap[largest])
        largest = right;

    if (largest != i)
    {
        swap(&maxHeap[i], &maxHeap[largest]);
        maxHeapifyDown(largest);
    }
}

void displayMaxHeap()
{
    if (maxSize == 0)
    {
        printf("Heap is empty!\n");
        return;
    }
	int i;
    printf("Max Heap: ");
    for (i = 0; i < maxSize; i++)
    {
        printf("%d ", maxHeap[i]);
    }
    printf("\n");
}

int main()
{
    int choice, value;

    do
    {
        printf("\n--- Heap Operations ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertMaxHeap(value);
            break;

        case 2:
            deleteMaxHeap();
            break;

        case 3:
            displayMaxHeap();
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice!!!\n");
        }

    } while (choice != 4);

    return 0;
}

