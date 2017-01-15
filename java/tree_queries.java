
/* 
 * File:   tree_queries.java
 * Author: rupali bhatnagar
 *
 *Problem: Tree Queries
 *          Devu and Churu like to play with trees a lot. Today, they have a 
 *          rooted unbalanced K-ary tree T consisting of N nodes and each node 
 *          in the tree is labeled uniquely with the integers from 1 to N. Node 
 *          with label 1 is the root of the tree T. To play with this tree, They
 *          have decided to perform Q operations on their tree T. In each 
 *          operation, they shall be given a list of K nodes. Now, they need to 
 *          find for all the nodes in this list, a node X, such that node X is 
 *          an ancestor of all nodes in the given list, and the depth of node X 
 *          is highest among all possible ancestors of the nodes in the list.
 * 
 * Input:   The first line of the input contains 2 space separated integers N 
 *          and Q denoting the number of nodes in the tree T and number of 
 *          operations to be performed. Each of the next N−1 lines of input 
 *          contains a single integer where the integer in the ith line is the 
 *          parent of node with label i+1. Each of the next 2×Q lines of input 
 *          contains Q operations where each operation spans over 2 lines and 
 *          has following format :
 *              The first line of each operation contains an integer K denoting 
 *              the number of nodes in the given operation.
 *              Second line of each operation contains K space separated 
 *              integers denoting labels of nodes over which you need to perform
 *              given operation.
 */
package myjava;

import static java.lang.Math.pow;
import java.util.LinkedList;
import java.util.Scanner;

public class MyJava {

    
    public static void main(String[] args) {
        Scanner in =new Scanner(System.in);
        int N=in.nextInt();
        int Q=in.nextInt();
        
        int []parentInput=new int[N];
        parentInput[0]=0;
        int max=0;
        
        for(int i=1;i<N;++i){
            parentInput[i]=in.nextInt();
            if(parentInput[i]>max){
                max=parentInput[i];
            }
        }
        
        int maxNodes=(int)pow(2,max+1);
        int[] tree=new int[maxNodes];
        int treePtr=0;
        tree[0]=1;
        
        LinkedList q =new LinkedList();
        q.add(tree[0]);
        
        while(!q.isEmpty()){
            int element=(int) q.remove();
            for(int i=1;i<N;++i){
                if(parentInput[i]==element){
                    treePtr=find(tree, element, maxNodes);
                    int childPos=tree[(2*treePtr)+1]==0?((2*treePtr)+1):((2*treePtr)+2);
                    tree[childPos]=i+1;
                    q.add(i+1);
                }
            }
        }
        
        
        for(int i=0;i<Q;++i){
        int Ne=in.nextInt();
        
        int answer=maxNodes;
        for(int j=0;j<Ne;++j){
            int query=in.nextInt();
            int elementPos=find(tree,query,maxNodes);
            int parentPos=(elementPos-1)/2;
            if(parentPos <answer){
                answer=parentPos;
            }
        }
        System.out.println(tree[answer]);
     }
                
    }

    private static int find(int[] tree, int element, int maxNodes) {
        for(int i=0;i<maxNodes;++i){
            if(tree[i]==element){
                return i;
            }
        }
        return -1;
    }
    
    
    
    
}
