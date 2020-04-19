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

void barrelSort(int* arr,int size)//Ͱ����
{
    const int maxsize = 10000;
    int* bar = (int*)calloc(maxsize,4);//������СΪ10000��Ͱ����calloc���������ݽ��г�ʼ��
    //�����ܿ��ٶ��ڴ�,��Ϊջ�ڴ�̫С
    if (bar == NULL)//�˴����пտ��п���,�������ʧ��,�±ߵ��߼��Ѿ�����
    {
        printf("����ʧ��!1\n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        bar[arr[i]]++;
    }
    //ͳ������arr�и������ֳ��ֵĴ���
    for (int i = 0; i < maxsize; i++)//��ͷ����Ͱ,���ʱ����ʵͰ��Ԫ�ر�ž�������arr�е�ֵ,������Ͱ�ı���ǰ��յ�����˳�������е�,������δ�ӡ���ı�žͿ��Եõ�arr�ĵ�������
    {
        for (int j = 0; j < bar[i]; j++)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    free(bar);
}
//ʱ�临�Ӷ�ΪO(m+n)mΪͰ�Ĵ�С,nΪ�����г��ֶԶ�ε�Ԫ�صĳ��ִ���
//����㷨��һ���ľ�����,��Ϊ����û������������Ԫ�ؽ�������,���ҵ�������Ԫ�ص����ֵ�ܴ�ʱ,���ڴ�����ļ���
//############################################################################################


void BbbleSort(int* arr,int size)//ð������
{
    for (int i = 0; i < size - 1; i++)//��size-1��Ԫ��ȫ���ó���
    {
        for (int j = 0; j < size - 1 - i; j++)//ÿ�α�������ȷ��size-1-i����ֵ
        {
            if (arr[j] > arr[j + 1])
            {
                Swap(arr, j, j + 1);
            }
            //���ǰ�ߵıȺ���Ĵ�Ͱ����ǽ��н���,��Ȼ���Ƕ���С����˵
        }
    }
}
//����������ʱ�临�Ӷ���O(n^2)ʵ��Ӧ�ò����Ƿǳ�����




//##########################################################################################

void InsertSort(int* arr, int size)//��������
{
    int tmp = 0;
    int j = 0;
    for (int i = 1; i < size; i++)//�������еĵڶ���Ԫ�ؿ�ʼ,�ֱ��ó������е�ֵ
    {
        tmp = arr[i];//�Ȱ��õ������ݽ��б���
        for (j = i; j > 0 && arr[j-1] > tmp;j--)//�ҵ�������ݵ�λ��
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;//���ҵ������ݲ��뵽���Լ���λ��
    }
}
//���׵õ����������ʱ�临�Ӷ���Ȼ��O(n)



void choiceSort(int* arr, int size)//ѡ������
{
    int i = 0;
    int j = 0;
    int small = 0;
    for (int i = 0; i < size - 1; i++)//�ó�size-1ǰ��Ԫ��,Ϊʲô������size-1����Ԫ����,size-1������һ������ȷʵû�б�Ҫ���Լ�����ȥ
    {
        int small = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[small])
            {
                small = j;
            }
            //��ÿһ�ֵ����ֵ�������Ԫ�ص�λ��
            Swap(arr, small, i);
        }
    }
}
//�׵���ʱ�临�Ӷ���Ȼ��O(n^2)
//###############################################################################



//���Ƚ���
void shiftDown(int* arr, int parent, int size)
{
    int child = parent * 2 + 1;
    while (child < size)
    {
        if (child + 1 < size && arr[child] < arr[child + 1])
        {
            child++;
        }
        //�ҵ����������нϴ����һ��
        if (arr[child] > arr[parent])//������ӱȸ��׻���,�Ǿ��ú���������,����������,�����¸��׵�λ��
        {
            Swap(arr, child, parent);
            parent = child;
            child = parent * 2 + 1;
        }
        else
            break;//�������С�ڸ����Ǿ�˵�����׵�λ����ȷ,����ѭ��
    }
}
void creatHeap(int* arr, int size)
{
    for (int i = (size - 2) / 2; i >= 0; i--)//�ӵ�һ����Ҷ�ӽڵ���������
    {
        shiftDown(arr, i, size);
    }
}
void heapSort(int* arr,int size) //������
{
    creatHeap(arr, size);
    while (size > 0)
    {
        Swap(arr, 0, size - 1);//���Ƚ���ͷ�����һ��Ԫ�ص�ֵ
        size--;//ɾͷ�൱�ڰ�����ֵ����������
        shiftDown(arr, 0, size);//�����ѽ���ѭ��
    }
}
//�׵ö������ʱ�临�Ӷ���O(nlog(n))





void quickSort(int* arr, int left, int right)//��������
{
    int i, j, temp;
    if (left > right)
        return;
    temp = arr[left];
    i = left;
    j = right;
    while (i != j)
    {
        while (i<j && arr[j]>=temp)//һ��ע��˳��,���ڻ�׼�Ǵ���,���Ӧ���ұ߿�ʼ(Ϊʲô��,���������鱾���Ѿ��ź�����^_^)
        j--;
        while (i < j && arr[i] <= temp)
        i++;
        if (i < j)
        {
            Swap(arr, i, j);
        }
    }
    Swap(arr, left, i);
    quickSort(arr, left, i - 1);//��������߽��д���
    quickSort(arr, i + 1, right);//�������ұ߽��д���
}

//ʱ�临�Ӷ�O(nlogn)
