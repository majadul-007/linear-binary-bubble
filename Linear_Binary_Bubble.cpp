#include <iostream>
using namespace std;

int tswaps = 0;
int tcomp = 0;

// Display Function

void display(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

// Bubble Sort Function

void bubbleSort(int *array, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        int swaps = 0; //flag to detect any swap is there or not
        for (int j = 0; j < size - i - 1; j++)
        {
             tcomp++;
            cout<< "Number of comparison: "<<tcomp<<endl;
            if (array[j] > array[j + 1])
            {
                tswaps++;

                cout<< "Number of swaps: "<<tswaps<<endl;
                swap(array[j], array[j + 1]);
                     display(array, size);

                swaps = 1; //set swap flag

            }
        }
        if (!swaps)
            break; // No swap in this pass, so array is sorted
    }
}

// Binary Search Function

void binary_search(int first, int arr[], int last, int middle, int num)
{
    while (first <= last)
    {
        if (arr[middle] < num)
        {
            first = middle + 1;
        }
        else if (arr[middle] == num)
        {
            cout << num << " found in the array at the location " << middle + 1 << "\n";
            break;
        }
        else
        {
            last = middle - 1;
        }
        middle = (first + last) / 2;
    }
    if (first > last)
    {
        cout << num << " not found in the array";
    }
}

// Linear Search Function

void linear_search(int n, int arr[], int key, int found)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at position " << i + 1;
            found = 1;
            break;
        }
    }
    if (!found)
    {
        cout << "Number Not Found" << endl;
    }
}
// Main Function
int main()
{
    int count, i, arr[30], num, first, last, middle;
    int opt;
    cout << "Which search method do you want to use?1.Binary Search Or 2.Linear Search 0r 3.Bubble Sort" << endl;
    cout << "Enter the number:(Ex: 1 for binary/2 for linear/3 for Bubble sort)" << endl;
    cin >> opt;
    //For Binary Search
    if (opt == 1)
    {
        cout << "how many elements would you like to enter?:";
        cin >> count;
        for (i = 0; i < count; i++)
        {
            cout << "Enter number " << (i + 1) << ": ";
            cin >> arr[i];
        }
        cout << "Enter the number that you want to search:";
        cin >> num;
        first = 0;
        last = count - 1;
        middle = (first + last) / 2;
        binary_search(first, arr, last, middle, num);
    }
    //For Linear Search
    else if (opt == 2)
    {
        int n, an, arr[30], key, i, found = 0;
        cout << "Please enter number of element you want:" << endl;
        cin >> n;
        cout << "Please enter the numbers" << endl;
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << "Please Enter the number you want to search" << endl;
        cin >> key;
        linear_search(n, arr, key, found);
    }
    // For Bubble Sort

    else if (opt == 3)
    {
        int n;
        cout << "Enter the number of elements: ";
        cin >> n;
        int arr[n]; //create an array with given number of elements
        cout << "Enter elements:" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << "Array before Sorting: ";
        display(arr, n);
        bubbleSort(arr, n);
        cout << "Array after Sorting: ";
        display(arr, n);
    }
    else
    {
        cout << "Please enter the correct number : ex: 1/2/3" << endl;
    }
    return 0;
}
