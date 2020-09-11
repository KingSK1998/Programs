#include<bits/stdc++.h>

using namespace std;

struct Workshop
{
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops
{
    int n;
    Workshop *x = new Workshop[n];
};

Available_Workshops* initialize(int start_time[], int duration[], int n){
    Available_Workshops* available = new Available_Workshops();
    available->n = n;
    for (int i = 0; i < n; i++)
    {
        Workshop w;
        w.start_time = start_time[i];
        w.duration = duration[i];
        w.end_time = start_time[i] + duration[i];
        available->x[i] = w;
    }
    return available;
}

int CalculateMaxWorkshops(Available_Workshops* ptr){
    int m = 1;
    int n = ptr->n;
    Workshop* ws = ptr->x;
    sort(ws, ws+n);
    Workshop prev = ws[0];
    for (int i = 1; i < n; i++)
    {
        Workshop current = ws[i];
        if(current.start_time >= prev.end_time){
            m++;
            prev = current;
        }
    }
    return m;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}