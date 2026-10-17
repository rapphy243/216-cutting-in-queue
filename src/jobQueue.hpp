#include "heap.hpp"
#include "job.hpp"

class JobQueue {
private:
  Heap<Job> jobs;

public:
  JobQueue(int height = 10) : jobs(height) {}

  void insert(Job job) {
    jobs.push(job);
  }

  void runHighestPriority() {
    if (!jobs.isEmpty()) {
      jobs.pop().execute();
    }
  }
};
