//
// Created by edge on 2019-10-18.
//

#include "Logger.h"

std::map<std::string, std::shared_ptr<spdlog::logger>> Logger::loggerMap;
std::shared_ptr<spdlog::sinks::basic_file_sink_mt> Logger::loggerSink;

Logger::Logger() {
    this->loggerSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("BigBangRemake.log");
}

std::shared_ptr<spdlog::logger> Logger::getLogger(const std::string &loggerName) {
    if (loggerMap.find(loggerName) == loggerMap.end()) {
        loggerMap.insert(std::pair<std::string, std::shared_ptr<spdlog::logger>>(loggerName, std::make_shared<spdlog::logger>(loggerName, loggerSink)));
    }
    return Logger::loggerMap.at(loggerName);
}

Logger::~Logger() {
    spdlog::drop_all();
}