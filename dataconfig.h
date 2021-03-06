#ifndef DATACONFIG_H
#define DATACONFIG_H

#include <QString>

class DataConfig
{
public:
    enum class MatchType{All, Normal, Ladder, Solo};
    enum class Skill{All, Normal, High, VeryHigh, Pro};
    enum class Time{All, ThisMonth, ThisWeek, V684, V683, V682};
    enum class Server{All, CN, Foreign};

    QString getUrlParams() const;
    QString getFileParams() const;
    void save(const QString &filename);
    void load(const QString &filename);

    static DataConfig & getCurrentConfig();
    static void setCurrentConfig(DataConfig &config);
    static QString getUrlParamsCurrent();
    static QString getFileParamsCurrent();
    static void saveCurrent(const QString &filename);
    static void loadCurrent(const QString &filename);


    MatchType matchtype;
    Skill skill;
    Time time;
    Server server;


private:
    const char * getMatchTypeStr(MatchType matchtype) const;
    const char * getSkillStr(Skill skill) const;
    const char * getTimeStr(Time time) const;
    const char * getServerStr(Server server) const;
};

#endif // DATACONFIG_H
