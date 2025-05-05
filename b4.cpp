#include <iostream>
using namespace std;

struct Item {
    int id; 
    int mass;
    int size;
};


void bubbleSortItemsByMass(Item items[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            
            if (items[j].mass > items[j + 1].mass) {
                
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}



void F6(int backpack_size_k, Item items[], int n, int &total_mass_p, int selected_item_ids[], int &selected_count_d) {
    
    bubbleSortItemsByMass(items, n);

    total_mass_p = 0; 
    int current_size = 0; 
    selected_count_d = 0; 

    
    for (int i = 0; i < n; ++i) {
        
        if (current_size + items[i].size <= backpack_size_k) {
            
            total_mass_p += items[i].mass;
            current_size += items[i].size;
            selected_item_ids[selected_count_d++] = items[i].id; 
        } else {
            
            break;
        }
    }
}

int main() {
    
    int k; 
    int n; 

    cout << "Nhap kich thuoc ba lo (k): ";
    cin >> k;

    cout << "Nhap so luong goi hang (n): ";
    cin >> n;

    
    const int MAX_ITEMS = 100;
    Item items[MAX_ITEMS];

    if (n > MAX_ITEMS) {
        cerr << "Loi: So luong goi hang (" << n << ") vuot qua gioi han cho phep (" << MAX_ITEMS << ").\n";
        return 1; 
    }

    cout << "Nhap khoi luong cua tung goi hang (m1 m2 ... mn): ";
    for (int i = 0; i < n; ++i) {
        items[i].id = i + 1; 
        cin >> items[i].mass;
    }

    cout << "Nhap kich thuoc cua tung goi hang (k1 k2 ... kn): ";
    for (int i = 0; i < n; ++i) {
        cin >> items[i].size;
    }

    
    int selected_item_ids[MAX_ITEMS];
    int selected_count_d = 0;
    int total_mass_p = 0;

    
    F6(k, items, n, total_mass_p, selected_item_ids, selected_count_d);

    
    cout << "Tong khoi luong cac goi hang duoc chon (p): " << total_mass_p << std::endl;

    cout << "Danh sach ID cac goi hang duoc chon (d): ";
    for (int i = 0; i < selected_count_d; ++i) {
        cout << selected_item_ids[i] << (i == selected_count_d - 1 ? "" : ", ");
    }
    cout << std::endl;

    return 0;
}


