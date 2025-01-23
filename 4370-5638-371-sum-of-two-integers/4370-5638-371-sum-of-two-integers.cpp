class Solution {
public:
    int getSum(int a, int b) 
    {
        while(b != 0) 
        {
            int carry = a & b;
            int actualCarry = carry << 1;
            a = a ^ b;
            b = actualCarry;
        }
        return a;
    }
};