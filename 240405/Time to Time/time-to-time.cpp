#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int hour, mins, end_hour, end_mins;
    int elapsed_time = 0;
    cin >> hour >> mins >> end_hour >> end_mins;
    while(true){
        if(hour == end_hour && mins == end_mins)
            break;
        
        elapsed_time++;
        mins++;

        if(mins == 60){
            hour++;
            mins = 0;
        }
    }
    cout << elapsed_time;
    return 0;
}