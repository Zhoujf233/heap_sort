//
//  main.cpp
//  heap_sort
//
//  Created by JF Zhou on 2019/8/26.
//  Copyright © 2019 JF Zhou. All rights reserved.
//

#include <iostream>
using namespace std;

void adjust_heap(int* arr, int node, int size)
{
    int left = 2*node + 1;
    int right = 2*node + 2;
    int max = node;
    if( left < size && arr[left] > arr[max])
        max = left;
    if( right < size && arr[right] > arr[max])
        max = right;
    if(max != node)
    {
        swap( arr[max], arr[node]);
        adjust_heap(arr, max, size);
    }
}

void heap_sort(int* arr, int size)
{
    for(int i = size/2 -1; i >= 0; --i)
        adjust_heap(arr, i, size);
    
    for(int i = size - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);           // 将当前最大的放置到数组末尾
        adjust_heap(arr, 0 , i);              // 将未完成排序的部分继续进行堆排序
    }
}

int main(int argc, const char * argv[])
{
    int arr[] = {89,22,-3,32,82,55,22,50,37,5,64,35,9,70};
    int size = (int) sizeof(arr)/sizeof(*arr);
    int i;
    cout<<"初始顺序为: ";
    for(i = 0;i < size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    heap_sort(arr, size);
    
    cout << "堆排序后顺序为：";
    for(i = 0;i < size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
