#include <iostream>
#include <string>
using namespace std;

// ����ö������ Rank����ʾ��ҵȼ�
enum Rank {
    BEGINNER,     // ��ѧ��
    PROFESSIONAL, // רҵ���
    EXPERT        // ר��
};

// User_Prof �ඨ��
class User_Prof {
private:
    string name;       // �������
    int loginTimes;    // ��¼����
    int playedMatches; // ����Ծ���
    int wonMatches;    // ʤ���Ծ���
    double winRatio;   // ʤ��
    Rank rank;         // ��ҵȼ�
    static int guestCounter; // ��¼��ǰ "guest" �û��ļ������������ֶ�� guest �û�

public:
    // ���캯������ʼ�������Ϣ
    User_Prof(string name = "guest", Rank rank = BEGINNER)
        : name(name), loginTimes(0), playedMatches(0), wonMatches(0), winRatio(0.0), rank(rank) {
        if (name == "guest") {
            guestCounter++;
            this->name += "_" + to_string(guestCounter); // ȷ��ÿ�� guest �û�Ψһ
        }
    }

    // ��¼���������ӵ�¼����
    void login() {
        loginTimes++;
        cout << name << " logged in. Total logins: " << loginTimes << endl;
    }

    // �ǳ�����
    void logout() {
        cout << name << " logged out." << endl;
    }

    // ���Ե�Ч�ԣ��ж������û��Ƿ���ͬ
    bool isEquivalentTo(const User_Prof& other) const {
        return name == other.name && rank == other.rank;
    }

    // ���Բ���Ч�ԣ��ж������û��Ƿ�ͬ
    bool isNotEquivalentTo(const User_Prof& other) const {
        return !isEquivalentTo(other);
    }

    // ������ҵĶԾֺ�ʤ����Ϣ
    void updateMatches(int played, int won) {
        playedMatches += played;
        wonMatches += won;
        if (playedMatches > 0) {
            winRatio = static_cast<double>(wonMatches) / playedMatches; // ����ʤ��
        }
    }

    // ��ӡ�����Ϣ
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
