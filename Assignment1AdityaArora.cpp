#include <iostream>
using namespace std;

void inputArray(int a[], int &size) {
    cout << "How many elements? ";
    cin >> size;
    cout << "Enter " << size << " values: ";
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
}

void showArray(int a[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void addElement(int a[], int &size) {
    int index, value;
    cout << "Position to insert (0-indexed): ";
    cin >> index;
    cout << "Value: ";
    cin >> value;

    for (int i = size; i > index; i--) {
        a[i] = a[i - 1];
    }
    a[index] = value;
    size++;
}

void removeElement(int a[], int &size) {
    int index;
    cout << "Position to delete (0-indexed): ";
    cin >> index;

    for (int i = index; i < size - 1; i++) {
        a[i] = a[i + 1];
    }
    size--;
}

void searchElement(int a[], int size) {
    int key;
    cout << "Enter number to search: ";
    cin >> key;

    for (int i = 0; i < size; i++) {
        if (a[i] == key) {
            cout << "Found at index " << i << endl;
            return;
        }
    }
    cout << "Not present in array.\n";
}

void uniqueArray(int a[], int &size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; ) {
            if (a[i] == a[j]) {
                for (int k = j; k < size - 1; k++) {
                    a[k] = a[k + 1];
                }
                size--;
            } else {
                j++;
            }
        }
    }
}

void demoOutput() {
    int arr[5] = {1};
    cout << "Array contents: ";
    for (int i = 0; i < 5; i++) cout << arr[i];
    cout << "  (Reason: Only first is 1, others auto-initialized to 0)" << endl;
}

void reverseArr(int a[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = a[i];
        a[i] = a[size - i - 1];
        a[size - i - 1] = temp;
    }
}

void multiplyMatrices() {
    int r1, c1, r2, c2;
    cout << "Enter rows & cols of Matrix A: ";
    cin >> r1 >> c1;
    cout << "Enter rows & cols of Matrix B: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Cannot multiply these matrices.\n";
        return;
    }

    int A[10][10], B[10][10], C[10][10] = {0};

    cout << "Enter Matrix A:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];

    cout << "Enter Matrix B:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Result:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMat() {
    int r, c;
    cout << "Enter rows & cols: ";
    cin >> r >> c;

    int mat[10][10];
    cout << "Enter matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat[i][j];

    cout << "Transpose:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << mat[j][i] << " ";
        }
        cout << endl;
    }
}

void sumRC() {
    int r, c;
    cout << "Enter rows & cols: ";
    cin >> r >> c;

    int mat[10][10];
    cout << "Enter matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat[i][j];

    for (int i = 0; i < r; i++) {
        int rowSum = 0;
        for (int j = 0; j < c; j++) rowSum += mat[i][j];
        cout << "Row " << i + 1 << " sum = " << rowSum << endl;
    }

    for (int j = 0; j < c; j++) {
        int colSum = 0;
        for (int i = 0; i < r; i++) colSum += mat[i][j];
        cout << "Column " << j + 1 << " sum = " << colSum << endl;
    }
}

int main() {
    int arr[100], n = 0, option;

    while (true) {
        cout << "\n--- MENU ---\n"
             << "1. Create Array\n2. Display\n3. Insert\n4. Delete\n5. Search\n"
             << "6. Remove Duplicates\n7. Predict Output\n8. Reverse Array\n"
             << "9. Matrix Multiplication\n10. Transpose Matrix\n11. Row/Col Sums\n12. Exit\n"
             << "Choose: ";
        cin >> option;

        switch (option) {
            case 1: inputArray(arr, n); break;
            case 2: showArray(arr, n); break;
            case 3: addElement(arr, n); break;
            case 4: removeElement(arr, n); break;
            case 5: searchElement(arr, n); break;
            case 6: uniqueArray(arr, n); break;
            case 7: demoOutput(); break;
            case 8: reverseArr(arr, n); break;
            case 9: multiplyMatrices(); break;
            case 10: transposeMat(); break;
            case 11: sumRC(); break;
            case 12: return 0;
            default: cout << "Invalid option.\n";
        }
    }
}
