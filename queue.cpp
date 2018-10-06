#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    for(int i=0; i<10;i++)
    {
        cout << "enqueuing " << i << endl;
        q.push(i);
    }
    cout << "size of my queue " << q.size() << endl;
    
    while(!q.empty()) {
        cout << "dequeing " << q.front() << endl;
        q.pop();
    }

}
