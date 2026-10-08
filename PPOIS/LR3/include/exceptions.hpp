#pragma once
#include <string>
#include <exception>

class WeatherException : public std::exception {
protected:
    std::string message;
    int code;
public:
    WeatherException(std::string msg, int c);
    const char* what() const noexcept override;
    int getCode();
};

class NetworkException : public WeatherException {
private:
    std::string url;
    int timeoutMs;
public:
    NetworkException(std::string msg, int c, std::string u, int t);
    bool isTimeout();
};

class ApiException : public WeatherException {
private:
    int statusCode;
    std::string apiName;
public:
    ApiException(std::string msg, int c, int s, std::string a);
    bool isRateLimit();
};

class ParseException : public WeatherException {
private:
    std::string rawData;
    int lineNumber;
public:
    ParseException(std::string msg, int c, std::string r, int l);
    int getPosition();
};

class AuthException : public WeatherException {
private:
    std::string login;
    int attempts;
public:
    AuthException(std::string msg, int c, std::string l, int a);
    bool isBlocked();
};

class NotFoundException : public WeatherException {
private:
    std::string entityType;
    std::string entityId;
public:
    NotFoundException(std::string msg, int c, std::string t, std::string id);
    std::string getFullMessage();
};

class InvalidDataException : public WeatherException {
private:
    std::string fieldName;
    std::string invalidValue;
public:
    InvalidDataException(std::string msg, int c, std::string f, std::string v);
    std::string getField();
};

class StorageException : public WeatherException {
private:
    std::string filePath;
    std::string operation;
public:
    StorageException(std::string msg, int c, std::string p, std::string o);
    bool isReadOnly();
};

class SensorException : public WeatherException {
private:
    std::string sensorId;
    int errorCode;
public:
    SensorException(std::string msg, int c, std::string id, int e);
    bool needsReplacement();
};

class ForecastException : public WeatherException {
private:
    std::string modelName;
    double confidence;
public:
    ForecastException(std::string msg, int c, std::string m, double conf);
    bool isLowConfidence();
};

class UserException : public WeatherException {
private:
    std::string userId;
    std::string action;
public:
    UserException(std::string msg, int c, std::string id, std::string a);
    std::string getUserAction();
};

class ConfigException : public WeatherException {
private:
    std::string paramName;
    std::string section;
public:
    ConfigException(std::string msg, int c, std::string p, std::string s);
    std::string getParam();
};