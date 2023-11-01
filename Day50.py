class Solution:
    def __init__(self):
        self.mp = {}

    # Helper function to perform an in-order traversal and count the frequency of each value
    def isValid(self, root):
        if root is None:
            return

        self.isValid(root.left)  # Traverse left subtree
        self.mp[root.val] = self.mp.get(root.val, 0) + 1  # Update frequency count in the dictionary
        self.isValid(root.right)  # Traverse right subtree

    # Main function to find the mode (most frequent elements)
    def findMode(self, root):
        self.isValid(root)  # Call the helper function to populate the frequency map

        maxi = 0
        # Find the maximum frequency encountered
        for value in self.mp.values():
            maxi = max(maxi, value)

        ans = []
        # Collect elements with the maximum frequency in the result list
        for key, value in self.mp.items():
            if value == maxi:
                ans.append(key)

        return ans
