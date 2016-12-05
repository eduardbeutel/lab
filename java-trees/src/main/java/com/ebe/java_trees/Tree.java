package com.ebe.java_trees;

import com.ebe.java_trees.tree.*;

public interface Tree<K,V>
    extends
        TreeNodeOperations<K,V>,
        TreeAncestorOperations<K,V>,
        TreeDescendantOperations<K,V>,
        TreeLeafOperations<K,V>,
        TreeLevelOperations<K,V>,
        TreeMergeOperations<K,V>
{}
