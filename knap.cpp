#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Knap {
public:
    int profit;
    int value;

    Knap(int profit, int value) {
        this->profit = profit;
        this->value = value;
    }
};

bool compare(Knap a, Knap b) {
    return (double)a.profit / a.value > (double)b.profit / b.value;
}

int main() {
    vector<int> profit = {25, 24, 15};
    vector<int> value = {18, 15, 10};
    
    vector<double> part(profit.size(), 0);  
    
    vector<Knap> knap;
    for (int i = 0; i < profit.size(); i++) {
        knap.push_back(Knap(profit[i], value[i]));
    }

    sort(knap.begin(), knap.end(), compare);

    int W = 20; 
    double maxprofit = 0; 
    
    

    for (int i = 0; i < knap.size(); i++) {
        if (knap[i].value <= W) {

            W -= knap[i].value;
            part[i] = 1;
            maxprofit += knap[i].profit;
        } else {
            
            double fraction = (double)W / knap[i].value;
            maxprofit += knap[i].profit * fraction;
            part[i]=fraction;
            W = 0; 
            break;
        }
    }
    
    cout<<"Max Profit "<<" "<<maxprofit<<endl;
   
   for(int i=0;i<part.size();i++){
       cout<<part[i]<<endl;
   }

  
    

    return 0;
}
