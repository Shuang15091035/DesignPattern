package com.utility.unittest.service;

import org.springframework.stereotype.Component;
import org.springframework.transaction.support.TransactionTemplate;

@Component
public class SortTree {

    private TransactionTemplate template;
    private Node root;
    class Node {
        private Integer value;
        private Node left;
        private Node right;
        public Node (Integer value){
            this.value = value;
            this.left = null;
            this.right = null;
        }
    }
//    public  Boolean searchBTValue(Integer value, Node f, Node p) {
//        return searchNode(this.root,value);
//    }
    public Boolean insertBTValue (Integer value) {
//        return insertValue(this.root,value);
        return insertNode(this.root,value);
    }
    public void printTree(){
//        printBiTree(this.root);
    }
//    private Boolean searchValue(Node node, Integer value){
//        if (node == null){
//            return false;
//        } else if (value.compareTo(node.value) == 0){
//            return true;
//        } else if (value.compareTo(node.value) < 0) {
//            return searchValue(node.left, value);
//        } else {
//            return searchValue(node.right, value);
//        }
//    }
//    private Boolean insertValue (Node node, Integer value) {
//        Node p = node,parent = null;
//
//        Node newNode = new Node(value);
//        if (node == null) {
//            this.root = newNode;
//            return true;
//        }
//        if (searchValue(node,value)) return false;
//        while (p != null){
//            parent = p;
//            if (value < p.value){
//               p = p.left;
//            } else {
//                p = p.right;
//            }
//        }
//        if (value < parent.value){
//            parent.left = newNode;
//        } else {
//            parent.right = newNode;
//        }
//        return true;
//    }
//
//    private void printBiTree(Node node){
//        if (node != null){
//            System.out.println(node.value);
//            printBiTree(node.left);
//            printBiTree(node.right);
//        } else {
//            System.out.println("空树");
//            return;
//        }
//    }


    public Boolean searchNode(Node node, Integer value, Node f, Node p) {
        if (node == null){
            p = f;
            return false;
        } else if (value.compareTo(node.value) == 0){
            p = node;
            return true;
        } else if (value.compareTo(node.value) < 0) {
            return searchNode(node.left, value, node, p);
        } else {
            return searchNode(node.right, value, node, p);
        }
    }

    public Boolean insertNode (Node node, Integer value) {
        Node p = null;
        System.out.println(p);
        Node newNode = new Node(value);
        if (node == null) {
            this.root = newNode;
            return true;
        }
        if (!searchNode(node,value,null,p)){
            if (value < p.value){
                p.left = newNode;
            } else {
                p.right = newNode;
            }
            return true;
        }
        return false;
    }

    public void test(Object... vales){

    }

}
