#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin >> q;
    
    while(q--) {
        // Read the query (position k, 1-indexed)
        unsigned long long k;
        cin >> k;
        
        // d: number of digits of the numbers in the current block.
        // count: how many numbers have d digits (9, 90, 900, ...).
        unsigned long long d = 1, count = 9;
        
        // Determine in which block k falls.
        // Each block contributes d * count digits.
        while (k > d * count) {
            k -= d * count;
            d++;
            count *= 10;
        }
        
        // Now k is within the block of numbers that have d digits.
        // The first d-digit number is 10^(d-1).
        unsigned long long start = 1;
        for (int i = 1; i < d; i++) {
            start *= 10;
        }
        
        // Find the offset within this block.
        // (k - 1) / d gives us the 0-indexed offset (i.e. how many numbers from start).
        unsigned long long offset = (k - 1) / d;
        
        // The exact number that contains the digit.
        unsigned long long number = start + offset;
        
        // The index of the digit in 'number' (0-indexed).
        int digit_index = (k - 1) % d;
        
        // Convert the number to string to extract the desired digit.
        string numStr = to_string(number);
        char answer = numStr[digit_index];
        
        cout << answer << "\n";
    }
    
    return 0;
}
