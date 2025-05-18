#ifndef ERRORREPORTER_H
#define ERRORREPORTER_H

#include <string>

class ErrorReporter {
    private:
    bool hadError;

    public:
    ErrorReporter();
    void error(int line, std::string message);
    bool getError();
    void setError();
};


#endif