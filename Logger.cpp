//
// Created by edge on 2019-10-18.
//

#include "Logger.h"

std::map<std::string, std::shared_ptr<spdlog::logger>> Logger::loggerMap;
std::shared_ptr<spdlog::sinks::basic_file_sink_mt> Logger::loggerSink = nullptr;

std::shared_ptr<spdlog::logger> Logger::getLogger(const std::string &loggerName) {
    if (Logger::loggerSink == nullptr) {
        Logger::loggerSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("BigBangRemake.log");
    }
    std::shared_ptr<spdlog::logger> logger;
    auto loggerIterator = Logger::loggerMap.find(loggerName);
    if (loggerIterator == Logger::loggerMap.end()) {
        logger = std::shared_ptr<spdlog::logger>(std::make_shared<spdlog::logger>(loggerName, Logger::loggerSink));
        logger->flush_on(spdlog::level::info);
        Logger::loggerMap.insert(std::pair<std::string, std::shared_ptr<spdlog::logger>>(loggerName, logger));
    } else {
        logger = loggerIterator->second;
    }
    return logger;
}

Logger::~Logger() {
    spdlog::drop_all();
}