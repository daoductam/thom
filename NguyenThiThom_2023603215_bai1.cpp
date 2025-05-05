#include<iostream>

using namespace std;

void sapXep(int a[], int n){
	for (int i=0; i<n-1; i++){
		int max=i;
		for(int j=i+1; j<n; j++){
			if(a[j]>a[max])
			max=j;
		}
		int tmp=a[i];
		a[i]=a[max];
		a[max]=tmp;
	}
}

int doiTien(int c[], int n, int m){
	int p=0;
	for(int i=0; i<n; i++){
		while(m>=c[i]){
			m-=c[i];
			p++;
		}
	}
	if(m>0) return -1;
	return p;
}

int main(){
	int n, m;
	cout<<"Nhap so loai xu n: ";
	cin>>n;
	
	int c[n];
	cout<<"Nhap cac menh gia xu: ";
	for(int i=0; i<n; i++){
		cin>>c[i];
	}
	cout<<"Nhap tong so tien m: ";
	cin>>m;
	
	sapXep(c, n);
	int ketQua=doiTien(c, n, m);
	
	if(ketQua != -1){
		cout<<"So dong xu it nhat can lay: "<<ketQua<<endl;
	}
	else{
		cout<<"Khong the doi duoc!";
	}
	return 0;
}