#include <iostream>
#include <string>
using namespace std;

// 定义枚举类型 Rank，表示玩家等级
enum Rank {
    BEGINNER,     // 初学者
    PROFESSIONAL, // 专业玩家
    EXPERT        // 专家
};

// User_Prof 类定义
class User_Prof {
private:
    string name;       // 玩家姓名
    int loginTimes;    // 登录次数
    int playedMatches; // 已玩对局数
    int wonMatches;    // 胜利对局数
    double winRatio;   // 胜率
    Rank rank;         // 玩家等级
    static int guestCounter; // 记录当前 "guest" 用户的计数，用于区分多个 guest 用户

public:
    // 构造函数：初始化玩家信息
    User_Prof(string name = "guest", Rank rank = BEGINNER)
        : name(name), loginTimes(0), playedMatches(0), wonMatches(0), winRatio(0.0), rank(rank) {
        if (name == "guest") {
            guestCounter++;
            this->name += "_" + to_string(guestCounter); // 确保每个 guest 用户唯一
        }
    }

    // 登录操作：增加登录次数
    void login() {
        loginTimes++;
        cout << name << " logged in. Total logins: " << loginTimes << endl;
    }

    // 登出操作
    void logout() {
        cout << name << " logged out." << endl;
    }

    // 测试等效性：判断两个用户是否相同
    bool isEquivalentTo(const User_Prof& other) const {
        return name == other.name && rank == other.rank;
    }

    // 测试不等效性：判断两个用户是否不同
    bool isNotEquivalentTo(const User_Prof& other) const {
        return !isEquivalentTo(other);
    }

    // 设置玩家的对局和胜率信息
    void updateMatches(int played, int won) {
        playedMatches += played;
        wonMatches += won;
        if (playedMatches > 0) {
            winRatio = static_cast<double>(wonMatches) / playedMatches; // 更新胜率
        }
    }

    // 打印玩家信息
    void printProfile() const {
        cout << "Name: " << name << endl;
        cout << "Login Times: " << loginTimes << endl;
        cout << "Played Matches: " << playedMatches << endl;
        cout << "Won Matches: " << wonMatches << endl;
        cout << "Win Ratio: " << winRatio * 100 << "%" << endl;
        cout << "Rank: ";
        switch (rank) {
            case BEGINNER:
                cout << "Beginner";
                break;
            case PROFESSIONAL:
                cout << "Professional";
                break;
            case EXPERT:
                cout << "Expert";
                break;
        }
        cout << endl;
    }
};
