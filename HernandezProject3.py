class Node:
    def __init__(self, val):
        self.left = None
        self.right = None
        self.val = val
class Tree:
    def __init__(self, d= None):
        if (d == None):
            self.root = None
        else:
            self.root = Node(d)

    def insert(self, d):
        def __insertHere__(n, d):
            if (n.val > d):  # if no node left insert here
                if (n.left == None):
                    n.left = Node(d)
                else:  # or try left child
                    __insertHere__(n.left, d)
            elif (n.val < d):  # if no node right insert here
                if (n.right == None):
                    n.right = Node(d)
                else:  # or try right child
                    __insertHere__(n.right, d)
        if (self.root == None):  # it was an empty tree
            self.root = Node(d)
        else:
            if (self.root.val > d):  # try left child
                if (self.root.left == None):  # if empty insert here
                    self.root.left = Node(d)
                else:  # try left subtree
                    __insertHere__(self.root.left, d)
            elif (self.root.val < d):  # try right child
                if (self.root.right == None):  # if empty insert here
                    self.root.right = Node(d)
                else:  # try right subtree
                    __insertHere__(self.root.right, d)
    # Created method in Tree class that takes values in tree and order them into a list using preorder traversal
    def preorder_traversal(self, result):
            def traversal(d):
                if d:
                    result.append(d.val)
                    if d.left:
                        traversal(d.left)
                    if d.right:
                        traversal(d.right)
            traversal(self.root)
            return
# method in tree class that creates an array that stores parent nodes with their children.
    def parentChildPair(self):
        parentChild = []
        def getPairs(r):
            if r:
                if r.left:
                    parentChild.append([r.val,r.left.val])
                if r.right:
                    parentChild.append([r.val,r.right.val])
                getPairs(r.left)
                getPairs(r.right)
        getPairs(self.root)
        return parentChild
    # Method that creates a matrix and fills in the difference between a parent and its child to an index.
    def createMatrix(self, result, pairs):
        matrix = [[0] * len(result) for _ in range(len(result))]
        for i in range(len(result)):
            for j in range(len(result)):
                a = len(pairs)
                for k in range(a):
                        if pairs[k] == [result[i],result[j]]:
                            print(pairs[k])
                            print([result[i],result[j]])
                            matrix[i][j] = abs(result[i] - result[j])
        return matrix
    # Used to output the matrix to the user.
    def printMatrix(self, matrix):
        print("Adjacency Matrix:")
        for row in matrix:
                print(row)
def main():
    # opens file and stores items in a variable called values
    with open("numbers.txt", 'r') as file:
        values = [int(line.strip()) for line in file]
    # Make an instance of the Tree class called Num. Then Insert values into the tree
    Num = Tree()
    for value in values:
        Num.insert(value)
    # Created list called result
    result = []
    # Used method to store node data into a list
    Num.preorder_traversal(result)
    print(result)
    # Stored parent child pairs from instance into a variable called cp
    cp = Num.parentChildPair()
    # Stored matrix from instance into a variable called a
    a = Num.createMatrix(result, cp)
    # Output the Matrix to the user from the instance using printMatrix method.
    Num.printMatrix(a)
# Activates the program.
if __name__ == "__main__":
    main()