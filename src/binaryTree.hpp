#include <vector>
#include <cmath>
#include <utility>

template <typename T>
class PerfectBinaryTree {
private:
    std::vector<T> nodes;
    int numNodes;
    int height;

public:
    PerfectBinaryTree(int treeHeight) : height(treeHeight), numNodes(0) {
        int n = static_cast<int>(std::pow(2, treeHeight + 1)) - 1;
        nodes.reserve(n);
    }

    T& getNode(int index) {
        return nodes[index];
    }

    const T& getNode(int index) const {
        return nodes[index];
    }

    void push(T value) {
        nodes.push_back(value);
        numNodes++;
    }

    void removeLast() {
        nodes.pop_back();
        numNodes--;
    }

    T& getRoot() {
        return nodes[0];
    }

    int getParentIndex(int index) const {
        return index == 0 ? -1 : (index - 1) / 2;
    }

    int getLeftChildIndex(int index) const {
        return 2 * index + 1;
    }

    int getRightChildIndex(int index) const {
        return 2 * index + 2;
    }

    bool hasParent(int index) const {
        return index != 0;
    }

    bool hasLeftChild(int index) const {
        return getLeftChildIndex(index) < numNodes;
    }

    bool hasRightChild(int index) const {
        return getRightChildIndex(index) < numNodes;
    }

    void swapNodes(int first, int second) {
        std::swap(nodes[first], nodes[second]);
    }

    bool isEmpty() const {
        return numNodes == 0;
    }

    bool isFull() const {
        return numNodes == getCapacity();
    }
    
    int getHeight() const {
        return height;
    }

    int getSize() const {
        return numNodes;
    }

    int getCapacity() const {
        return static_cast<int>(std::pow(2, height + 1)) - 1;
    }
};
