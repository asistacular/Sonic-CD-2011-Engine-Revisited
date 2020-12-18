#ifndef USERDATA_H
#define USERDATA_H

#define GLOBALVAR_COUNT (0x100)

#define ACHIEVEMENT_MAX (0x40)
#define LEADERBOARD_MAX (0x80)

#define SAVEDATA_MAX (0x2000)

enum OnlineMenuTypes {
    ONLINEMENU_ACHIEVEMENTS = 0,
    ONLINEMENU_LEADERBOARDS = 1,
};

struct Achievement {
    char name[0x40];
    int status;
};

struct LeaderboardEntry {
    int status;
};

extern int globalVariablesCount;
extern int globalVariables[GLOBALVAR_COUNT];
extern char globalVariableNames[GLOBALVAR_COUNT][0x20];

extern char gamePath[0x100];
extern int saveRAM[SAVEDATA_MAX];
extern Achievement achievements[ACHIEVEMENT_MAX];
extern LeaderboardEntry leaderboard[LEADERBOARD_MAX];


inline bool ReadSaveRAMData()
{
    char buffer[0x100];
    sprintf(buffer, "%ssavedata.sav", gamePath);
    FileIO *saveFile = fOpen(buffer, "rb");
    if (!saveFile)
        return false;
    fRead(saveRAM, 4u, SAVEDATA_MAX, saveFile);
    fClose(saveFile);
    return true;
}

inline bool WriteSaveRAMData()
{
    char buffer[0x100];
    sprintf(buffer, "%ssavedata.sav", gamePath);
    FileIO *saveFile = fOpen(buffer, "wb");
    if (!saveFile)
        return false;
    fWrite(saveRAM, 4u, SAVEDATA_MAX, saveFile);
    fClose(saveFile);
    return true;
}

void InitUserdata();
void writeSettings();
void ReadUserdata();
void WriteUserdata();

void AwardAchievement(int id, int status);
void SetAchievement(int achievementID, int achievementDone);
void SetLeaderboard(int leaderboardID, int result);
inline void LoadAchievementsMenu() { ReadUserdata(); }
inline void LoadLeaderboardsMenu() { ReadUserdata(); }

#endif //!USERDATA_H