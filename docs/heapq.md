# heapif: using the algorithm Bottom-Up Heap Construction.
All `leaf` node is already a valid heap cause they do not have child.
So we start at the last non-leaf node that we can get with:
    i = [N/2] - 1, for an array of size N.
