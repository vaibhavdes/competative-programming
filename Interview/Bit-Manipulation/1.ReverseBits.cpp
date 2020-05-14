unsigned int reverse(unsigned int A) {
    unsigned int res=0;
    int i,digit;
    for(i=0;i<32;i++)
    {
        digit=(A>>i)&1;
        res=(res<<1)|digit;
    }
    return res;
}
