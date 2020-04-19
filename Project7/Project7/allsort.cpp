#include"allsort.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void Swap(int* arr, int left, int right)
{
    int tmp = arr[left];
    arr[left] = arr[right];
    arr[right]=tmp;
}

void barrelSort(int* arr,int size)//桶排序
{
    const int maxsize = 10000;
    int* bar = (int*)calloc(maxsize,4);//创建大小为10000的桶并用calloc对其上数据进行初始化
    //尽可能开辟堆内存,因为栈内存太小
    if (bar == NULL)//此处的判空可有可无,如果分配失败,下边的逻辑已经崩溃
    {
        printf("创建失败!1\n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        bar[arr[i]]++;
    }
    //统计数组arr中各个数字出现的次数
    for (int i = 0; i < maxsize; i++)//从头遍历桶,这个时候其实桶的元素编号就是数组arr中的值,又由于桶的编号是按照递增的顺序来进行的,因此依次打印它的编号就可以得到arr的递增序列
    {
        for (int j = 0; j < bar[i]; j++)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    free(bar);
}
//时间复杂度为O(m+n)m为桶的大小,n为数组中出现对多次的元素的出现次数
//这个算法有一定的局限性,因为它并没有真正对数组元素进行排序,并且当数组中元素的最大值很大时,对内存的消耗极高
//############################################################################################


void BbbleSort(int* arr,int size)//冒泡排序
{
    for (int i = 0; i < size - 1; i++)//把size-1个元素全部拿出来
    {
        for (int j = 0; j < size - 1 - i; j++)//每次遍历都会确定size-1-i处的值
        {
            if (arr[j] > arr[j + 1])
            {
                Swap(arr, j, j + 1);
            }
            //如果前边的比后面的大就把他们进行交换,当然这是对于小序来说
        }
    }
}
//很明显它的时间复杂度是O(n^2)实际应用并不是非常理想




//##########################################################################################

void InsertSort(int* arr, int size)//插入排序
{
    int tmp = 0;
    int j = 0;
    for (int i = 1; i < size; i++)//从数组中的第二个元素开始,分别拿出数组中的值
    {
        tmp = arr[i];//先把拿到的数据进行保存
        for (j = i; j > 0 && arr[j-1] > tmp;j--)//找到这个数据的位置
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;//将找到的数据插入到它自己的位置
    }
}
//容易得到插入排序的时间复杂度仍然是O(n)



void choiceSort(int* arr, int size)//选择排序
{
    int i = 0;
    int j = 0;
    int small = 0;
    for (int i = 0; i < size - 1; i++)//拿出size-1前的元素,为什么不用排size-1处的元素呢,size-1处就它一个所以确实没有必要跟自己过不去
    {
        int small = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[small])
            {
                small = j;
            }
            //找每一轮的最大值放在这个元素的位置
            Swap(arr, small, i);
        }
    }
}
//易得其时间复杂度仍然是O(n^2)
//###############################################################################



//首先建队
void shiftDown(int* arr, int parent, int size)
{
    int child = parent * 2 + 1;
    while (child < size)
    {
        if (child + 1 < size && arr[child] < arr[child + 1])
        {
            child++;
        }
        //找到两个孩子中较大的那一个
        if (arr[child] > arr[parent])//如果孩子比父亲还大,那就让孩子做父亲,父亲做孩子,并更新父亲的位置
        {
            Swap(arr, child, parent);
            parent = child;
            child = parent * 2 + 1;
        }
        else
            break;//如果孩子小于父亲那就说明父亲的位置正确,结束循环
    }
}
void creatHeap(int* arr, int size)
{
    for (int i = (size - 2) / 2; i >= 0; i--)//从第一个非叶子节点依次向下
    {
        shiftDown(arr, i, size);
    }
}
void heapSort(int* arr,int size) //堆排序
{
    creatHeap(arr, size);
    while (size > 0)
    {
        Swap(arr, 0, size - 1);//首先交换头和最后一个元素的值
        size--;//删头相当于把最大的值放在了最后边
        shiftDown(arr, 0, size);//复建堆进行循坏
    }
}
//易得堆排序的时间复杂度是O(nlog(n))





void quickSort(int* arr, int left, int right)//快速排序
{
    int i, j, temp;
    if (left > right)
        return;
    temp = arr[left];
    i = left;
    j = right;
    while (i != j)
    {
        while (i<j && arr[j]>=temp)//一定注意顺序,由于基准是从左,因此应从右边开始(为什么呢,如果这个数组本来已经排好了呢^_^)
        j--;
        while (i < j && arr[i] <= temp)
        i++;
        if (i < j)
        {
            Swap(arr, i, j);
        }
    }
    Swap(arr, left, i);
    quickSort(arr, left, i - 1);//继续对左边进行处理
    quickSort(arr, i + 1, right);//继续对右边进行处理
}

//时间复杂度O(nlogn)
