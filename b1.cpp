#include <iostream>

using namespace std;


void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int F1(int coins[], int n, int m) {
   
    int temp[100]; 
    for (int i = 0; i < n; i++) {
        temp[i] = coins[i];
    }
    
    
    sortDescending(temp, n);
    
    int p = 0; 
    for (int i = 0; i < n; i++) {
        int xi = temp[i];
        if (xi <= m) {
            int count = m / xi; 
            p += count;
            m -= count * xi; 
        }
        if (m == 0) break; 
    }
    
    
    return m == 0 ? p : -1;
}

int main() {
    
    int n = 4; 
    int coins[] = {1, 5, 10, 25};
    int m = 30;
    
    
    cout << "So loai tien xu: " << n << endl;
    cout << "Cac menh gia: ";
    for (int i = 0; i < n; i++) cout << coins[i] << " ";
    cout << endl;
    cout << "So tien can doi: " << m << endl;
    
    
    int p = F1(coins, n, m);
    
   
    if (p != -1)
        cout << "So luong dong xu it nhat: " << p << endl;
    else
        cout << "Khong the doi duoc so tien " << m << endl;
    
    return 0;
}