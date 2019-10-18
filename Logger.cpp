//
// Created by edge on 2019-10-18.
//

#include "Logger.h"

std::map<std::string, Logger *> Logger::instance;

Logger::Logger() {
    this->loggerSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("BigBangRemake.log");
}

Logger::Logger(std::string loggerName) {
    auto logger = std::make_shared<spdlog::logger>(loggerName, loggerSink);
}

Logger *Logger::getInstance(std::string loggerName) {
    if (Logger::instance.find(loggerName) == Logger::instance.end()) {
        Logger::instance.insert(std::pair<std::string, Logger *>(loggerName, new Logger(loggerName)));
    }
    return Logger::instance.at(loggerName);
}

Logger::~Logger() {
    spdlog::drop_all();
}