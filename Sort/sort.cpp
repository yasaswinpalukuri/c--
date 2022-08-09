#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void bucketSort(int a[],int n){
    int bucket[n];
    for(int i=0;i<n;i++) bucket[i] = 0;
    for(int i=0;i<n;i++) bucket[a[i]]++;
    int cnt = 0;
    for(int i=0;i<n;i++) cnt += bucket[i];
    int b[cnt];
    for(int i=0;i<n;i++) b[i] = 0;
    for(int i=0;i<n;i++) b[bucket[a[i]]-1] = a[i];
    for(int i=0;i<cnt;i++) a[i] = b[i];
}

void combSort(int a[],int n){
    int gap = n;
    bool swapped = true;
    while(gap>1 || swapped){
        if(gap>1){
            gap = (int)(gap/1.3);
        }
        swapped = false;
        for(int i=0;i<n-gap;i++){
            if(a[i]>a[i+gap]){
                int temp = a[i];
                a[i] = a[i+gap];
                a[i+gap] = temp;
                swapped = true;
            }
        }
    }
}

void countSort(int a[],int n)
{
    int max = *max_element(arr, arr+n);
    int min = *min_element(arr, arr+n);
    int range = max - min + 1;
 
    vector<int> count(range), output(n);
    for (int i = 0; i < n; i++)
        count[arr[i] - min]++;
 
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

void insertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void swapValue(int *a, int *b)
{
	int *temp = a;
	a = b;
	b = temp;
	return;
}

void InsertionSort(int arr[], int *begin, int *end)
{
	int left = begin - arr;
	int right = end - arr;

	for (int i = left+1; i <= right; i++)
	{
		int key = arr[i];
		int j = i-1;
		while (j >= left && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
}

return;
}

int* Partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high- 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (arr + i + 1);
}

int *MedianOfThree(int * a, int * b, int * c)
{
	if (*a < *b && *b < *c) return (b);
	if (*a < *c && *c <= *b) return (c);
	if (*b <= *a && *a < *c) return (a);
	if (*b < *c && *c <= *a) return (c);
	if (*c <= *a && *a < *b) return (a);
	if (*c <= *b && *b <= *a) return (b);
}

void IntrosortUtil(int arr[], int * begin,int * end, int depthLimit)
{
	int size = end - begin;
	if (size < 16)
	{
		InsertionSort(arr, begin, end);
		return;
	}
	if (depthLimit == 0)
	{
		make_heap(begin, end+1);
		sort_heap(begin, end+1);
		return;
	}
	int * pivot = MedianOfThree(begin, begin+size/2, end);
	swapValue(pivot, end);

	int * partitionPoint = Partition(arr, begin-arr, end-arr);
	IntrosortUtil(arr, begin, partitionPoint-1, depthLimit - 1);
	IntrosortUtil(arr, partitionPoint + 1, end, depthLimit - 1);

	return;
}

void Introsort(int arr[], int *begin, int *end)
{
	int depthLimit = 2 * log(end-begin);
	IntrosortUtil(arr, begin, end, depthLimit);

	return;
}

void merge(int array[], int left, int mid,int right){
    int i = left, j = mid + 1, k = 0;
    int temp[right - left + 1];
    while(i <= mid && j <= right){
        if(array[i] < array[j]){
            temp[k] = array[i];
            i++;
        }
        else{
            temp[k] = array[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        temp[k] = array[i];
        i++;
        k++;
    }
    while(j <= right){
        temp[k] = array[j];
        j++;
        k++;
    }
    for(int i = 0; i < right - left + 1; i++){
        array[left + i] = temp[i];
    }
}

void mergeSort(int array[], int begin, int end){
    if(begin < end){
        int mid = (begin + end) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    }
}



void quickSort(int arr[], int low, int high) 
{ 
    if (low <= high) 
    {
        int pi = Partition(arr, low, high);
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}

void radixSort(int a[],int n){
    int max = a[0];
    for(int i=1;i<n;i++) if(a[i]>max) max = a[i];
    int exp = 1;
    while(max/exp>0){
        int bucket[10] = {0};
        for(int i=0;i<n;i++) bucket[a[i]/exp%10]++;
        int cnt = 0;
        for(int i=0;i<10;i++) cnt += bucket[i];
        int b[cnt];
        for(int i=0;i<10;i++) b[i] = 0;
        for(int i=0;i<10;i++) b[bucket[i]-1] = i*exp;
        for(int i=0;i<n;i++) a[i] = b[a[i]/exp%10];
        exp *= 10;
    }
}

void shellSort(int a[],int n){
    int gap = n/2;
    while(gap>0){
        for(int i=gap;i<n;i++){
            int key = a[i];
            int j = i-gap;
            while(j>=0 && a[j]>key){
                a[j+gap] = a[j];
                j -= gap;
            }
            a[j+gap] = key;
        }
    }
}
void selectionSort(int a[],int n){
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i+1;j<n;j++) if(a[j]<a[min]) min = j;
        swap(a[i],a[min]);
    }
}

int main(){
    do{
        int n;
        cout << "Enter the number of elements: ";
        cin >> n;
        if(n<=0) break;
        int a[n];
        cout << "Enter the elements: ";
        for(int i=0;i<n;i++) cin >> a[i];
        cout << "Enter the choice: " << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Merge Sort" << endl;
        cout << "5. Quick Sort" << endl;
        cout << "6. Radix Sort" << endl;
        cout << "7. Shell Sort" << endl;
        cout << "8. IntroSort" << endl;
        cout << "9. Exit" << endl;
        int choice;
        cin >> choice;
        switch(choice){
            case 1:
                bubbleSort(a,n);
                break;
            case 2:
                selectionSort(a,n);
                break;
            case 3:
                insertionSort(a,n);
                break;
            case 4:
                mergeSort(a,0,n-1);
                break;
            case 5:
                quickSort(a,0,n-1);
                break;
            case 6:
                radixSort(a,n);
                break;
            case 7:
                shellSort(a,n);
                break;
            case 8:
                Introsort(a,a,a+n-1);
                break;
            case 9:
                break;
            default:
                cout << "Invalid choice" << endl;
        }
        cout << "The sorted array is: ";
        for(int i=0;i<n;i++) cout << a[i] << " ";
        cout << endl;
    }while(true);
}