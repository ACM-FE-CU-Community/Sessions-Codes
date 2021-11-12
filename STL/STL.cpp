// Author : Abdallah Hemdan
#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using ld = long double;

void learn__about__vectors() {
    /**
     * ^ declare an array with fixed size n
     *            template
     *             |
     * * vector<data_type> name
     */

    int n = 4;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    /**
     * ^ fancy way of reading vector data
     */
    for (int& i : a) {
        cin >> i;
    }

    /**
     * ^ declare an vector with dynamic size
     */
    vector<int> b;

    /**
     * ^ push_back() : push the elements into a vector from the back
     */
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        b.push_back(x);
    }

    /**
     * ^ pop_back() : pop or remove elements from a vector from the back
     */
    a.pop_back();  // a = [1, 2, 3]

    /**
     * ^ size() : returns the number of elements in the vector
     */
    cout << a.size() << endl;

    /**
     * ^ empty : returns whether the container is empty
     */
    if (a.empty() == true) {
        cout << "our vector is empty" << endl;
    } else {
        cout << "we have some elements 🎉🎉" << endl;
    }

    /**
     * ^ front() : returns the first element in the vector
     *
     * e.g.
     * a = [1, 2, 3, 4]
     */
    cout << a.front() << endl;  // 1

    /**
     * ^ back() : returns the last element in the vector
     *
     * e.g.
     * a = [1, 2, 3, 4]
     */
    cout << a.back() << endl;  // 10

    /**
     * ^ begin() : returns an iterator pointing to the first element in the vector
     */
    auto it = a.begin();
    cout << *it << endl;  // access its value

    /**
     * ^ end() : returns an iterator pointing to the theoretical element that
     * follows the last element in the vector
     */
    for (auto i = a.begin(); i != a.end(); ++i) {
        cout << *i << " ";
    }

    /**
     * ^ erase() : removes elements from the specified position
     */
    a.erase(a.begin() + i);

    /**
     * ^ clear() : removes all the elements of the vector container
     */
    a.clear();
}

void learn__about__stacks() {
    /**
     * ^ declaring a new stack object
     *
     *          template
     *           |
     * * stack<data_type> name;
     */
    stack<int> s__int;
    stack<double> s__double;

    /**
     * ^ push(x) : adds the element ‘x’ at the top of the stack
     */

    int x;
    cin >> x;
    s__int.push(x);

     /**
     *  ^ pop() : deletes the top most element of the stack
     *
     * e.g.
     * s = [1, 2, 3, 4, 5, 6]
     */

    s__int.pop();  // s = [1, 2, 3, 4, 5]

    /**
     * ^ size() : returns the number of elements in the stack
     */
    cout << s__int.size() << endl;

    /**
     * ^ empty() : returns whether the stack is empty or not
     */
    if (s__int.empty()) {
        cout << "our stack is empty" << endl;
    } else {
        cout << "we have some elements 🎉🎉" << endl;
    }

    /**
     * ^ top() : returns a reference to the top most element of the stack
     */

    cout << s__int.top() << endl;  // 5

    /**
     * ^ to clear the stack content (there is no clear function)
     */
    while (!s__int.empty()) {
        int t = s__int.top();
        s__int.pop();
    }
}

void learn__about__queues() {
    /**
     * ^ declaring a new queue object
     *         template
     *           |
     * * queue<data_type> name;
     */

    queue<int> q__int;
    queue<double> q__double;

    /**
     *
     * ^ push(x) : adds the element ‘x’ at the end of the queue
     */
    int x;
    cin >> x;
    q__int.push(x);

    /**
     *
     * ^ pop() : deletes the first element of the queue.
     *
     * ! before
     * q__int : [1, 2, 3, 4, 5, 6, 7]
     *           |
     *        start
     *
     * * after
     * q__int : [2, 3, 4, 5, 6, 7]
     *           |
     *         start
     */
    q__int.pop();

    /**
     * ^ empty() : returns whether the queue is empty
     */
    if (q__int.empty()) {
        cout << "our queue is empty" << endl;
    } else {
        cout << "we have some elements 🎉🎉" << endl;
    }

    /**
     * ^ size() : returns the number of elements in the queue
     */
    cout << q__int.size() << endl;

    /**
     * ^ front() : returns the first element of the queue
     */
    cout << q__int.front() << endl;

    /**
     * ^ back() : returns the last element of the queue
     */
    cout << q__int.back() << endl;
}

