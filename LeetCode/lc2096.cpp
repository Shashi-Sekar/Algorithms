/*
LeetCode: 2096. Step-By-Step Directions from a Binary Tree Node to Another

Algorithm:

Main Method getDirection:
    1. Initialize a map parentMap that maps the node to its parent.
    2. Populate the parentMap using the populateParentMap method.
    3. Find the startNode using the findStartNode method.
    4. For the BFS:
        4.1 Initialize a queue q.
        4.2 Enqueue the startNode.
        4.3 Initialize a set visited to keep track of visited nodes.
        4.4 Initiliaze a map pathTracker to record the path from the startNode to the destNode.
    5. while the queue is not empty
        5.1 Dequeue the front node.
        5.2 If the node's value matches the destNode's value
            5.2.1 Call backtrackPathTracker method 
            5.2.2 Return the directions.
        5.3 If the node conatins a parent and it is not visited
            5.3.1 Enqueue the parent.
            5.3.2 Mark the parent as visited.
            5.3.3 Add an entry to pathtracker with the current node as key and a pair containing the parentNode and the direction 'U' as value.
        5.4 If the node contains a left child and it is not visited
            5.4.1 Enqueue the left child.
            5.4.2 Mark the left child as visited
            5.4.3 Add an entry to pathTracker with the current node as key and a pair containing the left child and the direction 'L' as value.
        5.5 If the node contains a right child and it is not visited
            5.5.1 Enqueue the right child.
            5.5.2 Mark the right child as visited
            5.5.3 Add an entry to the pathTracker with the current node as key and a pair containing the right child and the direction 'R' as value.
    6. Return an empty string since the destination node is not reachable.

Method populateParentMap:
    Parameters: root node, parentMap
    if the root is empty
        return null
    if the left child is not empty 
        add the left child to the parentMap as key and the root as the value
        call the populateParentMap method with the left child and the parentMap
    if the right child is not empty 
        add the right child to the parentMap as key and the root as the value
        call the populateParentMap method with the right child and the parentMap

Method findStartNode:
    Parameters: root node, startValue
    if the root is empty
        return null
    if the root's value matches the startValue
        return the root
    call the findStartNode method with the left child and the startValue
    call the findStartNode method with the right child and the startValue
    
*/

#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

    auto search = map.find(2);
    if (search != map.end()) {
        std::cout << "Found: " << search->first << " -> " << search->second << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}