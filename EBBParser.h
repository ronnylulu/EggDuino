#pragma once

// implemented Eggbot-Protocol-Version v13
// EBB-Command-Reference, I sourced from: http://www.schmalzhaus.com/EBB/EBBParser.html

#include <Stream.h>

class EBBParser {
public:
    EBBParser(Stream& stream);

protected:
    void parseStream();

    virtual void enableMotor(int axis, bool state) = 0;
    virtual void stepperMove(int duration, int numPenSteps, int numRotSteps) = 0;

    virtual void setPenState(bool up) = 0;
    virtual bool getPenState() = 0;
    virtual void setPenUpPos(int pos) = 0;
    virtual void setPenDownPos(int pos) = 0;

    virtual void setServoRateUp(int rate) = 0;
    virtual void setServoRateDown(int rate) = 0;

    virtual bool getPrgButtonState() = 0;
    virtual void setPinOutput(char port, int pin, int value) = 0;

    virtual void setEngraverState(bool state, int power) = 0;
private:
    void sendAck();
    void sendError();

    void parseEM(const char* arg1, const char* arg2);
    void parseND();
    void parseNI();
    void parsePO(const char* arg1, const char* arg2, const char* arg3);
    void parseQB();
    void parseQL();
    void parseQN();
    void parseQP();
    void parseSC(const char* arg1, const char* arg2);
    void parseSE(const char* arg1, const char* arg2, const char* arg3);
    void parseSL(const char* arg);
    void parseSM(const char* arg1, const char* arg2, const char* arg3);
    void parseSN(const char* arg);
    void parseSP(const char* arg1, const char* arg2, const char* arg3);
    void parseTP(const char* arg);
    void parseV();

    Stream& mStream;

    String readBuffer;
    unsigned int nodeCount;
    unsigned int layer;
};
