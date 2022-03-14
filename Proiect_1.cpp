#include <iostream>
#include <algorithm>
#include<ctime>
#include <time.h>
#include <vector>
using namespace std;

void random(long long n, vector<long long>& v, long long val_max)
{
    long long elem1, elem2, elem3, p;

    srand(time(NULL));
    for(long long i=0;i<n;i++)
    {
        elem1 = rand();
        elem2 = rand();
        elem3 = rand();
        p = (elem1 * elem2 * elem3);
        if(p<0)
            p *= -1;
        p%=val_max;
        ///cout<<p<<endl;
        v[i]=p;
    }
}

void test(vector<long long> v, long long n) {
    for(long long i = 1; i < n; i++)
        if (v[i-1] > v[i])
            cout<<"Sortat corect";
        else
            cout<<"Sortat incorect";
}

const int RUN = 32;

void InsertionSort(vector<long long>& v, long long st2, long long dr2)
{
    for (long long i=st2+1;i<=dr2;i++)
    {
        long long ord = v[i];
        long long j = i-1;
        while(j>=st2 && v[j]>ord)
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = ord;
    }
}

void MergeSort2(vector<long long>& v,long long const st, long long const mij, long long const dr)
{
    auto const sub_array1 = mij - st + 1;
    auto const sub_array2 = dr - mij;

    vector<long long> st_array;
    vector<long long> dr_array;

    for (auto i = 0;i < sub_array1; i++)
        st_array.push_back(v[st+i]);

    for (auto j = 0;j < sub_array2; j++)
        dr_array.push_back(v[mij + j + 1]);

    auto index1 = 0;
    auto index2 = 0;
    int index_v = st;

    while (index1 < sub_array1 && index2 < sub_array2)
        {

        if (st_array[index1] <= dr_array[index2])
        {
            v[index_v] = st_array[index1];
            index1 ++;
        }
        else
        {
            v[index_v] = dr_array[index2];
            index2 ++;
        }
        index_v ++;
        }
    while (index1 < sub_array1)
    {
        v[index_v] = st_array[index1];
        index1 ++;
        index_v ++;
    }
        while (index2 < sub_array2)
    {
        v[index_v] = dr_array[index2];
        index2 ++;
        index_v ++;
    }
}


void TimSort(vector<long long>& v, long long n)
{

    for (long long i = 0; i < n; i+=RUN)
        InsertionSort(v, i, min((i+RUN-1),
                                    (n-1)));

    for (long long size = RUN; size < n;
                             size = 2*size)
    {

        for (long long st = 0; st < n;
                             st += 2*size)
        {

            long long mij = st + size - 1;
            long long dr = min((st + 2*size - 1),
                                            (n-1));

              if(mij < dr)
                MergeSort2(v, st, mij, dr);
        }
    }
}

void shellsort_knuth(vector<long long> &v, long long n)
{
    long long i = 1, j, aux, l;

    while(i < n)
        i = i * 3 + 1;
	l = i;
	while(l > 0)
	{
		for (i = l; i < n; i += 1)
		{
			aux = v[i];
			for (j = i; j >= l && v[j - l] > aux; j -= l)
				v[j] = v[j - l];
			v[j] = aux;
		}
		l -= 1;
		l /= 3;
	}
}

int ShellSort_n_pe_2(vector<long long> v, long long n)
{

    for (long long i = n/2; i> 0; i /= 2)
    {
        for (long long j = i; j < n; j += 1)
        {
            int c = v[j],k;

            for (k = j; k >= i && v[k - i] > c; k -= i)
                v[k] = v[k - i];

            v[k] = c;
        }
    }
    return 0;
}

void MergeSort1(vector<long long>& v,long long const st, long long const mij, long long const dr)
{
    auto const sub_array1 = mij - st + 1;
    auto const sub_array2 = dr - mij;

    vector<long long> st_array;
    vector<long long> dr_array;

    for (auto i = 0;i < sub_array1; i++)
        st_array.push_back(v[st+i]);

    for (auto j = 0;j < sub_array2; j++)
        dr_array.push_back(v[mij + j + 1]);

    auto index1 = 0;
    auto index2 = 0;
    int index_v = st;

    while (index1 < sub_array1 && index2 < sub_array2)
        {

        if (st_array[index1] <= dr_array[index2])
        {
            v[index_v] = st_array[index1];
            index1 ++;
        }
        else
        {
            v[index_v] = dr_array[index2];
            index2 ++;
        }
        index_v ++;
        }
    while (index1 < sub_array1)
    {
        v[index_v] = st_array[index1];
        index1 ++;
        index_v ++;
    }
        while (index2 < sub_array2)
    {
        v[index_v] = dr_array[index2];
        index2 ++;
        index_v ++;
    }
}

