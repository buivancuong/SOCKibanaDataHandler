//
// Created by cuongbv on 12/18/2018.
//

#ifndef KIBANADATAHANDLER_EVENT_H
#define KIBANADATAHANDLER_EVENT_H

#include <iostream>
#include <string>

class Event {
private:
    std::string srcIP;
    std::string dstIP;
    std::string msg;
    std::string timeStamp;
    int count;
    int hourStep;

public:
    Event();

    explicit Event(std::string srcIP);

    ~Event();

    std::string getSrcIP();

    std::string getDstIP();

    std::string getMsg();

    std::string getTimeStamp();

    int getCount();

    int getHourStep();

    void setSrcIP(std::string srcIP);

    void setDstIP(std::string dstIP);

    void setMsg(std::string msg);

    void setTimeStamp(std::string timeStamp);

    void setCount(int count);

    void setHourStep(int hourStep);
};


#endif //KIBANADATAHANDLER_EVENT_H
