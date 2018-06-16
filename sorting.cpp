// Selection Sort: 
// Find the minimum (least) element and place it at the beginning of an array. 
// Keep doing this. 
// O(n^2) average and worst case. Memory O(1)
// Does O(n) swaps only, can be used when memory write is a costly operation.

int swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int arr[], int n){
	int i, j, min_index;
	for(int i = 0; i < n; i++){ //One by one move boundary in an unsorted subarray.
		min_index = i;
		for(int j = i+1; j < n; j++){ //find the minimum in the array
			if(arr[j] < arr[min_index]){
				min_index = j;
			}
		}
		swap(&arr[i], &arr[min_index]);
	}
}

// Bubble Sort: 
// O(n^2) average and worst case scenario, Memory: O(1)
// Keep swapping items, start from the beginning of the pairs, and keep going, until they are all sorted. 
// this way the smallest item eventually bubbles it ways up to the front. 

void bubbleSort(jnt arr[], int n){
	bool swapped;
	for(int i = 0; i < n; i++){
		swapped = false;
		for(int j = 0; j < n-i-1; j++){ //The reason it's going to be n-i-1 is because the last i elements will be sorted./ in place.
			if(arr[j] > arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
		if(swapped == false){ //It's already sorted, the inner loop will keep running for no reason. 
			break;
		}
	}
}

// Insertion Sort
// Insertion sort takes maximum time to sort if elements are sorted in reverse order. 
// And it takes minimum time (Order of n) when elements are already sorted.
// O(n^2)
//in a complete big array it could be useful, where it's almost sorted, only a few things missing.

void insertionSort(int arr[], int n){
   int i, key, j;
   for (i = 1; i < n; i++){
       key = arr[i];
       j = i-1;
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

// Recursive function to sort an array using
// insertion sort
void insertionSortRecursive(int arr[], int n)
{
    // Base case
    if (n <= 1)
        return;
 
    // Sort first n-1 elements
    insertionSortRecursive( arr, n-1 );
 
    // Insert last element at its correct position
    // in sorted array.
    int last = arr[n-1];
    int j = n-2;
 
    /* Move elements of arr[0..i-1], that are
      greater than key, to one position ahead
      of their current position */
    while (j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}
 
// QuickSort implementation : Divide and Conquer 
// Worst case: O(n^2), 
// Average and best case: O(nlogn)

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); //Swap the pivot and the locaiton after i, bring the pivot to the right place that is. 
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// MergeSort works well for LinkedLists than quickSort Unlike array, in linked list, we can insert items in the middle in O(1) extra space and O(1) time. 
//Therefore merge operation of merge sort can be implemented without extra space for linked lists.
// MergeSort also does not require too much random access like quicksort does. 


void Merge(int arr*, int low, int high, int mid){
	int i = low;
	int j = mid + 1;
	int k = 0; //new array index;
	int temp[high-low+1];
	while(i <= mid && j <= high){
		if(a[i] < a[j]){
			temp[k++] = a[i++];
		}
		else{
			temp[k++] = a[j++];
		}
	}
	while(i <= mid){ //Remaining values insert into the array 
		temp[k++] = a[i++];
	}

	while(j <= high){
		temp[k++] = a[j++];
	}
	for (i = low; i <= high; i++){ //assign 
		a[i] = temp[i-low];
	}

}


void MergeSort(int* arr, int low, int high){
	int middle;
	if(low < high){
		middle  = (low+high)/2;
		MergeSort(arr, low, middle);
		MergeSort(arr, middle+1, high);
		Merge(arr,low, high, middle);
	}
}


void mergeSort1(int* arr){
	int len = arr.size();
	int low = 0;
	int high = len - 1;
	MergeSort(arr, low, high);
}


// Rotated and sorted array : find the min element

int findMin(vector<int>& nums) {
        int len = nums.size();
        int start = 0;
        int end = len -1;
        while(start < end){
            if(nums[start] < nums[end]){
                return nums[start];
            } 
            int mid = (start + end)/2;
            if(nums[mid] >= nums[start]){
                start = mid+1;
            }
            else{
                end = mid; 
            }
        }
        return nums[start];
    }


vector<pair<int,int>> findSum(int sum, int n){
  //std::urordered_set<pair<int,int>> s;
  std::vector<std::pair<int,int>> answer;
  for (int i = 1; i <= n/2; i++){
    int target = n-i;
    answer.emplace_back(i,target);
  } 
  return answer;
}

int main(){
  {
    int sum = 100;
    int n = 99;
    findSum(sum,n);
    
  std::vector<int> myvector = {10,20,30};

  myvector.emplace_back (100);
  myvector.emplace_back (200);

  std::cout << "myvector contains:";
  for (auto& x: myvector)
    std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}

}
















 