#include <iostream>
using namespace std;
void bubbleSortAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int F2(int d, int bottle_capacities[], int n) {
    int filled_bottles = 0;
    int remaining_water = d;

    
    int sorted_capacities[n]; 
    for (int i = 0; i < n; ++i) {
        sorted_capacities[i] = bottle_capacities[i];
    }

    
    bubbleSortAscending(sorted_capacities, n);

    for (int i = 0; i < n; ++i) {
        int capacity = sorted_capacities[i];

        if (remaining_water == 0) {
            break; 
        }

        if (capacity <= remaining_water) {
           
            remaining_water -= capacity;
            filled_bottles++;
        } else {
          
            break;
        }
    }

    return filled_bottles;
}

int main() {
    
    int d; 
    int n; 

    cout << "Nhap dung tich binh nuoc (d): ";
    cin >> d;

    cout << "Nhap so luong chai (n): ";
    cin >> n;

    
    const int MAX_BOTTLES = 100; 
    int bottle_capacities[MAX_BOTTLES];

    if (n > MAX_BOTTLES) {
        cerr << "Loi: So luong chai (" << n << ") vuot qua gioi han cho phep (" << MAX_BOTTLES << ").\n";
        return 1; 
    }

    cout << "Nhap dung tich cua tung chai (cach nhau bang khoang trang): ";
    for (int i = 0; i < n; ++i) {
        cin >> bottle_capacities[i];
    }

    
    int q = F2(d, bottle_capacities, n);

    cout << "So luong chai toi da (theo chien luoc tham lam) duoc do day nuoc la: " << q << std::endl;

    return 0;
}