#include<stdio.h>
#include<stdlib.h>

struct Vector
{
    int * arr = (int*) malloc(sizeof(int));
    int size=0;
    int e=-1;
    int intial_size=1;
    int s=0;

    void push(int d)
    {
        if(size==0)
        {
            free(arr);
            intial_size=1;
             arr = (int*) realloc(arr,sizeof(int));
             e=-1;
             s=0;
        }
        *(arr+(++e))=d;
        ++size;
        arr = (int*) realloc(arr,sizeof(int)*(++intial_size));
        return;
    }
    void print()
    {
        for(int i=s;i<size;i++)
        {
            printf("%d ", *(arr+i)); 
        }
    }
    void pop_back()
    {
        if(size==0) return;
        *(arr+e) = 0;
        arr = (int*) realloc(arr,sizeof(int)*(--intial_size));
        --e;
        --size;
    }
    void erase(int i)
    {
        if(size==0) return;

        if(i>=0 && i<=e)
        {
        for(int j=i;j<size-1;j++)
        {
             *(arr+j)=*(arr+j+1);
        }
        *(arr+e) = 0;
        arr = (int*) realloc(arr,sizeof(int)*(--intial_size));
        --e;
        size--;
        }
    }
    void insert(int i, int d)
    {
       if(i>=0 && i<=e)
       {
        arr = (int*) realloc(arr,sizeof(int)*(intial_size++));
        for(int j=size-1;j>=i;j--)
        {
            arr[j+1]=arr[j];
        }
        arr[i]=d;
        size++;
        ++e;
       }
    } 
    void clear()
       {
         size=0;
       }
};

int main()
{
    Vector v;
    v.push(1);
    v.push(2);
    v.push(3);
    v.insert(1,789);
    v.print();

}