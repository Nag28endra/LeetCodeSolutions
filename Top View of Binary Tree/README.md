You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note: 

Return the nodes from the leftmost node to the rightmost node.
If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only. 

Examples:

Input: root[] = [1, 2, 3] 

![image](https://github.com/user-attachments/assets/52760724-c354-40c1-8359-3ef1afa7e07d)

Output: [2, 1, 3]

Input: root[] = [10, 20, 30, 40, 60, 90, 100]

![image](https://github.com/user-attachments/assets/6bfa3e24-61ce-4289-82e3-256f73d30e14)

Output: [40, 20, 10, 30, 100]
Explanation: The root 10 is visible.
On the left, 40 is the leftmost node and visible, followed by 20.
On the right, 30 and 100 are visible. Thus, the top view is 40 20 10 30 100.
