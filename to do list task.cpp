#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

class Location {
public:
    string name;
    double latitude, longitude;

    Location(const string& name, double lat, double lon) : name(name), latitude(lat), longitude(lon) {}
};

class LocationManager {
    vector<Location> locations;
public:
    void addLocation(const Location& loc) { locations.push_back(loc); }
    void removeLocation(const string& name) {
        locations.erase(remove_if(locations.begin(), locations.end(), [&name](const Location& loc) { return loc.name == name; }), locations.end());
    }
    void listLocations() const {
        for (const auto& loc : locations) cout << "Name: " << loc.name << ", Latitude: " << loc.latitude << ", Longitude: " << loc.longitude << endl;
    }
};

class WeatherVariable {
public:
    string name;
    double value;

    WeatherVariable(const string& name, double value) : name(name), value(value) {}
};

class WeatherVariableManager {
    vector<WeatherVariable> variables;
public:
    void addVariable(const WeatherVariable& var) { variables.push_back(var); }
    void listVariables() const {
        for (const auto& var : variables) cout << "Variable: " << var.name << ", Value: " << var.value << endl;
    }
};

class WeatherForecastingSystem {
public:
    void fetchWeatherForecast(const Location& loc) { cout << "Fetching weather forecast for " << loc.name << "..." << endl; }
    void displayWeatherForecast() { cout << "Displaying weather forecast..." << endl; }
};

class HistoricalWeatherSystem {
public:
    void fetchHistoricalData(const Location& loc) { cout << "Fetching historical weather data for " << loc.name << "..." << endl; }
    void displayHistoricalData() { cout << "Displaying historical weather data..." << endl; }
};

class AirQualityForecastingSystem {
public:
    void fetchAirQualityData(const Location& loc) { cout << "Fetching air quality data for " << loc.name << "..." << endl; }
    void displayAirQualityData() { cout << "Displaying air quality data..." << endl; }
};

class DataExporter {
public:
    void exportToCSV(const vector<WeatherVariable>& data, const string& filename) {
        ofstream file(filename);
        for (const auto& var : data) file << var.name << "," << var.value << "\n";
        file.close();
    }

    void exportToJSON(const vector<WeatherVariable>& data, const string& filename) {
        ofstream file(filename);
        file << "{\n";
        for (size_t i = 0; i < data.size(); ++i) {
            file << "  \"" << data[i].name << "\": " << data[i].value;
            if (i < data.size() - 1) file << ",";
            file << "\n";
        }
        file << "}\n";
        file.close();
    }
};

int main() {
    LocationManager locManager;
    WeatherVariableManager varManager;
    WeatherForecastingSystem weatherSystem;
    HistoricalWeatherSystem histSystem;
    AirQualityForecastingSystem airQualitySystem;
    DataExporter dataExporter;

    locManager.addLocation(Location("New York", 40.7128, -74.0060));
    locManager.addLocation(Location("Los Angeles", 34.0522, -118.2437));

    cout << "Locations:" << endl;
    locManager.listLocations();

    varManager.addVariable(WeatherVariable("Temperature", 22.5));
    varManager.addVariable(WeatherVariable("Wind Speed", 15.0));

    cout << "\nWeather Variables:" << endl;
    varManager.listVariables();

    cout << "\nWeather Forecast:" << endl;
    weatherSystem.fetchWeatherForecast(Location("New York", 40.7128, -74.0060));
    weatherSystem.displayWeatherForecast();

    cout << "\nHistorical Weather Data:" << endl;
    histSystem.fetchHistoricalData(Location("Los Angeles", 34.0522, -118.2437));
    histSystem.displayHistoricalData();

    cout << "\nAir Quality Data:" << endl;
    airQualitySystem.fetchAirQualityData(Location("New York", 40.7128, -74.0060));
    airQualitySystem.displayAirQualityData();

    cout << "\nExporting Data:" << endl;
    dataExporter.exportToCSV(varManager.variables, "weather_data.csv");
    dataExporter.exportToJSON(varManager.variables, "weather_data.json");
    cout << "Data exported to weather_data.csv and weather_data.json" << endl;

    return 0;
}

