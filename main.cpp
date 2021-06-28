//
// Created by Kylian Lee on 2021/06/28.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;
  int size = progresses.size();
  int progressRate[100] = {0};
  for (int i = 0; i < size; ++i) {
    int task = 100 - progresses[i];
    bool dividable = false;
    if(task % speeds[i] != 0)
      dividable = true;
    task /= speeds[i];
    if(dividable)
      task++;
    progressRate[i] = task;
  }
  int j;
  for (int i = 0; i < size; ++i) {
    queue<int> completed;
    completed.push(i);
    int min = progressRate[i];
    for (j = i + 1; j < size; ++j) {
      if(progressRate[j] > min){
        i = j - 1;
        break;
      }
      else {
        completed.push(j);
        continue;
      }
    }
    answer.push_back(completed.size());
    if(j == size)
      break;
  }
  return answer;
}

 int main() {
   vector<int> progress = {95, 90, 99, 99, 80, 99};
   vector<int> speed = {1, 1, 1, 1, 1, 1};
 //  vector<int> progress = {93, 30, 55};
 //  vector<int> speed = {1, 30, 5};
 //  vector<int> progress = {99, 49, 1};
 //  vector<int> speed = {2, 1, 1};
 //  vector<int> progress = {93};
 //  vector<int> speed = {1};
   vector<int> answer = solution(progress, speed);
   for (int i = 0; i < answer.size(); ++i) {
     cout << answer[i] << endl;
   }
   return 0;
 }