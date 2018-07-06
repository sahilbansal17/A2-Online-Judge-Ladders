#include <bits/stdc++.h>
using namespace std;

const int OR = 0, XOR = 1, MAX_SIZE = 1e6;

int tree[3*MAX_SIZE];
int element[MAX_SIZE];

// display the elements in the tree
void display(int node, int start, int end){
    printf("i = %d, node = %d\n", node, tree[node]);
    if(start == end){
        return;
    }

    int mid = (start + end)/2;
    display(2*node, start, mid);
    display(2*node + 1, mid + 1, end);
}

// perform the required operation on a and b
int perform(int a, int operation, int b){
    switch(operation){
        case OR  :  return (a|b);
        case XOR :  return (a^b);
    }
    return -1;
}

// switch the operation index
int other(int operation){
    return (operation ^ 1);
}

// build the tree 
void build(int node, int start, int end, int operation)
{
    if(start == end)
    {
        tree[node] = element[start];
        return;
    }

    int mid = (start + end)/2;

    build(2*node, start, mid, other(operation));
    build(2*node + 1, mid + 1, end, other(operation));

    tree[node] = perform(tree[2*node], operation, tree[2*node + 1]);
}

// update operation on the tree
void update(int node, int start, int end, int index, int value, int operation){
    if(start == end){
        tree[node] = element[index] = value;
        return;
    }

    int mid = (start + end)/2;

    if(index >= start && index <= mid){
        update(2*node, start, mid, index, value, other(operation));
    }
    else if(index > mid && index <= end){
        update(2*node + 1, mid + 1, end, index, value, other(operation));
    }

    tree[node] = perform(tree[2*node], operation, tree[2*node + 1]);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

    int n, no_of_queries;
    cin >> n >> no_of_queries;

    int no_of_elements = (1 << n);
    for(int i = 1; i <= no_of_elements; i++){
        cin >> element[i];
    }

    int first_operation = (n%2 == 0 ? XOR : OR);
    build(1, 1, no_of_elements, first_operation);
    // display(1,1, no_of_elements);

    while(no_of_queries--){
        int index, value;
        cin >> index >> value;

        update(1, 1, no_of_elements, index, value, first_operation);
        printf("%d\n", tree[1]);
    }
    return 0;
}