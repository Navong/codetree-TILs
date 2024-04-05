#include <iostream>
using namespace std;
int main() {
    // Please write your code here.
    int month, day, till_month, till_day;
    int elapse_day = 0;
    cin >> month >> day >> till_month >> till_day;
    int day_of_month[13] = {0, 31, 28,31,30,31,30,31,31,31,30,31,30};
    while(true){
        if (month == till_month && day == till_day)
            break;
        
        day++;
        elapse_day++;
        if (day > day_of_month[month]){
            month++;
            day = 1;
        }
    }

    cout << elapse_day;
    return 0;
}