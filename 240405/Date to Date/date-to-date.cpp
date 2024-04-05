#include <iostream>
using namespace std;
int main() {
    // Please write your code here.
    int month, day, till_month, till_day;
    int elapse_day = 0;
    cin >> month >> day >> till_month >> till_day;
    int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //                           1. 2. 3. 4. 5. 6. 7. 8. 9. 10. 11. 12. 
    while(true){
        if (month == till_month && day == till_day)
            break;

        elapse_day++;
        day++;

        if (day > num_of_days[month]){
            month++;
            day = 1;
        }
    }

    cout << elapse_day+1;
    return 0;
}