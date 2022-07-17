//Heap Sort
#include <iostream.h>
#include <conio.h>
int a[50],n,hs;
void swap(int &x,int &y)
{
    int temp=x;
    x=y;
    y=temp;
}
void heapify(int x)
{
    int left=(2*x);
    int right=(2*x)+1;
    int large;
    if((left<=hs)&&(a[left]>a[x]))
    {
        large=left;
    }
    else
    {
        large=x;
    }
    if((right<=hs)&&(a[right]>a[large]))
    {
        large=right;
    }
    if(x!=large)
    {
        swap(a[x],a[large]);
        heapify(large);
    }
}
void BuildMaxHeap()
{
    for(int i=n/2;i>0;i--)
    {
        heapify(i);
    }
}
void HeapSort()
{
    BuildMaxHeap();
    hs=n;
    for(int i=hs;i>1;i--)
    {
        swap(a[1],a[i]);
        hs--;
        heapify(1);
    }
}
void main()
{
    int i;
    clrscr();
    cout<<"Enter length:\t";
    cin>>n;
    cout<<endl<<"Enter elements:\n";
    for(i=1;i<=n;i++)       //Read Array
    {
        cin>>a[i];
    }
    HeapSort();
    cout<<endl<<"Sorted elements:\n";
    for(i=1;i<=n;i++)       //Print Sorted Array
    {
        cout<<a[i];
        if(i!=n)
        {
            cout<<"\t";
        }
    }
    getch();
}
