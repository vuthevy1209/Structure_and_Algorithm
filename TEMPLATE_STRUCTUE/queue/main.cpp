#include "Queue.h"


int main(){
    freopen("/Users/vuthevy1209/Documents/C++/input.rtf", "r", stdin);
    freopen("/Users/vuthevy1209/Documents/C++/output.rtf", "w", stdout);
    queue<int> a;
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        int x; cin >> x;
        a.push(x);
    }
    while(!a.empty()){
        cout << a.front() << " ";
        a.pop();
    }
}




