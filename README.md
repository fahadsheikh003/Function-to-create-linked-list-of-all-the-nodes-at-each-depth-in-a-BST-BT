# Function-to-create-linked-list-of-all-the-nodes-at-each-depth-in-a-BST-BT

# Problem:
Given a binary tree, write a function which creates a linked list of all the nodes at each depth (e.g., if you have a tree with depth D, you'll have D linked lists). The tree will be passed as an argument to the function and the function will return the number of linked lists created (depth of the tree).

# Explanation of Implementation:
I have used two queues, one to hold all nodes that will be used to create linked list and second to fill the first one again with all the children of nodes that are in second queue. At first, I calculated the height of the Tree and accordingly created an array of linked list (STL based linked list). Initially, I enqueued root into both queues and then I dequeued all the elements of the first queue (root) and entered them into first linked list and then I dequeued all the elements of the second queue (root) and enqueued their children into first queue and copied first queue into second queue and repeated the process stated above.
