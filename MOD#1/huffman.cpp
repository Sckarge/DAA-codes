/*
----------TIME COMPLEXITY----------
O(nlogn)
----------ALGORITHM----------
1) Make a struct node and a comparison structure(use operator overloading)
2) A program to printcodes at the end(use the presence of letter in the leaf nodes as a differentiator)
3) HUFFMAN
    - Make a priority queue accepting nodes as elements as using struct compare as a comparator
    - Use all elements from the two input arrays to make nodes and push them in the queue
    - while (size of the queue is greater than 1):
        > make the top of the queue the left and pop it repeat this once more to get the right
        > now make a new node temp which has the letter '*' and freq = left->freq + right->freq and push it back into the queue
    -Finally call the printcode function to print the codes with the top of the queue as the root parameter
*/
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    char letter;
    int freq;
    node *left, *right;
    node(char l, int f)
    {
        letter = l;
        freq = f;
        left = NULL;
        right = NULL;
    }
} node;

struct compare
{
    bool operator()(node *left, node *right) // instead of making a function like in frac_knapsack we use operator overloading for the reason that w cannot use references as parameters in the function
    {
        return left->freq > right->freq; // an instance of operator overloading
    }
};

void printcode(node *root, string s)
{
    if (!root) // base case
    {
        return;
    }
    if (root->letter != '*') // this is to find leaf nodes
        cout << root->letter << " -> " << s << endl;
    printcode(root->left, s + "0"); // if we go left add a 0 to the code and vice versa
    printcode(root->right, s + "1");
}

void huffman(char ac[], int an[], int n)
{
    priority_queue<node *, vector<node *>, compare> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(new node(ac[i], an[i])); // When we push these letters and frequencies into the priority queue they get sorted in an ascending order
    }
    node *lft, *rgt;
    while (pq.size() > 1)
    {
        lft = pq.top(); // pop the current smallest and make it the left
        pq.pop();
        rgt = pq.top(); // the second smallest becomes the right
        pq.pop();
        node *temp = new node('*', lft->freq + rgt->freq); // now we combine the two and the letter is * so as to identify non-leaf nodes
        temp->left = lft;
        temp->right = rgt;
        pq.push(temp); // this node is pushed again into the queue
    }
    printcode(pq.top(), " "); // we use the printcode function to print the code for this letter
}

int main()
{
    int n;
    cout << "Number of distinct characters in the text ";
    cin >> n;
    char *c_arr = new char[n];
    int *freq = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Character " << i + 1 << endl;
        cout << "Character: ";
        cin >> c_arr[i];
        cout << "Frequency: ";
        cin >> freq[i];
    }
    // char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    // int freq[] = {5, 9, 12, 13, 16, 45};
    // int n = 5;
    huffman(c_arr, freq, n);
}