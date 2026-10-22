#include <iostream>
using namespace std;
struct Stu {
    int id;
    int score;
};
void print_stu(Stu *p) {
    cout<<(*p).id<<" "<<(*p).score<<"\n";
}
int main() {
    Stu s = {102, 95};
    print_stu(&s);
    return 0;
}
