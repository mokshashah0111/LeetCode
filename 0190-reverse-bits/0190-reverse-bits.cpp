class Solution {
    private:
    uint32_t bitReversal(uint32_t x){
        uint32_t y=0;
        int size = 8;
        int position = size-1;

        while(position  >=0){
            y |= (x&1) <<position;
            x >>=1;
            position -=1;
        }
        return y;
    }
public:
    uint32_t reverseBits(uint32_t n) {
        vector<uint32_t>precomputed_reverse(pow(2,8));
        for(uint32_t i = 0; i<pow(2,8) ;i++){
            precomputed_reverse[i] = bitReversal(i);
        }
        int size = 8;
        int mask = 0xFF;
        return precomputed_reverse[n&mask] << (3*size) |
                precomputed_reverse[(n>>size) & mask] << (2*size) |
                precomputed_reverse[(n>>(2*size)) & mask] << size |
                precomputed_reverse[(n>>(3*size)) & mask];
    }
};