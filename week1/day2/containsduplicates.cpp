class Solution {
public:
    bool hasDuplicates(int arr[5]) {
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (arr[i] == arr[j]) {
                    cout << "true" << endl;
                    return true;
                }
            }
        }
        return false;
    }
};
