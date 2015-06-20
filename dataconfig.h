#ifndef DATACONFIG_H
#define DATACONFIG_H

#include <QString>

class DataConfig
{
public:
    enum class MatchType{All, Ladder, Normal, Solo};
    enum class Skill{All, Pro, VeryHigh, High, Normal};
    enum class Time{All, ThisMonth, ThisWeek, V684, V683, V682};
    enum class Server{All, CN, Foreign};

    QString getUrlParams();
    QString getFileParams();

    static DataConfig & getCurrentConfig();
    static void setCurrentConfig(DataConfig &config);

    MatchType matchtype;
    Skill skill;
    Time time;
    Server server;
private:
    const char * getMatchTypeStr(MatchType matchtype);
    const char * getSkillStr(Skill skill);
    const char * getTimeStr(Time time);
    const char * getServerStr(Server server);
};

#endif // DATACONFIG_H