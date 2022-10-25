# Binary Tree Notes

## Structure
 - Nonlinear Organization
 - Hierarchal Structure
    -Examples include file directories/school structure/army

## Defintion
  - A collection of nodes connected by edges (pointers)
  - Non-cyclical

## Terminology

- #### Level: The level of a node represents that node's hierarchy
- #### Root: The single node at the top of the level
- #### Children: The nodes at each successive (lower) level of a tree are the children of the nodes at the previous (higher) level
- #### Parent: A node that has children is the parent of those children 
- #### Leaf: A node that has no children 
- #### Subtree: Any node and its descendants form a subtree of the original tree. Leafs can be empty subtrees
- #### Siblings: Sibling nodes share the same parent node
- #### Uncles: Siblings of that node's parent
- #### Ancestor: A node that is connected to all lower-level nodes (leaf nodes)
- #### Descendant: The connected lower-level nodes are "descendants" of the ancestor(may be parent, or root) node

## Tree Connection Terminology
 - #### Edge: Connection between one node and another
 - #### Path: A sequence of nodes and edges connecting a node with a descendant
 - #### Height of a node: The height of a node is the number of edges on the longest path between that node and a leaf + 1. Or the amount of nodes between the leaf node and the node in question.
 - #### Height of a tree: The height of a tree is the height of its root node
 - #### Depth of a node: The depth of a node is the number of edges from the tree's root node to the node + 1

 ## Types of Trees
- A tree can have any number of children.
    - Binary tree has a max of two children nodes per parent.
    - Ternary tree has a max of three children nodes per parent.
    - N-ary tree has a max of n children nodes per parent.
    - Usually has a set of conditions to tell the tree where to create the children nodes

## Types of Binary Trees
- #### Full Binary Tree: All internal nodes have __two__ children, and all leaves are the same depth  
  
- #### Complete Binary Tree: An almost full binary tree; the bottom level of the tree is filling left to right but does not have a full complelemt of leaf nodes(not all leaf nodes are filled)

- #### Not full and Not complete: Any tree that does not match the specifications of the previous two definitions

- #### Balanced Binary Trees: The subtrees of each node in the tree differ in height by no more than 1

## Height of Full and/or Complete Binary Trees
 - The numner of nodes in a full binary tree of heigh h is : 
       $n = 2^h + 1 $
 - The height of a full or complete binary tree having n nodes: 
        $h=ceil(log_2(n+1)) $
 - The number of leaf nodes in a full binary tree having a height of h:   $n = 2^h$ $^-$ $^1$
 - The number of non-leaf nodes in a full binary tree having a height h: 
        $n = $ $2^h$ $^-$ $^1$ $ - 1$
 - The number of leaf nodes in a complete binary tree having a number of nodes n:
        $I = floor((n+1)/2)$
 - The number of non-leaf nodes in a complete binary tree having a number of nodes n:
        $nl = ceil((n-1)/2)$

## Tree Traversals
- #### 4 Common Tree Traversals
    - Pre-order Traversal (Recursive)
    - In-order Traversal (Recursive)
    - Post-order Traversal (Recursive)
    - Level-order Traversal (Iterative)

    ### Pre-order Traversal
    - Process the root      
    - Process the nodes in the left subtree with a recursive call
    - Process the nodes in th right subtree with a recursive call

    ### In-order Traversal
    - Process the nodes in the left subtree with a recursive call
    - Process the root
    - Process the nodes in th right subtree with a recursive call

    ### Post-order Traversal
    - Process the nodes in the left subtree with a recursive call
    - Process the nodes in th right subtree with a recursive call
    - Process the root

    ### Level-order Traversal
    - Process the root
    - Process the nodes one level at a time (visiting nodes in each level from left to right) (top to bottom)


## Tree Representations
### Storage Choices
- Array Representation (contiguous structure)
- Node Representation (linked list structure)

## Array Representation
### Formulas for the array representation:
- The data from the root always appears in the [1] element of the array  
- Suppose the data for a node appears in component [ i ] of the array. Then its children (if they exist) always have their data at these locations:  
    - Left child at component [2i]
    - Right child at component [2i+1]
- If the data for a non-root node is stored within component [i] of the array, then the location of the data for the parent of the non-root node is stored at array index [i/2].
- The actual links between the nodes are not stored but are determined by the formula.
- Disadvantages of the array representation include wasted memory in an unbalanced tree and a fixed array size may require re-sizing.
- Wasted memory comes from indexes in the array holding no relevant value in order to follow the formula for organization.

## Node Representation
 - Each node of a binary tree can be stored as an object of a binary tree node class
 - The class contains private instance variables that are pointers to other nodes in the tree
 - An entire tree is represented as a pointer to the root node
    - The pointer to the root is similar to the head of a linked list, providing a starting point to access all the nodes in the tree.
    - We could include other things in the tree node




