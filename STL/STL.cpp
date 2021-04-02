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

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    /**
     *
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
     * a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
     */
    cout << a.front() << endl;  // 1

    /**
     * ^ back() : returns the last element in the vector
     *
     * e.g.
     * a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
     */
    cout << a.back() << endl;  // 10

    /**
     * ^ pop_back() : pop or remove elements from a vector from the back
     */
    a.pop_back();  // a = [1, 2, 3, 4, 5, 6, 7, 8, 9]

    /**
     * ^ begin() : returns an iterator pointing to the first element in the
     * vector
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
     * ^ insert() : inserts new elements before the element at the specified
     * position
     */

    a.insert(a.begin() + 2, 5);

    /**
     * ^ erase() : removes elements from the specified position
     */
    a.erase(a.begin());

    /**
     * ^ clear() : removes all the elements of the vector container
     */
    a.clear();
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

    /**
     * ^ erase(x) : Removes the value ‘x’ from the set
     */
    st__int.erase(15);

    /**
     * ^ erase(x) : Removes the value ‘x’ from the set
     */
    st__int.erase(st__int.begin());
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
     * ^ clear() : removes all the elements of the map
     */
    mp__int__int.clear();
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
     * ^ empty() : returns whether the stack is empty or not
     */
    if (s__int.empty()) {
        cout << "our stack is empty" << endl;
    } else {
        cout << "we have some elements 🎉🎉" << endl;
    }

    /**
     * ^ push(x) : adds the element ‘x’ at the top of the stack
     */

    int x;
    cin >> x;
    s__int.push(x);

    /**
     * ^ size() : returns the number of elements in the stack
     */
    cout << s__int.size() << endl;

    /**
     *  ^ pop() : deletes the top most element of the stack
     *
     * e.g.
     * s = [1, 2, 3, 4, 5, 6]
     */

    s__int.pop();  // s = [1, 2, 3, 4, 5]

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

void learn__about__priority__queue() {
    /**
     * ^ declaring a new priority queue object
     *
     *          template
     *           |
     * * priority_queue<data_type> name;
     * ! sort descending by default
     */

    priority_queue<int> pq;  // 1 8 2 9 4 7 6 =====> 9 8 7 6 4 2 1
    priority_queue<string, vector<string>, greater<string>>
        pq__ascend;  // 1 8 2 9 4 7 6 =====> 1 2 4 6 7 8 9

    /**
     * ^ empty() : returns whether the priority queue is empty or not
     */
    if (pq.empty()) {
        cout << "our priority queue is empty" << endl;
    } else {
        cout << "we have some elements 🎉🎉" << endl;
    }

    /**
     * ^ push(x) : adds the element ‘x’ at the end of the priority queue
     */

    int x;
    cin >> x;
    pq.push(x);

    /**
     * ^ size() : returns the number of elements in the priority queue
     */
    cout << pq.size() << endl;

    /**
     *  ^ pop() : deletes the first element of the priority queue
     *
     * e.g.
     * order of adding = [1, 2, 3, 4, 5, 6]
     */
    pq.pop();  // [2, 3, 4, 5, 6]

    /**
     * ^ top() : returns a reference to the top most element of the priority
     * ^ queue
     */

    cout << pq.top() << endl;  // 1

    /**
     * ^ to clear the stack content (there is no clear function)
     */
    while (!pq.empty()) {
        int t = pq.top();
        pq.pop();
    }
}

void learn__about__stl__algorithms() {
    const int N = 100000;
    int a[N];

    sort(a, a + N);

    int n;
    vector<string> b(n);

    sort(b.rbegin(), b.rend());

    int n;
    vector<int> c(n);

    sort(c.begin(), c.end());

    /**
     * ^ binary_search() : return wether a vector has element x or not
     * ! your array should be sorted
     */
    int x;
    cin >> x;
    if (binary_search(b.begin(), b.end(), x)) {
        cout << "found" << endl;
    } else {
    }

    /**
     * ^ lower_bound() : returns an iterator pointing to the first element in
     * ^ the range which has a value not less than ‘x’
     *
     *
     * ! your array should be sorted
     */

    int x;
    cin >> x;
    auto it = lower_bound(b.begin(), b.end(), x);
    cout << *it << endl;

    int idx = distance(b.begin(), it);

    /**
     * ^ upper_bound() : returns an iterator pointing to the first element in
     * ^ the range which has a value not greater than ‘x’
     *
     *
     * ! your array should be sorted
     */
    int x;
    cin >> x;
    auto it = upper_bound(b.begin(), b.end(), x);
    cout << *it << endl;

    int idx = distance(b.begin(), it);

    /**
     * ^ reverse(start it, end it) : reverse your array / vector
     */
    reverse(a, a + N);            // Array
    reverse(b.begin(), b.end());  // Vector
}

void solve__problem__one() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int& i : a) cin >> i;
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

void solve__problem__two() {
    int n;
    cin >> n;

    map<string, int> mp;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (mp[s] > 0) {
            cout << s << mp[s] << endl;
        } else {
            cout << "OK" << endl;
        }

        mp[s]++;
        cout << s << ' ' << mp[s] << endl;
    }
}

void solve__problem__three() {
    int n, m;
    cin >> n >> m;

    map<string, string> mp;

    for (int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1.size() <= s2.size()) {
            mp[s1] = s1;
        } else {
            mp[s1] = s2;
        }
    }

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << mp[s] << " ";
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
