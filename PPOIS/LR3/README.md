# Прогноз погоды — объектная модель

## Классы

| Класс | Поля | Методы | Ассоциации |
|---|---|---|---|
| Temperature | 2 | 3 | — |
| Wind | 2 | 3 | — |
| Pressure | 2 | 3 | — |
| Humidity | 2 | 2 | — |
| Precipitation | 3 | 3 | — |
| Cloudiness | 2 | 2 | — |
| Weather | 6 | 3 | Temperature, Wind, Pressure, Humidity, WeatherCondition, TimeStamp |
| TimeStamp | 2 | 3 | — |
| GeoCoordinate | 2 | 2 | — |
| Location | 3 | 2 | GeoCoordinate |
| City | 3 | 2 | Location |
| Region | 3 | 2 | City |
| Country | 3 | 2 | Region |
| Address | 3 | 2 | City |
| Sensor | 4 | 3 | TimeStamp |
| Thermometer | 1 | 1 | — |
| Barometer | 1 | 1 | — |
| Anemometer | 1 | 2 | — |
| Hygrometer | 1 | 1 | — |
| SensorNetwork | 2 | 3 | Sensor |
| CalibrationTool | 0 | 1 | — |
| DailyForecast | 5 | 3 | Temperature, TimeStamp, Precipitation, Wind |
| Forecast | 4 | 3 | Location, TimeStamp, DailyForecast |
| TrendAnalyzer | 2 | 3 | Weather |
| ProbabilityCalculator | 2 | 3 | Weather, Location |
| HistoryStorage | 2 | 3 | Weather |
| ForecastModel | 3 | 3 | Weather, Forecast |
| DataSource | 3 | 2 | TimeStamp |
| SatelliteSource | 3 | 2 | — |
| WeatherStation | 4 | 3 | Location, Sensor, DataSource |
| Human | 2 | 1 | — |
| User | 4 | 4 | Location |
| Worker | 4 | 2 | — |
| Admin | 1 | 2 | User |
| Master | 3 | 3 | WeatherStation, Sensor |
| Supervisor | 0 | 1 | — |
| Alert | 6 | 2 | Location, TimeStamp |
| AlertCriteria | 4 | 1 | Weather |
| EmailNotifier | 2 | 2 | — |
| Tower | 6 | 2 | Location, Sensor, TimeStamp, WeatherStation |
| MaintenanceTask | 4 | 1 | Tower, Master, TimeStamp |
| WeatherException | 2 | 2 | — |
| NetworkException | 2 | 1 | — |
| ApiException | 2 | 1 | — |
| ParseException | 2 | 1 | — |
| AuthException | 2 | 1 | — |
| NotFoundException | 2 | 1 | — |
| InvalidDataException | 2 | 1 | — |
| StorageException | 2 | 1 | — |
| SensorException | 2 | 1 | — |
| ForecastException | 2 | 1 | — |
| UserException | 2 | 1 | — |
| ConfigException | 2 | 1 | — |

## Исключения (12)

- WeatherException
- NetworkException
- ApiException
- ParseException
- AuthException
- NotFoundException
- InvalidDataException
- StorageException
- SensorException
- ForecastException
- UserException
- ConfigException

## Итоговая статистика

| Показатель | Значение |
|---|---|
| Классов | 56 |
| Полей | 159 |
| Поведений | 107 |
| Ассоциаций | 30 |
| Исключений | 12 |