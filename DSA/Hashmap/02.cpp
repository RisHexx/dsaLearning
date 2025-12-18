#include <bits/stdc++.h>
using namespace std;
#define ll long long

template<typename V>
class Node{
    public:
    string key;
    V value;
    Node* next;

    Node(string key , V value){
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

    ~Node(){
        delete next;
    }
};

template<typename V>
class ourmap {

    public:
    Node<V>** buckets;
    int size;
    int numBuckets;

    ourmap(){
        size = 0 ;
        numBuckets = 5;
        buckets = new Node<V>*[numBuckets];

        for(int i = 0 ; i < numBuckets ; i++){
            buckets[i] = NULL;
        }
    }

    ~ourmap(){
        for(int i = 0 ; i < numBuckets ; i++){
            delete buckets[i] ;
        }
        delete [] buckets;
    }

    int getSize(){
        return size;
    }
    int getBucketIndex(string key){
        int hashcode = 0;
        int currCoff = 1;
        for(int i = key.length() - 1 ; i >= 0 ; i--){
            hashcode += key[i] * currCoff;
            hashcode = hashcode % numBuckets; // making it short
            currCoff *= 37; // random
        }
        return hashcode % numBuckets;
    }
    void insert(string key , V value){
        int bucketIndex = getBucketIndex(key);
        Node<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        Node<V>* node = new Node<V>(key , value);
        node->next = head;
        buckets[bucketIndex] = node;
        size++;
    }

    V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        Node<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    V remove(string key){
        int bucketIndex = getBucketIndex(key);
        Node<V>* head = buckets[bucketIndex];
        Node<V>* prev = NULL;
        while(head != NULL){
            if(head->key == key){
                if(prev == NULL){
                    buckets[bucketIndex] = head->next;
                }else{
                    prev->next = head->next;
                }
                head->next = NULL; // so destructor dont delete whole LL
                V returnValue = head->value;
                delete head;
                size--;
                return returnValue;
            }
            prev = head;
            head = head->next;
        }
        return 0; // if i dont get value in LL
    }

};


int main() {
    std::ios_base::sync_with_stdio(false);
    ourmap<int>map;
    map.insert("one" , 1);
    map.insert("two" , 2);
    map.insert("three" , 3);

    cout<<map.getValue("one")<<endl;
    cout<<map.getValue("three")<<endl;
    cout<<map.getSize()<<endl;
    cout<<map.remove("one")<<endl;
    cout<<map.getValue("one")<<endl;
    cout<<map.getSize()<<endl;
    
    return 0;
}