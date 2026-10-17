#include <iostream>
#include <string>

class Job {
private:
  std::string name;
  int priority;

public:
  Job() : name(), priority(0) {}
  Job(std::string n, int p) : name(n), priority(p) {}

  void execute() {
    std::cout << "Running the job with name "
      << name
      << " and priority "
      << priority;
  }

  std::string getName() {
    return name;
  }

  int getPriority() {
    return priority;
  }

  friend bool operator>(const Job& left, const Job& right) {
    return left.priority > right.priority;
  }

  friend bool operator<=(const Job& left, const Job& right) {
    return left.priority <= right.priority;
  }

  friend bool operator>=(const Job& left, const Job& right) {
    return left.priority >= right.priority;
  }
};
