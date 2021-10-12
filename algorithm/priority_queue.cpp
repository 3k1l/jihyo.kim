#include <queue>
#include <iostream>

using namespace std;

struct Person {

   string name;

   int age;

   int id;

  //Person(string nameIN, int ageIN, int idIN) : name(nameIN), age(ageIN), id(idIN){ }

};

struct cmp {
  bool operator()(Person lhs, Person rhs) {
        if(lhs.age > rhs.age)
            return lhs.age > rhs.age; // true 를 하면 lhs 가 더 크다는 것이고 age의 오름차순으로 정렬됩니다.
        else {
            return lhs.id < rhs.id; // true 를 하면 lhs 가 더 크다는 것이고 age의 오름차순으로 정렬됩니다.
        }
   }
};

int main() {
     priority_queue<Person, vector<Person>, cmp> pq;
     //Person persons[10];
     for(int i = 0 ; i < 10 ; ++i) {
        Person person = {"test", 26, 109+i};
        //persons[i] = person;
        pq.push(person);
     }
     /* for struct array
     for(int i = 0 ; i < 10 ; ++i) {
        cout << persons[i].age << endl;
     }
     */
     int len = pq.size();
     for(int i = 0 ; i < len ; ++i) {
         cout << pq.top().id << endl;
         pq.pop();
     }
}
 
