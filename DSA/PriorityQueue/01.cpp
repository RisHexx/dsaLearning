#include <bits/stdc++.h>
using namespace std;
#define ll long long

class priorityQueue{
    
    public:
    vector<int>pq;

    bool isEmpty(){
        return pq.size() == 0;
    }

    int getSize(){
        return pq.size();
    }

    int getMin(){
        if(isEmpty()) return 0;
        return pq[0];
    }

    void insert(int data){
        pq.push_back(data);
        int childIndex = pq.size() - 1;
        while(childIndex > 0){
            int parentIndex = (childIndex - 1) / 2;
            if(pq[childIndex] < pq[parentIndex]){
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[childIndex];
            pq[childIndex] = temp;
            }else{
                break;
            }
            childIndex = parentIndex;
        }
    }
    // heapsort
    
    int removeMin(){
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;
        int leftIndex = (2 * parentIndex) + 1;
        int rightIndex = (2 * parentIndex) + 2;

        while(leftIndex < pq.size()){
            int minIndex = parentIndex;
            if(pq[leftIndex] < pq[parentIndex]){
                minIndex = leftIndex;
            }
            if(rightIndex < pq.size() && pq[rightIndex] < pq[parentIndex]){
                minIndex = rightIndex;
            }
            if(minIndex == parentIndex){
                break;
            }
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[minIndex];
            pq[minIndex] = temp;

            parentIndex = minIndex;
            leftIndex = (2 * parentIndex) + 1;
            rightIndex = (2 * parentIndex) + 2;
        }




        return ans;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    priorityQueue pq1;
    pq1.insert(10);
    pq1.insert(50);
    pq1.insert(20);
    pq1.insert(60);
    pq1.insert(100);
    pq1.insert(25);

    for(int i = 0 ; i < pq1.getSize() ; i++){
        cout<<pq1.pq[i]<<" ";
    }
    
    return 0;
}