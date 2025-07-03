#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;

void swap(int& a, int& b);
void insert_pos(vector<int>& arr, int pos, int pos_end, int num);
void show(const vector<int>& arr);
bool sheng(const int& a, const int& b);
//各种排序算法
void bubble_sort(vector<int> arr);
void choose_sort(vector<int> arr);
void insert_sort(vector<int> arr);
void shell_sort(vector<int> arr);
void quick_sort(vector<int>& arr, int start, int end);
void quick_sort_start(vector<int> arr);
void quick_sort(vector<int>& arr, int start, int end);
void merge_sort_start(vector<int> arr);
void merge_sort(vector<int>& arr, int start, int end);

void heap_sort(vector<int> arr)		//堆排序
{

	show(arr);
}

void countint_sort(vector<int> arr)	//计数排序
{

	show(arr);
}

void bucket_sort(vector<int> arr)	//桶排序
{
	map<int, int> a;
	for (int& i : arr)
		a[i]++;
	int i = 0;
	for (pair<const int, int>& p : a)
	{
		for (int j = 0; j < p.second; j++)
			arr[i++] = p.first;
	}
	show(arr);
}

void radix_sort(vector<int> arr)	//基数排序
{

	show(arr);
}

void read(vector<int>& arr) 
{
#define rg register
	rg string str; rg int x;
	getline(cin, str);
	istringstream cins(str);
	while (cins >> x) 
		arr.push_back(x);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> arr;
	read(arr);
	cout << arr.size() << endl;
	int style;
	while (cin >> style)
	{
		switch (style)
		{
		case 0:
			show(arr);
			break;
		case 1:
			bubble_sort(arr); //冒泡排序
			break;
		case 2:
			choose_sort(arr); //选择排序
			break;
		case 3:
			insert_sort(arr); //插入排序
			break;
		case 4:
			shell_sort(arr);  //希尔排序
			break;
		case 5:
			quick_sort_start(arr);  //快速排序
			break;
		case 6:
			merge_sort_start(arr);	//归并排序
			break;
		case 7:
			heap_sort(arr);		//堆排序（未完成）
			break;
		case 8:
			countint_sort(arr);	//计数排序（未完成）
			break;
		case 9:
			bucket_sort(arr);	//桶排序
			break;
		case 10:
			radix_sort(arr);	//基数排序（未完成）
		default:
			break;
		}
	}
	return 0;
}


void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void insert_pos(vector<int>& arr, int pos, int pos_end, int num)
{
	for (int i = pos_end; i > pos; i--)
		arr[i] = arr[i - 1];
	arr[pos] = num;
}

void show(const vector<int>& arr)	//展示排序后的数组
{
	for (int i = 0, len = arr.size(); i < len; i++)
		cout << arr[i] << " "[i == len - 1];
	cout << endl;
}

bool sheng(const int& a, const int& b)
{
	return a > b;
}

void bubble_sort(vector<int> arr)	//冒泡排序（优化版）
{
	for (int i = 0, len = arr.size(); i < len; i++)
	{
		bool is = 0; //用于优化
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				is = 1;
			}
		}
		if (!is)
			break;
	}
	show(arr);
}

void choose_sort(vector<int> arr)	//选择排序（优化版）
{
	for (int i = 0, len = arr.size() / 2; i < len; i++)
	{
		int max = arr[i], min = arr[i];
		int index_max = i, index_min = i;
		for (int j = i + 1, len_j = arr.size() - i; j < len_j; j++)
		{
			if (max < arr[j])
			{
				index_max = j;
				max = arr[j];
			}
			if (min > arr[j])
			{
				index_min = j;
				min = arr[j];
			}
		}
		if (index_max == i)
		{
			swap(arr[arr.size() - i - 1], arr[index_max]);
			swap(arr[i], arr[index_min]);
		}
		else
		{
			swap(arr[i], arr[index_min]);
			swap(arr[arr.size() - i - 1], arr[index_max]);
		}
	}
	show(arr);
}

void insert_sort(vector<int> arr) //插入排序（二分优化）
{
	if (arr[0] > arr[1])
		swap(arr[0], arr[1]);
	for (int i = 2, len = arr.size(); i < len; i++)
	{
		int left = 0, right = i - 1;
		if (arr[left] > arr[i])
		{
			insert_pos(arr, left, i, arr[i]);
			continue;
		}
		else if (arr[right] < arr[i])
			continue;
		int mid = (left + right) >> 1;
		while (right - left > 1)
		{
			mid = (left + right) >> 1;
			if (arr[mid] < arr[i])
				left = mid;
			else if (arr[mid] > arr[i])
				right = mid;
			else
				break;
		}
		if (arr[mid] < arr[i])
			insert_pos(arr, mid + 1, i, arr[i]);
		else
			insert_pos(arr, mid, i, arr[i]);
	}
	show(arr);
}

void shell_sort(vector<int> arr)	//希尔排序
{
	for (int time = 1;; time++)
	{
		int size = arr.size();
		int step = size / (2 * time);

		for (int i = 0; i < size - step; i++)
			for (int j = i; j < size; j += step)
				for (int k = j + step; k < size; k += step)
				{
					if (arr[k] < arr[j]) swap(arr[j], arr[k]);
				}

		if (step == 1) break;
	}
	show(arr);
}

void quick_sort_start(vector<int> arr)
{
	int len = arr.size();
	quick_sort(arr, 0, len - 1);
	show(arr);
}

void quick_sort(vector<int>& arr, int start, int end)	//快速排序（思想版）
{
	if (end - start < 1) return;
	if (end - start == 1)
	{
		if (arr[end] < arr[start]) swap(arr[start], arr[end]);
		return;
	}

	int left = start, right = start + 1;
	while (right <= end)
	{
		if (arr[right] > arr[left])
		{
			right++;
		}
		else
		{
			insert_pos(arr, left, right, arr[right]);
			left++;
		}
		if (right == left) right++;
	}
	quick_sort(arr, start, left);
	quick_sort(arr, left + 1, end);
}

void merge_sort_start(vector<int> arr)
{
	int len = arr.size();
	merge_sort(arr, 0, len - 1);
	show(arr);
}

void merge_sort(vector<int>& arr, int start, int end)	//归并排序（递归）
{
	if (end - start <= 0) return;
	if (end - start == 1)
	{
		if (arr[end] < arr[start]) swap(arr[end], arr[start]);
		return;
	}

	int mid = (start + end) >> 1;
	merge_sort(arr, start, mid);
	merge_sort(arr, mid + 1, end);
	int right = end, left = mid;
	vector<int> temp(arr.begin() + start, arr.begin() + end + 1);
	while (right >= mid + 1 && left >= start && end >= start)
	{
		if (temp[right - start] > temp[left - start])
		{
			arr[end] = temp[right - start];
			right--; end--;
		}
		else
		{
			arr[end] = temp[left - start];
			left--; end--;
		}
	}
	while (right >= mid + 1 || left >= start)
	{
		if (right >= mid + 1)
		{
			arr[end--] = temp[right - start];
			right--;
		}
		if (left >= start)
		{
			arr[end--] = temp[left - start];
			left--;
		}
	}
}