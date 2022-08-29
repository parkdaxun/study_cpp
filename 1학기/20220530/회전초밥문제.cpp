#include <iostream>
using namespace std;
#defin MAX_BUDGET 1000000
int n;
int m;
int price[20];
int preference[20];

int FindMaxPref_recursive(int target)
{
    int maxPref = 0;
    for(int sushi = 0; sushi<n; sushi++)
    {
        if(budget - price[sushi] >= 0)
        {
            maxPref=max(maxPref, FindMaxPref_recursive(budget-price[sushi])+preference[sushi]);
        }
    }
    return maxPref;
}



int cacke[MAX_BUDGET+1];
int FindMaxPref_repeat()
{
    cacke[0]=0;
    for(int budget=1; budget<=m; budget++)
    {
        cache[budget]=0;
        for(int sushi = 0; sushi<n; sushi++)
        {
            int targetPrice = price[sushi];
            int targetPref = preference[sushi];
            if(budget<targetPrice) continue;
            cacke[budget] = max(cacke[budget], cacke[budget-targetPrice]+targetPref);
        }
    }
    return cache[m];
}

int sw[201];
int FindMaxPref_sliding_widow()
{
    m=m/100;
    sw[0]=0;
    for(int budget=1; budget<=m; budget++)
    {
        sw[budget%201] = 0;
        for(int sushi=0; sushi<n; sushi++)
        {
            int targetPrice = price[sushi]/100;
            int targetPref = preference[sushi];
            if(budget<targetPrice) continue;
            sw[budget%201] = max(sw[budget%201], sw[(budget-targetPrice)%201]+targetPref);
        }
    }
    return sw[m%201];
}

int main() {
    
}
