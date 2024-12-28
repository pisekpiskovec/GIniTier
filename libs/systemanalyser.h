#ifndef SYSTEMANALYSER_H
#define SYSTEMANALYSER_H
#include <string>

class SystemAnalyser
{
public:
    SystemAnalyser();
    virtual void RunCommand(const char * command);
    virtual void StoreOutput(std::string& result);
    virtual void DisplayOutput();
    virtual std::string ReturnOutput();
    virtual ~SystemAnalyser();
private:
    std::string outputStore;
};

#endif // SYSTEMANALYSER_H
