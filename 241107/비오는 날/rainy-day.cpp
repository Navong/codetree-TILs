#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

struct WeatherData {
    string date;
    string dayOfWeek;
    string weather;
};

// Function to compare earliest date
bool isEarlierDate(const string& date1, const string& date2){
    return date1 < date2;
}

int main(){
    int n;
    cin >> n;
    vector<WeatherData> data(n);
    
    // Read input data
    for(int i = 0; i < n; i++){
        cin >> data[i].date >> data[i].dayOfWeek >> data[i].weather;
    }

    // Find the earliest rain day
    WeatherData earliestRain = {"9999-12-31", "" , ""};
    for(const auto& entry : data){
        if(entry.weather == "Rain" && isEarlierDate(entry.date, earliestRain.date)){
            earliestRain = entry;
        }
    }

    // Print the result
    cout << earliestRain.date << " " << earliestRain.dayOfWeek << " " << earliestRain.weather << endl;
}