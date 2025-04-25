/*Two sorted arrays, such that the arrays may have some common
 elements. Find the sum of the maximum sum path to reach from the
 beginning of any array to the end of any of the two arrays. We can
 switch from one array to another array only at common elements*/

 #include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxSumPath(int arr1[], int n1, int arr2[], int n2) {
    int i = 0, j = 0; 
    int result = 0, sum1 = 0, sum2 = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            sum1 += arr1[i++];
        } else if (arr1[i] > arr2[j]) {
            sum2 += arr2[j++];
        } else {
            result += max(sum1, sum2) + arr1[i];
            sum1 = 0;
            sum2 = 0;
            i++;
            j++;
        }
    }

    while (i < n1) {
        sum1 += arr1[i++];
    }

    while (j < n2) {
        sum2 += arr2[j++];
    }

    result += max(sum1, sum2);

    return result;
}

int main() {
    int arr1[] = {2, 3, 7, 10, 12, 15, 30, 34};
    int arr2[] = {1, 5, 7, 8, 10, 15, 16, 19};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Maximum sum path: %d\n", maxSumPath(arr1, n1, arr2, n2));

    return 0;
}