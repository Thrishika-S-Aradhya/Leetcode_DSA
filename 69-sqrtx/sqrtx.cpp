class Solution {
public:
    int mySqrt(int x) {
        // For special cases when x is 0 or 1, return x.
        if (x == 0 || x == 1)
            return x;
        
        // Initialize the search range for the square root.
        int start = 1;
        int end = x;
        int mid = -1;
        
        while (start <= end) {
       
            mid = start + (end - start) / 2;
            
            long long square = static_cast<long long>(mid) * mid;
            
           
            if (square > x)
                end = mid - 1;
            else if (square == x)
                
                return mid;
            else
               
                start = mid + 1;
        }
        
        return static_cast<int>(std::round(end));
    }
};