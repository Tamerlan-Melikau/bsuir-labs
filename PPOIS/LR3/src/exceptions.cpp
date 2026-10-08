#include "exceptions.hpp"

WeatherException::WeatherException(std::string msg, int c) {
    message = msg;
    code = c;
}

const char* WeatherException::what() const noexcept {
    return message.c_str();
}

int WeatherException::getCode() {
    return code;
}

NetworkException::NetworkException(std::string msg, int c, std::string u, int t)
    : WeatherException(msg, c) {
    url = u;
    timeoutMs = t;
}

bool NetworkException::isTimeout() {
    return timeoutMs <= 0;
}

ApiException::ApiException(std::string msg, int c, int s, std::string a)
    : WeatherException(msg, c) {
    statusCode = s;
    apiName = a;
}

bool ApiException::isRateLimit() {
    return statusCode == 429;
}

ParseException::ParseException(std::string msg, int c, std::string r, int l)
    : WeatherException(msg, c) {
    rawData = r;
    lineNumber = l;
}

int ParseException::getPosition() {
    return lineNumber;
}

AuthException::AuthException(std::string msg, int c, std::string l, int a)
    : WeatherException(msg, c) {
    login = l;
    attempts = a;
}

bool AuthException::isBlocked() {
    return attempts >= 3;
}

NotFoundException::NotFoundException(std::string msg, int c, std::string t, std::string id)
    : WeatherException(msg, c) {
    entityType = t;
    entityId = id;
}

std::string NotFoundException::getFullMessage() {
    return entityType + " " + entityId + " not found";
}

InvalidDataException::InvalidDataException(std::string msg, int c, std::string f, std::string v)
    : WeatherException(msg, c) {
    fieldName = f;
    invalidValue = v;
}

std::string InvalidDataException::getField() {
    return fieldName;
}

StorageException::StorageException(std::string msg, int c, std::string p, std::string o)
    : WeatherException(msg, c) {
    filePath = p;
    operation = o;
}

bool StorageException::isReadOnly() {
    return operation == "write";
}

SensorException::SensorException(std::string msg, int c, std::string id, int e)
    : WeatherException(msg, c) {
    sensorId = id;
    errorCode = e;
}

bool SensorException::needsReplacement() {
    return errorCode > 100;
}

ForecastException::ForecastException(std::string msg, int c, std::string m, double conf)
    : WeatherException(msg, c) {
    modelName = m;
    confidence = conf;
}

bool ForecastException::isLowConfidence() {
    return confidence < 0.5;
}

UserException::UserException(std::string msg, int c, std::string id, std::string a)
    : WeatherException(msg, c) {
    userId = id;
    action = a;
}

std::string UserException::getUserAction() {
    return action;
}

ConfigException::ConfigException(std::string msg, int c, std::string p, std::string s)
    : WeatherException(msg, c) {
    paramName = p;
    section = s;
}

std::string ConfigException::getParam() {
    return paramName;
}