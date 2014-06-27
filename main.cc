#include <iostream>
#include <vector>

#define PL( text ) (cout << text << endl)

using namespace std;

struct Menu {
    struct Answer {
        string text;
        int num;
    };

    vector<string> list;
    Answer ask() {
        vector<string>::iterator it = list.begin();
        for (int i = 1; it != list.end(); ++i) {
            PL(i << ". " << *it);
            ++it;
        }
        Answer answer;

        while (answer.text == "") {
            string in;
            getline(cin, in);
            try {
                answer.num = atoi(in.c_str());
            } catch(...) {
                PL("Please enter a number from 1 to " << list.size());
                continue;
            }
            if (answer.num == 0 || answer.num > list.size()) {
                PL("Please enter a number from 1 to " << list.size());
                continue;
            }
            answer.text = list[answer.num - 1];
        }

        return answer;
    }

    void add(string s) {
        list.push_back(s);
    }

    void clear() {
        list.clear();
    }
};

int main (int argc, char**argv) {
    PL("Welcome to Text Harvest!");
    Menu main_menu;
    main_menu.add("New Game");  // 1
    main_menu.add("Continue");  // 2
    main_menu.add("Options");   // 3
    main_menu.add("Credits");   // 4
    main_menu.add("Quit");      // 5

    while (1) {
        Menu::Answer answer = main_menu.ask();
        PL(answer.text);
        if (answer.num == 5) {
            break;
        }
    }
}
