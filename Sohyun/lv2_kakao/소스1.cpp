#include <string>
#include <vector>

using namespace std;

bool right(string u) {
    int open = 0, close = 0;

    for (int i = 0; i < u.size(); i++) {
        if (u[i] == '(') open++;
        else close++;

        if (close > open) return false;
    }
    return true;
}

string split(string w) {
    string ret;
    string u, v;

    int open = 0, close = 0;

    if (w.size() == 0)return w;

    for (int i = 0; i < w.size(); i++) {
        if (w[i] == '(') open++;
        else close++;

        u.push_back(w[i]);

        if (open != 0 && open == close) {
            for (int j = i + 1; j < w.size(); j++) {
                v.push_back(w[j]);
            }
            break;
        }
    }

    if (right(u)) return (u + split(v));
    else {
        ret = '(' + split(v) + ')';

        u.erase(u.begin() + u.size() - 1), u.erase(u.begin());
        string reverse_u;

        for (int i = 0; i < u.size(); i++) {

            if (u[i] == '(') reverse_u.push_back(')');
            else reverse_u.push_back('(');
        }
        return ret += reverse_u;
    }
}

string solution(string p) {
    return split(p);
}