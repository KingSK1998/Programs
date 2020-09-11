def revUtil(vector<int> &arr, int start, int end):
    while(start < end):
        swap(arr[start],arr[end]);
        start++;
        end--;

def rotateClock(vector<int> &arr, int d, int n):
    revUtil(arr, 0, d-1); 
    revUtil(arr, d, n-1);
    revUtil(arr, 0, n-1);   

if __name__ == "__main__":
    M = int(input())
    N = int(input())
    vector = []
    vector_ar = []
    arr = []
    vector < vector_ar > arr(M, vector<int>(N));
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }
    vector<ll> rotate; ll input;
    while(cin>>input) rotate.push_back(input);

    if (M==2 && N==2){
        vector<int> temp;
        for(int i=0; i<2; i++){
            temp.push_back(arr[0][i]);
        }
        for(int i=1; i>=0; i--){
            temp.push_back(arr[1][i]);
        }
        int sz = temp.size();
        rotateClock(temp, rotate[0], sz);
        int j=0;
        for(int i=0; i<2; i++){
            arr[0][i] = temp[j];
            j++;
        }
        for(int i=1; i>=0; i--){
            arr[1][i] = temp[j];
            j++;
        }
        for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
 else{
    vector<int> temp;
    for(int i=0; i<N; i++){ //1st Row
        temp.push_back(arr[0][i]);
    }
    for(int j=1; j<M; j++){ //Last column
        temp.push_back(arr[j][N-1]);
    }
    for(int i=N-2; i>=0; i--){ // last row in reverse
        temp.push_back(arr[M-1][i]);
    }
    for(int j=M-2; j>0; j--){ // last col in reverse
        temp.push_back(arr[j][0]);
        //cout<<arr[j][0]<<endl;
    }
    int sz = temp.size();
    rotateClock(temp, rotate[0], sz);

    //for(int i=0; i<sz; i++){
     //   cout<<temp[i];
    //}
    //cout<<endl;
    int m = M-2, n = N-2;
    int temp_inner[m][n];
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            temp_inner[i-1][j-1] = arr[i][j];
            //cout<<arr[i][j];
        }
    }

    //Rotate InnerMatrix - Anticlockwise
    for(int i=0; i<rotate[1]; i++){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i<j){
                    swap(temp_inner[i][j],temp_inner[j][i]);
            }
        }
         }
        for(int i=0;i<m;i++){
            reverse(temp_inner[i],temp_inner[i]+n);
            }
    }


    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            arr[i][j]=temp_inner[i-1][j-1];

        }
    }
 
    int j=0;
    for(int i=0; i<N; i++){ 
        arr[0][i]=temp[j];
        j++;
    }
    for(int i=1; i<M; i++){
        arr[i][N-1] = temp[j];
        j++;
    }
    for(int i=N-2; i>=0; i--){ 
        arr[M-1][i] = temp[j];
        j++;
    }
    for(int i=M-2; i>0; i--){ 
        arr[i][0]= temp[j];
        j++;
    }
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
 }

}