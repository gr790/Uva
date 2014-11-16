#include <iostream>
#include <fstream>
using namespace std;

typedef long long int ll; 
 
long long int inv_count = 0;
void merge(ll arr[], int start, int mid, int end)
{
        int h,i,j,k;
        ll *b = new ll[end-start+1];
        h = start;
        i = 0;
        j = mid+1; 
        while( ( h <= mid) && (j <= end))
        {
                if(arr[h] <= arr[j])
                {
                        b[i] = arr[h];
                        h++;
                }
                else
                {
                        b[i] = arr[j];
                        inv_count += (mid - h + 1);
                        j++;
                }
                i++;
        }

        while (h <= mid )
        {
                b[i] = arr[h];
                i++; h++;
        }

        while( j <= end )
        {
                b[i] = arr[j];
                i++; j++;
        }

        for(k = 0; k <= end-start; ++k)
        {
                arr[k+start] = b[k];
        }

        delete [] b;
}
 
void merge_sort(ll arr[], int start, int end)
{
        if( start < end )
        {
                int mid = (int)(start+end)/2;
                merge_sort(arr, start, mid);
                merge_sort(arr, mid+1, end);
                merge(arr, start, mid, end);
        }
}

void count_swap(ll arr[], int num)
{
	merge_sort(arr, 0, num-1);
}
	

int main()
{
        int num;
        freopen("./sample.txt", "r", stdin);

        while( cin >> num )
        {
                ll *arr = new ll[num];
                for(int i = 0; i < num; ++i)
                        cin >> arr[i];

                if( num < 2) 
                {
                        inv_count = 0;
                        cout << inv_count << endl;
                }
                else
                {
                        count_swap(arr, num);
                        cout << inv_count << endl;
                }
                delete [] arr;
                inv_count = 0;
        }
        return 0;
}
