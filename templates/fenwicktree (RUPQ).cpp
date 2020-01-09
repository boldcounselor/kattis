//Credit goes to Steven Halim. This is adapted from his book "Competitive Programming 3".
class FenwickTree {
    private:
        vector<int> ft;
        int LSOne(int s){
            return (s & (-s));
        }

    public: 
        //Initialises n+1 zeroes.
        FenwickTree(int n){
            ft.assign(n + 1, 0);
        }


        int rsq(int b){ // returns RSQ(1, b)
            int sum = 0;
            for (;b ; b-=LSOne(b)){
                sum += ft[b];
            }
            return sum;
        }

        int rsq(int a, int b){ // returns RSQ(a, b)
            return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
        }

        // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
        void adjust(int k, int v){ // note: n = ft.size() - 1
            for (; k<(int)ft.size(); k += LSOne(k)){
                ft[k] += v;
            }
        }
};