void verificare(vector<long long>& v, long long const start, long long const stop)
{
    if (start >= stop)
        return;

    auto mij2 = start + (stop - start) / 2;
    verificare(v, start, mij2);
    verificare(v, mij2 + 1, stop);
    MergeSort1(v, start, mij2, stop);}

void InsertionSort(vector<long long>& v, long long n)
{
    long long i, c, j;
    for (i = 1; i < n; i++)
    {
        c = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > c)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = c;
    }
}

void creare_arr(vector<long long> &v, long long n, long exp)
{
    long long i, frecventa[10]={0};
    vector<long long> o(n);

    for(i=0;i<n;i++)
        frecventa[(v[i] / exp)%10]+=1;

    for(i=1;i<10;i++)
        frecventa[i] += frecventa[i-1];


    for(i=n-1;i>=0;i--)
    {
        o[frecventa[(v[i] / exp)%10]-1] = v[i];
        frecventa[(v[i] / exp)%10]-=1;
    }

    for(i=0;i<n;i++)
        v[i] = o[i];
}

void RadixSort(vector<long long> &v, long long n)
{
    long long m=v[0],i,exp;

    for(i=1;i<n;i++)
        if(v[i]>m)
            m=v[i];

    for(exp=1;m/exp>0;exp*=10)
        creare_arr(v, n, exp);
}

void afisare(vector<long long> &v, long long n)
{
    for (auto k = 0;k < n; k++)
        cout<<v[k]<<" ";
}

int main()
{

    long long n,val_max;


    double start1, stop;

    cout<<"n=";
    cin>>n;
    vector <long long> v(n);
    vector <long long> v2(n);

    cout<<"Pana la: ";
    cin>>val_max;

    random(n, v, val_max);


    copy(v.begin(), v.end(), back_inserter(v2));
    start1 = clock();
    RadixSort(v2, n);
    stop = clock();

    cout<<"Timpul pentru RadixSort: "<<(stop-start1)/CLOCKS_PER_SEC<<"\n\n";


    start1 = clock();
    InsertionSort(v, n);
    stop = clock();
    cout<<"Timpul pentru InsertionSort: "<<(stop-start1)/CLOCKS_PER_SEC<<"\n\n";


    copy(v.begin(), v.end(), back_inserter(v2));
    start1 = clock();
    verificare(v2, 0, n - 1);
    stop = clock();
    cout<<"Timpul pentru MergeSort: "<<(stop-start1)/CLOCKS_PER_SEC<<"\n\n";


    copy(v.begin(), v.end(), back_inserter(v2));
    start1 = clock();
    ShellSort_n_pe_2(v2, n);
    stop = clock();
    cout<<"Timpul pentru ShellSort(varianta n/2): "<<(stop-start1)/CLOCKS_PER_SEC<<"\n\n";


    copy(v.begin(), v.end(), back_inserter(v2));
    start1 = clock();
    shellsort_knuth(v2, n);
    stop = clock();
    cout<<"Timpul pentru ShellSort(varianta de implementare knuth): "<<(stop-start1)/CLOCKS_PER_SEC<<"\n\n";


    copy(v.begin(), v.end(), back_inserter(v2));
    start1 = clock();
    TimSort(v2, n);
    stop = clock();
    cout<<"Timpul pentru TimSort: "<<(stop-start1)/CLOCKS_PER_SEC<<"\n\n";


    copy(v.begin(), v.end(), back_inserter(v2));
    start1 = clock();
    sort(v2.begin(), v2.end());
    stop = clock();
    cout<<"Timpul pentru sortarea nativa: "<<(stop-start1)/CLOCKS_PER_SEC;


    return 0;
}
