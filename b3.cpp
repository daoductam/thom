#include <iostream>
using namespace std;

struct Job {
    int id; 
    int start_time;
    int finish_time;
};


void bubbleSortJobs(Job jobs[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            
            if (jobs[j].finish_time > jobs[j + 1].finish_time) {
                
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}


int F3(Job jobs[], int n) {
    
    bubbleSortJobs(jobs, n);

    
    int selected_job_indices[n]; 
    int selected_count = 0; 

    
    if (n > 0) {
        selected_job_indices[selected_count++] = 0; 
        int last_finish_time = jobs[0].finish_time; 

        
        for (int i = 1; i < n; ++i) {
          
            if (jobs[i].start_time >= last_finish_time) {
                selected_job_indices[selected_count++] = i; 
                last_finish_time = jobs[i].finish_time; 
            }
        }
    }

    
    std::cout << "Tap cuc dai cac cong viec tuong hop la (theo ID): ";
    for (int i = 0; i < selected_count; ++i) {
       
        cout << jobs[selected_job_indices[i]].id << (i == selected_count - 1 ? "" : ", ");
    }
    cout << std::endl;

    return selected_count;
}

int main() {
   
    int n; 

    cout << "Nhap so luong cong viec (n): ";
    cin >> n;

  
    const int MAX_JOBS = 100; 
    Job jobs[MAX_JOBS];

    if (n > MAX_JOBS) {
        cerr << "Loi: So luong cong viec (" << n << ") vuot qua gioi han cho phep (" << MAX_JOBS << ").\n";
        return 1; 
    }

    cout << "Nhap thoi diem bat dau cua tung cong viec (s1 s2 ... sn): ";
    for (int i = 0; i < n; ++i) {
        jobs[i].id = i + 1; 
        cin >> jobs[i].start_time;
    }

    cout << "Nhap thoi diem ket thuc cua tung cong viec (f1 f2 ... fn): ";
    for (int i = 0; i < n; ++i) {
        cin >> jobs[i].finish_time;
    }

    
    int max_compatible_jobs_count = F3(jobs, n);

    cout << "So luong cong viec toi da trong tap tuong hop la: " << max_compatible_jobs_count << std::endl;

    return 0;
}