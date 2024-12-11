#include "OpenMeteoWeatherService.hpp"
#include "WeatherAnalyzer.hpp"
#include "WeatherPresenter.hpp"

int main() {
    OpenMeteoWeatherService weatherService;     // Create dependency (OpenMeteoWeatherService)
    WeatherAnalyzer weather(weatherService);    // Inject dependency into WeatherAnalyzer
    WeatherPresenter presenter;

    // Esslingen University - coordinates
    double latEsslingen = 48.738;
    double lonEsslingen = 9.311;

    weather.getWeatherData(latEsslingen, lonEsslingen);
    presenter.displayWeather(weather.getWeatherInfo(), "Esslingen University");

    // Sunnyvale, California - coordinates
    double latSunnyvale = 37.3688;
    double lonSunnyvale = -122.0363;

    weather.getWeatherData(latSunnyvale, lonSunnyvale);
    presenter.displayWeather(weather.getWeatherInfo(), "Sunnyvale, California");

    return 0;
}