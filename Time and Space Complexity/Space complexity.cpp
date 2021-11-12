
// Memory Analysis
// Check if any number is repeated:    arr[i] < N

// Memory O(1) & Time O(N^2)
bool Ex8(vector<int>& arr)
{
    int N = arr.size();
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (arr[i] == arr[j]) {
                return 1;
            }
        }
    }
    return 0;
}

// Another Solution: Shows Memory & Time compromising
// Memory O(N) & Time O(N)
bool Ex8(vector<int>& arr)
{
    int N = arr.size();

    vector<bool> exist(N, 0); // Allocate N location

    for (int i = 0; i < N; ++i) {
        if (exist[arr[i]] == 1) {
            return 1;
        }
        exist[arr[i]] = 1;
    }
    return 0;
}
