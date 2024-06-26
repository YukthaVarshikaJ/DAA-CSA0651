#include <stdio.h>
#include <limits.h>
int main()
{
    int arr[] = {3, 5, 1, 8, 9, 2, 7, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = INT_MIN;
    int min = INT_MAX;
    int stack[100][2];
    int top = -1;
    top++;
    stack[top][0] = 0;
    stack[top][1] = n - 1;
    while (top >= 0) {
        int low = stack[top][0];
        int high = stack[top][1];
        top--;
        if (low == high)
		{
            if (arr[low] > max) max = arr[low];
            if (arr[low] < min) min = arr[low];
        }
		else if (low + 1 == high)
		{
            if (arr[low] > arr[high])
			{
                if (arr[low] > max) max = arr[low];
                if (arr[high] < min) min = arr[high];
            }
			else
			{
                if (arr[high] > max) max = arr[high];
                if (arr[low] < min) min = arr[low];
            }
        }
		else
		{
            int mid = (low + high) / 2;
            top++;
            stack[top][0] = mid + 1;
            stack[top][1] = high;
            top++;
            stack[top][0] = low;
            stack[top][1] = mid;
        }
    }
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
}
