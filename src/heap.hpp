#include "binaryTree.hpp"

template <typename T>
class Heap {
private:
    PerfectBinaryTree<T> tree;

    void heapUp() {
        int index = tree.getSize() - 1;

        while (tree.hasParent(index)) {
            int parent = tree.getParentIndex(index);

            if (tree.getNode(index) <= tree.getNode(parent)) {
                break;
            }

            tree.swapNodes(index, parent);
            index = parent;
        }
    }

    void heapDown() {
        int index = 0;

        while (tree.hasLeftChild(index)) {
            int largestChild = tree.getLeftChildIndex(index);
            int rightChild = tree.getRightChildIndex(index);

            if (tree.hasRightChild(index) &&
                tree.getNode(rightChild) > tree.getNode(largestChild)) {
                largestChild = rightChild;
            }

            if (tree.getNode(index) >= tree.getNode(largestChild)) {
                break;
            }

            tree.swapNodes(index, largestChild);
            index = largestChild;
        }
    }

public:
    Heap(int height) : tree(height) {}

    void push(T value) {
        if (!tree.isFull()) {
            tree.push(value);
            heapUp();
        }
    }

    T peek() {
        if (!tree.isEmpty()) {
            return tree.getNode(0);
        }
        return T();
    }

    T pop() {
        if (!tree.isEmpty()) {
            T value = tree.getNode(0);
            tree.swapNodes(0, tree.getSize() - 1);
            tree.removeLast();
            if (!tree.isEmpty()) {
                heapDown();
            }
            return value;
        }
        return T();
    }
        

    bool isEmpty() const {
        return tree.isEmpty();
    }

    bool isFull() const {
        return tree.isFull();
    }

    int getSize() const {
        return tree.getSize();
    }

    int getCapacity() const {
        return tree.getCapacity();
    }
};