void learn__about__sets() {
    /**
     * ^ declaring a new set object
     *
     *          template
     *           |
     * * set<data_type, function__optional> name;
     */
    set<int> st__int;
    set<double> st_double;
    set<int, greater<int>> st__int__greater;

    /**
     * ^ insert(x) : adds a new element ‘x’ to the set
     */
    int x;
    cin >> x;
    st__int.insert(x);

    /**
     * ^ erase(x) : Removes the value ‘x’ from the set
     */
    st__int.erase(15);

    /**
     * ^ erase(x) : Removes the value ‘x’ from the set
     */
    st__int.erase(st__int.begin());

    /**
     * ^ empty() : returns whether the set is empty
     */
    if (st__int.empty()) {
        cout << "our set is empty" << endl;
    } else {
        cout << "we have some elements 🎉🎉" << endl;
    }

    /**
     * ^ size() : returns the number of elements in the set
     */
    cout << st__int.size() << endl;

    /**
     * ^ begin() : returns an iterator pointing to the first element in the set
     */
    auto it = st__int.begin();
    cout << *it << endl;  // access its value

    /**
     * ^ end() : returns an iterator pointing to the theoretical element that
     * ^ follows the last element in the set
     *
     */
    for (auto i = st__int.begin(); i != st__int.end(); ++i) {
        cout << *i << " ";
    }

    /**
     * ^ easy way to iterator over set
     */

    for (auto it : st__int) {
        cout << it << endl;
    }
}

void learn__about__maps() {
    /**
     * ^ declaring a new map object
     *
     *          template          template
     *           |                 |
     * * map<key_data_type, value_data_type> name;
     */
    map<int, int> mp__int__int;
    map<int, double> mp__int__double;
    map<int, vector<int>> mp__int__vector;
    map<int, set<int>> mp__int__vector;
    map<string, int> mp__string__int;

    /**
     * ^ insert(make_pair(key, value)) : adds a new element pair <key, value> to
     * ^ the map
     */
    int k, v;
    cin >> k >> v;
    mp__int__int.insert(make_pair(k, v));
    mp__int__int.insert({k, v});

    /**
     * ? alternative way to add key-value pair
     */
    mp__int__int[k] = v;
    mp__string__int["Hemdan"] = 22;

    /**
     * ^ size() : returns the number of elements in the map
     */
    cout << mp__int__int.size() << endl;

    /**
     * ^ empty() : returns whether the map is empty
     */
    if (mp__int__int.empty()) {
        cout << "our map is empty" << endl;
    } else {
        cout << "we have some elements 🎉🎉" << endl;
    }

    /**
     * ^ begin() : returns an iterator pointing to the first element in the map
     */

    auto it = mp__int__int.begin();

    cout << it->first << endl;   // access its key
    cout << it->second << endl;  // access its value

    /**
     * ^ end() : returns an iterator pointing to the theoretical element that
     * ^ follows the last element in the map
     *
     */
    for (auto it = mp__int__int.begin(); it != mp__int__int.end(); ++it) {
        cout << it->first << endl;   // access its key
        cout << it->second << endl;  // access its key
    }

    for (auto it : mp__int__int) {
        cout << it.first << endl;
        cout << it.second << endl;
    }

    /**
     * ^ clear() : removes all the elements of the map
     */
    mp__int__int.clear();
}

void learn__about__stl__algorithms() {
     /**
     * ^ sort(start it, end it) : sort your array / vector
     */
    const int N = 100000;
    int a[N];

    sort(a, a + N);

    int n;
    vector<string> b(n);

    sort(b.begin(), b.end());
    sort(b.rbegin(), b.rend());

    /**
     * ^ reverse(start it, end it) : reverse your array / vector
     */
    reverse(a, a + N);            // Array
    reverse(b.begin(), b.end());  // Vector
}

void solve__problem__1() {
    // https://codeforces.com/group/zvsr84He8w/contest/315331/problem/A

    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i =0 ; i< n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (auto i : arr) {
        cout << i << ' ';
    }
}

void solve__problem__2() {
    // Link: https://codeforces.com/group/k43ChfKeWS/contest/353135/problem/C
    int n, k;
    cin >> n >> k;

    map<int, int> freq;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        freq[x] = i + 1;
    }

    if (freq.size() >= k) {
        cout << "YES" << endl;
        
        auto it = freq.begin();
        for (int i = 0; i < k; i++)
            cout << (it++->second) << ' ';
    } else {
        cout << "NO";
    }
}

void solve__problem__3() {
    // https://codeforces.com/group/zvsr84He8w/contest/315331/problem/B
    int n;
    cin >> n;

    string s;
    map<string, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (freq[s] == 0) {// freq.count(s)
            cout << "OK" << endl;
            freq[s] = 1;
        } else {
            cout << s << freq[s]++ << endl;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("In.txt", "r", stdin);
    freopen("Out.txt", "w", stdout);
#else
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
#endif
    learn__about__vectors();
    learn__about__queues();
    learn__about__sets();
    learn__about__maps();
    learn__about__stacks();
    learn__about__priority__queue();
    learn__about__stl__algorithms();
    solve__problem__one();
    solve__problem__two();
    solve__problem__three();
}
