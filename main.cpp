#include <iostream>
#include "./src/jobQueue.hpp"

using namespace std;

int main() {
    JobQueue jobQueue;
 
    Job jobA("This is job a", 5);
    Job jobB("This is job b", 2);
    Job jobC("This is job c", 9);
    Job jobD("This is job d", 8);
    Job jobE("This is job e", 1);
    jobQueue.insert(jobA);
    jobQueue.insert(jobB);
    jobQueue.insert(jobC);
    jobQueue.insert(jobD);
    jobQueue.insert(jobE);

    jobQueue.runHighestPriority(); // Calls jobC.execute() since job C has the highest priority
    cout << std::endl;
    jobQueue.runHighestPriority(); // Calls jobD.execute() since job C has the highest priority
    cout << std::endl;
    jobQueue.runHighestPriority(); // Calls jobA.execute() since job C has the highest priority
    cout << std::endl;
    jobQueue.runHighestPriority(); // Calls jobB.execute() since job C has the highest priority
    cout << std::endl;
    jobQueue.runHighestPriority(); // Calls jobE.execute() since job C has the highest priority
    cout << std::endl;
    return 0;
}
