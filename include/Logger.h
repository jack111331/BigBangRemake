//
// Created by edge on 2019-10-18.
//

#ifndef BIGBANGREMAKE_LOGGER_H
#define BIGBANGREMAKE_LOGGER_H

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"
#include <map>

class Logger {
public:
    static std::shared_ptr<spdlog::logger> getLogger(const std::string &loggerName);

    ~Logger();

private:
    static std::map<std::string, std::shared_ptr<spdlog::logger>> loggerMap;
    static std::shared_ptr<spdlog::sinks::basic_file_sink_mt> loggerSink;
};


#endif //BIGBANGREMAKE_LOGGER_H
