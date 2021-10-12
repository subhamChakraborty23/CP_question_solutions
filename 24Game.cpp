/*
You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.

Example 1:
Input: [4, 1, 8, 7]
Output: True
Explanation: (8-4) * (7-1) = 24
Example 2:
Input: [1, 2, 1, 2]
Output: False
Note:
The division operator / represents real division, not integer division. For example, 4 / (1 - 2/3) = 12.
Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.
*/
//Solution : #leetcode: 679
class solution{
    public:
        vector<double> util(vector<double> a,vector<double> b){
                vector<double> r;
                for(int i=0;i<a.size();i++){
                    for(int j=0;j<b.size();j++){
                        r.push_back(a[i]+b[j]);
                        r.push_back(a[i]*b[j]);
                        r.push_back(a[i]/b[j]);
                        r.push_back(a[i]-b[j]);
                        r.push_back(b[j]/a[i]);
                        r.push_back(b[j]-a[i]);
                    }
                }
                return r;
            }
            bool judgePoint24(vector<int>& n) {
                double epsilon=pow(10,-6);
                vector<double> a,b,c,x,y,z;
                bool f;
                for(int i=0;i<3;i++){
                    for(int j=i+1;j<4;j++){
                        a=util({(double)n[i]},{(double)n[j]});
                        f=true;
                        for(int k=0;k<4;k++){
                            if(k!=i&&k!=j){
                                if(f){
                                    b={(double)n[k]};
                                    f=false;
                                }
                                else c={(double)n[k]};
                            }
                        }
                        x=util(a,util(b,c));
                        y=util(util(a,b),c);
                        z=util(util(a,c),b);
                        for(int l=0;l<x.size();l++){
                            if(abs(x[l]-24)<epsilon)return true;
                        }
                        for(int l=0;l<y.size();l++){
                            if(abs(y[l]-24)<epsilon)return true;
                        }
                        for(int l=0;l<z.size();l++){
                            if(abs(z[l]-24)<epsilon)return true;
                        }                
                    }
                }
                return false;
            }
};