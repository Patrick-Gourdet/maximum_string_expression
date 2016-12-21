#include <iostream>
#include <set>
#include <cassert>
#include <vector>
#include <cstring>
#include <climits>
#include <cmath>

using std::vector;
using std::string;
using std::max;
using std::min;
std::vector<string> stringPortions,stringFac;
int permutation;
char opMult = '*',opAdd = '+';

long long eval(long long a, long long b,char op) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else {
        assert(0);
    }
}

long long get_maximum_value() {
    int numOfnum = stringPortions.size();

    long long minArray[numOfnum][numOfnum];
    long long maxArray[numOfnum][numOfnum];
    memset(minArray,0,sizeof(minArray)); // initialize to 0
    memset(maxArray,0,sizeof(maxArray));

    for (int i = 0; i < numOfnum; i++){

            minArray[i][i] = std::stoll(stringPortions[i]);
            maxArray[i][i] = std::stoll(stringPortions[i]);

        }

    for (int s = 0; s < numOfnum - 1; s++)
    {
        for (int i = 0; i < numOfnum - s - 1; i++)
        {
            int j = i + s + 1;
            long long minVal = LLONG_MAX;
            long long maxVal = LLONG_MIN;
            long long minVal1 = LLONG_MAX;
            long long maxVal1 = LLONG_MIN;
            long long resultMin = LLONG_MIN;
            long long resultMax = LLONG_MAX;
            long long a = 0,a1=0;
            long long b = 0,b1=0;
            long long c = 0,c1=0;
            long long d = 0,d1=0;
            // find the minimum and maximum values for the expression
            // between the ith number and jth number
            for (int k = i; k < j; k++ )
            {


                a = eval(minArray[i][k],minArray[k + 1][j],opAdd);
                b = eval(minArray[i][k],maxArray[k + 1][j],opAdd);
                a1 = eval(minArray[i][k],minArray[k + 1][j],opMult);
                b1 = eval(minArray[i][k],maxArray[k + 1][j],opMult);
                c = eval(maxArray[i][k],minArray[k + 1][j],opMult);
                d = eval(maxArray[i][k],maxArray[k + 1][j],opMult);
                c1 = eval(maxArray[i][k],minArray[k + 1][j],opAdd);
                d1 = eval(maxArray[i][k],maxArray[k + 1][j],opAdd);


/*                if(a >= b && a >= c && a >= d && a >= a1 && a >= b1 && a >= c1 && a >= d1)
                if(b >= a && b >= c && b >= d && b >= a1 && b >= b1 && b >= c1 && b >= d1)
                    std::cout << minArray[i][k]<< opAdd <<maxArray[k + 1][j]<< std::endl;;
                if(c >= a && c >= b && c >= d && c >= a1 && c >= b1 && c >= c1 && c >= d1)
                    std::cout << maxArray[i][k]<< opAdd <<minArray[k + 1][j]<< std::endl;;*/
                minVal1 = min(minVal1,min(a1,min(b1,min(c1,d1))));
                maxVal1 = max(maxVal1,max(a1,max(b1,max(c1,d1))));
                minVal = min(minVal,min(a,min(b,min(c,d))));
                maxVal = max(maxVal,max(a,max(b,max(c,d))));

                resultMax=max(maxVal1,maxVal);
                resultMin=min(minVal1,minVal);
            }
            minArray[i][j] = resultMin;
            maxArray[i][j] = resultMax;
        }

    }
    return maxArray[0][numOfnum - 1];
}

int main() {
    string temp;
    int n;
    long long max = 0;

    std::cin >> n;

    permutation = pow(2,n-1);
    stringFac.resize(permutation);

    for(int i = 0;i < n;i++){
        std::cin >> temp;
        stringPortions.push_back(temp);
    }
    max = get_maximum_value();

    std::cout << max<< std::endl;
    return 0;
}

