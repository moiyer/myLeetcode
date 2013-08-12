// sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//插入排序，稳定的排序
int insertion_sort(int data[], int n)
{
	if(data == NULL || n <= 0)return -1;
	if(n == 1)return 0;

	int p_cur = 1;
	int cur = 0;
	int i = 0;
	while(p_cur < n)
	{
		cur = data[p_cur];
		i = p_cur - 1;
		for(; i >= 0; --i)
		{
			if(data[i] > cur)data[i + 1] = data[i];
			else break;
		}
		data[i + 1] = cur;
		++p_cur;
	}

	return 0;
}

//归并排序，稳定的排序
void merge(int data[], int l, int m, int r, int tp[])
{
	int i = l, j = m + 1, k = l;
	while(i <= m && j <= r)
	{
		if(data[i] <= data[j])
			tp[k++] = data[i++];
		else tp[k++] = data[j++];
	}
	while(i <= m)tp[k++] = data[i++];
	while(j <= r)tp[k++] = data[j++];

	k = l;
	while( k <= r)data[k++] = tp[k++];
}

void merge_sort(int data[], int l, int r, int tp[])
{
	if(l == r)return;

	int m = l + (r - l) / 2;
	merge_sort(data, l, m, tp);
	merge_sort(data, m + 1, r, tp);
	merge(data, l, m, r, tp);
}

//快速排序，不稳定的排序
void qsort(int data[], int l, int r)
{
	if(l >= r)return;

	int pivot = data[l];
	int p_cur = l + 1, p_divid = l;
	while(p_cur <= r)
	{
		if(data[p_cur] < pivot)
		{
			data[p_divid] = data[p_cur];
			p_divid++;
		}
		p_cur++;
	}
	data[p_divid] = pivot;
	qsort(data, l, p_divid - 1);
	qsort(data, p_divid + 1, r);
}

//堆排序，不稳定的排序
void sift_up(int data[], int i)
{
	int cur = i;
	int father = (i - 1) / 2;
	while(cur > 0)
	{
		if(data[cur] > data[father])
			swap(data[cur], data[father]);
		else break;
		cur = father;
		father = (father - 1) / 2;
	}
}

void sift_down(int data[], int i)
{
	int cur = 0;
	int child = cur * 2 + 1;
	while(child <= i)
	{
		if(child + 1 <= i && data[child + 1] > data[child])
			child = child + 1;
		if(data[cur] < data[child])
		{
			swap(data[cur], data[child]);
			cur = child;
			child = child * 2 + 1;
		}else break;
	}
}

void heap_sort(int data[], int n)
{
	for(int i = 0; i < n; ++i)
		sift_up(data, i);

	for(int i = n - 1; i > 0; --i)
	{
		swap(data[i], data[0]);
		sift_down(data, i - 1);
	}
}

//二分查找
int bsearch(int data[], int n, int query)
{
	int l = 0, r = n - 1;
	int m = 0;
	while(l <= r)
	{
		m = l + (r - l) / 2;
		if(data[m] < query)
		{
			l = m + 1;
		}else if(data[m] > query)
		{
			r = m - 1;
		}else return m;
	}
	return -1;
}

int bsearch_first(int data[], int n, int query)
{
	int l = 0, r = n - 1;
	int m = 0;
	while(l < r)//注意没有等号
	{
		m = l + ((r - l) >> 1);
		if(data[m] < query)
			l = m + 1;
		else if(data[m] > query)
			r = m - 1;
		else r = m;
	}
	if(l < n && data[l] == query)return l;
	else return -1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int data[] = {2, 3, 4, -1, -3, 0, 8, 0, -22};
	int data2[] = {2, -4, 9, 0};
	int data3[] = {1, -7};
	
	cout << "insertion" << endl;
	insertion_sort(data, 9);
	for(int i = 0; i < 9; ++i)
		cout << data[i] << " ";
	cout << endl;
	
	insertion_sort(data2, 4);
	for(int i = 0; i < 4; ++i)
		cout << data2[i] << " ";
	cout << endl;

	insertion_sort(data3, 2);
	for(int i = 0; i < 2; ++i)
		cout << data3[i] << " ";
	cout << endl;

	
	cout << "merge" << endl;
	int *tp = new int[9];
	merge_sort(data, 0, 8, tp);
	for(int i = 0; i < 9; ++i)
		cout << data[i] << " ";
	cout << endl;
	
	merge_sort(data2, 0, 3, tp);
	for(int i = 0; i < 4; ++i)
		cout << data2[i] << " ";
	cout << endl;

	merge_sort(data3, 0, 1, tp);
	for(int i = 0; i < 2; ++i)
		cout << data3[i] << " ";
	cout << endl;
	delete[] tp;


		cout << "qsort" << endl;
	qsort(data, 0, 8);
	for(int i = 0; i < 9; ++i)
		cout << data[i] << " ";
	cout << endl;
	
	qsort(data2, 0, 3);
	for(int i = 0; i < 4; ++i)
		cout << data2[i] << " ";
	cout << endl;

	qsort(data3, 0, 1);
	for(int i = 0; i < 2; ++i)
		cout << data3[i] << " ";
	cout << endl;

	
		cout << "heap" << endl;
	heap_sort(data, 9);
	for(int i = 0; i < 9; ++i)
		cout << data[i] << " ";
	cout << endl;
	
	heap_sort(data2, 4);
	for(int i = 0; i < 4; ++i)
		cout << data2[i] << " ";
	cout << endl;

	heap_sort(data3, 2);
	for(int i = 0; i < 2; ++i)
		cout << data3[i] << " ";
	cout << endl;



	int q1[] = {2, 2};
	int q2[] = {1};
	int q3[] = {1, 3, 3, 3, 5, 6};
	int q4[] = {1, 2, 4, 4};

	cout << "bsearch" << endl;
	cout << bsearch(q1, 2, 0) << endl;
	cout << bsearch(q1, 2, 1) << endl;
	cout << bsearch(q1, 2, 2) << endl;
	cout << bsearch(q1, 2, 3) << endl;
	cout << bsearch(q2, 1, 0) << endl;
	cout << bsearch(q2, 1, 1) << endl;
	cout << bsearch(q2, 1, -1) << endl;
	cout << bsearch(q3, 6, 3) << endl;
	cout << bsearch(q4, 4, 0) << endl;

		cout << "bsearch_first" << endl;
	cout << bsearch_first(q1, 2, 0) << endl;
	cout << bsearch_first(q1, 2, 1) << endl;
	cout << bsearch_first(q1, 2, 2) << endl;
	cout << bsearch_first(q1, 2, 3) << endl;
	cout << bsearch_first(q2, 1, 2) << endl;
	cout << bsearch_first(q2, 1, 1) << endl;
	cout << bsearch_first(q2, 1, -1) << endl;
	cout << bsearch_first(q3, 6, 3) << endl;
	cout << bsearch_first(q4, 4, 4) << endl;

	system("pause");
	return 0;
}

