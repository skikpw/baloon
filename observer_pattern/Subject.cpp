#include "Subject.h"
#include "Observer.h"

void Subject::attach(Observer *obs) {
  views.push_back(obs);
}

void Subject::notify() {
  // 5. Publisher broadcasts
  for (int i = 0; i < views.size(); i++)
    views[i]->update(this);
}

string Subject::GetTimeStamp(){
    struct timeval tv;
    gettimeofday(&tv,NULL);
    string s = to_string(tv.tv_sec) + ";" + to_string(tv.tv_usec);
    return s;
}
