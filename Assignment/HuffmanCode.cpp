#include <stdio.h>
#include <stdlib.h>
//2015004584_배지운_A

int aFreq = 0;
struct MinHeapNode 
{
   char data;
   unsigned freq;
   struct MinHeapNode *Left, *Right;
};

struct MinHeap 
{
   unsigned size;
   unsigned capacity;
   struct MinHeapNode **array;
};

struct MinHeapNode * newNode(char  data, unsigned freq) 
{
   struct MinHeapNode * temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
   temp->Left = temp->Right = NULL;
   temp->data = data;
   temp->freq = freq;
   return temp;
}

struct MinHeap * createMinHeap(unsigned capacity) 
{
   struct MinHeap * minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
   minHeap->size = 0;
   minHeap->capacity = capacity;
   minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode *));
   return minHeap;
}

void swapNode(struct MinHeapNode** a, struct MinHeapNode ** b) 
{
   struct MinHeapNode *t = *a;
   *a = *b;
   *b = t;
}

void minHeapify(struct MinHeap * minHeap, int inx) 
{
   int small = inx;
   int left = 2 * inx + 1;
   int right = 2 * inx + 2;
   if (left < minHeap->size&&minHeap->array[left]->freq < minHeap->array[small]->freq)
      small = left;
   if (right < minHeap->size&&minHeap->array[right]->freq < minHeap->array[small]->freq)
      small = right;
   if (small != inx) 
   {
      swapNode(&minHeap->array[small], &minHeap->array[inx]);
      minHeapify(minHeap, small);
   }
}

int is_sizeOne(struct MinHeap * minHeap) 
{
   return (minHeap->size == 1);
}

struct MinHeapNode * extractMin(struct MinHeap * minHeap) 
{
   struct MinHeapNode * temp = minHeap->array[0];
   minHeap->array[0] = minHeap->array[minHeap->size - 1];
   --minHeap->size;
   minHeapify(minHeap, 0);
   return temp;
}

void insertHeap(struct MinHeap * minHeap, struct MinHeapNode * minHeapNode) 
{
   ++minHeap->size;
   int idx = minHeap->size - 1;
   while (idx&&minHeapNode->freq < minHeap->array[(idx - 1) / 2]->freq) 
   {
      minHeap->array[idx] = minHeap->array[(idx - 1) / 2];
      idx = (idx - 1) / 2;
   }
   minHeap->array[idx] = minHeapNode;
}

void buildHeap(struct MinHeap * minHeap) 
{
   int num = minHeap->size - 1;
   int idx;
   for (idx = (num - 1) / 2; idx >= 0; --idx)
      minHeapify(minHeap, idx);
}

int isLeaf(struct MinHeapNode * root) 
{
   return !(root->Left) && !(root->Right);
}

struct MinHeap * CreateAndBuild_MinHeap(char  data[], int freq[], int size) 
{
   struct MinHeap * minHeap = createMinHeap(size);
   for (int i = 0; i < size; ++i) 
   {
      minHeap->array[i] = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
      minHeap->array[i] = newNode(data[i], freq[i]);
   }
   minHeap->size = size;
   buildHeap(minHeap);
   return minHeap;
}

struct MinHeapNode * buildHuffmanTree(char  data[], int freq[], int size) 
{
   struct MinHeapNode * left, *right, *top;

   struct MinHeap* minHeap = CreateAndBuild_MinHeap(data, freq, size);
   while (!is_sizeOne(minHeap)) 
   {
      left = extractMin(minHeap);
      right = extractMin(minHeap);
      top = newNode('$', left->freq + right->freq);
      top->Left = left;
      top->Right = right;
      insertHeap(minHeap, top);
   }
   return extractMin(minHeap);
}
void printArr(int freq, int top) 
{
   aFreq = aFreq + freq*top;
}
void printCodes(struct MinHeapNode * root, int arr[], int top) {
   if (root->Left) 
   {
      arr[top] = 0;
      printCodes(root->Left, arr, top + 1);
   }
   if (root->Right) 
   {
      arr[top] = 1;
      printCodes(root->Right, arr, top + 1);
   }
   if (isLeaf(root)) 
   {
      printArr(root->freq, top);
   }
}
void HuffmanCodes(char  data[], int freq[], int size) 
{
   struct MinHeapNode * root = buildHuffmanTree(data, freq, size);
   int arr[100];
   int top = 0;
   printCodes(root, arr, top);
   printf("%d", aFreq);
}
int bitelength(int num) 
{
   int length = num;
   int i = 1;
   while (length > 1) 
   {
      length /= 2;
      i++;
   }
   return i;
}
int main(int argc, char * argv[]) 
{
   int input, length;
   scanf("%d", &input);
   char *arr = (char *)malloc(sizeof(char)*input);
   int *freq = (int *)malloc(sizeof(int)*input);
   for (int i = 0; i < input; ++i) 
   {
      scanf("%s", &arr[i]);
      scanf("%d", &freq[i]);
   }
   scanf("%d", &length);
   printf("%d\n", length*bitelength(input));
   HuffmanCodes(arr, freq, input);
   return 0;
}