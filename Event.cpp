#include <utility>

#include <utility>

#include <utility>

#include <utility>

#include <utility>

//
// Created by cuongbv on 12/18/2018.
//

#include "Event.h"

Event::Event() = default;

Event::Event(std::string srcIP) {
    this->srcIP = std::move(srcIP);
}

std::string Event::getSrcIP() {
    return this->srcIP;
}

std::string Event::getDstIP() {
    return this->dstIP;
}

std::string Event::getMsg() {
    return this->msg;
}

std::string Event::getTimeStamp() {
    return this->timeStamp;
}

int Event::getCount() {
    return this->count;
}

void Event::setSrcIP(std::string srcIP) {
    this->srcIP = std::move(srcIP);
}

void Event::setDstIP(std::string dstIP) {
    this->dstIP = std::move(dstIP);
}

void Event::setMsg(std::string msg) {
    this->msg = std::move(msg);
}

void Event::setTimeStamp(std::string timeStamp) {
    this->timeStamp = std::move(timeStamp);
}

void Event::setCount(int count) {
    this->count = count;
}

int Event::getHourStep() {
    return this->hourStep;
}

void Event::setHourStep(int hourStep) {
    this->hourStep = hourStep;
}

Event::~Event() = default;
