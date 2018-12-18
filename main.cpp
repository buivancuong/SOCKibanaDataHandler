#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <deque>
#include <utility>
#include <time.h>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <windows.h>
#include "Event.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "Xin hay nhap tham so la file *.csv can xu ly" << std::endl;
        return 0;
    } else {
        std::string fileName(argv[1]);

        std::deque<Event> eventListResult;
        std::deque<Event> eventDeque;

        std::fstream eventFile;
        eventFile.open(fileName, std::ios::in);
        std::string eventLine;
        std::cout << "Loading data from Event file of Kibana to memory, please wait ..." << std::endl;
        std::string dump;
        std::getline(eventFile, dump);

        while (!eventFile.eof()) {
            std::getline(eventFile, eventLine);
            std::vector<std::string> vectorLine;
            boost::split(vectorLine, eventLine, boost::is_any_of(","));

            auto *event = new Event();
            event->setSrcIP(vectorLine[0]);
            event->setDstIP(vectorLine[1]);
            event->setMsg(vectorLine[2]);
            event->setTimeStamp(vectorLine[3] + vectorLine[4]);
            std::stringstream stringCount(vectorLine[5]);
            int count;
            stringCount >> count;
            event->setCount(count);

            std::vector<std::string> vectorTimeStamp;
            boost::split(vectorTimeStamp, vectorLine[4], boost::is_any_of(":"));
            std::stringstream stringHour(vectorTimeStamp[0]);
            int hourStep;
            stringHour >> hourStep;
            if (hourStep <= 18) {
                hourStep += 24;
            }
            if (hourStep % 2 == 1) {
                hourStep--;
            }
            event->setHourStep(hourStep);

            eventDeque.push_back(*event);
        }
        eventFile.close();

        eventListResult.push_back(eventDeque.front());
        eventDeque.pop_front();
        while (!eventDeque.empty()) {
            Event currentEvent = eventDeque.front();
            Event lastEvent = eventListResult.back();
            if ((currentEvent.getSrcIP() == lastEvent.getSrcIP()) && (currentEvent.getDstIP() == lastEvent.getDstIP()) && (currentEvent.getMsg() == lastEvent.getMsg())) {
                if ((currentEvent.getHourStep() == lastEvent.getHourStep())) {
                    std::cout << "Last: " << lastEvent.getCount() << std::endl;
                    std::cout << "Current: " << currentEvent.getCount() << std::endl;
                    eventListResult.back().setCount(lastEvent.getCount() + currentEvent.getCount());
                    std::cout << "new Last: " << eventListResult.back().getCount() << std::endl;
                    eventDeque.pop_front();
                    continue;
                } else {
                    eventListResult.push_back(currentEvent);
                    eventDeque.pop_front();
                }
            } else {
                eventListResult.push_back(currentEvent);
                eventDeque.pop_front();
            }
        }

        std::fstream resutlFile;
        resutlFile.open("result.csv", std::ios::out);
        for (auto &item : eventListResult) {
            resutlFile << item.getSrcIP() << ", " << item.getDstIP() << ", " << item.getMsg() << ", " << item.getTimeStamp() << ", " << item.getCount() << std::endl;
        }
        resutlFile.close();

        return 0;
    }
}