#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double
#define en endl
#define all(x) x.begin(),x.end()
#define f(i,from,to) for(ll i=from;i<to;i++)
#define fe(i,from,to) for(ll i=from;i<=to;i++)
#define fre(i,from,to) for(ll i=from;i>=to;i--)
#define fr(i,from,to) for(ll i=from;i>to;i--)
#define pb(x) push_back(x)
#define mx(v) *max_element(v.begin(), v.end())
#define mn(v) *min_element(v.begin(), v.end())
#define vi vector<ll>
#define vip vector<pair<ll,ll>>

// this whole implementation is for max heap
class Heap{
    public:
    int arr[100];
    int size;

    Heap(){
        size=0;
        arr[0]=-1;
    }
    // Tc:  O(logN)
    void insert(int val){
        size++;
        int index=size;
        arr[index]=val;

        // take val to it's correct position
        while(index>1 ){

            int parent=index/2;

            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }else{
                return;
            }
        }
    }

    // TC: O(logn)
    void deletion(){ // deletion is always for root node
        if(size==0){
            cout<<"Nothing to delete";return;
        }

        // copy root node with last leaf node from right and delete last leaf node 
        arr[1]=arr[size];
        size--;

        // take root node to it's correct position
        int i=1;
        while(i<size){
            int leftchild=2*i;
            int rightchild=2*i+1;

            if(leftchild<size && arr[i]<arr[leftchild]){
                swap(arr[i],arr[leftchild]);
                i=leftchild;
            }else if(rightchild<size && arr[i]<arr[rightchild]){
                swap(arr[i],arr[rightchild]);
                i=rightchild;
            }else{
                return;
            }
        }

    }

    // heapify - since leaf node itself is heap so we dont' need to process them and they lie in range from n/2+1 to n 
    // hence we need to modify between 1 to n/2

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<' ';
        }
        cout<<en;
    }

};

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<=n && arr[largest]<arr[left]) largest=left;
    if(right<=n && arr[largest]<arr[right]) largest=right;

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}


// TC: O(NlogN)
void heapSort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,size,1);
    }
}

int main()
{

    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(60);
    h.insert(70);

    h.deletion();
    h.print();
    // heap creation
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,6,i);
    }
    for(int i=1;i<=n;i++) cout<<arr[i]<<' ';
    cout<<en;
    // heapsort
    heapSort(arr,n);
    for(int i=1;i<=n;i++) cout<<arr[i]<<' ';
    cout<<en;

    return 0;
}